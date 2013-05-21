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

public:
	serialCommunicationCapsule_Actor( RTController * rtg_rts, RTActorRef * rtg_ref );
	virtual ~serialCommunicationCapsule_Actor( void );
	virtual int _followInV( RTBindingEnd & rtg_end, int rtg_portId, int rtg_repIndex );

protected:
	// {{{RME enter ':TOP:Reset'
	INLINE_METHODS void enter2_Reset( void );
	// }}}RME
	virtual void enterStateV( void );
	// {{{RME transition ':TOP:Initial:Initial'
	INLINE_METHODS void transition1_Initial( const void * rtdata, RTProtocol * rtport );
	// }}}RME
	// {{{RME transition ':TOP:openPort:True'
	INLINE_METHODS void transition3_True( const void * rtdata, RTProtocol * rtport );
	// }}}RME

private:
	INLINE_CHAINS void chain1_Initial( void );

protected:
	// {{{RME choicePoint ':TOP:openPort'
	INLINE_METHODS int choicePoint1_openPort( const void * rtdata, RTProtocol * rtport );
	// }}}RME

private:
	INLINE_CHAINS void chain3_True( void );

protected:
	// {{{RME choicePoint ':TOP:getChars'
	INLINE_METHODS int choicePoint2_getChars( const void * rtdata, RTProtocol * rtport );
	// }}}RME

private:
	INLINE_CHAINS void chain4_True( void );
	INLINE_CHAINS void chain5_False( void );
	INLINE_CHAINS void chain2_False( void );

public:
	virtual void rtsBehavior( int signalIndex, int portIndex );

protected:
	// {{{RME choicePoint ':TOP:ClosePort'
	INLINE_METHODS int choicePoint3_ClosePort( const void * rtdata, RTProtocol * rtport );
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
