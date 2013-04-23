// {{{RME classifier 'Logical View::mainCapsule'

#ifndef mainCapsule_H
#define mainCapsule_H

#ifdef PRAGMA
#pragma interface "mainCapsule.h"
#endif

#include <RTSystem/ourProgram.h>
#include <tcpProtocol.h>

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
	// {{{RME classAttribute 'clientSocket'
	SOCKET clientSocket;
	// }}}RME

protected:
	// {{{RME capsuleRole 'instanceTcpCapsule'
	RTActorRef instanceTcpCapsule;
	// }}}RME
	// {{{RME port 'tcpConnection'
	tcpProtocol::Conjugate tcpConnection;
	// }}}RME
	// {{{RME port 'frame'
	Frame::Base frame;
	// }}}RME

public:
	mainCapsule_Actor( RTController * rtg_rts, RTActorRef * rtg_ref );
	virtual ~mainCapsule_Actor( void );
	virtual int _followInV( RTBindingEnd & rtg_end, int rtg_portId, int rtg_repIndex );

protected:
	// {{{RME transition ':TOP:Initial:Initial'
	INLINE_METHODS void transition1_Initial( const void * rtdata, RTProtocol * rtport );
	// }}}RME
	// {{{RME transition ':TOP:KlaarVoorData:J5176823800F4:dataReceived'
	INLINE_METHODS void transition2_dataReceived( const RTString * rtdata, tcpProtocol::Conjugate * rtport );
	// }}}RME

private:
	INLINE_CHAINS void chain1_Initial( void );
	INLINE_CHAINS void chain2_dataReceived( void );

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

public:
	static const RTFieldDescriptor rtg_mainCapsule_fields[];
};
#undef SUPER

// {{{RME tool 'OT::Cpp' property 'HeaderEnding'
// {{{USR

// }}}USR
// }}}RME

#endif /* mainCapsule_H */

// }}}RME
