// {{{RME classifier 'Logical View::DomainLogic::ABesturingseenheid'

#ifndef ABesturingseenheid_H
#define ABesturingseenheid_H

#ifdef PRAGMA
#pragma interface "ABesturingseenheid.h"
#endif

#include <RTSystem/WarmeDrankenAutomaatComponent.h>

// {{{RME tool 'OT::Cpp' property 'HeaderPreface'
// {{{USR

// }}}USR
// }}}RME

extern const RTActorClass ABesturingseenheid;

#define SUPER RTActor
class ABesturingseenheid_Actor : public RTActor
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
	// {{{RME capsuleRole 'aMaakCacao'
	RTActorRef aMaakCacao;
	// }}}RME

public:
	ABesturingseenheid_Actor( RTController * rtg_rts, RTActorRef * rtg_ref );
	virtual ~ABesturingseenheid_Actor( void );
	virtual int _followInV( RTBindingEnd & rtg_end, int rtg_portId, int rtg_repIndex );
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

#endif /* ABesturingseenheid_H */

// }}}RME
