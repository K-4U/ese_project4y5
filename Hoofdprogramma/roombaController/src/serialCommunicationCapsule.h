// {{{RME classifier 'Logical View::Serial::serialCommunicationCapsule'

#ifndef serialCommunicationCapsule_H
#define serialCommunicationCapsule_H

#ifdef PRAGMA
#pragma interface "serialCommunicationCapsule.h"
#endif

#include <RTSystem/roombaController.h>
#include <serialRawProtocol.h>
class serialProperties;

// {{{RME tool 'OT::Cpp' property 'HeaderPreface'
// {{{USR
#include <stdio.h>
#include <stdlib.h>
//#include <SerialProperties.h>

#include "../../include/rs232.h"

#ifdef _WIN32
#include <Windows.h>
#else
#include <unistd.h>
#endif

// }}}USR
// }}}RME

extern const RTActorClass serialCommunicationCapsule;

#define SUPER RTActor
class serialCommunicationCapsule_Actor : public RTActor
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
	// {{{RME port 'serialPort'
	serialRawProtocol::Base serialPort;
	// }}}RME
	// {{{RME port 'timer'
	Timing::Base timer;
	// }}}RME

public:
	serialCommunicationCapsule_Actor( RTController * rtg_rts, RTActorRef * rtg_ref );
	virtual ~serialCommunicationCapsule_Actor( void );
	virtual int _followInV( RTBindingEnd & rtg_end, int rtg_portId, int rtg_repIndex );

protected:
	// {{{RME enter ':TOP:Ready'
	INLINE_METHODS void enter2_Ready( void );
	// }}}RME
	virtual void enterStateV( void );
	// {{{RME enter ':TOP:pollData'
	INLINE_METHODS void enter4_pollData( void );
	// }}}RME
	// {{{RME enter ':TOP:SetBaud'
	INLINE_METHODS void enter5_SetBaud( void );
	// }}}RME
	// {{{RME transition ':TOP:Initial:Initial'
	INLINE_METHODS void transition1_Initial( const void * rtdata, RTProtocol * rtport );
	// }}}RME
	// {{{RME transition ':TOP:openPort:False'
	INLINE_METHODS void transition2_False( const void * rtdata, RTProtocol * rtport );
	// }}}RME
	// {{{RME transition ':TOP:SetBaud:J51AEFD8B01BC:ReallyDone'
	INLINE_METHODS void transition6_ReallyDone( const void * rtdata, RTProtocol * rtport );
	// }}}RME

private:
	INLINE_CHAINS void chain1_Initial( void );

protected:
	// {{{RME choicePoint ':TOP:openPort'
	INLINE_METHODS int choicePoint1_openPort( const void * rtdata, RTProtocol * rtport );
	// }}}RME

private:
	INLINE_CHAINS void chain3_True( void );
	INLINE_CHAINS void chain2_False( void );
	INLINE_CHAINS void chain5_timer( void );

public:
	virtual void rtsBehavior( int signalIndex, int portIndex );

protected:
	// {{{RME choicePoint ':TOP:ClosePort'
	INLINE_METHODS int choicePoint2_ClosePort( const void * rtdata, RTProtocol * rtport );
	// }}}RME

public:
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

#endif /* serialCommunicationCapsule_H */

// }}}RME
