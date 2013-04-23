// {{{RME classifier 'Logical View::UserInterface::AUserInterface'

#ifndef AUserInterface_H
#define AUserInterface_H

#ifdef PRAGMA
#pragma interface "AUserInterface.h"
#endif

#include <RTSystem/WarmeDrankenAutomaatComponent.h>
#include <PGuiConnection.h>
#include <PGuiInit.h>
#include <PUserInterface.h>

// {{{RME tool 'OT::Cpp' property 'HeaderPreface'
// {{{USR
//zet windowsversie op XP
#define WINVER 0x0501

#include <winsock2.h> 
#include <ws2tcpip.h> 
#include <stdio.h> 

// }}}USR
// }}}RME

extern const RTActorClass AUserInterface;

#define SUPER RTActor
class AUserInterface_Actor : public RTActor
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
	// {{{RME capsuleRole 'aGui'
	RTActorRef aGui;
	// }}}RME
	// {{{RME capsuleRole 'aTCPServer_QtSocket'
	RTActorRef aTCPServer_QtSocket;
	// }}}RME
	// {{{RME port 'pUserInterface'
	PUserInterface::Base pUserInterface;
	// }}}RME
	// {{{RME port 'pGuiInit'
	PGuiInit::Conjugate pGuiInit;
	// }}}RME
	// {{{RME port 'frame'
	Frame::Base frame;
	// }}}RME
	// {{{RME port 'pGuiConnection'
	PGuiConnection::Conjugate pGuiConnection;
	// }}}RME

public:
	AUserInterface_Actor( RTController * rtg_rts, RTActorRef * rtg_ref );
	virtual ~AUserInterface_Actor( void );
	virtual int _followInV( RTBindingEnd & rtg_end, int rtg_portId, int rtg_repIndex );
	virtual int _followOutV( RTBindingEnd & rtg_end, int rtg_compId, int rtg_portId, int rtg_repIndex );

protected:
	// {{{RME transition ':TOP:Initial:Initial'
	INLINE_METHODS void transition1_Initial( const void * rtdata, RTProtocol * rtport );
	// }}}RME
	// {{{RME transition ':TOP:klaarVoorAanvraag:J4BB87B9D02F0:receivedExternalEvent'
	INLINE_METHODS void transition2_receivedExternalEvent( const RTString * rtdata, PGuiConnection::Conjugate * rtport );
	// }}}RME
	// {{{RME transition ':TOP:klaarVoorAanvraag:J4BDEC76C009E:ready'
	INLINE_METHODS void transition3_ready( const void * rtdata, PUserInterface::Base * rtport );
	// }}}RME
	// {{{RME transition ':TOP:J4BE68AD702F0:receivedSocketNumber'
	INLINE_METHODS void transition4_receivedSocketNumber( const unsigned * rtdata, PGuiConnection::Conjugate * rtport );
	// }}}RME
	// {{{RME transition ':TOP:J4BE68B2C00CB:cancelledSocket'
	INLINE_METHODS void transition5_cancelledSocket( const void * rtdata, PGuiConnection::Conjugate * rtport );
	// }}}RME

private:
	INLINE_CHAINS void chain1_Initial( void );
	INLINE_CHAINS void chain4_receivedSocketNumber( void );
	INLINE_CHAINS void chain5_cancelledSocket( void );
	INLINE_CHAINS void chain3_ready( void );
	INLINE_CHAINS void chain2_receivedExternalEvent( void );

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

#endif /* AUserInterface_H */

// }}}RME
