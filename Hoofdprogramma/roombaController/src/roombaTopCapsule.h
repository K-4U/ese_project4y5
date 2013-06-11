// {{{RME classifier 'Logical View::Roomba::roombaTopCapsule'

#ifndef roombaTopCapsule_H
#define roombaTopCapsule_H

#ifdef PRAGMA
#pragma interface "roombaTopCapsule.h"
#endif

#include <RTSystem/roombaController.h>
#include <programProtocol.h>
#include <roombaProtocol.h>
class clsRoomba;

// {{{RME tool 'OT::Cpp' property 'HeaderPreface'
// {{{USR
#include <clsRoomba.h>
#include <stdio.h>
#include <stdlib.h>
#include "../../include/json.h"

#ifdef _WIN32
#include <Windows.h>
#else
#include <unistd.h>
#endif

// }}}USR
// }}}RME

// {{{RME classAttribute 'NUMSENSORS'
#define NUMSENSORS 14
// }}}RME

extern const RTActorClass roombaTopCapsule;

#define SUPER RTActor
class roombaTopCapsule_Actor : public RTActor
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
	// {{{RME classAttribute 'roomba'
	clsRoomba roomba;
	// }}}RME
	// {{{RME classAttribute 'isOperating'
	bool isOperating;
	// }}}RME
	// {{{RME classAttribute 'cleanWasTrue'
	bool cleanWasTrue;
	// }}}RME
	// {{{RME classAttribute 'dockWasTrue'
	bool dockWasTrue;
	// }}}RME
	// {{{RME classAttribute 'searchingDock'
	bool searchingDock;
	// }}}RME

protected:
	// {{{RME capsuleRole 'roombaProgramInstance'
	RTActorRef roombaProgramInstance;
	// }}}RME
	// {{{RME port 'toMain'
	roombaProtocol::Base toMain;
	// }}}RME
	// {{{RME port 'timer'
	Timing::Base timer;
	// }}}RME
	// {{{RME port 'program'
	programProtocol::Conjugate program;
	// }}}RME
	// {{{RME port 'frame'
	Frame::Base frame;
	// }}}RME

public:
	roombaTopCapsule_Actor( RTController * rtg_rts, RTActorRef * rtg_ref );
	virtual ~roombaTopCapsule_Actor( void );

protected:
	// {{{RME operation 'sendRoombaCommandSetMotors()'
	void sendRoombaCommandSetMotors( void );
	// }}}RME

public:
	virtual int _followInV( RTBindingEnd & rtg_end, int rtg_portId, int rtg_repIndex );
	virtual int _followOutV( RTBindingEnd & rtg_end, int rtg_compId, int rtg_portId, int rtg_repIndex );

protected:
	// {{{RME transition ':TOP:waitForCom:J519B68FC0073:comReady'
	INLINE_METHODS void transition1_comReady( const void * rtdata, roombaProtocol::Base * rtport );
	// }}}RME
	// {{{RME transition ':TOP:Ready:J51AB647002D6:dataReceived'
	INLINE_METHODS void transition2_dataReceived( const byteArray * rtdata, roombaProtocol::Base * rtport );
	// }}}RME
	// {{{RME transition ':TOP:Ready:J519B5D200005:commandReceived'
	INLINE_METHODS void transition3_commandReceived( const jsonCommand * rtdata, roombaProtocol::Base * rtport );
	// }}}RME
	// {{{RME transition ':TOP:Initial:Initial'
	INLINE_METHODS void transition4_Initial( const void * rtdata, RTProtocol * rtport );
	// }}}RME
	// {{{RME transition ':TOP:Ready:J51AB645400D1:handleSensors'
	INLINE_METHODS void transition5_handleSensors( const byteArray * rtdata, roombaProtocol::Base * rtport );
	// }}}RME
	// {{{RME transition ':TOP:Ready:J51A5CE4A021F:askSensors'
	INLINE_METHODS void transition6_askSensors( const void * rtdata, Timing::Base * rtport );
	// }}}RME
	// {{{RME transition ':TOP:Ready:J51AB4F6F0301:playSong'
	INLINE_METHODS void transition7_playSong( const int * rtdata, programProtocol::Conjugate * rtport );
	// }}}RME
	// {{{RME transition ':TOP:Ready:J51AB52300119:stopProgram'
	INLINE_METHODS void transition8_stopProgram( const int * rtdata, programProtocol::Conjugate * rtport );
	// }}}RME
	// {{{RME transition ':TOP:Ready:J51AB5BCB00F3:drive'
	INLINE_METHODS void transition9_drive( const clsDriveCommand * rtdata, programProtocol::Conjugate * rtport );
	// }}}RME
	// {{{RME transition ':TOP:Ready:J51AB77110307:doSend'
	INLINE_METHODS void transition10_doSend( const byteArray * rtdata, programProtocol::Conjugate * rtport );
	// }}}RME
	// {{{RME transition ':TOP:Ready:J51B718480383:SetMotors'
	INLINE_METHODS void transition11_SetMotors( const clsRoomba::clsMotors * rtdata, programProtocol::Conjugate * rtport );
	// }}}RME

private:
	INLINE_CHAINS void chain4_Initial( void );
	INLINE_CHAINS void chain2_dataReceived( void );
	INLINE_CHAINS void chain3_commandReceived( void );
	INLINE_CHAINS void chain6_askSensors( void );
	INLINE_CHAINS void chain7_playSong( void );
	INLINE_CHAINS void chain8_stopProgram( void );
	INLINE_CHAINS void chain9_drive( void );
	INLINE_CHAINS void chain10_doSend( void );
	INLINE_CHAINS void chain11_SetMotors( void );
	INLINE_CHAINS void chain1_comReady( void );

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
	static const RTFieldDescriptor rtg_roombaTopCapsule_fields[];
};
#undef SUPER

// {{{RME classAttribute 'sensorsToQuery'
extern int sensorsToQuery[ NUMSENSORS ][ 2 ];
// }}}RME

// {{{RME tool 'OT::Cpp' property 'HeaderEnding'
// {{{USR

// }}}USR
// }}}RME

#endif /* roombaTopCapsule_H */

// }}}RME
