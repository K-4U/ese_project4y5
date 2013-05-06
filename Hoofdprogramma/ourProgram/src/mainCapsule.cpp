// {{{RME classifier 'Logical View::mainCapsule'

#if defined( PRAGMA ) && ! defined( PRAGMA_IMPLEMENTED )
#pragma implementation "mainCapsule.h"
#endif

#include <RTSystem/ourProgram.h>
#include <mainCapsule.h>

// {{{RME tool 'OT::Cpp' property 'ImplementationPreface'
// {{{USR

// }}}USR
// }}}RME

static RTActor * new_mainCapsule_Actor( RTController * _rts, RTActorRef * _ref )
{
	return new mainCapsule_Actor( _rts, _ref );
}

const RTActorClass mainCapsule =
{
	(const RTActorClass *)0
  , "mainCapsule"
  , (RTVersionId)0
  , 0
  , (const RTRelayDescriptor *)0
  , new_mainCapsule_Actor
};

static const char * const rtg_state_names[] =
{
	"TOP"
};

#define SUPER RTActor

mainCapsule_Actor::mainCapsule_Actor( RTController * rtg_rts, RTActorRef * rtg_ref )
	: RTActor( rtg_rts, rtg_ref )
{
}

mainCapsule_Actor::~mainCapsule_Actor( void )
{
}

void mainCapsule_Actor::rtsBehavior( int signalIndex, int portIndex )
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

const RTActor_class * mainCapsule_Actor::getActorData( void ) const
{
	return &mainCapsule_Actor::rtg_class;
}

const RTActor_class mainCapsule_Actor::rtg_class =
{
	(const RTActor_class *)0
  , rtg_state_names
  , 1
  , mainCapsule_Actor::rtg_parent_state
  , &mainCapsule
  , 0
  , (const RTComponentDescriptor *)0
  , 1
  , mainCapsule_Actor::rtg_ports
  , 0
  , (const RTLocalBindingDescriptor *)0
  , 0
  , (const RTFieldDescriptor *)0
};

const RTStateId mainCapsule_Actor::rtg_parent_state[] =
{
	0
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
};

#undef SUPER

// {{{RME tool 'OT::Cpp' property 'ImplementationEnding'
// {{{USR

// }}}USR
// }}}RME

// }}}RME
