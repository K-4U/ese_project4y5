// {{{RME classifier 'Logical View::DomainLogic::ABesturingseenheid'

#if defined( PRAGMA ) && ! defined( PRAGMA_IMPLEMENTED )
#pragma implementation "ABesturingseenheid.h"
#endif

#include <RTSystem/WarmeDrankenAutomaatComponent.h>
#include <ABesturingseenheid.h>
#include <PReservoir.h>
#include <PUserInterface.h>
extern const RTActorClass AMaakCacao;

// {{{RME tool 'OT::Cpp' property 'ImplementationPreface'
// {{{USR

// }}}USR
// }}}RME

static const RTRelayDescriptor rtg_relays[] =
{
	{
		"pReservoir"
	  , &PReservoir::Conjugate::rt_class
	  , 1 // cardinality
	}
  , {
		"pUserInterface"
	  , &PUserInterface::Conjugate::rt_class
	  , 1 // cardinality
	}
};

static RTActor * new_ABesturingseenheid_Actor( RTController * _rts, RTActorRef * _ref )
{
	return new ABesturingseenheid_Actor( _rts, _ref );
}

const RTActorClass ABesturingseenheid =
{
	(const RTActorClass *)0
  , "ABesturingseenheid"
  , (RTVersionId)0
  , 2
  , rtg_relays
  , new_ABesturingseenheid_Actor
};

static const char * const rtg_state_names[] =
{
	"TOP"
};

static const RTInterfaceDescriptor rtg_interfaces_aMaakCacao[] =
{
	{
		"pUserInterface"
	  , 1
	}
  , {
		"pReservoir"
	  , 1
	}
};

static const RTBindingDescriptor rtg_bindings_aMaakCacao[] =
{
	{
		0
	  , &PUserInterface::Base::rt_class
	}
  , {
		1
	  , &PReservoir::Base::rt_class
	}
};

#define SUPER RTActor

ABesturingseenheid_Actor::ABesturingseenheid_Actor( RTController * rtg_rts, RTActorRef * rtg_ref )
	: RTActor( rtg_rts, rtg_ref )
{
}

ABesturingseenheid_Actor::~ABesturingseenheid_Actor( void )
{
}

int ABesturingseenheid_Actor::_followInV( RTBindingEnd & rtg_end, int rtg_portId, int rtg_repIndex )
{
	switch( rtg_portId )
	{
	case 0:
		// pReservoir
		if( rtg_repIndex < 1 )
		{
			// aMaakCacao/pReservoir
			return aMaakCacao._followIn( rtg_end, 1, rtg_repIndex );
		}
		break;
	case 1:
		// pUserInterface
		if( rtg_repIndex < 1 )
		{
			// aMaakCacao/pUserInterface
			return aMaakCacao._followIn( rtg_end, 0, rtg_repIndex );
		}
		break;
	default:
		break;
	}
	return RTActor::_followInV( rtg_end, rtg_portId, rtg_repIndex );
}

int ABesturingseenheid_Actor::_followOutV( RTBindingEnd & rtg_end, int rtg_compId, int rtg_portId, int rtg_repIndex )
{
	switch( rtg_compId )
	{
	case 1:
		// aMaakCacao
		switch( rtg_portId )
		{
		case 0:
			// pUserInterface
			if( rtg_repIndex < 1 )
			{
				// pUserInterface
				return _followOut( rtg_end, 1, rtg_repIndex );
			}
			break;
		case 1:
			// pReservoir
			if( rtg_repIndex < 1 )
			{
				// pReservoir
				return _followOut( rtg_end, 0, rtg_repIndex );
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

void ABesturingseenheid_Actor::rtsBehavior( int signalIndex, int portIndex )
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

const RTActor_class * ABesturingseenheid_Actor::getActorData( void ) const
{
	return &ABesturingseenheid_Actor::rtg_class;
}

const RTActor_class ABesturingseenheid_Actor::rtg_class =
{
	(const RTActor_class *)0
  , rtg_state_names
  , 1
  , ABesturingseenheid_Actor::rtg_parent_state
  , &ABesturingseenheid
  , 1
  , ABesturingseenheid_Actor::rtg_capsule_roles
  , 0
  , (const RTPortDescriptor *)0
  , 0
  , (const RTLocalBindingDescriptor *)0
  , 0
  , (const RTFieldDescriptor *)0
};

const RTStateId ABesturingseenheid_Actor::rtg_parent_state[] =
{
	0
};

const RTComponentDescriptor ABesturingseenheid_Actor::rtg_capsule_roles[] =
{
	{
		"aMaakCacao"
	  , &AMaakCacao
	  , RTOffsetOf( ABesturingseenheid_Actor, aMaakCacao )
	  , 1
	  , RTComponentDescriptor::Fixed
	  , 1
	  , 1 // cardinality
	  , 2
	  , rtg_interfaces_aMaakCacao
	  , 2
	  , rtg_bindings_aMaakCacao
	}
};

#undef SUPER

// {{{RME tool 'OT::Cpp' property 'ImplementationEnding'
// {{{USR

// }}}USR
// }}}RME

// }}}RME
