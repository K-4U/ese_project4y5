// {{{RME classifier 'Logical View::DomainLogic::AMaakCacao'

#if defined( PRAGMA ) && ! defined( PRAGMA_IMPLEMENTED )
#pragma implementation "AMaakCacao.h"
#endif

#include <RTSystem/WarmeDrankenAutomaatComponent.h>
#include <AMaakCacao.h>

// {{{RME tool 'OT::Cpp' property 'ImplementationPreface'
// {{{USR

// }}}USR
// }}}RME

static const RTRelayDescriptor rtg_relays[] =
{
	{
		"pUserInterface"
	  , &PUserInterface::Conjugate::rt_class
	  , 1 // cardinality
	}
  , {
		"pReservoir"
	  , &PReservoir::Conjugate::rt_class
	  , 1 // cardinality
	}
};

static RTActor * new_AMaakCacao_Actor( RTController * _rts, RTActorRef * _ref )
{
	return new AMaakCacao_Actor( _rts, _ref );
}

const RTActorClass AMaakCacao =
{
	(const RTActorClass *)0
  , "AMaakCacao"
  , (RTVersionId)0
  , 2
  , rtg_relays
  , new_AMaakCacao_Actor
};

static const char * const rtg_state_names[] =
{
	"TOP"
  , "wachtOpAanvraag"
  , "maakCacao"
  , "geefCacaopoeder"
  , "gevraagdOfErVoorraadIs"
  , "geefHeetWater"
  , "isErVoorraad"
};

#define SUPER RTActor

AMaakCacao_Actor::AMaakCacao_Actor( RTController * rtg_rts, RTActorRef * rtg_ref )
	: RTActor( rtg_rts, rtg_ref )
	, voorraad( false )
{
}

AMaakCacao_Actor::~AMaakCacao_Actor( void )
{
}

int AMaakCacao_Actor::_followInV( RTBindingEnd & rtg_end, int rtg_portId, int rtg_repIndex )
{
	switch( rtg_portId )
	{
	case 0:
		// pUserInterface
		if( rtg_repIndex < 1 )
		{
			rtg_end.port = &pUserInterface;
			rtg_end.index = rtg_repIndex;
			return 1;
		}
		break;
	case 1:
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

// {{{RME transition ':TOP:maakCacao:J4BADE3D80351:drankAangevraagd'
INLINE_METHODS void AMaakCacao_Actor::transition4_drankAangevraagd( const void * rtdata, PUserInterface::Conjugate * rtport )
{
	// {{{USR
	pReservoir.vraagVoorraad().send();
	// }}}USR
}
// }}}RME

// {{{RME transition ':TOP:maakCacao:gevraagdOfErVoorraadIs:J4BADF95100EB:voorraadAntwoord'
INLINE_METHODS void AMaakCacao_Actor::transition5_voorraadAntwoord( const bool * rtdata, PReservoir::Conjugate * rtport )
{
	// {{{USR
	voorraad = rtdata;
	// }}}USR
}
// }}}RME

// {{{RME transition ':TOP:maakCacao:isErVoorraad:True'
INLINE_METHODS void AMaakCacao_Actor::transition6_True( const bool * rtdata, PReservoir::Conjugate * rtport )
{
	// {{{USR
	timer.informIn(RTTimespec(3,0));
	pReservoir.startLeverProduct().send();
	// }}}USR
}
// }}}RME

// {{{RME transition ':TOP:maakCacao:geefCacaopoeder:J4BADFC2A01B6:cacaoToegevoegd'
INLINE_METHODS void AMaakCacao_Actor::transition8_cacaoToegevoegd( const void * rtdata, Timing::Base * rtport )
{
	// {{{USR
	timer.informIn(RTTimespec(3,0));
	pReservoir.stopLeverProduct().send();
	//klepsturing voor water ontbreekt nog
	cout << "klepsturing voor watertoevoegen hier opnemen" << endl;
	// }}}USR
}
// }}}RME

// {{{RME transition ':TOP:maakCacao:geefHeetWater:J4BAE0B370197:cacaoKlaar'
INLINE_METHODS void AMaakCacao_Actor::transition9_cacaoKlaar( const void * rtdata, Timing::Base * rtport )
{
	// {{{USR
	//klepsturing voor water ontbreekt nog
	cout << "klepsturing voor waterafsluiten hier opnemen" << endl;
	pUserInterface.drankGereed().send();
	// }}}USR
}
// }}}RME

INLINE_CHAINS void AMaakCacao_Actor::chain1_Initial( void )
{
	// transition ':TOP:Initial:Initial'
	rtgChainBegin( 1, "Initial" );
	rtgTransitionBegin();
	rtgTransitionEnd();
	enterState( 2 );
}

INLINE_CHAINS void AMaakCacao_Actor::chain2_maakCacao( void )
{
	// transition ':TOP:wachtOpAanvraag:J4BADE3D8034C:maakCacao'
	rtgChainBegin( 2, "maakCacao" );
	exitState( rtg_parent_state );
	rtgTransitionBegin();
	rtgTransitionEnd();
	enterState( 3 );
	// transition ':TOP:maakCacao:J4BADE3D80351:drankAangevraagd'
	rtgChainBegin( 3, "drankAangevraagd" );
	rtgTransitionBegin();
	transition4_drankAangevraagd( msg->data, (PUserInterface::Conjugate *)msg->sap() );
	rtgTransitionEnd();
	enterState( 5 );
}

INLINE_CHAINS void AMaakCacao_Actor::chain8_cacaoToegevoegd( void )
{
	// transition ':TOP:maakCacao:geefCacaopoeder:J4BADFC2A01B6:cacaoToegevoegd'
	rtgChainBegin( 4, "cacaoToegevoegd" );
	exitState( rtg_parent_state );
	rtgTransitionBegin();
	transition8_cacaoToegevoegd( msg->data, (Timing::Base *)msg->sap() );
	rtgTransitionEnd();
	enterState( 6 );
}

INLINE_CHAINS void AMaakCacao_Actor::chain5_voorraadAntwoord( void )
{
	// transition ':TOP:maakCacao:gevraagdOfErVoorraadIs:J4BADF95100EB:voorraadAntwoord'
	rtgChainBegin( 5, "voorraadAntwoord" );
	exitState( rtg_parent_state );
	rtgTransitionBegin();
	transition5_voorraadAntwoord( (const bool *)msg->data, (PReservoir::Conjugate *)msg->sap() );
	rtgTransitionEnd();
	if( choicePoint1_isErVoorraad( (const bool *)msg->data, (PReservoir::Conjugate *)msg->sap() ) )
		chain6_True();
	else
		chain7_False();
}

// {{{RME choicePoint ':TOP:maakCacao:isErVoorraad'
INLINE_METHODS int AMaakCacao_Actor::choicePoint1_isErVoorraad( const bool * rtdata, PReservoir::Conjugate * rtport )
{
	// {{{USR
	voorraad;
	// }}}USR
}
// }}}RME

INLINE_CHAINS void AMaakCacao_Actor::chain6_True( void )
{
	// transition ':TOP:maakCacao:isErVoorraad:True'
	rtgChainBegin( 7, "True" );
	rtgTransitionBegin();
	transition6_True( (const bool *)msg->data, (PReservoir::Conjugate *)msg->sap() );
	rtgTransitionEnd();
	enterState( 4 );
}

INLINE_CHAINS void AMaakCacao_Actor::chain7_False( void )
{
	// transition ':TOP:maakCacao:isErVoorraad:False'
	rtgChainBegin( 7, "False" );
	rtgTransitionBegin();
	rtgTransitionEnd();
	// transition ':TOP:maakCacao:klaar:meldResultaat'
	rtgChainBegin( 3, "meldResultaat" );
	exitState( rtg_parent_state );
	rtgTransitionBegin();
	rtgTransitionEnd();
	enterState( 2 );
}

INLINE_CHAINS void AMaakCacao_Actor::chain9_cacaoKlaar( void )
{
	// transition ':TOP:maakCacao:geefHeetWater:J4BAE0B370197:cacaoKlaar'
	rtgChainBegin( 6, "cacaoKlaar" );
	exitState( rtg_parent_state );
	rtgTransitionBegin();
	transition9_cacaoKlaar( msg->data, (Timing::Base *)msg->sap() );
	rtgTransitionEnd();
	// transition ':TOP:maakCacao:klaar:meldResultaat'
	rtgChainBegin( 3, "meldResultaat" );
	exitState( rtg_parent_state );
	rtgTransitionBegin();
	rtgTransitionEnd();
	enterState( 2 );
}

void AMaakCacao_Actor::rtsBehavior( int signalIndex, int portIndex )
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
			// {{{RME state ':TOP:wachtOpAanvraag'
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
				// {{{RME port 'pUserInterface'
				switch( signalIndex )
				{
				case PUserInterface::Conjugate::rti_cacao:
					chain2_maakCacao();
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
			// {{{RME state ':TOP:maakCacao'
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
		case 4:
			// {{{RME state ':TOP:maakCacao:geefCacaopoeder'
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
			case 3:
				// {{{RME port 'timer'
				switch( signalIndex )
				{
				case Timing::Base::rti_timeout:
					chain8_cacaoToegevoegd();
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
		case 5:
			// {{{RME state ':TOP:maakCacao:gevraagdOfErVoorraadIs'
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
			case 2:
				// {{{RME port 'pReservoir'
				switch( signalIndex )
				{
				case PReservoir::Conjugate::rti_antwoordVoorraad:
					chain5_voorraadAntwoord();
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
		case 6:
			// {{{RME state ':TOP:maakCacao:geefHeetWater'
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
			case 3:
				// {{{RME port 'timer'
				switch( signalIndex )
				{
				case Timing::Base::rti_timeout:
					chain9_cacaoKlaar();
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

const RTActor_class * AMaakCacao_Actor::getActorData( void ) const
{
	return &AMaakCacao_Actor::rtg_class;
}

const RTActor_class AMaakCacao_Actor::rtg_class =
{
	(const RTActor_class *)0
  , rtg_state_names
  , 6
  , AMaakCacao_Actor::rtg_parent_state
  , &AMaakCacao
  , 0
  , (const RTComponentDescriptor *)0
  , 3
  , AMaakCacao_Actor::rtg_ports
  , 0
  , (const RTLocalBindingDescriptor *)0
  , 1
  , AMaakCacao_Actor::rtg_AMaakCacao_fields
};

const RTStateId AMaakCacao_Actor::rtg_parent_state[] =
{
	0
  , 1
  , 1
  , 3
  , 3
  , 3
};

const RTPortDescriptor AMaakCacao_Actor::rtg_ports[] =
{
	{
		"pUserInterface"
	  , (const char *)0
	  , &PUserInterface::Conjugate::rt_class
	  , RTOffsetOf( AMaakCacao_Actor, AMaakCacao_Actor::pUserInterface )
	  , 1 // cardinality
	  , 1
	  , RTPortDescriptor::KindWired + RTPortDescriptor::NotificationDisabled + RTPortDescriptor::RegisterNotPermitted + RTPortDescriptor::VisibilityPublic
	}
  , {
		"pReservoir"
	  , (const char *)0
	  , &PReservoir::Conjugate::rt_class
	  , RTOffsetOf( AMaakCacao_Actor, AMaakCacao_Actor::pReservoir )
	  , 1 // cardinality
	  , 2
	  , RTPortDescriptor::KindWired + RTPortDescriptor::NotificationDisabled + RTPortDescriptor::RegisterNotPermitted + RTPortDescriptor::VisibilityPublic
	}
  , {
		"timer"
	  , (const char *)0
	  , &Timing::Base::rt_class
	  , RTOffsetOf( AMaakCacao_Actor, AMaakCacao_Actor::timer )
	  , 1 // cardinality
	  , 3
	  , RTPortDescriptor::KindSpecial + RTPortDescriptor::NotificationDisabled + RTPortDescriptor::RegisterNotPermitted + RTPortDescriptor::VisibilityProtected
	}
};

const RTFieldDescriptor AMaakCacao_Actor::rtg_AMaakCacao_fields[] =
{
	// {{{RME classAttribute 'voorraad'
	{
		"voorraad"
	  , RTOffsetOf( AMaakCacao_Actor, voorraad )
		// {{{RME tool 'OT::CppTargetRTS' property 'TypeDescriptor'
	  , &RTType_bool
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
