// {{{RME classifier 'Logical View::mainCapsule'

#if defined( PRAGMA ) && ! defined( PRAGMA_IMPLEMENTED )
#pragma implementation "mainCapsule.h"
#endif

#include <RTSystem/roombaController.h>
#include <mainCapsule.h>

// {{{RME tool 'OT::Cpp' property 'ImplementationPreface'
// {{{USR

// }}}USR
// }}}RME

static const RTRelayDescriptor rtg_relays[] =
{
	{
		"GUI"
	  , &jsonProtocol::Conjugate::rt_class
	  , 1 // cardinality
	}
  , {
		"Serial"
	  , &serialProtocol::Conjugate::rt_class
	  , 1 // cardinality
	}
  , {
		"Roomba"
	  , &roombaProtocol::Conjugate::rt_class
	  , 1 // cardinality
	}
};

static RTActor * new_mainCapsule_Actor( RTController * _rts, RTActorRef * _ref )
{
	return new mainCapsule_Actor( _rts, _ref );
}

const RTActorClass mainCapsule =
{
	(const RTActorClass *)0
  , "mainCapsule"
  , (RTVersionId)0
  , 3
  , rtg_relays
  , new_mainCapsule_Actor
};

static const char * const rtg_state_names[] =
{
	"TOP"
  , "ready"
  , "waitingForCom"
  , "Exit"
};

#define SUPER RTActor

mainCapsule_Actor::mainCapsule_Actor( RTController * rtg_rts, RTActorRef * rtg_ref )
	: RTActor( rtg_rts, rtg_ref )
{
}

mainCapsule_Actor::~mainCapsule_Actor( void )
{
}

int mainCapsule_Actor::_followInV( RTBindingEnd & rtg_end, int rtg_portId, int rtg_repIndex )
{
	switch( rtg_portId )
	{
	case 0:
		// GUI
		if( rtg_repIndex < 1 )
		{
			rtg_end.port = &GUI;
			rtg_end.index = rtg_repIndex;
			return 1;
		}
		break;
	case 1:
		// Serial
		if( rtg_repIndex < 1 )
		{
			rtg_end.port = &Serial;
			rtg_end.index = rtg_repIndex;
			return 1;
		}
		break;
	case 2:
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

// {{{RME enter ':TOP:waitingForCom'
INLINE_METHODS void mainCapsule_Actor::enter3_waitingForCom( void )
{
	// {{{USR
	cout << "MAI: Waiting for com port to open" << endl;
	// }}}USR
}
// }}}RME

void mainCapsule_Actor::enterStateV( void )
{
	switch( getCurrentState() )
	{
	case 3:
		enter3_waitingForCom();
		break;
	case 4:
		enter4_Exit();
		break;
	default:
		RTActor::enterStateV();
		break;
	}
}

// {{{RME enter ':TOP:Exit'
INLINE_METHODS void mainCapsule_Actor::enter4_Exit( void )
{
	// {{{USR
	cout << "MAI: Com port not opened. Quiting..." << endl;
	// }}}USR
}
// }}}RME

// {{{RME transition ':TOP:Initial:Initial'
INLINE_METHODS void mainCapsule_Actor::transition1_Initial( const void * rtdata, RTProtocol * rtport )
{
	// {{{USR
	cout << "Initializing mainCapsule" << endl;

	// }}}USR
}
// }}}RME

// {{{RME transition ':TOP:ready:J51A475DD0298:GUIDataReceived'
INLINE_METHODS void mainCapsule_Actor::transition2_GUIDataReceived( const jsonCommand * rtdata, jsonProtocol::Conjugate * rtport )
{
	// {{{USR
	Roomba.commandReceived(*rtdata).send();
	// }}}USR
}
// }}}RME

// {{{RME transition ':TOP:ready:J519345E300C5:serialDataReceived'
INLINE_METHODS void mainCapsule_Actor::transition3_serialDataReceived( const byteArray * rtdata, serialProtocol::Conjugate * rtport )
{
	// {{{USR
	Roomba.dataReceived(*rtdata).send();
	// }}}USR
}
// }}}RME

// {{{RME transition ':TOP:waitingForCom:J519B520503E6:comOpened'
INLINE_METHODS void mainCapsule_Actor::transition4_comOpened( const void * rtdata, serialProtocol::Conjugate * rtport )
{
	// {{{USR
	Roomba.ready().send();
	cout << "MainCapsule is ready and happy to handle your stuff :D " << endl;

	// }}}USR
}
// }}}RME

// {{{RME transition ':TOP:ready:J519B64890324:roombaDataReceived'
INLINE_METHODS void mainCapsule_Actor::transition6_roombaDataReceived( const byteArray * rtdata, roombaProtocol::Conjugate * rtport )
{
	// {{{USR
	Serial.sendCommand(*rtdata).send();
	// }}}USR
}
// }}}RME

// {{{RME transition ':TOP:ready:J51AC8C82005A:setCommandLength'
INLINE_METHODS void mainCapsule_Actor::transition7_setCommandLength( const int * rtdata, roombaProtocol::Conjugate * rtport )
{
	// {{{USR
	Serial.commandLength(*rtdata).send();
	// }}}USR
}
// }}}RME

INLINE_CHAINS void mainCapsule_Actor::chain1_Initial( void )
{
	// transition ':TOP:Initial:Initial'
	rtgChainBegin( 1, "Initial" );
	rtgTransitionBegin();
	transition1_Initial( msg->data, msg->sap() );
	rtgTransitionEnd();
	enterState( 3 );
}

INLINE_CHAINS void mainCapsule_Actor::chain2_GUIDataReceived( void )
{
	// transition ':TOP:ready:J51A475DD0298:GUIDataReceived'
	rtgChainBegin( 2, "GUIDataReceived" );
	exitState( rtg_parent_state );
	rtgTransitionBegin();
	transition2_GUIDataReceived( (const jsonCommand *)msg->data, (jsonProtocol::Conjugate *)msg->sap() );
	rtgTransitionEnd();
	enterState( 2 );
}

INLINE_CHAINS void mainCapsule_Actor::chain3_serialDataReceived( void )
{
	// transition ':TOP:ready:J519345E300C5:serialDataReceived'
	rtgChainBegin( 2, "serialDataReceived" );
	exitState( rtg_parent_state );
	rtgTransitionBegin();
	transition3_serialDataReceived( (const byteArray *)msg->data, (serialProtocol::Conjugate *)msg->sap() );
	rtgTransitionEnd();
	enterState( 2 );
}

INLINE_CHAINS void mainCapsule_Actor::chain6_roombaDataReceived( void )
{
	// transition ':TOP:ready:J519B64890324:roombaDataReceived'
	rtgChainBegin( 2, "roombaDataReceived" );
	exitState( rtg_parent_state );
	rtgTransitionBegin();
	transition6_roombaDataReceived( (const byteArray *)msg->data, (roombaProtocol::Conjugate *)msg->sap() );
	rtgTransitionEnd();
	enterState( 2 );
}

INLINE_CHAINS void mainCapsule_Actor::chain7_setCommandLength( void )
{
	// transition ':TOP:ready:J51AC8C82005A:setCommandLength'
	rtgChainBegin( 2, "setCommandLength" );
	exitState( rtg_parent_state );
	rtgTransitionBegin();
	transition7_setCommandLength( (const int *)msg->data, (roombaProtocol::Conjugate *)msg->sap() );
	rtgTransitionEnd();
	enterState( 2 );
}

INLINE_CHAINS void mainCapsule_Actor::chain4_comOpened( void )
{
	// transition ':TOP:waitingForCom:J519B520503E6:comOpened'
	rtgChainBegin( 3, "comOpened" );
	exitState( rtg_parent_state );
	rtgTransitionBegin();
	transition4_comOpened( msg->data, (serialProtocol::Conjugate *)msg->sap() );
	rtgTransitionEnd();
	enterState( 2 );
}

INLINE_CHAINS void mainCapsule_Actor::chain5_comError( void )
{
	// transition ':TOP:waitingForCom:J519B525003DD:comError'
	rtgChainBegin( 3, "comError" );
	exitState( rtg_parent_state );
	rtgTransitionBegin();
	rtgTransitionEnd();
	enterState( 4 );
}

void mainCapsule_Actor::rtsBehavior( int signalIndex, int portIndex )
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
					chain1_Initial();
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
			// {{{RME state ':TOP:ready'
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
			case 2:
				// {{{RME port 'GUI'
				switch( signalIndex )
				{
				case jsonProtocol::Conjugate::rti_commandReceived:
					chain2_GUIDataReceived();
					return;
				default:
					break;
				}
				break;
				// }}}RME
			case 3:
				// {{{RME port 'Serial'
				switch( signalIndex )
				{
				case serialProtocol::Conjugate::rti_commandReceived:
					chain3_serialDataReceived();
					return;
				default:
					break;
				}
				break;
				// }}}RME
			case 4:
				// {{{RME port 'Roomba'
				switch( signalIndex )
				{
				case roombaProtocol::Conjugate::rti_sendData:
					chain6_roombaDataReceived();
					return;
				case roombaProtocol::Conjugate::rti_setCommandLength:
					chain7_setCommandLength();
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
			// {{{RME state ':TOP:waitingForCom'
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
			case 3:
				// {{{RME port 'Serial'
				switch( signalIndex )
				{
				case serialProtocol::Conjugate::rti_comOpened:
					chain4_comOpened();
					return;
				case serialProtocol::Conjugate::rti_comError:
					chain5_comError();
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
			// {{{RME state ':TOP:Exit'
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

const RTActor_class * mainCapsule_Actor::getActorData( void ) const
{
	return &mainCapsule_Actor::rtg_class;
}

const RTActor_class mainCapsule_Actor::rtg_class =
{
	(const RTActor_class *)0
  , rtg_state_names
  , 4
  , mainCapsule_Actor::rtg_parent_state
  , &mainCapsule
  , 0
  , (const RTComponentDescriptor *)0
  , 4
  , mainCapsule_Actor::rtg_ports
  , 0
  , (const RTLocalBindingDescriptor *)0
  , 0
  , (const RTFieldDescriptor *)0
};

const RTStateId mainCapsule_Actor::rtg_parent_state[] =
{
	0
  , 1
  , 1
  , 1
};

const RTPortDescriptor mainCapsule_Actor::rtg_ports[] =
{
	{
		"frame"
	  , (const char *)0
	  , &Frame::Base::rt_class
	  , RTOffsetOf( mainCapsule_Actor, mainCapsule_Actor::frame )
	  , 1 // cardinality
	  , 1
	  , RTPortDescriptor::KindSpecial + RTPortDescriptor::NotificationDisabled + RTPortDescriptor::RegisterNotPermitted + RTPortDescriptor::VisibilityProtected
	}
  , {
		"GUI"
	  , (const char *)0
	  , &jsonProtocol::Conjugate::rt_class
	  , RTOffsetOf( mainCapsule_Actor, mainCapsule_Actor::GUI )
	  , 1 // cardinality
	  , 2
	  , RTPortDescriptor::KindWired + RTPortDescriptor::NotificationDisabled + RTPortDescriptor::RegisterNotPermitted + RTPortDescriptor::VisibilityPublic
	}
  , {
		"Serial"
	  , (const char *)0
	  , &serialProtocol::Conjugate::rt_class
	  , RTOffsetOf( mainCapsule_Actor, mainCapsule_Actor::Serial )
	  , 1 // cardinality
	  , 3
	  , RTPortDescriptor::KindWired + RTPortDescriptor::NotificationDisabled + RTPortDescriptor::RegisterNotPermitted + RTPortDescriptor::VisibilityPublic
	}
  , {
		"Roomba"
	  , (const char *)0
	  , &roombaProtocol::Conjugate::rt_class
	  , RTOffsetOf( mainCapsule_Actor, mainCapsule_Actor::Roomba )
	  , 1 // cardinality
	  , 4
	  , RTPortDescriptor::KindWired + RTPortDescriptor::NotificationDisabled + RTPortDescriptor::RegisterNotPermitted + RTPortDescriptor::VisibilityPublic
	}
};

#undef SUPER

// {{{RME tool 'OT::Cpp' property 'ImplementationEnding'
// {{{USR

// }}}USR
// }}}RME

// }}}RME
