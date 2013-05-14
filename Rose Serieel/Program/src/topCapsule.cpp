// {{{RME classifier 'Logical View::topCapsule'

#if defined( PRAGMA ) && ! defined( PRAGMA_IMPLEMENTED )
#pragma implementation "topCapsule.h"
#endif

#include <RTSystem/Program.h>
#include <topCapsule.h>
extern const RTActorClass SerialCommunicationCapsule;

// {{{RME tool 'OT::Cpp' property 'ImplementationPreface'
// {{{USR

// }}}USR
// }}}RME

static RTActor * new_topCapsule_Actor( RTController * _rts, RTActorRef * _ref )
{
	return new topCapsule_Actor( _rts, _ref );
}

const RTActorClass topCapsule =
{
	(const RTActorClass *)0
  , "topCapsule"
  , (RTVersionId)0
  , 0
  , (const RTRelayDescriptor *)0
  , new_topCapsule_Actor
};

static const char * const rtg_state_names[] =
{
	"TOP"
  , "S1"
};

static const RTInterfaceDescriptor rtg_interfaces_serialCommunicationCapsuleR1[] =
{
	{
		"SerialCommunication"
	  , 0
	}
};

#define SUPER RTActor

topCapsule_Actor::topCapsule_Actor( RTController * rtg_rts, RTActorRef * rtg_ref )
	: RTActor( rtg_rts, rtg_ref )
{
}

topCapsule_Actor::~topCapsule_Actor( void )
{
}

// {{{RME enter ':TOP:S1'
INLINE_METHODS void topCapsule_Actor::enter2_S1( void )
{
	// {{{USR
	cout << "topCapsule initialized" << endl;
	// }}}USR
}
// }}}RME

void topCapsule_Actor::enterStateV( void )
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

INLINE_CHAINS void topCapsule_Actor::chain1_Initial( void )
{
	// transition ':TOP:Initial:Initial'
	rtgChainBegin( 1, "Initial" );
	rtgTransitionBegin();
	rtgTransitionEnd();
	enterState( 2 );
}

void topCapsule_Actor::rtsBehavior( int signalIndex, int portIndex )
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

const RTActor_class * topCapsule_Actor::getActorData( void ) const
{
	return &topCapsule_Actor::rtg_class;
}

const RTActor_class topCapsule_Actor::rtg_class =
{
	(const RTActor_class *)0
  , rtg_state_names
  , 2
  , topCapsule_Actor::rtg_parent_state
  , &topCapsule
  , 1
  , topCapsule_Actor::rtg_capsule_roles
  , 0
  , (const RTPortDescriptor *)0
  , 0
  , (const RTLocalBindingDescriptor *)0
  , 0
  , (const RTFieldDescriptor *)0
};

const RTStateId topCapsule_Actor::rtg_parent_state[] =
{
	0
  , 1
};

const RTComponentDescriptor topCapsule_Actor::rtg_capsule_roles[] =
{
	{
		"serialCommunicationCapsuleR1"
	  , &SerialCommunicationCapsule
	  , RTOffsetOf( topCapsule_Actor, serialCommunicationCapsuleR1 )
	  , 1
	  , RTComponentDescriptor::Fixed
	  , 1
	  , 1 // cardinality
	  , 1
	  , rtg_interfaces_serialCommunicationCapsuleR1
	  , 0
	  , (const RTBindingDescriptor *)0
	}
};

#undef SUPER

// {{{RME tool 'OT::Cpp' property 'ImplementationEnding'
// {{{USR

// }}}USR
// }}}RME

// }}}RME
