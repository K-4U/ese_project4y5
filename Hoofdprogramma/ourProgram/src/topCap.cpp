// {{{RME classifier 'Logical View::topCap'

#if defined( PRAGMA ) && ! defined( PRAGMA_IMPLEMENTED )
#pragma implementation "topCap.h"
#endif

#include <RTSystem/ourProgram.h>
#include <topCap.h>
extern const RTActorClass mainCapsule;
extern const RTActorClass tcpTopCapsule;

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

#define SUPER RTActor

topCap_Actor::topCap_Actor( RTController * rtg_rts, RTActorRef * rtg_ref )
	: RTActor( rtg_rts, rtg_ref )
{
}

topCap_Actor::~topCap_Actor( void )
{
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
		"tcpTopCapsuleR1"
	  , &tcpTopCapsule
	  , RTOffsetOf( topCap_Actor, tcpTopCapsuleR1 )
	  , 1
	  , RTComponentDescriptor::Fixed
	  , 1
	  , 1 // cardinality
	  , 0
	  , (const RTInterfaceDescriptor *)0
	  , 0
	  , (const RTBindingDescriptor *)0
	}
  , {
		"mainCapsuleR1"
	  , &mainCapsule
	  , RTOffsetOf( topCap_Actor, mainCapsuleR1 )
	  , 2
	  , RTComponentDescriptor::Fixed
	  , 1
	  , 1 // cardinality
	  , 0
	  , (const RTInterfaceDescriptor *)0
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
