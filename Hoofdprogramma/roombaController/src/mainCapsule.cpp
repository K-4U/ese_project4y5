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
  , 2
  , rtg_relays
  , new_mainCapsule_Actor
};

static const char * const rtg_state_names[] =
{
	"TOP"
  , "ready"
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
	default:
		break;
	}
	return RTActor::_followInV( rtg_end, rtg_portId, rtg_repIndex );
}

// {{{RME enter ':TOP:ready'
INLINE_METHODS void mainCapsule_Actor::enter2_ready( void )
{
	// {{{USR
	//cout << "MainCapsule is ready and happy to handle your stuff :D " << endl;
	// }}}USR
}
// }}}RME

void mainCapsule_Actor::enterStateV( void )
{
	switch( getCurrentState() )
	{
	case 2:
		enter2_ready();
		break;
	default:
		RTActor::enterStateV();
		break;
	}
}

// {{{RME transition ':TOP:Initial:Initial'
INLINE_METHODS void mainCapsule_Actor::transition1_Initial( const void * rtdata, RTProtocol * rtport )
{
	// {{{USR
	cout << "Initializing mainCapsule" << endl;
	cout << "Starting a stream on the roomba" << endl;

	byteArray b;
	//Safe mode
	b.append(128);
	Serial.sendCommand(b).send();
	b.clear();

	//Then, a stream
	b.append(148);
	//Bumpers only plox
	b.append(1);
	b.append(7);

	Serial.sendCommand(b).send();
	b.clear();

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
	// }}}USR
}
// }}}RME

// {{{RME transition ':TOP:ready:J518A1EA5031A:GUIDataReceived'
INLINE_METHODS void mainCapsule_Actor::transition2_GUIDataReceived( const jsonCommand * rtdata, jsonProtocol::Conjugate * rtport )
{
	// {{{USR
	cout << "MAI: GUI Data received: " << (char *)rtdata << endl;
	//Just, send it back! :D
	GUI.sendCommand(*rtdata).send();
	// }}}USR
}
// }}}RME

// {{{RME transition ':TOP:ready:J519345E300C5:serialDataReceived'
INLINE_METHODS void mainCapsule_Actor::transition3_serialDataReceived( const byteArray * rtdata, serialProtocol::Conjugate * rtport )
{
	// {{{USR
	byteArray b = *rtdata;
	cout << "MAI: Received packet from serial: ";
	b.print();
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
	enterState( 2 );
}

INLINE_CHAINS void mainCapsule_Actor::chain2_GUIDataReceived( void )
{
	// transition ':TOP:ready:J518A1EA5031A:GUIDataReceived'
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
  , 2
  , mainCapsule_Actor::rtg_parent_state
  , &mainCapsule
  , 0
  , (const RTComponentDescriptor *)0
  , 3
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
};

#undef SUPER

// {{{RME tool 'OT::Cpp' property 'ImplementationEnding'
// {{{USR

// }}}USR
// }}}RME

// }}}RME
