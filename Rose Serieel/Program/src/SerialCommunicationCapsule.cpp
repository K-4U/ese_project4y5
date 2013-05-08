// {{{RME classifier 'Logical View::SerialCommunicationCapsule'

#if defined( PRAGMA ) && ! defined( PRAGMA_IMPLEMENTED )
#pragma implementation "SerialCommunicationCapsule.h"
#endif

#include <RTSystem/Program.h>
#include <SerialCommunicationCapsule.h>

// {{{RME tool 'OT::Cpp' property 'ImplementationPreface'
// {{{USR

// }}}USR
// }}}RME

static const RTRelayDescriptor rtg_relays[] =
{
	{
		"SerialCommunication"
	  , &SerialProtocol::Base::rt_class
	  , 1 // cardinality
	}
};

static RTActor * new_SerialCommunicationCapsule_Actor( RTController * _rts, RTActorRef * _ref )
{
	return new SerialCommunicationCapsule_Actor( _rts, _ref );
}

const RTActorClass SerialCommunicationCapsule =
{
	(const RTActorClass *)0
  , "SerialCommunicationCapsule"
  , (RTVersionId)0
  , 1
  , rtg_relays
  , new_SerialCommunicationCapsule_Actor
};

static const char * const rtg_state_names[] =
{
	"TOP"
  , "Reset"
  , "OpenPort"
  , "SetupPort"
  , "ShutdownConnection"
  , "SerialReceived"
};

#define SUPER RTActor

SerialCommunicationCapsule_Actor::SerialCommunicationCapsule_Actor( RTController * rtg_rts, RTActorRef * rtg_ref )
	: RTActor( rtg_rts, rtg_ref )
{
}

SerialCommunicationCapsule_Actor::~SerialCommunicationCapsule_Actor( void )
{
}

int SerialCommunicationCapsule_Actor::_followInV( RTBindingEnd & rtg_end, int rtg_portId, int rtg_repIndex )
{
	switch( rtg_portId )
	{
	case 0:
		// SerialCommunication
		if( rtg_repIndex < 1 )
		{
			rtg_end.port = &SerialCommunication;
			rtg_end.index = rtg_repIndex;
			return 1;
		}
		break;
	default:
		break;
	}
	return RTActor::_followInV( rtg_end, rtg_portId, rtg_repIndex );
}

// {{{RME enter ':TOP:Reset'
INLINE_METHODS void SerialCommunicationCapsule_Actor::enter2_Reset( void )
{
	// {{{USR
	cout << "in reset terecht gekomen" << endl;
	timer.informIn(RTTimespec(4,0));
	// }}}USR
}
// }}}RME

void SerialCommunicationCapsule_Actor::enterStateV( void )
{
	switch( getCurrentState() )
	{
	case 2:
		enter2_Reset();
		break;
	default:
		RTActor::enterStateV();
		break;
	}
}

// {{{RME transition ':TOP:OpenPort:False'
INLINE_METHODS void SerialCommunicationCapsule_Actor::transition2_False( const void * rtdata, RTProtocol * rtport )
{
	// {{{USR
	cout << "Onjuiste COM-poort" << endl;
	// }}}USR
}
// }}}RME

INLINE_CHAINS void SerialCommunicationCapsule_Actor::chain1_Initial( void )
{
	// transition ':TOP:Initial:Initial'
	rtgChainBegin( 1, "Initial" );
	rtgTransitionBegin();
	rtgTransitionEnd();
	if( choicePoint1_OpenPort( msg->data, msg->sap() ) )
		chain3_True();
	else
		chain2_False();
}

// {{{RME choicePoint ':TOP:OpenPort'
INLINE_METHODS int SerialCommunicationCapsule_Actor::choicePoint1_OpenPort( const void * rtdata, RTProtocol * rtport )
{
	// {{{USR
	cout << "Test" << endl;
	// }}}USR
}
// }}}RME

INLINE_CHAINS void SerialCommunicationCapsule_Actor::chain3_True( void )
{
	// transition ':TOP:OpenPort:True'
	rtgChainBegin( 3, "True" );
	rtgTransitionBegin();
	rtgTransitionEnd();
	chain5_True();
}

INLINE_CHAINS void SerialCommunicationCapsule_Actor::chain5_True( void )
{
	// transition ':TOP:SetupPort:True'
	rtgChainBegin( 4, "True" );
	rtgTransitionBegin();
	rtgTransitionEnd();
}

INLINE_CHAINS void SerialCommunicationCapsule_Actor::chain2_False( void )
{
	// transition ':TOP:OpenPort:False'
	rtgChainBegin( 3, "False" );
	rtgTransitionBegin();
	transition2_False( msg->data, msg->sap() );
	rtgTransitionEnd();
	enterState( 2 );
}

void SerialCommunicationCapsule_Actor::rtsBehavior( int signalIndex, int portIndex )
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
			// {{{RME state ':TOP:Reset'
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

const RTActor_class * SerialCommunicationCapsule_Actor::getActorData( void ) const
{
	return &SerialCommunicationCapsule_Actor::rtg_class;
}

const RTActor_class SerialCommunicationCapsule_Actor::rtg_class =
{
	(const RTActor_class *)0
  , rtg_state_names
  , 2
  , SerialCommunicationCapsule_Actor::rtg_parent_state
  , &SerialCommunicationCapsule
  , 0
  , (const RTComponentDescriptor *)0
  , 2
  , SerialCommunicationCapsule_Actor::rtg_ports
  , 0
  , (const RTLocalBindingDescriptor *)0
  , 0
  , (const RTFieldDescriptor *)0
};

const RTStateId SerialCommunicationCapsule_Actor::rtg_parent_state[] =
{
	0
  , 1
};

const RTPortDescriptor SerialCommunicationCapsule_Actor::rtg_ports[] =
{
	{
		"SerialCommunication"
	  , (const char *)0
	  , &SerialProtocol::Base::rt_class
	  , RTOffsetOf( SerialCommunicationCapsule_Actor, SerialCommunicationCapsule_Actor::SerialCommunication )
	  , 1 // cardinality
	  , 1
	  , RTPortDescriptor::KindWired + RTPortDescriptor::NotificationDisabled + RTPortDescriptor::RegisterNotPermitted + RTPortDescriptor::VisibilityPublic
	}
  , {
		"timer"
	  , (const char *)0
	  , &Timing::Base::rt_class
	  , RTOffsetOf( SerialCommunicationCapsule_Actor, SerialCommunicationCapsule_Actor::timer )
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
