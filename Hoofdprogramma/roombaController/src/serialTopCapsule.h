// {{{RME classifier 'Logical View::Serial::serialTopCapsule'

#ifndef serialTopCapsule_H
#define serialTopCapsule_H

#ifdef PRAGMA
#pragma interface "serialTopCapsule.h"
#endif

#include <RTSystem/roombaController.h>
#include <serialProtocol.h>

// {{{RME tool 'OT::Cpp' property 'HeaderPreface'
// {{{USR

// }}}USR
// }}}RME

extern const RTActorClass serialTopCapsule;

#define SUPER RTActor
class serialTopCapsule_Actor : public RTActor
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
	// {{{RME capsuleRole 'serialCommunicationInstance'
	RTActorRef serialCommunicationInstance;
	// }}}RME
	// {{{RME capsuleRole 'serialTranslateCapsuleR1'
	RTActorRef serialTranslateCapsuleR1;
	// }}}RME
	// {{{RME port 'frame'
	Frame::Base frame;
	// }}}RME
	// {{{RME port 'internalSerial'
	serialProtocol::Conjugate internalSerial;
	// }}}RME
	// {{{RME port 'externalSerial'
	serialProtocol::Base externalSerial;
	// }}}RME

public:
	serialTopCapsule_Actor( RTController * rtg_rts, RTActorRef * rtg_ref );
	virtual ~serialTopCapsule_Actor( void );
	virtual int _followInV( RTBindingEnd & rtg_end, int rtg_portId, int rtg_repIndex );
	virtual int _followOutV( RTBindingEnd & rtg_end, int rtg_compId, int rtg_portId, int rtg_repIndex );

protected:
	// {{{RME transition ':TOP:Initial:Initial'
	INLINE_METHODS void transition1_Initial( const void * rtdata, RTProtocol * rtport );
	// }}}RME
	// {{{RME transition ':TOP:ready:J51922F8C025B:commandReceived'
	INLINE_METHODS void transition2_commandReceived( const byteArray * rtdata, serialProtocol::Conjugate * rtport );
	// }}}RME
	// {{{RME transition ':TOP:ready:J5193582D0135:sendCommand'
	INLINE_METHODS void transition3_sendCommand( const byteArray * rtdata, serialProtocol::Base * rtport );
	// }}}RME
	// {{{RME transition ':TOP:ready:J519B511B0342:comOpened'
	INLINE_METHODS void transition4_comOpened( const void * rtdata, serialProtocol::Conjugate * rtport );
	// }}}RME
	// {{{RME transition ':TOP:ready:J519B513C00E7:comError'
	INLINE_METHODS void transition5_comError( const void * rtdata, serialProtocol::Conjugate * rtport );
	// }}}RME
	// {{{RME transition ':TOP:ready:J51AC8CD800D7:setCommandLength'
	INLINE_METHODS void transition6_setCommandLength( const int * rtdata, serialProtocol::Base * rtport );
	// }}}RME

private:
	INLINE_CHAINS void chain1_Initial( void );
	INLINE_CHAINS void chain2_commandReceived( void );
	INLINE_CHAINS void chain4_comOpened( void );
	INLINE_CHAINS void chain5_comError( void );
	INLINE_CHAINS void chain3_sendCommand( void );
	INLINE_CHAINS void chain6_setCommandLength( void );

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

#endif /* serialTopCapsule_H */

// }}}RME
