// {{{RME classifier 'Logical View::mainCapsule'

#ifndef mainCapsule_H
#define mainCapsule_H

#ifdef PRAGMA
#pragma interface "mainCapsule.h"
#endif

#include <RTSystem/Program.h>
#include <SerialProtocol.h>

// {{{RME tool 'OT::Cpp' property 'HeaderPreface'
// {{{USR
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

protected:
	// {{{RME port 'frame'
	Frame::Base frame;
	// }}}RME
	// {{{RME port 'Serial'
	SerialProtocol::Conjugate Serial;
	// }}}RME

public:
	mainCapsule_Actor( RTController * rtg_rts, RTActorRef * rtg_ref );
	virtual ~mainCapsule_Actor( void );
	virtual int _followInV( RTBindingEnd & rtg_end, int rtg_portId, int rtg_repIndex );

protected:
	// {{{RME enter ':TOP:ready'
	INLINE_METHODS void enter2_ready( void );
	// }}}RME
	virtual void enterStateV( void );
	// {{{RME transition ':TOP:ready:J51921871008A:DataReceived'
	INLINE_METHODS void transition2_DataReceived( const RTString * rtdata, SerialProtocol::Conjugate * rtport );
	// }}}RME

private:
	INLINE_CHAINS void chain1_Initial( void );
	INLINE_CHAINS void chain2_DataReceived( void );

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

#endif /* mainCapsule_H */

// }}}RME
