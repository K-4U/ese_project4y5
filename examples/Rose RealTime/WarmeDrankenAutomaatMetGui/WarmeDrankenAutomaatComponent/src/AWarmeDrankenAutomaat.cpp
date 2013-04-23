// {{{RME classifier 'Logical View::DomainLogic::AWarmeDrankenAutomaat'

#if defined( PRAGMA ) && ! defined( PRAGMA_IMPLEMENTED )
#pragma implementation "AWarmeDrankenAutomaat.h"
#endif

#include <RTSystem/WarmeDrankenAutomaatComponent.h>
#include <AWarmeDrankenAutomaat.h>
#include <PReservoir.h>
#include <PUserInterface.h>
extern const RTActorClass ABesturingseenheid;
extern const RTActorClass ACacaoreservoir;
extern const RTActorClass AUserInterface;

// {{{RME tool 'OT::Cpp' property 'ImplementationPreface'
// {{{USR

// }}}USR
// }}}RME

static RTActor * new_AWarmeDrankenAutomaat_Actor( RTController * _rts, RTActorRef * _ref )
{
	return new AWarmeDrankenAutomaat_Actor( _rts, _ref );
}

const RTActorClass AWarmeDrankenAutomaat =
{
	(const RTActorClass *)0
  , "AWarmeDrankenAutomaat"
  , (RTVersionId)0
  , 0
  , (const RTRelayDescriptor *)0
  , new_AWarmeDrankenAutomaat_Actor
};

static const char * const rtg_state_names[] =
{
	"TOP"
};

static const RTInterfaceDescriptor rtg_interfaces_aBesturingseenheid[] =
{
	{
		"pReservoir"
	  , 1
	}
  , {
		"pUserInterface"
	  , 1
	}
};

static const RTBindingDescriptor rtg_bindings_aBesturingseenheid[] =
{
	{
		0
	  , &PReservoir::Base::rt_class
	}
  , {
		1
	  , &PUserInterface::Base::rt_class
	}
};

static const RTInterfaceDescriptor rtg_interfaces_aCacaoreservoir[] =
{
	{
		"pReservoir"
	  , 1
	}
};

static const RTBindingDescriptor rtg_bindings_aCacaoreservoir[] =
{
	{
		0
	  , &PReservoir::Conjugate::rt_class
	}
};

static const RTInterfaceDescriptor rtg_interfaces_aUserInterface[] =
{
	{
		"pUserInterface"
	  , 1
	}
};

static const RTBindingDescriptor rtg_bindings_aUserInterface[] =
{
	{
		0
	  , &PUserInterface::Conjugate::rt_class
	}
};

#define SUPER RTActor

AWarmeDrankenAutomaat_Actor::AWarmeDrankenAutomaat_Actor( RTController * rtg_rts, RTActorRef * rtg_ref )
	: RTActor( rtg_rts, rtg_ref )
{
}

AWarmeDrankenAutomaat_Actor::~AWarmeDrankenAutomaat_Actor( void )
{
}

int AWarmeDrankenAutomaat_Actor::_followOutV( RTBindingEnd & rtg_end, int rtg_compId, int rtg_portId, int rtg_repIndex )
{
	switch( rtg_compId )
	{
	case 1:
		// aBesturingseenheid
		switch( rtg_portId )
		{
		case 0:
			// pReservoir
			if( rtg_repIndex < 1 )
			{
				// aCacaoreservoir/pReservoir
				return aCacaoreservoir._followIn( rtg_end, 0, rtg_repIndex );
			}
			break;
		case 1:
			// pUserInterface
			if( rtg_repIndex < 1 )
			{
				// aUserInterface/pUserInterface
				return aUserInterface._followIn( rtg_end, 0, rtg_repIndex );
			}
			break;
		default:
			break;
		}
	case 2:
		// aCacaoreservoir
		switch( rtg_portId )
		{
		case 0:
			// pReservoir
			if( rtg_repIndex < 1 )
			{
				// aBesturingseenheid/pReservoir
				return aBesturingseenheid._followIn( rtg_end, 0, rtg_repIndex );
			}
			break;
		default:
			break;
		}
	case 3:
		// aUserInterface
		switch( rtg_portId )
		{
		case 0:
			// pUserInterface
			if( rtg_repIndex < 1 )
			{
				// aBesturingseenheid/pUserInterface
				return aBesturingseenheid._followIn( rtg_end, 1, rtg_repIndex );
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

void AWarmeDrankenAutomaat_Actor::rtsBehavior( int signalIndex, int portIndex )
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

const RTActor_class * AWarmeDrankenAutomaat_Actor::getActorData( void ) const
{
	return &AWarmeDrankenAutomaat_Actor::rtg_class;
}

const RTActor_class AWarmeDrankenAutomaat_Actor::rtg_class =
{
	(const RTActor_class *)0
  , rtg_state_names
  , 1
  , AWarmeDrankenAutomaat_Actor::rtg_parent_state
  , &AWarmeDrankenAutomaat
  , 3
  , AWarmeDrankenAutomaat_Actor::rtg_capsule_roles
  , 0
  , (const RTPortDescriptor *)0
  , 0
  , (const RTLocalBindingDescriptor *)0
  , 0
  , (const RTFieldDescriptor *)0
};

const RTStateId AWarmeDrankenAutomaat_Actor::rtg_parent_state[] =
{
	0
};

const RTComponentDescriptor AWarmeDrankenAutomaat_Actor::rtg_capsule_roles[] =
{
	{
		"aBesturingseenheid"
	  , &ABesturingseenheid
	  , RTOffsetOf( AWarmeDrankenAutomaat_Actor, aBesturingseenheid )
	  , 1
	  , RTComponentDescriptor::Fixed
	  , 1
	  , 1 // cardinality
	  , 2
	  , rtg_interfaces_aBesturingseenheid
	  , 2
	  , rtg_bindings_aBesturingseenheid
	}
  , {
		"aCacaoreservoir"
	  , &ACacaoreservoir
	  , RTOffsetOf( AWarmeDrankenAutomaat_Actor, aCacaoreservoir )
	  , 2
	  , RTComponentDescriptor::Fixed
	  , 1
	  , 1 // cardinality
	  , 1
	  , rtg_interfaces_aCacaoreservoir
	  , 1
	  , rtg_bindings_aCacaoreservoir
	}
  , {
		"aUserInterface"
	  , &AUserInterface
	  , RTOffsetOf( AWarmeDrankenAutomaat_Actor, aUserInterface )
	  , 3
	  , RTComponentDescriptor::Fixed
	  , 1
	  , 1 // cardinality
	  , 1
	  , rtg_interfaces_aUserInterface
	  , 1
	  , rtg_bindings_aUserInterface
	}
};

#undef SUPER

// {{{RME tool 'OT::Cpp' property 'ImplementationEnding'
// {{{USR

// }}}USR
// }}}RME

// }}}RME
