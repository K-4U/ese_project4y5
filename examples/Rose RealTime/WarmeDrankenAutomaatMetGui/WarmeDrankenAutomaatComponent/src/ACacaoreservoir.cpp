// {{{RME classifier 'Logical View::DomainLogic::ACacaoreservoir'

#if defined( PRAGMA ) && ! defined( PRAGMA_IMPLEMENTED )
#pragma implementation "ACacaoreservoir.h"
#endif

#include <RTSystem/WarmeDrankenAutomaatComponent.h>
#include <ACacaoreservoir.h>

// {{{RME tool 'OT::Cpp' property 'ImplementationPreface'
// {{{USR

// }}}USR
// }}}RME

static const RTRelayDescriptor rtg_relays[] =
{
	{
		"pReservoir"
	  , &PReservoir::Base::rt_class
	  , 1 // cardinality
	}
};

static RTActor * new_ACacaoreservoir_Actor( RTController * _rts, RTActorRef * _ref )
{
	return new ACacaoreservoir_Actor( _rts, _ref );
}

const RTActorClass ACacaoreservoir =
{
	(const RTActorClass *)0
  , "ACacaoreservoir"
  , (RTVersionId)0
  , 1
  , rtg_relays
  , new_ACacaoreservoir_Actor
};

static const char * const rtg_state_names[] =
{
	"TOP"
  , "klepDicht"
  , "klepOpen"
};

#define SUPER RTActor

ACacaoreservoir_Actor::ACacaoreservoir_Actor( RTController * rtg_rts, RTActorRef * rtg_ref )
	: RTActor( rtg_rts, rtg_ref )
{
}

ACacaoreservoir_Actor::~ACacaoreservoir_Actor( void )
{
}

// {{{RME operation 'setKlep(bool)'
void ACacaoreservoir_Actor::setKlep( bool position )
{
	// {{{USR
	klep.setKlep(position);
	// }}}USR
}
// }}}RME

// {{{RME operation 'getVoorraad()'
bool ACacaoreservoir_Actor::getVoorraad( void )
{
	// {{{USR
	return true;
	// }}}USR
}
// }}}RME

int ACacaoreservoir_Actor::_followInV( RTBindingEnd & rtg_end, int rtg_portId, int rtg_repIndex )
{
	switch( rtg_portId )
	{
	case 0:
		// pReservoir
		if( rtg_repIndex < 1 )
		{
			rtg_end.port = &pReservoir;
			rtg_end.index = rtg_repIndex;
			return 1;
		}
		break;
	default:
		break;
	}
	return RTActor::_followInV( rtg_end, rtg_portId, rtg_repIndex );
}

// {{{RME transition ':TOP:J4BADEF0E0148:geefVoorraadTerug'
INLINE_METHODS void ACacaoreservoir_Actor::transition2_geefVoorraadTerug( const void * rtdata, PReservoir::Base * rtport )
{
	// {{{USR
	pReservoir.antwoordVoorraad(getVoorraad()).send();
	// }}}USR
}
// }}}RME

// {{{RME transition ':TOP:klepDicht:J4BADEF2C0178:klepOpen'
INLINE_METHODS void ACacaoreservoir_Actor::transition3_klepOpen( const void * rtdata, PReservoir::Base * rtport )
{
	// {{{USR
	klep.setKlep(true);
	// }}}USR
}
// }}}RME

// {{{RME transition ':TOP:klepOpen:J4BADEF4B03BA:klepDicht'
INLINE_METHODS void ACacaoreservoir_Actor::transition4_klepDicht( const void * rtdata, PReservoir::Base * rtport )
{
	// {{{USR
	klep.setKlep(false);
	// }}}USR
}
// }}}RME

INLINE_CHAINS void ACacaoreservoir_Actor::chain1_Initial( void )
{
	// transition ':TOP:Initial:Initial'
	rtgChainBegin( 1, "Initial" );
	rtgTransitionBegin();
	rtgTransitionEnd();
	enterState( 2 );
}

INLINE_CHAINS void ACacaoreservoir_Actor::chain2_geefVoorraadTerug( void )
{
	// transition ':TOP:J4BADEF0E0148:geefVoorraadTerug'
	rtgChainBegin( 1, "geefVoorraadTerug" );
	exitToChainState( 1, rtg_parent_state );
	rtgTransitionBegin();
	transition2_geefVoorraadTerug( msg->data, (PReservoir::Base *)msg->sap() );
	rtgTransitionEnd();
	processHistory();
}

INLINE_CHAINS void ACacaoreservoir_Actor::chain3_klepOpen( void )
{
	// transition ':TOP:klepDicht:J4BADEF2C0178:klepOpen'
	rtgChainBegin( 2, "klepOpen" );
	exitState( rtg_parent_state );
	rtgTransitionBegin();
	transition3_klepOpen( msg->data, (PReservoir::Base *)msg->sap() );
	rtgTransitionEnd();
	enterState( 3 );
}

INLINE_CHAINS void ACacaoreservoir_Actor::chain4_klepDicht( void )
{
	// transition ':TOP:klepOpen:J4BADEF4B03BA:klepDicht'
	rtgChainBegin( 3, "klepDicht" );
	exitState( rtg_parent_state );
	rtgTransitionBegin();
	transition4_klepDicht( msg->data, (PReservoir::Base *)msg->sap() );
	rtgTransitionEnd();
	enterState( 2 );
}

void ACacaoreservoir_Actor::rtsBehavior( int signalIndex, int portIndex )
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
			case 1:
				// {{{RME port 'pReservoir'
				switch( signalIndex )
				{
				case PReservoir::Base::rti_vraagVoorraad:
					chain2_geefVoorraadTerug();
					return;
				default:
					break;
				}
				break;
				// }}}RME
			default:
				break;
			}
			unexpectedMessage();
			return;
			// }}}RME
		case 2:
			// {{{RME state ':TOP:klepDicht'
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
				// {{{RME port 'pReservoir'
				switch( signalIndex )
				{
				case PReservoir::Base::rti_startLeverProduct:
					chain3_klepOpen();
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
		case 3:
			// {{{RME state ':TOP:klepOpen'
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
				// {{{RME port 'pReservoir'
				switch( signalIndex )
				{
				case PReservoir::Base::rti_stopLeverProduct:
					chain4_klepDicht();
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

const RTActor_class * ACacaoreservoir_Actor::getActorData( void ) const
{
	return &ACacaoreservoir_Actor::rtg_class;
}

const RTActor_class ACacaoreservoir_Actor::rtg_class =
{
	(const RTActor_class *)0
  , rtg_state_names
  , 3
  , ACacaoreservoir_Actor::rtg_parent_state
  , &ACacaoreservoir
  , 0
  , (const RTComponentDescriptor *)0
  , 1
  , ACacaoreservoir_Actor::rtg_ports
  , 0
  , (const RTLocalBindingDescriptor *)0
  , 1
  , ACacaoreservoir_Actor::rtg_ACacaoreservoir_fields
};

const RTStateId ACacaoreservoir_Actor::rtg_parent_state[] =
{
	0
  , 1
  , 1
};

const RTPortDescriptor ACacaoreservoir_Actor::rtg_ports[] =
{
	{
		"pReservoir"
	  , (const char *)0
	  , &PReservoir::Base::rt_class
	  , RTOffsetOf( ACacaoreservoir_Actor, ACacaoreservoir_Actor::pReservoir )
	  , 1 // cardinality
	  , 1
	  , RTPortDescriptor::KindWired + RTPortDescriptor::NotificationDisabled + RTPortDescriptor::RegisterNotPermitted + RTPortDescriptor::VisibilityPublic
	}
};

const RTFieldDescriptor ACacaoreservoir_Actor::rtg_ACacaoreservoir_fields[] =
{
	// {{{RME classAttribute 'klep'
	{
		"klep"
	  , RTOffsetOf( ACacaoreservoir_Actor, klep )
		// {{{RME tool 'OT::CppTargetRTS' property 'TypeDescriptor'
	  , &RTType_CKlep
		// }}}RME
		// {{{RME tool 'OT::CppTargetRTS' property 'GenerateTypeModifier'
	  , (const RTTypeModifier *)0
		// }}}RME
	}
	// }}}RME
};
#undef SUPER

// {{{RME tool 'OT::Cpp' property 'ImplementationEnding'
// {{{USR

// }}}USR
// }}}RME

// }}}RME
