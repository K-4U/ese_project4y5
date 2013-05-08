// {{{RME classifier 'Logical View::topCap'

#ifndef topCap_H
#define topCap_H

#ifdef PRAGMA
#pragma interface "topCap.h"
#endif

#include <RTSystem/ourProgram.h>

// {{{RME tool 'OT::Cpp' property 'HeaderPreface'
// {{{USR

// }}}USR
// }}}RME

extern const RTActorClass topCap;

#define SUPER RTActor
class topCap_Actor : public RTActor
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
	// {{{RME capsuleRole 'tcpTopCapsuleR1'
	RTActorRef tcpTopCapsuleR1;
	// }}}RME
	// {{{RME capsuleRole 'mainCapsuleR1'
	RTActorRef mainCapsuleR1;
	// }}}RME

public:
	topCap_Actor( RTController * rtg_rts, RTActorRef * rtg_ref );
	virtual ~topCap_Actor( void );
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

#endif /* topCap_H */

// }}}RME
