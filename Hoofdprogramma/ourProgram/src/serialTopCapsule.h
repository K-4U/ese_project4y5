// {{{RME classifier 'Logical View::Serial::serialTopCapsule'

#ifndef serialTopCapsule_H
#define serialTopCapsule_H

#ifdef PRAGMA
#pragma interface "serialTopCapsule.h"
#endif

#include <RTSystem/ourProgram.h>

// {{{RME tool 'OT::Cpp' property 'HeaderPreface'
// {{{USR

// }}}USR
// }}}RME

extern const RTActorClass serialTopCapsule;

#define SUPER RTActor
class serialTopCapsule_Actor : public RTActor
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
	// {{{RME capsuleRole 'serialCommunicationInstance'
	RTActorRef serialCommunicationInstance;
	// }}}RME
	// {{{RME port 'frame'
	Frame::Base frame;
	// }}}RME

public:
	serialTopCapsule_Actor( RTController * rtg_rts, RTActorRef * rtg_ref );
	virtual ~serialTopCapsule_Actor( void );

protected:
	// {{{RME transition ':TOP:Initial:Initial'
	INLINE_METHODS void transition1_Initial( const void * rtdata, RTProtocol * rtport );
	// }}}RME

private:
	INLINE_CHAINS void chain1_Initial( void );

public:
	virtual void rtsBehavior( int signalIndex, int portIndex );
	virtual const RTActor_class * getActorData( void ) const;

protected:
	static const RTActor_class rtg_class;

public:
	static const RTStateId rtg_parent_state[];

private:
	static const RTComponentDescriptor rtg_capsule_roles[];
	static const RTPortDescriptor rtg_ports[];
};
#undef SUPER

// {{{RME tool 'OT::Cpp' property 'HeaderEnding'
// {{{USR

// }}}USR
// }}}RME

#endif /* serialTopCapsule_H */

// }}}RME
