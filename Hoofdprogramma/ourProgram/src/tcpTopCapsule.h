// {{{RME classifier 'Logical View::TCPIP::tcpTopCapsule'

#ifndef tcpTopCapsule_H
#define tcpTopCapsule_H

#ifdef PRAGMA
#pragma interface "tcpTopCapsule.h"
#endif

#include <RTSystem/ourProgram.h>
#include <jsonProtocol.h>

// {{{RME tool 'OT::Cpp' property 'HeaderPreface'
// {{{USR

// }}}USR
// }}}RME

extern const RTActorClass tcpTopCapsule;

#define SUPER RTActor
class tcpTopCapsule_Actor : public RTActor
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
	// {{{RME capsuleRole 'tcpInstance'
	RTActorRef tcpInstance;
	// }}}RME
	// {{{RME capsuleRole 'jsonTranslateInstance'
	RTActorRef jsonTranslateInstance;
	// }}}RME
	// {{{RME port 'internalJsonPort'
	jsonProtocol::Conjugate internalJsonPort;
	// }}}RME
	// {{{RME port 'frame'
	Frame::Base frame;
	// }}}RME

public:
	tcpTopCapsule_Actor( RTController * rtg_rts, RTActorRef * rtg_ref );
	virtual ~tcpTopCapsule_Actor( void );
	virtual int _followOutV( RTBindingEnd & rtg_end, int rtg_compId, int rtg_portId, int rtg_repIndex );

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

#endif /* tcpTopCapsule_H */

// }}}RME
