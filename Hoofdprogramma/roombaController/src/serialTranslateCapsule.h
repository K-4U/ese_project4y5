// {{{RME classifier 'Logical View::Serial::serialTranslateCapsule'

#ifndef serialTranslateCapsule_H
#define serialTranslateCapsule_H

#ifdef PRAGMA
#pragma interface "serialTranslateCapsule.h"
#endif

#include <RTSystem/roombaController.h>
#include <serialProtocol.h>
#include <serialRawProtocol.h>
class serialProperties;

// {{{RME tool 'OT::Cpp' property 'HeaderPreface'
// {{{USR
#include <stdio.h>
#include <stdlib.h>

#include "../../include/rs232.h"

#ifdef _WIN32
#include <Windows.h>
#else
#include <unistd.h>
#endif

// }}}USR
// }}}RME

extern const RTActorClass serialTranslateCapsule;

#define SUPER RTActor
class serialTranslateCapsule_Actor : public RTActor
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
	// {{{RME classAttribute 'firstByte'
	char firstByte;
	// }}}RME
	// {{{RME classAttribute 'inCommand'
	bool inCommand;
	// }}}RME
	// {{{RME classAttribute 'commandLength'
	int commandLength;
	// }}}RME
	// {{{RME classAttribute 'buffer'
	byteArray buffer;
	// }}}RME
	// {{{RME classAttribute 'lengthNotYetReceived'
	bool lengthNotYetReceived;
	// }}}RME

protected:
	// {{{RME port 'serialRaw'
	serialRawProtocol::Conjugate serialRaw;
	// }}}RME
	// {{{RME port 'serialOut'
	serialProtocol::Base serialOut;
	// }}}RME

public:
	serialTranslateCapsule_Actor( RTController * rtg_rts, RTActorRef * rtg_ref );
	virtual ~serialTranslateCapsule_Actor( void );
	virtual int _followInV( RTBindingEnd & rtg_end, int rtg_portId, int rtg_repIndex );

protected:
	// {{{RME transition ':TOP:S1:J519234560116:dataReceived'
	INLINE_METHODS void transition2_dataReceived( const byteArray * rtdata, serialRawProtocol::Conjugate * rtport );
	// }}}RME
	// {{{RME transition ':TOP:S1:J5193551C029A:sendCommand'
	INLINE_METHODS void transition3_sendCommand( const byteArray * rtdata, serialProtocol::Base * rtport );
	// }}}RME

private:
	INLINE_CHAINS void chain1_Initial( void );
	INLINE_CHAINS void chain2_dataReceived( void );
	INLINE_CHAINS void chain3_sendCommand( void );

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
	static const RTFieldDescriptor rtg_serialTranslateCapsule_fields[];
};
#undef SUPER

// {{{RME tool 'OT::Cpp' property 'HeaderEnding'
// {{{USR

// }}}USR
// }}}RME

#endif /* serialTranslateCapsule_H */

// }}}RME
