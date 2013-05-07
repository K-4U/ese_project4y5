// {{{RME classifier 'Logical View::TCPIP::tcpTopCapsule'

#if defined( PRAGMA ) && ! defined( PRAGMA_IMPLEMENTED )
#pragma implementation "tcpTopCapsule.h"
#endif

#include <RTSystem/ourProgram.h>
#include <tcpTopCapsule.h>
#include <tcpProtocol.h>
extern const RTActorClass jsonTranslateCapsule;
extern const RTActorClass tcpCapsule;

// {{{RME tool 'OT::Cpp' property 'ImplementationPreface'
// {{{USR

// }}}USR
// }}}RME

static RTActor * new_tcpTopCapsule_Actor( RTController * _rts, RTActorRef * _ref )
{
	return new tcpTopCapsule_Actor( _rts, _ref );
}

const RTActorClass tcpTopCapsule =
{
	(const RTActorClass *)0
  , "tcpTopCapsule"
  , (RTVersionId)0
  , 0
  , (const RTRelayDescriptor *)0
  , new_tcpTopCapsule_Actor
};

static const char * const rtg_state_names[] =
{
	"TOP"
  , "S1"
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

static const RTInterfaceDescriptor rtg_interfaces_jsonTranslateCapsuleR1[] =
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

static const RTBindingDescriptor rtg_bindings_jsonTranslateCapsuleR1[] =
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
				// jsonTranslateCapsuleR1/tcpPort
				return jsonTranslateCapsuleR1._followIn( rtg_end, 0, rtg_repIndex );
			}
			break;
		default:
			break;
		}
	case 2:
		// jsonTranslateCapsuleR1
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

// {{{RME enter ':TOP:S1'
INLINE_METHODS void tcpTopCapsule_Actor::enter2_S1( void )
{
	// {{{USR
	cout << "tcpTopCapsule initialized" << endl;
	// }}}USR
}
// }}}RME

void tcpTopCapsule_Actor::enterStateV( void )
{
	switch( getCurrentState() )
	{
	case 2:
		enter2_S1();
		break;
	default:
		RTActor::enterStateV();
		break;
	}
}

// {{{RME transition ':TOP:Initial:Initial'
INLINE_METHODS void tcpTopCapsule_Actor::transition1_Initial( const void * rtdata, RTProtocol * rtport )
{
	// {{{USR
	frame.incarnate(tcpInstance,tcpCapsule,EmptyObject,ThreadUserInterface);
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
			// {{{RME state ':TOP:S1'
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
  , 2
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
		"jsonTranslateCapsuleR1"
	  , &jsonTranslateCapsule
	  , RTOffsetOf( tcpTopCapsule_Actor, jsonTranslateCapsuleR1 )
	  , 2
	  , RTComponentDescriptor::Fixed
	  , 1
	  , 1 // cardinality
	  , 2
	  , rtg_interfaces_jsonTranslateCapsuleR1
	  , 2
	  , rtg_bindings_jsonTranslateCapsuleR1
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
};

#undef SUPER

// {{{RME tool 'OT::Cpp' property 'ImplementationEnding'
// {{{USR

// }}}USR
// }}}RME

// }}}RME
