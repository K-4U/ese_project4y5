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
  , "checkBatteryLevel"
  , "checkRotatedAngle"
};

#define SUPER RTActor

roombaProgram_Actor::roombaProgram_Actor( RTController * rtg_rts, RTActorRef * rtg_ref )
	: RTActor( rtg_rts, rtg_ref )
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
	this->drive(100,100);
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
	//Keep asking for sensor data!
	Roomba.getTotalAngle(false).send();
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

	// }}}USR
}
// }}}RME

// {{{RME transition ':TOP:roombaStart:J51AB5CF303CA:bumper'
INLINE_METHODS void roombaProgram_Actor::transition4_bumper( const clsRoomba::clsBumpersAndCliff * rtdata, programProtocol::Base * rtport )
{
	// {{{USR
	clsRoomba::clsBumpersAndCliff bumpersTriggered = *rtdata;
	this->stop();
	//Drive backwards for just a bit please
	this->drive(-100,-100);
	Sleep(500);
	this->stop();

	//Check sensors:
	if(bumpersTriggered.left && bumpersTriggered.right){
	    //Head on collision! rotate 90 degrees and try again!
	    this->angleToRotate = 90;
	    this->drive(100, -100);
	    //Reset total angle
	    Roomba.getTotalAngle(true).send();
	}else if(bumpersTriggered.left){
	    this->angleToRotate = 45;
	    this->drive(100, -100);
	    //Reset total angle
	    Roomba.getTotalAngle(true).send();
	}
	// }}}USR
}
// }}}RME

// {{{RME transition ':TOP:bumperTriggered:J51AB626A0363:getTotalAngle'
INLINE_METHODS void roombaProgram_Actor::transition5_getTotalAngle( const int * rtdata, programProtocol::Base * rtport )
{
	// {{{USR
	this->angleRotated = *rtdata;

	// }}}USR
}
// }}}RME

INLINE_CHAINS void roombaProgram_Actor::chain8_Initial( void )
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
	if(this->batteryLevel < 80){
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
	rtgChainBegin( 5, "batteryFull" );
	rtgTransitionBegin();
	transition3_batteryFull( (const int *)msg->data, (programProtocol::Base *)msg->sap() );
	rtgTransitionEnd();
	enterState( 3 );
}

INLINE_CHAINS void roombaProgram_Actor::chain2_batteryTooLow( void )
{
	// transition ':TOP:checkBatteryLevel:batteryTooLow'
	rtgChainBegin( 5, "batteryTooLow" );
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

INLINE_CHAINS void roombaProgram_Actor::chain5_getTotalAngle( void )
{
	// transition ':TOP:bumperTriggered:J51AB626A0363:getTotalAngle'
	rtgChainBegin( 4, "getTotalAngle" );
	exitState( rtg_parent_state );
	rtgTransitionBegin();
	transition5_getTotalAngle( (const int *)msg->data, (programProtocol::Base *)msg->sap() );
	rtgTransitionEnd();
	if( choicePoint2_checkRotatedAngle( (const int *)msg->data, (programProtocol::Base *)msg->sap() ) )
		chain6_straightOn();
	else
		chain7_False();
}

// {{{RME choicePoint ':TOP:checkRotatedAngle'
INLINE_METHODS int roombaProgram_Actor::choicePoint2_checkRotatedAngle( const int * rtdata, programProtocol::Base * rtport )
{
	// {{{USR
	if(this->angleToRotate <= *rtdata){
	    return true;
	}else{
	    return false;
	}
	// }}}USR
}
// }}}RME

INLINE_CHAINS void roombaProgram_Actor::chain6_straightOn( void )
{
	// transition ':TOP:checkRotatedAngle:straightOn'
	rtgChainBegin( 6, "straightOn" );
	rtgTransitionBegin();
	rtgTransitionEnd();
	enterState( 3 );
}

INLINE_CHAINS void roombaProgram_Actor::chain7_False( void )
{
	// transition ':TOP:checkRotatedAngle:False'
	rtgChainBegin( 6, "False" );
	rtgTransitionBegin();
	rtgTransitionEnd();
	enterState( 4 );
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
					chain8_Initial();
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
				case programProtocol::Base::rti_totalAngle:
					chain5_getTotalAngle();
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
  , 4
  , roombaProgram_Actor::rtg_parent_state
  , &roombaProgram
  , 0
  , (const RTComponentDescriptor *)0
  , 1
  , roombaProgram_Actor::rtg_ports
  , 0
  , (const RTLocalBindingDescriptor *)0
  , 4
  , roombaProgram_Actor::rtg_roombaProgram_fields
};

const RTStateId roombaProgram_Actor::rtg_parent_state[] =
{
	0
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
};
#undef SUPER

// {{{RME tool 'OT::Cpp' property 'ImplementationEnding'
// {{{USR

// }}}USR
// }}}RME

// }}}RME
