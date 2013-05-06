// {{{RME classifier 'Logical View::mainCapsule'

#ifndef mainCapsule_H
#define mainCapsule_H

#ifdef PRAGMA
#pragma interface "mainCapsule.h"
#endif

#include <RTSystem/ourProgram.h>

// {{{RME tool 'OT::Cpp' property 'HeaderPreface'
// {{{USR
//zet windowsversie op XP
#define WINVER 0x0501

#include <winsock2.h> 
#include <ws2tcpip.h> 
#include <stdio.h>

// }}}USR
// }}}RME

extern const RTActorClass mainCapsule;

#define SUPER RTActor
class mainCapsule_Actor : public RTActor
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
	// {{{RME port 'frame'
	Frame::Base frame;
	// }}}RME

public:
	mainCapsule_Actor( RTController * rtg_rts, RTActorRef * rtg_ref );
	virtual ~mainCapsule_Actor( void );
	virtual void rtsBehavior( int signalIndex, int portIndex );
	virtual const RTActor_class * getActorData( void ) const;

protected:
	static const RTActor_class rtg_class;

public:
	static const RTStateId rtg_parent_state[];

private:
	static const RTPortDescriptor rtg_ports[];
};
#undef SUPER

// {{{RME tool 'OT::Cpp' property 'HeaderEnding'
// {{{USR

// }}}USR
// }}}RME

#endif /* mainCapsule_H */

// }}}RME
