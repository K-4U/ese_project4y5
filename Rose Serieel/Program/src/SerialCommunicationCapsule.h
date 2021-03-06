// {{{RME classifier 'Logical View::SerialCommunicationCapsule'

#ifndef SerialCommunicationCapsule_H
#define SerialCommunicationCapsule_H

#ifdef PRAGMA
#pragma interface "SerialCommunicationCapsule.h"
#endif

#include <RTSystem/Program.h>
#include <SerialProtocol.h>
class SerialProperties;

// {{{RME tool 'OT::Cpp' property 'HeaderPreface'
// {{{USR
#include <stdio.h>
#include <stdlib.h>
#include <SerialProperties.h>

#include "../../include/rs232.h"

#ifdef _WIN32
#include <Windows.h>
#else
#include <unistd.h>
#endif

// }}}USR
// }}}RME

extern const RTActorClass SerialCommunicationCapsule;

#define SUPER RTActor
class SerialCommunicationCapsule_Actor : public RTActor
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
	// {{{RME port 'SerialCommunication'
	SerialProtocol::Base SerialCommunication;
	// }}}RME
	// {{{RME port 'timer'
	Timing::Base timer;
	// }}}RME

public:
	SerialCommunicationCapsule_Actor( RTController * rtg_rts, RTActorRef * rtg_ref );
	virtual ~SerialCommunicationCapsule_Actor( void );
	virtual int _followInV( RTBindingEnd & rtg_end, int rtg_portId, int rtg_repIndex );

protected:
	// {{{RME enter ':TOP:Reset'
	INLINE_METHODS void enter2_Reset( void );
	// }}}RME
	virtual void enterStateV( void );

private:
	INLINE_CHAINS void chain1_Initial( void );

protected:
	// {{{RME choicePoint ':TOP:OpenPort'
	INLINE_METHODS int choicePoint1_OpenPort( const void * rtdata, RTProtocol * rtport );
	// }}}RME

private:
	INLINE_CHAINS void chain3_True( void );

protected:
	// {{{RME choicePoint ':TOP:GetCaracters'
	INLINE_METHODS int choicePoint2_GetCaracters( const void * rtdata, RTProtocol * rtport );
	// }}}RME

private:
	INLINE_CHAINS void chain4_True( void );
	INLINE_CHAINS void chain5_False( void );

protected:
	// {{{RME choicePoint ':TOP:ClosePort'
	INLINE_METHODS int choicePoint3_ClosePort( const void * rtdata, RTProtocol * rtport );
	// }}}RME

private:
	INLINE_CHAINS void chain6_False( void );
	INLINE_CHAINS void chain2_False( void );

public:
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

#endif /* SerialCommunicationCapsule_H */

// }}}RME
