// {{{RME classifier 'Logical View::UserInterface::AGui'

#if defined( PRAGMA ) && ! defined( PRAGMA_IMPLEMENTED )
#pragma implementation "AGui.h"
#endif

#include <RTSystem/WarmeDrankenAutomaatComponent.h>
#include <AGui.h>

// {{{RME tool 'OT::Cpp' property 'ImplementationPreface'
// {{{USR

// }}}USR
// }}}RME

static const RTRelayDescriptor rtg_relays[] =
{
	{
		"pGuiInit"
	  , &PGuiInit::Base::rt_class
	  , 1 // cardinality
	}
};

static RTActor * new_AGui_Actor( RTController * _rts, RTActorRef * _ref )
{
	return new AGui_Actor( _rts, _ref );
}

const RTActorClass AGui =
{
	(const RTActorClass *)0
  , "AGui"
  , (RTVersionId)0
  , 1
  , rtg_relays
  , new_AGui_Actor
};

static const char * const rtg_state_names[] =
{
	"TOP"
  , "waitForInit"
};

#define SUPER RTActor

AGui_Actor::AGui_Actor( RTController * rtg_rts, RTActorRef * rtg_ref )
	: RTActor( rtg_rts, rtg_ref )
{
}

AGui_Actor::~AGui_Actor( void )
{
}

int AGui_Actor::_followInV( RTBindingEnd & rtg_end, int rtg_portId, int rtg_repIndex )
{
	switch( rtg_portId )
	{
	case 0:
		// pGuiInit
		if( rtg_repIndex < 1 )
		{
			rtg_end.port = &pGuiInit;
			rtg_end.index = rtg_repIndex;
			return 1;
		}
		break;
	default:
		break;
	}
	return RTActor::_followInV( rtg_end, rtg_portId, rtg_repIndex );
}

// {{{RME transition ':TOP:waitForInit:J4BB86BDA03DA:initReceived'
INLINE_METHODS void AGui_Actor::transition2_initReceived( const void * rtdata, PGuiInit::Base * rtport )
{
	// {{{USR
	//Hier kan eventueel de GUI worden gestart
	//Op dit moment wordt uitgegaan van een externe GUI
	//met gebruik maken van een socket
	// }}}USR
}
// }}}RME

INLINE_CHAINS void AGui_Actor::chain1_Initial( void )
{
	// transition ':TOP:Initial:Initial'
	rtgChainBegin( 1, "Initial" );
	rtgTransitionBegin();
	rtgTransitionEnd();
	enterState( 2 );
}

INLINE_CHAINS void AGui_Actor::chain2_initReceived( void )
{
	// transition ':TOP:waitForInit:J4BB86BDA03DA:initReceived'
	rtgChainBegin( 2, "initReceived" );
	exitState( rtg_parent_state );
	rtgTransitionBegin();
	transition2_initReceived( msg->data, (PGuiInit::Base *)msg->sap() );
	rtgTransitionEnd();
	enterState( 2 );
}

void AGui_Actor::rtsBehavior( int signalIndex, int portIndex )
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
			// {{{RME state ':TOP:waitForInit'
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
				// {{{RME port 'pGuiInit'
				switch( signalIndex )
				{
				case PGuiInit::Base::rti_init:
					chain2_initReceived();
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

const RTActor_class * AGui_Actor::getActorData( void ) const
{
	return &AGui_Actor::rtg_class;
}

const RTActor_class AGui_Actor::rtg_class =
{
	(const RTActor_class *)0
  , rtg_state_names
  , 2
  , AGui_Actor::rtg_parent_state
  , &AGui
  , 0
  , (const RTComponentDescriptor *)0
  , 1
  , AGui_Actor::rtg_ports
  , 0
  , (const RTLocalBindingDescriptor *)0
  , 0
  , (const RTFieldDescriptor *)0
};

const RTStateId AGui_Actor::rtg_parent_state[] =
{
	0
  , 1
};

const RTPortDescriptor AGui_Actor::rtg_ports[] =
{
	{
		"pGuiInit"
	  , (const char *)0
	  , &PGuiInit::Base::rt_class
	  , RTOffsetOf( AGui_Actor, AGui_Actor::pGuiInit )
	  , 1 // cardinality
	  , 1
	  , RTPortDescriptor::KindWired + RTPortDescriptor::NotificationDisabled + RTPortDescriptor::RegisterNotPermitted + RTPortDescriptor::VisibilityPublic
	}
};

#undef SUPER

// {{{RME tool 'OT::Cpp' property 'ImplementationEnding'
// {{{USR

// }}}USR
// }}}RME

// }}}RME
