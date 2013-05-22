// {{{RME classifier 'Logical View::Roomba::roombaTopCapsule'

#if defined( PRAGMA ) && ! defined( PRAGMA_IMPLEMENTED )
#pragma implementation "roombaTopCapsule.h"
#endif

#include <RTSystem/roombaController.h>
#include <roombaTopCapsule.h>
#include <clsRoomba.h>

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

#define SUPER RTActor

roombaTopCapsule_Actor::roombaTopCapsule_Actor( RTController * rtg_rts, RTActorRef * rtg_ref )
	: RTActor( rtg_rts, rtg_ref )
{
}

roombaTopCapsule_Actor::~roombaTopCapsule_Actor( void )
{
}

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

	//Then, a stream
	b.append(148);
	//First the length:
	int sizeOfArray = (sizeof(sensorsToQuery) / sizeof(int)) / 2;
	b.append(sizeOfArray);
	int i = 0;
	for(i=0;i < sizeOfArray; i++){
	    b.append(sensorsToQuery[i][0]);
	}

	toMain.sendData(b).send();
	b.clear();

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

// {{{RME transition ':TOP:Ready:J519B5D19038A:dataReceived'
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
	        if(b.get(i) == 19){
	            inSensorList = true;
	        }
	    }else{
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
	    }
	    i++;
	}
	this->roomba.printSensors();
	// }}}USR
}
// }}}RME

INLINE_CHAINS void roombaTopCapsule_Actor::chain4_Initial( void )
{
	// transition ':TOP:Initial:Initial'
	rtgChainBegin( 1, "Initial" );
	rtgTransitionBegin();
	rtgTransitionEnd();
	enterState( 3 );
}

INLINE_CHAINS void roombaTopCapsule_Actor::chain2_dataReceived( void )
{
	// transition ':TOP:Ready:J519B5D19038A:dataReceived'
	rtgChainBegin( 2, "dataReceived" );
	exitState( rtg_parent_state );
	rtgTransitionBegin();
	transition2_dataReceived( (const byteArray *)msg->data, (roombaProtocol::Base *)msg->sap() );
	rtgTransitionEnd();
	enterState( 2 );
}

INLINE_CHAINS void roombaTopCapsule_Actor::chain3_commandReceived( void )
{
	// transition ':TOP:Ready:J519B5D200005:commandReceived'
	rtgChainBegin( 2, "commandReceived" );
	exitState( rtg_parent_state );
	rtgTransitionBegin();
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
  , 0
  , (const RTComponentDescriptor *)0
  , 1
  , roombaTopCapsule_Actor::rtg_ports
  , 0
  , (const RTLocalBindingDescriptor *)0
  , 1
  , roombaTopCapsule_Actor::rtg_roombaTopCapsule_fields
};

const RTStateId roombaTopCapsule_Actor::rtg_parent_state[] =
{
	0
  , 1
  , 1
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
