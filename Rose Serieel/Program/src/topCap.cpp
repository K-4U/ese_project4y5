// {{{RME classifier 'Logical View::topCap'

#if defined( PRAGMA ) && ! defined( PRAGMA_IMPLEMENTED )
#pragma implementation "topCap.h"
#endif

#include <RTSystem/Program.h>
#include <topCap.h>
#include <SerialProtocol.h>
extern const RTActorClass SerialCommunicationCapsule;
extern const RTActorClass mainCapsule;

// {{{RME tool 'OT::Cpp' property 'ImplementationPreface'
// {{{USR

// }}}USR
// }}}RME

static RTActor * new_topCap_Actor( RTController * _rts, RTActorRef * _ref )
{
	return new topCap_Actor( _rts, _ref );
}

const RTActorClass topCap =
{
	(const RTActorClass *)0
  , "topCap"
  , (RTVersionId)0
  , 0
  , (const RTRelayDescriptor *)0
  , new_topCap_Actor
};

static const char * const rtg_state_names[] =
{
	"TOP"
};

static const RTInterfaceDescriptor rtg_interfaces_mainCapsuleR1[] =
{
	{
		"Serial"
	  , 1
	}
};

static const RTBindingDescriptor rtg_bindings_mainCapsuleR1[] =
{
	{
		0
	  , &SerialProtocol::Base::rt_class
	}
};

static const RTInterfaceDescriptor rtg_interfaces_serialCommunicationCapsuleR1[] =
{
	{
		"SerialCommunication"
	  , 1
	}
};

static const RTBindingDescriptor rtg_bindings_serialCommunicationCapsuleR1[] =
{
	{
		0
	  , &SerialProtocol::Conjugate::rt_class
	}
};

#define SUPER RTActor

topCap_Actor::topCap_Actor( RTController * rtg_rts, RTActorRef * rtg_ref )
	: RTActor( rtg_rts, rtg_ref )
{
}

topCap_Actor::~topCap_Actor( void )
{
}

int topCap_Actor::_followOutV( RTBindingEnd & rtg_end, int rtg_compId, int rtg_portId, int rtg_repIndex )
{
	switch( rtg_compId )
	{
	case 1:
		// mainCapsuleR1
		switch( rtg_portId )
		{
		case 0:
			// Serial
			if( rtg_repIndex < 1 )
			{
				// serialCommunicationCapsuleR1/SerialCommunication
				return serialCommunicationCapsuleR1._followIn( rtg_end, 0, rtg_repIndex );
			}
			break;
		default:
			break;
		}
	case 2:
		// serialCommunicationCapsuleR1
		switch( rtg_portId )
		{
		case 0:
			// SerialCommunication
			if( rtg_repIndex < 1 )
			{
				// mainCapsuleR1/Serial
				return mainCapsuleR1._followIn( rtg_end, 0, rtg_repIndex );
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

void topCap_Actor::rtsBehavior( int signalIndex, int portIndex )
{
	for( int stateIndex = getCurrentState(); ; )
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
		default:
			unexpectedState();
			return;
		}
}

const RTActor_class * topCap_Actor::getActorData( void ) const
{
	return &topCap_Actor::rtg_class;
}

const RTActor_class topCap_Actor::rtg_class =
{
	(const RTActor_class *)0
  , rtg_state_names
  , 1
  , topCap_Actor::rtg_parent_state
  , &topCap
  , 2
  , topCap_Actor::rtg_capsule_roles
  , 0
  , (const RTPortDescriptor *)0
  , 0
  , (const RTLocalBindingDescriptor *)0
  , 0
  , (const RTFieldDescriptor *)0
};

const RTStateId topCap_Actor::rtg_parent_state[] =
{
	0
};

const RTComponentDescriptor topCap_Actor::rtg_capsule_roles[] =
{
	{
		"mainCapsuleR1"
	  , &mainCapsule
	  , RTOffsetOf( topCap_Actor, mainCapsuleR1 )
	  , 1
	  , RTComponentDescriptor::Fixed
	  , 1
	  , 1 // cardinality
	  , 1
	  , rtg_interfaces_mainCapsuleR1
	  , 1
	  , rtg_bindings_mainCapsuleR1
	}
  , {
		"serialCommunicationCapsuleR1"
	  , &SerialCommunicationCapsule
	  , RTOffsetOf( topCap_Actor, serialCommunicationCapsuleR1 )
	  , 2
	  , RTComponentDescriptor::Fixed
	  , 1
	  , 1 // cardinality
	  , 1
	  , rtg_interfaces_serialCommunicationCapsuleR1
	  , 1
	  , rtg_bindings_serialCommunicationCapsuleR1
	}
};

#undef SUPER

// {{{RME tool 'OT::Cpp' property 'ImplementationEnding'
// {{{USR

// }}}USR
// }}}RME

// }}}RME
