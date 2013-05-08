// {{{RME classifier 'Logical View::topCapsule'

#ifndef topCapsule_H
#define topCapsule_H

#ifdef PRAGMA
#pragma interface "topCapsule.h"
#endif

#include <RTSystem/Program.h>

// {{{RME tool 'OT::Cpp' property 'HeaderPreface'
// {{{USR
#include <stdio.h>

// }}}USR
// }}}RME

extern const RTActorClass topCapsule;

#define SUPER RTActor
class topCapsule_Actor : public RTActor
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
	// {{{RME capsuleRole 'serialCommunicationCapsuleR1'
	RTActorRef serialCommunicationCapsuleR1;
	// }}}RME

public:
	topCapsule_Actor( RTController * rtg_rts, RTActorRef * rtg_ref );
	virtual ~topCapsule_Actor( void );
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

#endif /* topCapsule_H */

// }}}RME
