// {{{RME classifier 'Logical View::DomainLogic::ACacaoreservoir'

#ifndef ACacaoreservoir_H
#define ACacaoreservoir_H

#ifdef PRAGMA
#pragma interface "ACacaoreservoir.h"
#endif

#include <RTSystem/WarmeDrankenAutomaatComponent.h>
#include <CKlep.h>
#include <PReservoir.h>

// {{{RME tool 'OT::Cpp' property 'HeaderPreface'
// {{{USR

// }}}USR
// }}}RME

extern const RTActorClass ACacaoreservoir;

#define SUPER RTActor
class ACacaoreservoir_Actor : public RTActor
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
	// {{{RME classAttribute 'klep'
	CKlep klep;
	// }}}RME

protected:
	// {{{RME port 'pReservoir'
	PReservoir::Base pReservoir;
	// }}}RME

public:
	ACacaoreservoir_Actor( RTController * rtg_rts, RTActorRef * rtg_ref );
	virtual ~ACacaoreservoir_Actor( void );

protected:
	// {{{RME operation 'setKlep(bool)'
	void setKlep( bool position = false );
	// }}}RME
	// {{{RME operation 'getVoorraad()'
	bool getVoorraad( void );
	// }}}RME

public:
	virtual int _followInV( RTBindingEnd & rtg_end, int rtg_portId, int rtg_repIndex );

protected:
	// {{{RME transition ':TOP:J4BADEF0E0148:geefVoorraadTerug'
	INLINE_METHODS void transition2_geefVoorraadTerug( const void * rtdata, PReservoir::Base * rtport );
	// }}}RME
	// {{{RME transition ':TOP:klepDicht:J4BADEF2C0178:klepOpen'
	INLINE_METHODS void transition3_klepOpen( const void * rtdata, PReservoir::Base * rtport );
	// }}}RME
	// {{{RME transition ':TOP:klepOpen:J4BADEF4B03BA:klepDicht'
	INLINE_METHODS void transition4_klepDicht( const void * rtdata, PReservoir::Base * rtport );
	// }}}RME

private:
	INLINE_CHAINS void chain1_Initial( void );
	INLINE_CHAINS void chain2_geefVoorraadTerug( void );
	INLINE_CHAINS void chain3_klepOpen( void );
	INLINE_CHAINS void chain4_klepDicht( void );

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
	static const RTFieldDescriptor rtg_ACacaoreservoir_fields[];
};
#undef SUPER

// {{{RME tool 'OT::Cpp' property 'HeaderEnding'
// {{{USR

// }}}USR
// }}}RME

#endif /* ACacaoreservoir_H */

// }}}RME
