// {{{RME classifier 'Logical View::Roomba::roombaProgram'

#if defined( PRAGMA ) && ! defined( PRAGMA_IMPLEMENTED )
#pragma implementation "roombaProgram.h"
#endif

#include <RTSystem/roombaController.h>
#include <roombaProgram.h>

// {{{RME tool 'OT::Cpp' property 'ImplementationPreface'
// {{{USR

// }}}USR
// }}}RME

static const RTRelayDescriptor rtg_relays[] =
{
	{
		"Roomba"
	  , &programProtocol::Base::rt_class
	  , 1 // cardinality
	}
};

static RTActor * new_roombaProgram_Actor( RTController * _rts, RTActorRef * _ref )
{
	return new roombaProgram_Actor( _rts, _ref );
}

const RTActorClass roombaProgram =
{
	(const RTActorClass *)0
  , "roombaProgram"
  , (RTVersionId)0
  , 1
  , rtg_relays
  , new_roombaProgram_Actor
};

static const char * const rtg_state_names[] =
{
	"TOP"
  , "roombaWaitForStart"
  , "roombaStart"
  , "bumperTriggered"
  , "CheckWhereWeAre"
  , "checkBatteryLevel"
};

#define SUPER RTActor

roombaProgram_Actor::roombaProgram_Actor( RTController * rtg_rts, RTActorRef * rtg_ref )
	: RTActor( rtg_rts, rtg_ref )
	, speedLeft( MOTORNORMAL )
	, speedRight( MOTORNORMAL )
{
}

roombaProgram_Actor::~roombaProgram_Actor( void )
{
}

// {{{RME operation 'drive(int,int)'
void roombaProgram_Actor::drive( int left, int right )
{
	// {{{USR
	clsDriveCommand dr(left,right);

	Roomba.drive(dr).send();
	// }}}USR
}
// }}}RME

// {{{RME operation 'stop()'
void roombaProgram_Actor::stop( void )
{
	// {{{USR
	clsDriveCommand dr;
	dr.left = 0;
	dr.right = 0;

	Roomba.drive(dr).send();
	// }}}USR
}
// }}}RME

// {{{RME operation 'calculateTimeToRotateAngle(int,int,int)'
int roombaProgram_Actor::calculateTimeToRotateAngle( int leftSpeed, int rightSpeed, int angleToRotate )
{
	// {{{USR
	double dDistance = leftSpeed - rightSpeed;
	//Calculate the angle at which the roomba is turning. angleAdj.
	//We know that the difference between the wheels will give us a
	//Triangle with equivalent legs
	//When we aply some magic formulas to that(see below)
	//We get the angle the roomba has rotated
	double d = dDistance / 2;
	//double f = (d / 225);
	double f = (d / 258);
	double sinCalc = asin(f);
	double angleAdj = ((sinCalc / M_PI) * 180);
	angleAdj = (angleAdj * 2);

	//AngleAdj now contains the value this thing will turn in 1 second.
	angleAdj = angleAdj;
	//cout << "AA = " << angleAdj;
	//And now in 1 ms
	return abs((int)((angleToRotate / angleAdj) * 1000));
	// }}}USR
}
// }}}RME

// {{{RME operation 'setMotors(bool,bool,bool)'
void roombaProgram_Actor::setMotors( bool mainBrush, bool sideBrush, bool vacuum )
{
	// {{{USR
	clsRoomba::clsMotors m;
	m.mainBrush = mainBrush;
	m.sideBrush = sideBrush;
	m.vacuum = vacuum;

	Roomba.setMotors(m).send();

	// }}}USR
}
// }}}RME

int roombaProgram_Actor::_followInV( RTBindingEnd & rtg_end, int rtg_portId, int rtg_repIndex )
{
	switch( rtg_portId )
	{
	case 0:
		// Roomba
		if( rtg_repIndex < 1 )
		{
			rtg_end.port = &Roomba;
			rtg_end.index = rtg_repIndex;
			return 1;
		}
		break;
	default:
		break;
	}
	return RTActor::_followInV( rtg_end, rtg_portId, rtg_repIndex );
}

// {{{RME enter ':TOP:roombaStart'
INLINE_METHODS void roombaProgram_Actor::enter3_roombaStart( void )
{
	// {{{USR
	this->drive(speedLeft, speedRight);
	this->setMotors(true,true,true);
	// }}}USR
}
// }}}RME

void roombaProgram_Actor::enterStateV( void )
{
	switch( getCurrentState() )
	{
	case 3:
		enter3_roombaStart();
		break;
	case 4:
		enter4_bumperTriggered();
		break;
	default:
		RTActor::enterStateV();
		break;
	}
}

// {{{RME enter ':TOP:bumperTriggered'
INLINE_METHODS void roombaProgram_Actor::enter4_bumperTriggered( void )
{
	// {{{USR
	//Check sensors:
	if(bumpersTriggered.left && bumpersTriggered.right){
	    //Head on collision! rotate 90 degrees and try again!
	    this->drive(MOTORNORMAL*-1, MOTORNORMAL);

	    int theTime = calculateTimeToRotateAngle(MOTORNORMAL*-1, MOTORNORMAL, 30);
	    cout << "The Time = " << theTime << endl;
	    timer.informIn(theTime/10);
	}else if(bumpersTriggered.left){
	    this->drive(MOTORNORMAL, MOTORNORMAL*-1);
	    int theTime = calculateTimeToRotateAngle(MOTORNORMAL, MOTORNORMAL*-1, 180);
	    cout << "The Time = " << theTime << endl;
	    timer.informIn(theTime/10);
	}else if(bumpersTriggered.right){
	    this->drive(MOTORNORMAL*-1, MOTORNORMAL);
	    int theTime = calculateTimeToRotateAngle(MOTORNORMAL*-1, MOTORNORMAL, -10);
	    cout << "The Time = " << theTime << endl;
	    timer.informIn(theTime/10);
	}

	bumpersTriggered.left = false;
	bumpersTriggered.right = false;
	// }}}USR
}
// }}}RME

// {{{RME transition ':TOP:roombaWaitForStart:J51AB5A2600DB:Start'
INLINE_METHODS void roombaProgram_Actor::transition1_Start( const int * rtdata, programProtocol::Base * rtport )
{
	// {{{USR
	this->batteryLevel = *rtdata;

	// }}}USR
}
// }}}RME

// {{{RME transition ':TOP:checkBatteryLevel:batteryTooLow'
INLINE_METHODS void roombaProgram_Actor::transition2_batteryTooLow( const int * rtdata, programProtocol::Base * rtport )
{
	// {{{USR
	Roomba.playSong(0).send();
	Roomba.stopProgram(0).send(); //RC 0 = Low Battery
	// }}}USR
}
// }}}RME

// {{{RME transition ':TOP:checkBatteryLevel:batteryFull'
INLINE_METHODS void roombaProgram_Actor::transition3_batteryFull( const int * rtdata, programProtocol::Base * rtport )
{
	// {{{USR
	cout << "Program starting!" << endl;
	Roomba.playSong(1).send();

	logEntry l("Program started");
	Roomba.log(l).send();
	// }}}USR
}
// }}}RME

// {{{RME transition ':TOP:roombaStart:J51AB5CF303CA:bumper'
INLINE_METHODS void roombaProgram_Actor::transition4_bumper( const clsRoomba::clsBumpersAndCliff * rtdata, programProtocol::Base * rtport )
{
	// {{{USR
	this->bumpersTriggered = *rtdata;
	this->stop();
	this->setMotors(true, false, true);
	//Drive backwards for just a bit please
	this->drive(MOTORNORMAL*-1,MOTORNORMAL*-1);
	Sleep(650);
	// }}}USR
}
// }}}RME

// {{{RME transition ':TOP:bumperTriggered:J51ADAD540256:StopHammerTime'
INLINE_METHODS void roombaProgram_Actor::transition6_StopHammerTime( const void * rtdata, programProtocol::Base * rtport )
{
	// {{{USR
	Roomba.stopProgram(2).send();
	// }}}USR
}
// }}}RME

// {{{RME transition ':TOP:roombaStart:J51ADAD78038C:Stop'
INLINE_METHODS void roombaProgram_Actor::transition7_Stop( const void * rtdata, programProtocol::Base * rtport )
{
	// {{{USR
	Roomba.stopProgram(2).send();
	// }}}USR
}
// }}}RME

// {{{RME transition ':TOP:bumperTriggered:J51ADB8DA02CF:pijltje'
INLINE_METHODS void roombaProgram_Actor::transition8_pijltje( const void * rtdata, Timing::Base * rtport )
{
	// {{{USR
	this->stop();
	speedLeft = MOTORNORMAL;
	speedRight = MOTORNORMAL;
	// }}}USR
}
// }}}RME

// {{{RME transition ':TOP:CheckWhereWeAre:J51B5A22101B3:t1'
INLINE_METHODS void roombaProgram_Actor::transition10_t1( const int * rtdata, programProtocol::Base * rtport )
{
	// {{{USR
	//if we are charging, please drive backwards for a short period and then rotate 180
	//THEN we start the program:
	int whereAreWe = *rtdata;
	//std::cout << "PRM: WAW: " << whereAreWe << endl;
	if(whereAreWe > 0 && whereAreWe != 4){
	    //We are charging
	    drive(MOTORNORMAL*-1, MOTORNORMAL*-1);
	    Sleep(1000);
	    this->drive(MOTORNORMAL*-1, MOTORNORMAL);
	    int theTime = calculateTimeToRotateAngle(MOTORNORMAL*-1, MOTORNORMAL, 180);
	    Sleep(theTime);
	}
	// }}}USR
}
// }}}RME

// {{{RME transition ':TOP:roombaStart:J51B5A7140151:overCurrent'
INLINE_METHODS void roombaProgram_Actor::transition11_overCurrent( const void * rtdata, programProtocol::Base * rtport )
{
	// {{{USR
	speedRight = MOTORFASTER;
	// }}}USR
}
// }}}RME

INLINE_CHAINS void roombaProgram_Actor::chain5_Initial( void )
{
	// transition ':TOP:Initial:Initial'
	rtgChainBegin( 1, "Initial" );
	rtgTransitionBegin();
	rtgTransitionEnd();
	enterState( 2 );
}

INLINE_CHAINS void roombaProgram_Actor::chain1_Start( void )
{
	// transition ':TOP:roombaWaitForStart:J51AB5A2600DB:Start'
	rtgChainBegin( 2, "Start" );
	exitState( rtg_parent_state );
	rtgTransitionBegin();
	transition1_Start( (const int *)msg->data, (programProtocol::Base *)msg->sap() );
	rtgTransitionEnd();
	if( choicePoint1_checkBatteryLevel( (const int *)msg->data, (programProtocol::Base *)msg->sap() ) )
		chain3_batteryFull();
	else
		chain2_batteryTooLow();
}

// {{{RME choicePoint ':TOP:checkBatteryLevel'
INLINE_METHODS int roombaProgram_Actor::choicePoint1_checkBatteryLevel( const int * rtdata, programProtocol::Base * rtport )
{
	// {{{USR
	if(this->batteryLevel <= MINBATTERY){
	    return false;
	}else{
	    return true;
	}
	// }}}USR
}
// }}}RME

INLINE_CHAINS void roombaProgram_Actor::chain3_batteryFull( void )
{
	// transition ':TOP:checkBatteryLevel:batteryFull'
	rtgChainBegin( 6, "batteryFull" );
	rtgTransitionBegin();
	transition3_batteryFull( (const int *)msg->data, (programProtocol::Base *)msg->sap() );
	rtgTransitionEnd();
	enterState( 5 );
}

INLINE_CHAINS void roombaProgram_Actor::chain2_batteryTooLow( void )
{
	// transition ':TOP:checkBatteryLevel:batteryTooLow'
	rtgChainBegin( 6, "batteryTooLow" );
	rtgTransitionBegin();
	transition2_batteryTooLow( (const int *)msg->data, (programProtocol::Base *)msg->sap() );
	rtgTransitionEnd();
	enterState( 2 );
}

INLINE_CHAINS void roombaProgram_Actor::chain4_bumper( void )
{
	// transition ':TOP:roombaStart:J51AB5CF303CA:bumper'
	rtgChainBegin( 3, "bumper" );
	exitState( rtg_parent_state );
	rtgTransitionBegin();
	transition4_bumper( (const clsRoomba::clsBumpersAndCliff *)msg->data, (programProtocol::Base *)msg->sap() );
	rtgTransitionEnd();
	enterState( 4 );
}

INLINE_CHAINS void roombaProgram_Actor::chain7_Stop( void )
{
	// transition ':TOP:roombaStart:J51ADAD78038C:Stop'
	rtgChainBegin( 3, "Stop" );
	exitState( rtg_parent_state );
	rtgTransitionBegin();
	transition7_Stop( msg->data, (programProtocol::Base *)msg->sap() );
	rtgTransitionEnd();
	enterState( 2 );
}

INLINE_CHAINS void roombaProgram_Actor::chain11_overCurrent( void )
{
	// transition ':TOP:roombaStart:J51B5A7140151:overCurrent'
	rtgChainBegin( 3, "overCurrent" );
	exitState( rtg_parent_state );
	rtgTransitionBegin();
	transition11_overCurrent( msg->data, (programProtocol::Base *)msg->sap() );
	rtgTransitionEnd();
	enterState( 3 );
}

INLINE_CHAINS void roombaProgram_Actor::chain9_t1( void )
{
	// transition ':TOP:bumperTriggered:J51ADCE6F0025:t1'
	rtgChainBegin( 4, "t1" );
	exitState( rtg_parent_state );
	rtgTransitionBegin();
	rtgTransitionEnd();
	enterState( 4 );
}

INLINE_CHAINS void roombaProgram_Actor::chain6_StopHammerTime( void )
{
	// transition ':TOP:bumperTriggered:J51ADAD540256:StopHammerTime'
	rtgChainBegin( 4, "StopHammerTime" );
	exitState( rtg_parent_state );
	rtgTransitionBegin();
	transition6_StopHammerTime( msg->data, (programProtocol::Base *)msg->sap() );
	rtgTransitionEnd();
	enterState( 2 );
}

INLINE_CHAINS void roombaProgram_Actor::chain8_pijltje( void )
{
	// transition ':TOP:bumperTriggered:J51ADB8DA02CF:pijltje'
	rtgChainBegin( 4, "pijltje" );
	exitState( rtg_parent_state );
	rtgTransitionBegin();
	transition8_pijltje( msg->data, (Timing::Base *)msg->sap() );
	rtgTransitionEnd();
	enterState( 3 );
}

INLINE_CHAINS void roombaProgram_Actor::chain10_t1( void )
{
	// transition ':TOP:CheckWhereWeAre:J51B5A22101B3:t1'
	rtgChainBegin( 5, "t1" );
	exitState( rtg_parent_state );
	rtgTransitionBegin();
	transition10_t1( (const int *)msg->data, (programProtocol::Base *)msg->sap() );
	rtgTransitionEnd();
	enterState( 3 );
}

void roombaProgram_Actor::rtsBehavior( int signalIndex, int portIndex )
{
	for( int stateIndex = getCurrentState(); ; stateIndex = rtg_parent_state[ stateIndex - 1 ] )
		switch( stateIndex )
		{
		case 1:
			// {{{RME state ':TOP'
			switch( portIndex )
			{
			case 0:
				switch( signalIndex )
				{
				case 1:
					chain5_Initial();
					return;
				default:
					break;
				}
				break;
			default:
				break;
			}
			unexpectedMessage();
			return;
			// }}}RME
		case 2:
			// {{{RME state ':TOP:roombaWaitForStart'
			switch( portIndex )
			{
			case 0:
				switch( signalIndex )
				{
				case 1:
					return;
				default:
					break;
				}
				break;
			case 1:
				// {{{RME port 'Roomba'
				switch( signalIndex )
				{
				case programProtocol::Base::rti_start:
					chain1_Start();
					return;
				default:
					break;
				}
				break;
				// }}}RME
			default:
				break;
			}
			break;
			// }}}RME
		case 3:
			// {{{RME state ':TOP:roombaStart'
			switch( portIndex )
			{
			case 0:
				switch( signalIndex )
				{
				case 1:
					return;
				default:
					break;
				}
				break;
			case 1:
				// {{{RME port 'Roomba'
				switch( signalIndex )
				{
				case programProtocol::Base::rti_bumpersTriggered:
					chain4_bumper();
					return;
				case programProtocol::Base::rti_stop:
					chain7_Stop();
					return;
				case programProtocol::Base::rti_sideBrushOverCurrent:
					chain11_overCurrent();
					return;
				default:
					break;
				}
				break;
				// }}}RME
			default:
				break;
			}
			break;
			// }}}RME
		case 4:
			// {{{RME state ':TOP:bumperTriggered'
			switch( portIndex )
			{
			case 0:
				switch( signalIndex )
				{
				case 1:
					return;
				default:
					break;
				}
				break;
			case 1:
				// {{{RME port 'Roomba'
				switch( signalIndex )
				{
				case programProtocol::Base::rti_bumpersTriggered:
					chain9_t1();
					return;
				case programProtocol::Base::rti_stop:
					chain6_StopHammerTime();
					return;
				default:
					break;
				}
				break;
				// }}}RME
			case 2:
				// {{{RME port 'timer'
				switch( signalIndex )
				{
				case Timing::Base::rti_timeout:
					chain8_pijltje();
					return;
				default:
					break;
				}
				break;
				// }}}RME
			default:
				break;
			}
			break;
			// }}}RME
		case 5:
			// {{{RME state ':TOP:CheckWhereWeAre'
			switch( portIndex )
			{
			case 0:
				switch( signalIndex )
				{
				case 1:
					return;
				default:
					break;
				}
				break;
			case 1:
				// {{{RME port 'Roomba'
				switch( signalIndex )
				{
				case programProtocol::Base::rti_isCharging:
					chain10_t1();
					return;
				default:
					break;
				}
				break;
				// }}}RME
			default:
				break;
			}
			break;
			// }}}RME
		default:
			unexpectedState();
			return;
		}
}

const RTActor_class * roombaProgram_Actor::getActorData( void ) const
{
	return &roombaProgram_Actor::rtg_class;
}

const RTActor_class roombaProgram_Actor::rtg_class =
{
	(const RTActor_class *)0
  , rtg_state_names
  , 5
  , roombaProgram_Actor::rtg_parent_state
  , &roombaProgram
  , 0
  , (const RTComponentDescriptor *)0
  , 2
  , roombaProgram_Actor::rtg_ports
  , 0
  , (const RTLocalBindingDescriptor *)0
  , 6
  , roombaProgram_Actor::rtg_roombaProgram_fields
};

const RTStateId roombaProgram_Actor::rtg_parent_state[] =
{
	0
  , 1
  , 1
  , 1
  , 1
};

const RTPortDescriptor roombaProgram_Actor::rtg_ports[] =
{
	{
		"Roomba"
	  , (const char *)0
	  , &programProtocol::Base::rt_class
	  , RTOffsetOf( roombaProgram_Actor, roombaProgram_Actor::Roomba )
	  , 1 // cardinality
	  , 1
	  , RTPortDescriptor::KindWired + RTPortDescriptor::NotificationDisabled + RTPortDescriptor::RegisterNotPermitted + RTPortDescriptor::VisibilityPublic
	}
  , {
		"timer"
	  , (const char *)0
	  , &Timing::Base::rt_class
	  , RTOffsetOf( roombaProgram_Actor, roombaProgram_Actor::timer )
	  , 1 // cardinality
	  , 2
	  , RTPortDescriptor::KindSpecial + RTPortDescriptor::NotificationDisabled + RTPortDescriptor::RegisterNotPermitted + RTPortDescriptor::VisibilityProtected
	}
};

const RTFieldDescriptor roombaProgram_Actor::rtg_roombaProgram_fields[] =
{
	// {{{RME classAttribute 'batteryLevel'
	{
		"batteryLevel"
	  , RTOffsetOf( roombaProgram_Actor, batteryLevel )
		// {{{RME tool 'OT::CppTargetRTS' property 'TypeDescriptor'
	  , &RTType_int
		// }}}RME
		// {{{RME tool 'OT::CppTargetRTS' property 'GenerateTypeModifier'
	  , (const RTTypeModifier *)0
		// }}}RME
	}
	// }}}RME
	// {{{RME classAttribute 'bumpersTriggered'
  , {
		"bumpersTriggered"
	  , RTOffsetOf( roombaProgram_Actor, bumpersTriggered )
		// {{{RME tool 'OT::CppTargetRTS' property 'TypeDescriptor'
	  , (const RTObject_class *)0
		// }}}RME
		// {{{RME tool 'OT::CppTargetRTS' property 'GenerateTypeModifier'
	  , (const RTTypeModifier *)0
		// }}}RME
	}
	// }}}RME
	// {{{RME classAttribute 'angleToRotate'
  , {
		"angleToRotate"
	  , RTOffsetOf( roombaProgram_Actor, angleToRotate )
		// {{{RME tool 'OT::CppTargetRTS' property 'TypeDescriptor'
	  , &RTType_int
		// }}}RME
		// {{{RME tool 'OT::CppTargetRTS' property 'GenerateTypeModifier'
	  , (const RTTypeModifier *)0
		// }}}RME
	}
	// }}}RME
	// {{{RME classAttribute 'angleRotated'
  , {
		"angleRotated"
	  , RTOffsetOf( roombaProgram_Actor, angleRotated )
		// {{{RME tool 'OT::CppTargetRTS' property 'TypeDescriptor'
	  , &RTType_int
		// }}}RME
		// {{{RME tool 'OT::CppTargetRTS' property 'GenerateTypeModifier'
	  , (const RTTypeModifier *)0
		// }}}RME
	}
	// }}}RME
	// {{{RME classAttribute 'speedLeft'
  , {
		"speedLeft"
	  , RTOffsetOf( roombaProgram_Actor, speedLeft )
		// {{{RME tool 'OT::CppTargetRTS' property 'TypeDescriptor'
	  , &RTType_int
		// }}}RME
		// {{{RME tool 'OT::CppTargetRTS' property 'GenerateTypeModifier'
	  , (const RTTypeModifier *)0
		// }}}RME
	}
	// }}}RME
	// {{{RME classAttribute 'speedRight'
  , {
		"speedRight"
	  , RTOffsetOf( roombaProgram_Actor, speedRight )
		// {{{RME tool 'OT::CppTargetRTS' property 'TypeDescriptor'
	  , &RTType_int
		// }}}RME
		// {{{RME tool 'OT::CppTargetRTS' property 'GenerateTypeModifier'
	  , (const RTTypeModifier *)0
		// }}}RME
	}
	// }}}RME
};
#undef SUPER

// {{{RME tool 'OT::Cpp' property 'ImplementationEnding'
// {{{USR

// }}}USR
// }}}RME

// }}}RME
