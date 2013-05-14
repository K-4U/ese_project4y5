// {{{RME classifier 'Logical View::Serial::serialTopCapsule'

#if defined( PRAGMA ) && ! defined( PRAGMA_IMPLEMENTED )
#pragma implementation "serialTopCapsule.h"
#endif

#include <RTSystem/ourProgram.h>
#include <serialTopCapsule.h>
extern const RTActorClass serialCommunicationCapsule;

// {{{RME tool 'OT::Cpp' property 'ImplementationPreface'
// {{{USR

// }}}USR
// }}}RME

static RTActor * new_serialTopCapsule_Actor( RTController * _rts, RTActorRef * _ref )
{
	return new serialTopCapsule_Actor( _rts, _ref );
}

const RTActorClass serialTopCapsule =
{
	(const RTActorClass *)0
  , "serialTopCapsule"
  , (RTVersionId)0
  , 0
  , (const RTRelayDescriptor *)0
  , new_serialTopCapsule_Actor
};

static const char * const rtg_state_names[] =
{
	"TOP"
  , "ready"
};

static const RTInterfaceDescriptor rtg_interfaces_serialCommunicationInstance[] =
{
	{
		"serialPort"
	  , 0
	}
};

#define SUPER RTActor

serialTopCapsule_Actor::serialTopCapsule_Actor( RTController * rtg_rts, RTActorRef * rtg_ref )
	: RTActor( rtg_rts, rtg_ref )
{
}

serialTopCapsule_Actor::~serialTopCapsule_Actor( void )
{
}

// {{{RME transition ':TOP:Initial:Initial'
INLINE_METHODS void serialTopCapsule_Actor::transition1_Initial( const void * rtdata, RTProtocol * rtport )
{
	// {{{USR
	frame.incarnate(serialCommunicationInstance,serialCommunicationCapsule,EmptyObject,ThreadSerial);

	cout << "serialTopCapsule initialized" << endl;
	// }}}USR
}
// }}}RME

INLINE_CHAINS void serialTopCapsule_Actor::chain1_Initial( void )
{
	// transition ':TOP:Initial:Initial'
	rtgChainBegin( 1, "Initial" );
	rtgTransitionBegin();
	transition1_Initial( msg->data, msg->sap() );
	rtgTransitionEnd();
	enterState( 2 );
}

void serialTopCapsule_Actor::rtsBehavior( int signalIndex, int portIndex )
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

const RTActor_class * serialTopCapsule_Actor::getActorData( void ) const
{
	return &serialTopCapsule_Actor::rtg_class;
}

const RTActor_class serialTopCapsule_Actor::rtg_class =
{
	(const RTActor_class *)0
  , rtg_state_names
  , 2
  , serialTopCapsule_Actor::rtg_parent_state
  , &serialTopCapsule
  , 1
  , serialTopCapsule_Actor::rtg_capsule_roles
  , 1
  , serialTopCapsule_Actor::rtg_ports
  , 0
  , (const RTLocalBindingDescriptor *)0
  , 0
  , (const RTFieldDescriptor *)0
};

const RTStateId serialTopCapsule_Actor::rtg_parent_state[] =
{
	0
  , 1
};

const RTComponentDescriptor serialTopCapsule_Actor::rtg_capsule_roles[] =
{
	{
		"serialCommunicationInstance"
	  , &serialCommunicationCapsule
	  , RTOffsetOf( serialTopCapsule_Actor, serialCommunicationInstance )
	  , 1
	  , RTComponentDescriptor::Optional
	  , 1
	  , 1 // cardinality
	  , 1
	  , rtg_interfaces_serialCommunicationInstance
	  , 0
	  , (const RTBindingDescriptor *)0
	}
};

const RTPortDescriptor serialTopCapsule_Actor::rtg_ports[] =
{
	{
		"frame"
	  , (const char *)0
	  , &Frame::Base::rt_class
	  , RTOffsetOf( serialTopCapsule_Actor, serialTopCapsule_Actor::frame )
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
