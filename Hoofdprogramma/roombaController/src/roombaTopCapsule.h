// {{{RME classifier 'Logical View::Roomba::roombaTopCapsule'

#ifndef roombaTopCapsule_H
#define roombaTopCapsule_H

#ifdef PRAGMA
#pragma interface "roombaTopCapsule.h"
#endif

#include <RTSystem/roombaController.h>
#include <roombaProtocol.h>
class clsRoomba;

// {{{RME tool 'OT::Cpp' property 'HeaderPreface'
// {{{USR
#include <clsRoomba.h>

// }}}USR
// }}}RME

// {{{RME classAttribute 'NUMSENSORS'
#define NUMSENSORS 12
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

protected:
	// {{{RME port 'toMain'
	roombaProtocol::Base toMain;
	// }}}RME

public:
	roombaTopCapsule_Actor( RTController * rtg_rts, RTActorRef * rtg_ref );
	virtual ~roombaTopCapsule_Actor( void );
	virtual int _followInV( RTBindingEnd & rtg_end, int rtg_portId, int rtg_repIndex );

protected:
	// {{{RME transition ':TOP:waitForCom:J519B68FC0073:comReady'
	INLINE_METHODS void transition1_comReady( const void * rtdata, roombaProtocol::Base * rtport );
	// }}}RME

private:
	INLINE_CHAINS void chain4_Initial( void );
	INLINE_CHAINS void chain2_dataReceived( void );
	INLINE_CHAINS void chain3_commandReceived( void );
	INLINE_CHAINS void chain1_comReady( void );

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
	static const RTFieldDescriptor rtg_roombaTopCapsule_fields[];
};
#undef SUPER

// {{{RME classAttribute 'sensorsToQuery'
extern int sensorsToQuery[ NUMSENSORS ];
// }}}RME

// {{{RME tool 'OT::Cpp' property 'HeaderEnding'
// {{{USR

// }}}USR
// }}}RME

#endif /* roombaTopCapsule_H */

// }}}RME