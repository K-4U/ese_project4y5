// {{{RME classifier 'Logical View::DomainLogic::AMaakCacao'

#ifndef AMaakCacao_H
#define AMaakCacao_H

#ifdef PRAGMA
#pragma interface "AMaakCacao.h"
#endif

#include <RTSystem/WarmeDrankenAutomaatComponent.h>
#include <PReservoir.h>
#include <PUserInterface.h>

// {{{RME tool 'OT::Cpp' property 'HeaderPreface'
// {{{USR

// }}}USR
// }}}RME

extern const RTActorClass AMaakCacao;

#define SUPER RTActor
class AMaakCacao_Actor : public RTActor
{
public:
	// {{{RME tool 'OT::Cpp' property 'PublicDeclarations'
	// {{{USR

	// }}}USR
	// }}}RME

protected:
	// {{{RME tool 'OT::Cpp' property 'ProtectedDeclarations'
	// {{{USR

	// }}}USR
	// }}}RME

private:
	// {{{RME tool 'OT::Cpp' property 'PrivateDeclarations'
	// {{{USR

	// }}}USR
	// }}}RME
	// {{{RME classAttribute 'voorraad'
	bool voorraad;
	// }}}RME

protected:
	// {{{RME port 'pUserInterface'
	PUserInterface::Conjugate pUserInterface;
	// }}}RME
	// {{{RME port 'pReservoir'
	PReservoir::Conjugate pReservoir;
	// }}}RME
	// {{{RME port 'timer'
	Timing::Base timer;
	// }}}RME

public:
	AMaakCacao_Actor( RTController * rtg_rts, RTActorRef * rtg_ref );
	virtual ~AMaakCacao_Actor( void );
	virtual int _followInV( RTBindingEnd & rtg_end, int rtg_portId, int rtg_repIndex );

protected:
	// {{{RME transition ':TOP:maakCacao:J4BADE3D80351:drankAangevraagd'
	INLINE_METHODS void transition4_drankAangevraagd( const void * rtdata, PUserInterface::Conjugate * rtport );
	// }}}RME
	// {{{RME transition ':TOP:maakCacao:gevraagdOfErVoorraadIs:J4BADF95100EB:voorraadAntwoord'
	INLINE_METHODS void transition5_voorraadAntwoord( const bool * rtdata, PReservoir::Conjugate * rtport );
	// }}}RME
	// {{{RME transition ':TOP:maakCacao:isErVoorraad:True'
	INLINE_METHODS void transition6_True( const bool * rtdata, PReservoir::Conjugate * rtport );
	// }}}RME
	// {{{RME transition ':TOP:maakCacao:geefCacaopoeder:J4BADFC2A01B6:cacaoToegevoegd'
	INLINE_METHODS void transition8_cacaoToegevoegd( const void * rtdata, Timing::Base * rtport );
	// }}}RME
	// {{{RME transition ':TOP:maakCacao:geefHeetWater:J4BAE0B370197:cacaoKlaar'
	INLINE_METHODS void transition9_cacaoKlaar( const void * rtdata, Timing::Base * rtport );
	// }}}RME

private:
	INLINE_CHAINS void chain1_Initial( void );
	INLINE_CHAINS void chain2_maakCacao( void );
	INLINE_CHAINS void chain8_cacaoToegevoegd( void );
	INLINE_CHAINS void chain5_voorraadAntwoord( void );

protected:
	// {{{RME choicePoint ':TOP:maakCacao:isErVoorraad'
	INLINE_METHODS int choicePoint1_isErVoorraad( const bool * rtdata, PReservoir::Conjugate * rtport );
	// }}}RME

private:
	INLINE_CHAINS void chain6_True( void );
	INLINE_CHAINS void chain7_False( void );
	INLINE_CHAINS void chain9_cacaoKlaar( void );

public:
	virtual void rtsBehavior( int signalIndex, int portIndex );
	virtual const RTActor_class * getActorData( void ) const;

protected:
	static const RTActor_class rtg_class;

public:
	static const RTStateId rtg_parent_state[];

private:
	static const RTPortDescriptor rtg_ports[];

public:
	static const RTFieldDescriptor rtg_AMaakCacao_fields[];
};
#undef SUPER

// {{{RME tool 'OT::Cpp' property 'HeaderEnding'
// {{{USR

// }}}USR
// }}}RME

#endif /* AMaakCacao_H */

// }}}RME
