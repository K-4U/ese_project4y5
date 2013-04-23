// {{{RME classifier 'Logical View::tcpCapsule'

#ifndef tcpCapsule_H
#define tcpCapsule_H

#ifdef PRAGMA
#pragma interface "tcpCapsule.h"
#endif

#include <RTSystem/ourProgram.h>
#include <tcpProtocol.h>
class TCPCONSTANTS;

// {{{RME tool 'OT::Cpp' property 'HeaderPreface'
// {{{USR
//zet windowsversie op XP
#define WINVER 0x0501

#include <winsock2.h> 
#include <ws2tcpip.h> 
#include <stdio.h>
#include <TCPCONSTANTS.h>

// }}}USR
// }}}RME

extern const RTActorClass tcpCapsule;

#define SUPER RTActor
class tcpCapsule_Actor : public RTActor
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
	// {{{RME classAttribute 'ClientSocket'
	SOCKET ClientSocket;
	// }}}RME
	// {{{RME classAttribute 'hints'
	addrinfo hints;
	// }}}RME
	// {{{RME classAttribute 'iResult'
	int iResult;
	// }}}RME
	// {{{RME classAttribute 'ListenSocket'
	SOCKET ListenSocket;
	// }}}RME
	// {{{RME classAttribute 'ptr'
	addrinfo * ptr;
	// }}}RME
	// {{{RME classAttribute 'recvbuf'
	char recvbuf[ DEFAULT_BUFLEN ];
	// }}}RME
	// {{{RME classAttribute 'result'
	addrinfo * result;
	// }}}RME
	// {{{RME classAttribute 'wsaData'
	WSADATA wsaData;
	// }}}RME

protected:
	// {{{RME port 'mainConnection'
	tcpProtocol::Base mainConnection;
	// }}}RME
	// {{{RME port 'timer'
	Timing::Base timer;
	// }}}RME

public:
	tcpCapsule_Actor( RTController * rtg_rts, RTActorRef * rtg_ref );
	virtual ~tcpCapsule_Actor( void );
	virtual int _followInV( RTBindingEnd & rtg_end, int rtg_portId, int rtg_repIndex );

protected:
	// {{{RME enter ':TOP:Reset'
	INLINE_METHODS void enter2_Reset( void );
	// }}}RME
	virtual void enterStateV( void );
	// {{{RME transition ':TOP:acceptConnection:True'
	INLINE_METHODS void transition14_True( const void * rtdata, Timing::Base * rtport );
	// }}}RME
	// {{{RME transition ':TOP:getBytes:False'
	INLINE_METHODS void transition17_False( const void * rtdata, Timing::Base * rtport );
	// }}}RME

private:
	INLINE_CHAINS void chain1_Initial( void );

protected:
	// {{{RME choicePoint ':TOP:InitializeWinsock'
	INLINE_METHODS int choicePoint1_InitializeWinsock( const void * rtdata, Timing::Base * rtport );
	// }}}RME

private:
	INLINE_CHAINS void chain3_True( void );

protected:
	// {{{RME choicePoint ':TOP:addressCorrect'
	INLINE_METHODS int choicePoint2_addressCorrect( const void * rtdata, Timing::Base * rtport );
	// }}}RME

private:
	INLINE_CHAINS void chain6_True( void );

protected:
	// {{{RME choicePoint ':TOP:validSocket'
	INLINE_METHODS int choicePoint3_validSocket( const void * rtdata, Timing::Base * rtport );
	// }}}RME

private:
	INLINE_CHAINS void chain7_True( void );

protected:
	// {{{RME choicePoint ':TOP:bindingSuccesfull'
	INLINE_METHODS int choicePoint4_bindingSuccesfull( const void * rtdata, Timing::Base * rtport );
	// }}}RME

private:
	INLINE_CHAINS void chain8_True( void );

protected:
	// {{{RME choicePoint ':TOP:listening'
	INLINE_METHODS int choicePoint5_listening( const void * rtdata, Timing::Base * rtport );
	// }}}RME

private:
	INLINE_CHAINS void chain9_True( void );

protected:
	// {{{RME choicePoint ':TOP:acceptConnection'
	INLINE_METHODS int choicePoint6_acceptConnection( const void * rtdata, Timing::Base * rtport );
	// }}}RME

private:
	INLINE_CHAINS void chain14_True( void );

protected:
	// {{{RME choicePoint ':TOP:getBytes'
	INLINE_METHODS int choicePoint7_getBytes( const void * rtdata, Timing::Base * rtport );
	// }}}RME

private:
	INLINE_CHAINS void chain15_True( void );
	INLINE_CHAINS void chain17_False( void );

protected:
	// {{{RME choicePoint ':TOP:shutdownConnection'
	INLINE_METHODS int choicePoint8_shutdownConnection( const void * rtdata, Timing::Base * rtport );
	// }}}RME

private:
	INLINE_CHAINS void chain18_True( void );
	INLINE_CHAINS void chain13_False( void );
	INLINE_CHAINS void chain16_False( void );
	INLINE_CHAINS void chain12_False( void );
	INLINE_CHAINS void chain11_False( void );
	INLINE_CHAINS void chain10_False( void );
	INLINE_CHAINS void chain4_False( void );
	INLINE_CHAINS void chain2_False( void );
	INLINE_CHAINS void chain5_viaResetToInit( void );

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
	static const RTFieldDescriptor rtg_tcpCapsule_fields[];
};
#undef SUPER

// {{{RME tool 'OT::Cpp' property 'HeaderEnding'
// {{{USR

// }}}USR
// }}}RME

#endif /* tcpCapsule_H */

// }}}RME
