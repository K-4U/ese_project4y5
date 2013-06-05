// {{{RME classifier 'Logical View::TCPIP::tcpTopCapsule'

#if defined( PRAGMA ) && ! defined( PRAGMA_IMPLEMENTED )
#pragma implementation "tcpTopCapsule.h"
#endif

#include <RTSystem/roombaController.h>
#include <tcpTopCapsule.h>
#include <tcpProtocol.h>
extern const RTActorClass jsonTranslateCapsule;
extern const RTActorClass tcpCapsule;

// {{{RME tool 'OT::Cpp' property 'ImplementationPreface'
// {{{USR

// }}}USR
// }}}RME

static const RTRelayDescriptor rtg_relays[] =
{
	{
		"externalJsonPort"
	  , &jsonProtocol::Base::rt_class
	  , 1 // cardinality
	}
};

static RTActor * new_tcpTopCapsule_Actor( RTController * _rts, RTActorRef * _ref )
{
	return new tcpTopCapsule_Actor( _rts, _ref );
}

const RTActorClass tcpTopCapsule =
{
	(const RTActorClass *)0
  , "tcpTopCapsule"
  , (RTVersionId)0
  , 1
  , rtg_relays
  , new_tcpTopCapsule_Actor
};

static const char * const rtg_state_names[] =
{
	"TOP"
  , "readyToReceive"
};

static const RTInterfaceDescriptor rtg_interfaces_tcpInstance[] =
{
	{
		"mainConnection"
	  , 1
	}
};

static const RTBindingDescriptor rtg_bindings_tcpInstance[] =
{
	{
		0
	  , &tcpProtocol::Conjugate::rt_class
	}
};

static const RTInterfaceDescriptor rtg_interfaces_jsonTranslateInstance[] =
{
	{
		"tcpPort"
	  , 1
	}
  , {
		"jsonPort"
	  , 1
	}
};

static const RTBindingDescriptor rtg_bindings_jsonTranslateInstance[] =
{
	{
		0
	  , &tcpProtocol::Base::rt_class
	}
  , {
		1
	  , &jsonProtocol::Conjugate::rt_class
	}
};

#define SUPER RTActor

tcpTopCapsule_Actor::tcpTopCapsule_Actor( RTController * rtg_rts, RTActorRef * rtg_ref )
	: RTActor( rtg_rts, rtg_ref )
{
}

tcpTopCapsule_Actor::~tcpTopCapsule_Actor( void )
{
}

int tcpTopCapsule_Actor::_followInV( RTBindingEnd & rtg_end, int rtg_portId, int rtg_repIndex )
{
	switch( rtg_portId )
	{
	case 0:
		// externalJsonPort
		if( rtg_repIndex < 1 )
		{
			rtg_end.port = &externalJsonPort;
			rtg_end.index = rtg_repIndex;
			return 1;
		}
		break;
	default:
		break;
	}
	return RTActor::_followInV( rtg_end, rtg_portId, rtg_repIndex );
}

int tcpTopCapsule_Actor::_followOutV( RTBindingEnd & rtg_end, int rtg_compId, int rtg_portId, int rtg_repIndex )
{
	switch( rtg_compId )
	{
	case 1:
		// tcpInstance
		switch( rtg_portId )
		{
		case 0:
			// mainConnection
			if( rtg_repIndex < 1 )
			{
				// jsonTranslateInstance/tcpPort
				return jsonTranslateInstance._followIn( rtg_end, 0, rtg_repIndex );
			}
			break;
		default:
			break;
		}
	case 2:
		// jsonTranslateInstance
		switch( rtg_portId )
		{
		case 0:
			// tcpPort
			if( rtg_repIndex < 1 )
			{
				// tcpInstance/mainConnection
				return tcpInstance._followIn( rtg_end, 0, rtg_repIndex );
			}
			break;
		case 1:
			// jsonPort
			if( rtg_repIndex < 1 )
			{
				// internalJsonPort
				rtg_end.port = &internalJsonPort;
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

// {{{RME transition ':TOP:Initial:Initial'
INLINE_METHODS void tcpTopCapsule_Actor::transition1_Initial( const void * rtdata, RTProtocol * rtport )
{
	// {{{USR
	frame.incarnate(tcpInstance, tcpCapsule, EmptyObject, ThreadUserInterface);
	frame.incarnate(jsonTranslateInstance, jsonTranslateCapsule, EmptyObject, ThreadJsonTranslate);

	cout << "tcpTopCapsule initialized" << endl;
	// }}}USR
}
// }}}RME

// {{{RME transition ':TOP:readyToReceive:J518A1A0D0015:receiveCommand'
INLINE_METHODS void tcpTopCapsule_Actor::transition2_receiveCommand( const jsonCommand * rtdata, jsonProtocol::Conjugate * rtport )
{
	// {{{USR
	//Just pass it on
	externalJsonPort.commandReceived(*rtdata).send();
	// }}}USR
}
// }}}RME

// {{{RME transition ':TOP:readyToReceive:J518A1A3200A8:sendCommand'
INLINE_METHODS void tcpTopCapsule_Actor::transition3_sendCommand( const jsonCommand * rtdata, jsonProtocol::Base * rtport )
{
	// {{{USR
	//Just pass it on
	internalJsonPort.sendCommand(*rtdata).send();
	// }}}USR
}
// }}}RME

INLINE_CHAINS void tcpTopCapsule_Actor::chain1_Initial( void )
{
	// transition ':TOP:Initial:Initial'
	rtgChainBegin( 1, "Initial" );
	rtgTransitionBegin();
	transition1_Initial( msg->data, msg->sap() );
	rtgTransitionEnd();
	enterState( 2 );
}

INLINE_CHAINS void tcpTopCapsule_Actor::chain2_receiveCommand( void )
{
	// transition ':TOP:readyToReceive:J518A1A0D0015:receiveCommand'
	rtgChainBegin( 2, "receiveCommand" );
	exitState( rtg_parent_state );
	rtgTransitionBegin();
	transition2_receiveCommand( (const jsonCommand *)msg->data, (jsonProtocol::Conjugate *)msg->sap() );
	rtgTransitionEnd();
	enterState( 2 );
}

INLINE_CHAINS void tcpTopCapsule_Actor::chain3_sendCommand( void )
{
	// transition ':TOP:readyToReceive:J518A1A3200A8:sendCommand'
	rtgChainBegin( 2, "sendCommand" );
	exitState( rtg_parent_state );
	rtgTransitionBegin();
	transition3_sendCommand( (const jsonCommand *)msg->data, (jsonProtocol::Base *)msg->sap() );
	rtgTransitionEnd();
	enterState( 2 );
}

void tcpTopCapsule_Actor::rtsBehavior( int signalIndex, int portIndex )
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
			// {{{RME state ':TOP:readyToReceive'
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
				// {{{RME port 'internalJsonPort'
				switch( signalIndex )
				{
				case jsonProtocol::Conjugate::rti_commandReceived:
					chain2_receiveCommand();
					return;
				default:
					break;
				}
				break;
				// }}}RME
			case 3:
				// {{{RME port 'externalJsonPort'
				switch( signalIndex )
				{
				case jsonProtocol::Base::rti_sendCommand:
					chain3_sendCommand();
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

const RTActor_class * tcpTopCapsule_Actor::getActorData( void ) const
{
	return &tcpTopCapsule_Actor::rtg_class;
}

const RTActor_class tcpTopCapsule_Actor::rtg_class =
{
	(const RTActor_class *)0
  , rtg_state_names
  , 2
  , tcpTopCapsule_Actor::rtg_parent_state
  , &tcpTopCapsule
  , 2
  , tcpTopCapsule_Actor::rtg_capsule_roles
  , 3
  , tcpTopCapsule_Actor::rtg_ports
  , 0
  , (const RTLocalBindingDescriptor *)0
  , 0
  , (const RTFieldDescriptor *)0
};

const RTStateId tcpTopCapsule_Actor::rtg_parent_state[] =
{
	0
  , 1
};

const RTComponentDescriptor tcpTopCapsule_Actor::rtg_capsule_roles[] =
{
	{
		"tcpInstance"
	  , &tcpCapsule
	  , RTOffsetOf( tcpTopCapsule_Actor, tcpInstance )
	  , 1
	  , RTComponentDescriptor::Optional
	  , 1
	  , 1 // cardinality
	  , 1
	  , rtg_interfaces_tcpInstance
	  , 1
	  , rtg_bindings_tcpInstance
	}
  , {
		"jsonTranslateInstance"
	  , &jsonTranslateCapsule
	  , RTOffsetOf( tcpTopCapsule_Actor, jsonTranslateInstance )
	  , 2
	  , RTComponentDescriptor::Optional
	  , 1
	  , 1 // cardinality
	  , 2
	  , rtg_interfaces_jsonTranslateInstance
	  , 2
	  , rtg_bindings_jsonTranslateInstance
	}
};

const RTPortDescriptor tcpTopCapsule_Actor::rtg_ports[] =
{
	{
		"internalJsonPort"
	  , (const char *)0
	  , &jsonProtocol::Conjugate::rt_class
	  , RTOffsetOf( tcpTopCapsule_Actor, tcpTopCapsule_Actor::internalJsonPort )
	  , 1 // cardinality
	  , 1
	  , RTPortDescriptor::KindWired + RTPortDescriptor::NotificationDisabled + RTPortDescriptor::RegisterNotPermitted + RTPortDescriptor::VisibilityProtected
	}
  , {
		"frame"
	  , (const char *)0
	  , &Frame::Base::rt_class
	  , RTOffsetOf( tcpTopCapsule_Actor, tcpTopCapsule_Actor::frame )
	  , 1 // cardinality
	  , 2
	  , RTPortDescriptor::KindSpecial + RTPortDescriptor::NotificationDisabled + RTPortDescriptor::RegisterNotPermitted + RTPortDescriptor::VisibilityProtected
	}
  , {
		"externalJsonPort"
	  , (const char *)0
	  , &jsonProtocol::Base::rt_class
	  , RTOffsetOf( tcpTopCapsule_Actor, tcpTopCapsule_Actor::externalJsonPort )
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
