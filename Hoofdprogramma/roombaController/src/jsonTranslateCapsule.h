// {{{RME classifier 'Logical View::TCPIP::jsonTranslateCapsule'

#ifndef jsonTranslateCapsule_H
#define jsonTranslateCapsule_H

#ifdef PRAGMA
#pragma interface "jsonTranslateCapsule.h"
#endif

#include <RTSystem/roombaController.h>
#include <jsonProtocol.h>
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

extern const RTActorClass jsonTranslateCapsule;

#define SUPER RTActor
class jsonTranslateCapsule_Actor : public RTActor
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
	// {{{RME classAttribute 'depth'
	int depth;
	// }}}RME
	// {{{RME classAttribute 'jsonBuffer'
	std::string jsonBuffer;
	// }}}RME
	// {{{RME classAttribute 'jsonReader'
	Json::Reader jsonReader;
	// }}}RME
	// {{{RME classAttribute 'socket'
	SOCKET socket;
	// }}}RME
	// {{{RME classAttribute 'inString'
	bool inString;
	// }}}RME

protected:
	// {{{RME port 'tcpPort'
	tcpProtocol::Conjugate tcpPort;
	// }}}RME
	// {{{RME port 'jsonPort'
	jsonProtocol::Base jsonPort;
	// }}}RME

public:
	jsonTranslateCapsule_Actor( RTController * rtg_rts, RTActorRef * rtg_ref );
	virtual ~jsonTranslateCapsule_Actor( void );
	virtual int _followInV( RTBindingEnd & rtg_end, int rtg_portId, int rtg_repIndex );

protected:
	// {{{RME transition ':TOP:KlaarVoorData:J5176823800F4:dataReceived'
	INLINE_METHODS void transition1_dataReceived( const RTString * rtdata, tcpProtocol::Conjugate * rtport );
	// }}}RME
	// {{{RME transition ':TOP:Initial:Initial'
	INLINE_METHODS void transition2_Initial( const void * rtdata, RTProtocol * rtport );
	// }}}RME
	// {{{RME transition ':TOP:J5188EA8C00E2:socketConnected'
	INLINE_METHODS void transition3_socketConnected( const unsigned * rtdata, tcpProtocol::Conjugate * rtport );
	// }}}RME
	// {{{RME transition ':TOP:J5188EB280304:socketDisconnected'
	INLINE_METHODS void transition4_socketDisconnected( const void * rtdata, tcpProtocol::Conjugate * rtport );
	// }}}RME
	// {{{RME transition ':TOP:KlaarVoorData:J518A1AC6031A:sendCommand'
	INLINE_METHODS void transition5_sendCommand( const jsonCommand * rtdata, jsonProtocol::Base * rtport );
	// }}}RME

private:
	INLINE_CHAINS void chain2_Initial( void );
	INLINE_CHAINS void chain3_socketConnected( void );
	INLINE_CHAINS void chain4_socketDisconnected( void );
	INLINE_CHAINS void chain1_dataReceived( void );
	INLINE_CHAINS void chain5_sendCommand( void );

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
	static const RTFieldDescriptor rtg_jsonTranslateCapsule_fields[];
};
#undef SUPER

// {{{RME tool 'OT::Cpp' property 'HeaderEnding'
// {{{USR

// }}}USR
// }}}RME

#endif /* jsonTranslateCapsule_H */

// }}}RME
