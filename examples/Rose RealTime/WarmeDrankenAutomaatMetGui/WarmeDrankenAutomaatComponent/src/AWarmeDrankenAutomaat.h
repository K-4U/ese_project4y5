// {{{RME classifier 'Logical View::DomainLogic::AWarmeDrankenAutomaat'

#ifndef AWarmeDrankenAutomaat_H
#define AWarmeDrankenAutomaat_H

#ifdef PRAGMA
#pragma interface "AWarmeDrankenAutomaat.h"
#endif

#include <RTSystem/WarmeDrankenAutomaatComponent.h>

// {{{RME tool 'OT::Cpp' property 'HeaderPreface'
// {{{USR

// }}}USR
// }}}RME

extern const RTActorClass AWarmeDrankenAutomaat;

#define SUPER RTActor
class AWarmeDrankenAutomaat_Actor : public RTActor
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

protected:
	// {{{RME capsuleRole 'aBesturingseenheid'
	RTActorRef aBesturingseenheid;
	// }}}RME
	// {{{RME capsuleRole 'aCacaoreservoir'
	RTActorRef aCacaoreservoir;
	// }}}RME
	// {{{RME capsuleRole 'aUserInterface'
	RTActorRef aUserInterface;
	// }}}RME

public:
	AWarmeDrankenAutomaat_Actor( RTController * rtg_rts, RTActorRef * rtg_ref );
	virtual ~AWarmeDrankenAutomaat_Actor( void );
	virtual int _followOutV( RTBindingEnd & rtg_end, int rtg_compId, int rtg_portId, int rtg_repIndex );
	virtual void rtsBehavior( int signalIndex, int portIndex );
	virtual const RTActor_class * getActorData( void ) const;

protected:
	static const RTActor_class rtg_class;

public:
	static const RTStateId rtg_parent_state[];

private:
	static const RTComponentDescriptor rtg_capsule_roles[];
};
#undef SUPER

// {{{RME tool 'OT::Cpp' property 'HeaderEnding'
// {{{USR

// }}}USR
// }}}RME

#endif /* AWarmeDrankenAutomaat_H */

// }}}RME
