// {{{RME classifier 'Logical View::mainCapsule'

#ifndef mainCapsule_H
#define mainCapsule_H

#ifdef PRAGMA
#pragma interface "mainCapsule.h"
#endif

#include <RTSystem/roombaController.h>
#include <jsonProtocol.h>
#include <roombaProtocol.h>
#include <serialProtocol.h>

// {{{RME tool 'OT::Cpp' property 'HeaderPreface'
// {{{USR

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
	// {{{RME port 'GUI'
	jsonProtocol::Conjugate GUI;
	// }}}RME
	// {{{RME port 'Serial'
	serialProtocol::Conjugate Serial;
	// }}}RME
	// {{{RME port 'Roomba'
	roombaProtocol::Conjugate Roomba;
	// }}}RME

public:
	mainCapsule_Actor( RTController * rtg_rts, RTActorRef * rtg_ref );
	virtual ~mainCapsule_Actor( void );
	virtual int _followInV( RTBindingEnd & rtg_end, int rtg_portId, int rtg_repIndex );

protected:
	// {{{RME enter ':TOP:waitingForCom'
	INLINE_METHODS void enter3_waitingForCom( void );
	// }}}RME
	virtual void enterStateV( void );
	// {{{RME enter ':TOP:Exit'
	INLINE_METHODS void enter4_Exit( void );
	// }}}RME
	// {{{RME transition ':TOP:Initial:Initial'
	INLINE_METHODS void transition1_Initial( const void * rtdata, RTProtocol * rtport );
	// }}}RME
	// {{{RME transition ':TOP:ready:J51A475DD0298:GUIDataReceived'
	INLINE_METHODS void transition2_GUIDataReceived( const jsonCommand * rtdata, jsonProtocol::Conjugate * rtport );
	// }}}RME
	// {{{RME transition ':TOP:ready:J51B596CA016E:serialDataReceived'
	INLINE_METHODS void transition3_serialDataReceived( const byteArray * rtdata, serialProtocol::Conjugate * rtport );
	// }}}RME
	// {{{RME transition ':TOP:waitingForCom:J519B520503E6:comOpened'
	INLINE_METHODS void transition4_comOpened( const void * rtdata, serialProtocol::Conjugate * rtport );
	// }}}RME
	// {{{RME transition ':TOP:ready:J519B64890324:roombaDataReceived'
	INLINE_METHODS void transition6_roombaDataReceived( const byteArray * rtdata, roombaProtocol::Conjugate * rtport );
	// }}}RME
	// {{{RME transition ':TOP:ready:J51AC8C82005A:setCommandLength'
	INLINE_METHODS void transition7_setCommandLength( const int * rtdata, roombaProtocol::Conjugate * rtport );
	// }}}RME
	// {{{RME transition ':TOP:ready:J51B596D9006C:sendToGUI'
	INLINE_METHODS void transition8_sendToGUI( const jsonCommand * rtdata, roombaProtocol::Conjugate * rtport );
	// }}}RME

private:
	INLINE_CHAINS void chain1_Initial( void );
	INLINE_CHAINS void chain2_GUIDataReceived( void );
	INLINE_CHAINS void chain3_serialDataReceived( void );
	INLINE_CHAINS void chain6_roombaDataReceived( void );
	INLINE_CHAINS void chain7_setCommandLength( void );
	INLINE_CHAINS void chain8_sendToGUI( void );
	INLINE_CHAINS void chain4_comOpened( void );
	INLINE_CHAINS void chain5_comError( void );

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
