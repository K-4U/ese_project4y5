// {{{RME classifier 'Logical View::Roomba::roombaTopCapsule'

#if defined( PRAGMA ) && ! defined( PRAGMA_IMPLEMENTED )
#pragma implementation "roombaTopCapsule.h"
#endif

#include <RTSystem/roombaController.h>
#include <roombaTopCapsule.h>
#include <clsRoomba.h>
extern const RTActorClass roombaProgram;

// {{{RME tool 'OT::Cpp' property 'ImplementationPreface'
// {{{USR

// }}}USR
// }}}RME

static const RTRelayDescriptor rtg_relays[] =
{
	{
		"toMain"
	  , &roombaProtocol::Base::rt_class
	  , 1 // cardinality
	}
};

static RTActor * new_roombaTopCapsule_Actor( RTController * _rts, RTActorRef * _ref )
{
	return new roombaTopCapsule_Actor( _rts, _ref );
}

const RTActorClass roombaTopCapsule =
{
	(const RTActorClass *)0
  , "roombaTopCapsule"
  , (RTVersionId)0
  , 1
  , rtg_relays
  , new_roombaTopCapsule_Actor
};

static const char * const rtg_state_names[] =
{
	"TOP"
  , "Ready"
  , "waitForCom"
};

static const RTInterfaceDescriptor rtg_interfaces_roombaProgramInstance[] =
{
	{
		"Roomba"
	  , 1
	}
};

static const RTBindingDescriptor rtg_bindings_roombaProgramInstance[] =
{
	{
		0
	  , &programProtocol::Conjugate::rt_class
	}
};

#define SUPER RTActor

roombaTopCapsule_Actor::roombaTopCapsule_Actor( RTController * rtg_rts, RTActorRef * rtg_ref )
	: RTActor( rtg_rts, rtg_ref )
	, isOperating( false )
{
}

roombaTopCapsule_Actor::~roombaTopCapsule_Actor( void )
{
}

// {{{RME operation 'sendRoombaCommandSetMotors()'
void roombaTopCapsule_Actor::sendRoombaCommandSetMotors( void )
{
	// {{{USR
	bool mainBrush = false;
	bool sideBrush = false;
	bool vacuum = false;

	this->roomba.getMotors(&mainBrush, &sideBrush, &vacuum);

	std::cout << "RMB: MainBrush: " << mainBrush << endl;

	byteArray b;
	std::cout << "Starting full mode" << endl;
	b.append(130);
	toMain.sendData(b).send();
	b.clear();


	b.append(138);
	b.append((mainBrush << 2) | (sideBrush << 0) | (vacuum << 1));

	std::cout << "RMB: Sending";
	b.print();
	toMain.sendData(b).send();
	// }}}USR
}
// }}}RME

int roombaTopCapsule_Actor::_followInV( RTBindingEnd & rtg_end, int rtg_portId, int rtg_repIndex )
{
	switch( rtg_portId )
	{
	case 0:
		// toMain
		if( rtg_repIndex < 1 )
		{
			rtg_end.port = &toMain;
			rtg_end.index = rtg_repIndex;
			return 1;
		}
		break;
	default:
		break;
	}
	return RTActor::_followInV( rtg_end, rtg_portId, rtg_repIndex );
}

int roombaTopCapsule_Actor::_followOutV( RTBindingEnd & rtg_end, int rtg_compId, int rtg_portId, int rtg_repIndex )
{
	switch( rtg_compId )
	{
	case 1:
		// roombaProgramInstance
		switch( rtg_portId )
		{
		case 0:
			// Roomba
			if( rtg_repIndex < 1 )
			{
				// program
				rtg_end.port = &program;
				rtg_end.index = rtg_repIndex;
				return 1;
			}
			break;
		default:
			break;
		}
	default:
		break;
	}
	return RTActor::_followOutV( rtg_end, rtg_compId, rtg_portId, rtg_repIndex );
}

// {{{RME transition ':TOP:waitForCom:J519B68FC0073:comReady'
INLINE_METHODS void roombaTopCapsule_Actor::transition1_comReady( const void * rtdata, roombaProtocol::Base * rtport )
{
	// {{{USR
	cout << "RMB: Ready received!" << endl;
	//Start query
	byteArray b;
	//Safe mode
	b.append(128);
	toMain.sendData(b).send();
	b.clear();

	//Send in our music.
	//Battery failure:
	// 45 44 43 42
	/*
	b.append(140);
	b.append(0); //Store in 0
	b.append(4);
	b.append(45);
	b.append(16);
	b.append(44);
	b.append(16);
	b.append(43);
	b.append(16);
	b.append(42);
	b.append(16);
	toMain.sendData(b).send();
	*/

	//Start timer for polling:
	timer.informIn(30);

	/*
	//Full mode
	b.append(130);
	Serial.sendCommand(b).send();
	b.clear();

	//And driving!
	b.append(145);
	b.append(3);
	b.append(232);

	b.append(4);
	b.append(26);
	Serial.sendCommand(b).send();
	b.clear();
	*/

	cout << "RMB: Initialized" << endl;

	// }}}USR
}
// }}}RME

// {{{RME transition ':TOP:Ready:J51AB647002D6:dataReceived'
INLINE_METHODS void roombaTopCapsule_Actor::transition2_dataReceived( const byteArray * rtdata, roombaProtocol::Base * rtport )
{
	// {{{USR
	//It probably is a sensor list
	//Translate everything to a variable.

	byteArray b = *rtdata;
	int s = b.size();
	int i = 0;

	bool inSensorList;
	while(i < s){
	    if(!inSensorList){
	        if(b.get(i) == 149){
	            inSensorList = true;
	            i++; //skip number of packets.
	        }
	    }else{
	        if(this->isOperating){
	            int x = 0;
	            int sizeOfArray = (sizeof(sensorsToQuery) / sizeof(int)) / 2;
	            for(x=0;x< sizeOfArray; x++){
	                if(sensorsToQuery[x][0] == b.get(i)){
	                    int value = 0;
	                    i++;
	                    if(sensorsToQuery[x][1] == 2){
	                        value = b.get(i) << 8;
	                        i++;
	                    }
	                    value += b.get(i);
	                    this->roomba.setSensor(sensorsToQuery[x][0], value);
	                }
	            }
	        }else{
	            //Only three sensors;
	            int sId = b.get(i);
	            i++;
	            int v = b.get(i);

	            if(sId != 18){
	                v = (v << 8);
	                i++;
	                v+= b.get(i);
	            }

	            //std::cout << "sId: " << sId << " V: " << v << endl;
	            this->roomba.setSensor(sId, v);
	        }
	    }
	    i++;
	}
	//this->roomba.printSensors();

	// }}}USR
}
// }}}RME

// {{{RME transition ':TOP:Ready:J519B5D200005:commandReceived'
INLINE_METHODS void roombaTopCapsule_Actor::transition3_commandReceived( const jsonCommand * rtdata, roombaProtocol::Base * rtport )
{
	// {{{USR
	//Parse command:
	jsonCommand c = *rtdata;
	if(c.command == "SETMOTORBRUSHVACUUM"){
	    //std::cout << "RMB: Main: " << c.data["MainBrush"].asBool() << endl;
	    this->roomba.setMotors(c.data["MainBrush"].asBool(), 
	            c.data["SideBrush"].asBool(),
	            c.data["Vacuum"].asBool());
	    this->sendRoombaCommandSetMotors();
	}
	// }}}USR
}
// }}}RME

// {{{RME transition ':TOP:Initial:Initial'
INLINE_METHODS void roombaTopCapsule_Actor::transition4_Initial( const void * rtdata, RTProtocol * rtport )
{
	// {{{USR
	frame.incarnate(roombaProgramInstance,roombaProgram,EmptyObject,ThreadProgram);

	// }}}USR
}
// }}}RME

// {{{RME transition ':TOP:Ready:J51AB645400D1:handleSensors'
INLINE_METHODS void roombaTopCapsule_Actor::transition5_handleSensors( const byteArray * rtdata, roombaProtocol::Base * rtport )
{
	// {{{USR
	if(this->isOperating){
	    //Check all sensors:
	    clsRoomba::clsBumpersAndCliff bmprs = this->roomba.getBumpers();
	    //std::cout << "BMPRS: FL " << bmprs.frontLeft << " FR " << bmprs.frontRight;
	    //std::cout << " L " << bmprs.left << " R " << bmprs.right << endl;
	    if((bmprs.frontLeft == true) || 
	       (bmprs.frontRight == true) || 
	       (bmprs.left == true) ||
	       (bmprs.right == true)){
	        program.bumpersTriggered(bmprs).send();
	    }
	}else{
	    //Probably buttons received. Check them plox
	    clsRoomba::clsButtons btns = this->roomba.getButtons();
	    //cout << "Buttons: C: " << btns.clean << " S: " << btns.spot << " D: " << btns.dock << endl;
	    if(btns.clean == true){
	        //Do this!
	        std::cout << "Starting program!" << endl;
	        //int battLevel = (100 * this->roomba.getSensor(25)) / this->roomba.getSensor(26);
	        int battLevel = 90;
	        program.start(battLevel).send();
	        byteArray b;
	        b.append(130);

	        toMain.sendData(b).send();
	        this->isOperating = true;
	    }
	}
	// }}}USR
}
// }}}RME

// {{{RME transition ':TOP:Ready:J51A5CE4A021F:askSensors'
INLINE_METHODS void roombaTopCapsule_Actor::transition6_askSensors( const void * rtdata, Timing::Base * rtport )
{
	// {{{USR
	byteArray b;
	if(this->isOperating){
	    //Then, a stream
	    b.append(149);
	    //First the length:
	    int sizeOfArray = (sizeof(sensorsToQuery) / sizeof(int)) / 2;
	    b.append(sizeOfArray);
	    int i = 0;
	    for(i=0;i < sizeOfArray; i++){
	        b.append(sensorsToQuery[i][0]);
	    }
	}else{
	    //Wait for buttons, battery charge and battery max:
	    b.append(149);
	    b.append(3);
	    b.append(18);
	    b.append(25);
	    b.append(26);
	}
	toMain.sendData(b).send();
	b.clear();

	timer.informIn(100); //Every 100 ms
	// }}}USR
}
// }}}RME

// {{{RME transition ':TOP:Ready:J51AB4F6F0301:playSong'
INLINE_METHODS void roombaTopCapsule_Actor::transition7_playSong( const int * rtdata, programProtocol::Conjugate * rtport )
{
	// {{{USR
	byteArray b;
	b.append(141);
	b.append(*rtdata);

	toMain.sendData(b).send();
	// }}}USR
}
// }}}RME

// {{{RME transition ':TOP:Ready:J51AB52300119:stopProgram'
INLINE_METHODS void roombaTopCapsule_Actor::transition8_stopProgram( const int * rtdata, programProtocol::Conjugate * rtport )
{
	// {{{USR
	this->isOperating = false;

	std::cout << "RMB: Stopped program, RC " << *rtdata << endl;
	// }}}USR
}
// }}}RME

// {{{RME transition ':TOP:Ready:J51AB5BCB00F3:drive'
INLINE_METHODS void roombaTopCapsule_Actor::transition9_drive( const clsDriveCommand * rtdata, programProtocol::Conjugate * rtport )
{
	// {{{USR
	clsDriveCommand dr = *rtdata;
	byteArray b;
	b.append(145);
	b.append(dr.right >> 8);
	b.append(dr.right & 0xFF);
	b.append(dr.left >> 8);
	b.append(dr.left & 0xFF);

	b.print();

	toMain.sendData(b).send();
	// }}}USR
}
// }}}RME

// {{{RME transition ':TOP:Ready:J51AB77110307:getTotalAngle'
INLINE_METHODS void roombaTopCapsule_Actor::transition10_getTotalAngle( const bool * rtdata, programProtocol::Conjugate * rtport )
{
	// {{{USR
	int v = 0;
	if(*rtdata == true){
	    v = this->roomba.getAndResetTotalAngle();
	}else{
	    v = this->roomba.getTotalAngle();
	}

	program.totalAngle(v).send();
	// }}}USR
}
// }}}RME

INLINE_CHAINS void roombaTopCapsule_Actor::chain4_Initial( void )
{
	// transition ':TOP:Initial:Initial'
	rtgChainBegin( 1, "Initial" );
	rtgTransitionBegin();
	transition4_Initial( msg->data, msg->sap() );
	rtgTransitionEnd();
	enterState( 3 );
}

INLINE_CHAINS void roombaTopCapsule_Actor::chain2_dataReceived( void )
{
	// transition ':TOP:Ready:J51AB647002D6:dataReceived'
	rtgChainBegin( 2, "dataReceived" );
	exitState( rtg_parent_state );
	rtgTransitionBegin();
	transition2_dataReceived( (const byteArray *)msg->data, (roombaProtocol::Base *)msg->sap() );
	rtgTransitionEnd();
	enterState( 2 );
	// transition ':TOP:Ready:J51AB647201BD:t1'
	rtgChainBegin( 2, "t1" );
	rtgTransitionBegin();
	rtgTransitionEnd();
	// transition ':TOP:Ready:J51AB645400D1:handleSensors'
	rtgChainBegin( 2, "handleSensors" );
	exitState( rtg_parent_state );
	rtgTransitionBegin();
	transition5_handleSensors( (const byteArray *)msg->data, (roombaProtocol::Base *)msg->sap() );
	rtgTransitionEnd();
	enterState( 2 );
}

INLINE_CHAINS void roombaTopCapsule_Actor::chain3_commandReceived( void )
{
	// transition ':TOP:Ready:J519B5D200005:commandReceived'
	rtgChainBegin( 2, "commandReceived" );
	exitState( rtg_parent_state );
	rtgTransitionBegin();
	transition3_commandReceived( (const jsonCommand *)msg->data, (roombaProtocol::Base *)msg->sap() );
	rtgTransitionEnd();
	enterState( 2 );
}

INLINE_CHAINS void roombaTopCapsule_Actor::chain6_askSensors( void )
{
	// transition ':TOP:Ready:J51A5CE4A021F:askSensors'
	rtgChainBegin( 2, "askSensors" );
	exitState( rtg_parent_state );
	rtgTransitionBegin();
	transition6_askSensors( msg->data, (Timing::Base *)msg->sap() );
	rtgTransitionEnd();
	enterState( 2 );
}

INLINE_CHAINS void roombaTopCapsule_Actor::chain7_playSong( void )
{
	// transition ':TOP:Ready:J51AB4F6F0301:playSong'
	rtgChainBegin( 2, "playSong" );
	exitState( rtg_parent_state );
	rtgTransitionBegin();
	transition7_playSong( (const int *)msg->data, (programProtocol::Conjugate *)msg->sap() );
	rtgTransitionEnd();
	enterState( 2 );
}

INLINE_CHAINS void roombaTopCapsule_Actor::chain8_stopProgram( void )
{
	// transition ':TOP:Ready:J51AB52300119:stopProgram'
	rtgChainBegin( 2, "stopProgram" );
	exitState( rtg_parent_state );
	rtgTransitionBegin();
	transition8_stopProgram( (const int *)msg->data, (programProtocol::Conjugate *)msg->sap() );
	rtgTransitionEnd();
	enterState( 2 );
}

INLINE_CHAINS void roombaTopCapsule_Actor::chain9_drive( void )
{
	// transition ':TOP:Ready:J51AB5BCB00F3:drive'
	rtgChainBegin( 2, "drive" );
	exitState( rtg_parent_state );
	rtgTransitionBegin();
	transition9_drive( (const clsDriveCommand *)msg->data, (programProtocol::Conjugate *)msg->sap() );
	rtgTransitionEnd();
	enterState( 2 );
}

INLINE_CHAINS void roombaTopCapsule_Actor::chain10_getTotalAngle( void )
{
	// transition ':TOP:Ready:J51AB77110307:getTotalAngle'
	rtgChainBegin( 2, "getTotalAngle" );
	exitState( rtg_parent_state );
	rtgTransitionBegin();
	transition10_getTotalAngle( (const bool *)msg->data, (programProtocol::Conjugate *)msg->sap() );
	rtgTransitionEnd();
	enterState( 2 );
}

INLINE_CHAINS void roombaTopCapsule_Actor::chain1_comReady( void )
{
	// transition ':TOP:waitForCom:J519B68FC0073:comReady'
	rtgChainBegin( 3, "comReady" );
	exitState( rtg_parent_state );
	rtgTransitionBegin();
	transition1_comReady( msg->data, (roombaProtocol::Base *)msg->sap() );
	rtgTransitionEnd();
	enterState( 2 );
}

void roombaTopCapsule_Actor::rtsBehavior( int signalIndex, int portIndex )
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
					chain4_Initial();
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
			// {{{RME state ':TOP:Ready'
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
				// {{{RME port 'toMain'
				switch( signalIndex )
				{
				case roombaProtocol::Base::rti_dataReceived:
					chain2_dataReceived();
					return;
				case roombaProtocol::Base::rti_commandReceived:
					chain3_commandReceived();
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
					chain6_askSensors();
					return;
				default:
					break;
				}
				break;
				// }}}RME
			case 3:
				// {{{RME port 'program'
				switch( signalIndex )
				{
				case programProtocol::Conjugate::rti_playSong:
					chain7_playSong();
					return;
				case programProtocol::Conjugate::rti_stopProgram:
					chain8_stopProgram();
					return;
				case programProtocol::Conjugate::rti_drive:
					chain9_drive();
					return;
				case programProtocol::Conjugate::rti_getTotalAngle:
					chain10_getTotalAngle();
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
			// {{{RME state ':TOP:waitForCom'
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
				// {{{RME port 'toMain'
				switch( signalIndex )
				{
				case roombaProtocol::Base::rti_ready:
					chain1_comReady();
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

const RTActor_class * roombaTopCapsule_Actor::getActorData( void ) const
{
	return &roombaTopCapsule_Actor::rtg_class;
}

const RTActor_class roombaTopCapsule_Actor::rtg_class =
{
	(const RTActor_class *)0
  , rtg_state_names
  , 3
  , roombaTopCapsule_Actor::rtg_parent_state
  , &roombaTopCapsule
  , 1
  , roombaTopCapsule_Actor::rtg_capsule_roles
  , 4
  , roombaTopCapsule_Actor::rtg_ports
  , 0
  , (const RTLocalBindingDescriptor *)0
  , 2
  , roombaTopCapsule_Actor::rtg_roombaTopCapsule_fields
};

const RTStateId roombaTopCapsule_Actor::rtg_parent_state[] =
{
	0
  , 1
  , 1
};

const RTComponentDescriptor roombaTopCapsule_Actor::rtg_capsule_roles[] =
{
	{
		"roombaProgramInstance"
	  , &roombaProgram
	  , RTOffsetOf( roombaTopCapsule_Actor, roombaProgramInstance )
	  , 1
	  , RTComponentDescriptor::Optional
	  , 1
	  , 1 // cardinality
	  , 1
	  , rtg_interfaces_roombaProgramInstance
	  , 1
	  , rtg_bindings_roombaProgramInstance
	}
};

const RTPortDescriptor roombaTopCapsule_Actor::rtg_ports[] =
{
	{
		"toMain"
	  , (const char *)0
	  , &roombaProtocol::Base::rt_class
	  , RTOffsetOf( roombaTopCapsule_Actor, roombaTopCapsule_Actor::toMain )
	  , 1 // cardinality
	  , 1
	  , RTPortDescriptor::KindWired + RTPortDescriptor::NotificationDisabled + RTPortDescriptor::RegisterNotPermitted + RTPortDescriptor::VisibilityPublic
	}
  , {
		"timer"
	  , (const char *)0
	  , &Timing::Base::rt_class
	  , RTOffsetOf( roombaTopCapsule_Actor, roombaTopCapsule_Actor::timer )
	  , 1 // cardinality
	  , 2
	  , RTPortDescriptor::KindSpecial + RTPortDescriptor::NotificationDisabled + RTPortDescriptor::RegisterNotPermitted + RTPortDescriptor::VisibilityProtected
	}
  , {
		"program"
	  , (const char *)0
	  , &programProtocol::Conjugate::rt_class
	  , RTOffsetOf( roombaTopCapsule_Actor, roombaTopCapsule_Actor::program )
	  , 1 // cardinality
	  , 3
	  , RTPortDescriptor::KindWired + RTPortDescriptor::NotificationDisabled + RTPortDescriptor::RegisterNotPermitted + RTPortDescriptor::VisibilityProtected
	}
  , {
		"frame"
	  , (const char *)0
	  , &Frame::Base::rt_class
	  , RTOffsetOf( roombaTopCapsule_Actor, roombaTopCapsule_Actor::frame )
	  , 1 // cardinality
	  , 4
	  , RTPortDescriptor::KindSpecial + RTPortDescriptor::NotificationDisabled + RTPortDescriptor::RegisterNotPermitted + RTPortDescriptor::VisibilityProtected
	}
};

const RTFieldDescriptor roombaTopCapsule_Actor::rtg_roombaTopCapsule_fields[] =
{
	// {{{RME classAttribute 'roomba'
	{
		"roomba"
	  , RTOffsetOf( roombaTopCapsule_Actor, roomba )
		// {{{RME tool 'OT::CppTargetRTS' property 'TypeDescriptor'
	  , &RTType_clsRoomba
		// }}}RME
		// {{{RME tool 'OT::CppTargetRTS' property 'GenerateTypeModifier'
	  , (const RTTypeModifier *)0
		// }}}RME
	}
	// }}}RME
	// {{{RME classAttribute 'isOperating'
  , {
		"isOperating"
	  , RTOffsetOf( roombaTopCapsule_Actor, isOperating )
		// {{{RME tool 'OT::CppTargetRTS' property 'TypeDescriptor'
	  , &RTType_bool
		// }}}RME
		// {{{RME tool 'OT::CppTargetRTS' property 'GenerateTypeModifier'
	  , (const RTTypeModifier *)0
		// }}}RME
	}
	// }}}RME
};
#undef SUPER

// {{{RME classAttribute 'sensorsToQuery'
int sensorsToQuery[ NUMSENSORS ][ 2 ] = {{7, 1}, {9, 1}, {10, 1}, {11, 1}, {12, 1}, {19, 2}, 
 {20, 2}, {21, 1}, {24, 1}, {25, 2}, {26, 2}, {35, 1}};
// }}}RME

// {{{RME tool 'OT::Cpp' property 'ImplementationEnding'
// {{{USR

// }}}USR
// }}}RME

// }}}RME
