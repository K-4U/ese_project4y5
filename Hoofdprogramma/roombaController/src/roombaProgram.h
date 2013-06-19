// {{{RME classifier 'Logical View::Roomba::roombaProgram'

#ifndef roombaProgram_H
#define roombaProgram_H

#ifdef PRAGMA
#pragma interface "roombaProgram.h"
#endif

#include <RTSystem/roombaController.h>
#include <programProtocol.h>

// {{{RME tool 'OT::Cpp' property 'HeaderPreface'
// {{{USR
#include <stdio.h>
#include <stdlib.h>
#define _USE_MATH_DEFINES
#include <math.h>

#ifdef _WIN32
#include <Windows.h>
#else
#include <unistd.h>
#endif


// }}}USR
// }}}RME

// {{{RME classAttribute 'MINBATTERY'
#define MINBATTERY 90
// }}}RME

// {{{RME classAttribute 'MOTORNORMAL'
#define MOTORNORMAL 200
// }}}RME

// {{{RME classAttribute 'MOTORFASTER'
#define MOTORFASTER 300
// }}}RME

extern const RTActorClass roombaProgram;

#define SUPER RTActor
class roombaProgram_Actor : public RTActor
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
	// {{{RME classAttribute 'batteryLevel'
	int batteryLevel;
	// }}}RME
	// {{{RME classAttribute 'bumpersTriggered'
	clsRoomba::clsBumpersAndCliff bumpersTriggered;
	// }}}RME
	// {{{RME classAttribute 'angleToRotate'
	int angleToRotate;
	// }}}RME
	// {{{RME classAttribute 'angleRotated'
	int angleRotated;
	// }}}RME
	// {{{RME classAttribute 'speedLeft'
	int speedLeft;
	// }}}RME
	// {{{RME classAttribute 'speedRight'
	int speedRight;
	// }}}RME

protected:
	// {{{RME port 'Roomba'
	programProtocol::Base Roomba;
	// }}}RME
	// {{{RME port 'timer'
	Timing::Base timer;
	// }}}RME

public:
	roombaProgram_Actor( RTController * rtg_rts, RTActorRef * rtg_ref );
	virtual ~roombaProgram_Actor( void );

protected:
	// {{{RME operation 'drive(int,int)'
	void drive( int left, int right );
	// }}}RME
	// {{{RME operation 'stop()'
	void stop( void );
	// }}}RME
	// {{{RME operation 'calculateTimeToRotateAngle(int,int,int)'
	int calculateTimeToRotateAngle( int leftSpeed, int rightSpeed, int angleToRotate );
	// }}}RME
	// {{{RME operation 'setMotors(bool,bool,bool)'
	void setMotors( bool mainBrush, bool sideBrush, bool vacuum );
	// }}}RME

public:
	virtual int _followInV( RTBindingEnd & rtg_end, int rtg_portId, int rtg_repIndex );

protected:
	// {{{RME enter ':TOP:roombaStart'
	INLINE_METHODS void enter3_roombaStart( void );
	// }}}RME
	virtual void enterStateV( void );
	// {{{RME enter ':TOP:rotating'
	INLINE_METHODS void enter4_rotating( void );
	// }}}RME
	// {{{RME transition ':TOP:roombaWaitForStart:J51AB5A2600DB:Start'
	INLINE_METHODS void transition1_Start( const int * rtdata, programProtocol::Base * rtport );
	// }}}RME
	// {{{RME transition ':TOP:checkBatteryLevel:batteryTooLow'
	INLINE_METHODS void transition2_batteryTooLow( const int * rtdata, programProtocol::Base * rtport );
	// }}}RME
	// {{{RME transition ':TOP:checkBatteryLevel:batteryFull'
	INLINE_METHODS void transition3_batteryFull( const int * rtdata, programProtocol::Base * rtport );
	// }}}RME
	// {{{RME transition ':TOP:roombaStart:J51AB5CF303CA:bumperTriggered'
	INLINE_METHODS void transition4_bumperTriggered( const clsRoomba::clsBumpersAndCliff * rtdata, programProtocol::Base * rtport );
	// }}}RME
	// {{{RME transition ':TOP:rotating:J51ADAD540256:Stop'
	INLINE_METHODS void transition6_Stop( const void * rtdata, programProtocol::Base * rtport );
	// }}}RME
	// {{{RME transition ':TOP:roombaStart:J51ADAD78038C:Stop'
	INLINE_METHODS void transition7_Stop( const void * rtdata, programProtocol::Base * rtport );
	// }}}RME
	// {{{RME transition ':TOP:rotating:J51ADB8DA02CF:doneRotating'
	INLINE_METHODS void transition8_doneRotating( const void * rtdata, Timing::Base * rtport );
	// }}}RME
	// {{{RME transition ':TOP:CheckWhereWeAre:J51B5A22101B3:Start'
	INLINE_METHODS void transition10_Start( const int * rtdata, programProtocol::Base * rtport );
	// }}}RME
	// {{{RME transition ':TOP:roombaStart:J51B5A7140151:noOverCurrent'
	INLINE_METHODS void transition11_noOverCurrent( const void * rtdata, programProtocol::Base * rtport );
	// }}}RME

private:
	INLINE_CHAINS void chain5_Initial( void );
	INLINE_CHAINS void chain1_Start( void );

protected:
	// {{{RME choicePoint ':TOP:checkBatteryLevel'
	INLINE_METHODS int choicePoint1_checkBatteryLevel( const int * rtdata, programProtocol::Base * rtport );
	// }}}RME

private:
	INLINE_CHAINS void chain3_batteryFull( void );
	INLINE_CHAINS void chain2_batteryTooLow( void );
	INLINE_CHAINS void chain4_bumperTriggered( void );
	INLINE_CHAINS void chain7_Stop( void );
	INLINE_CHAINS void chain11_noOverCurrent( void );
	INLINE_CHAINS void chain9_bumperTriggered( void );
	INLINE_CHAINS void chain6_Stop( void );
	INLINE_CHAINS void chain8_doneRotating( void );
	INLINE_CHAINS void chain10_Start( void );

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
	static const RTFieldDescriptor rtg_roombaProgram_fields[];
};
#undef SUPER

// {{{RME tool 'OT::Cpp' property 'HeaderEnding'
// {{{USR

// }}}USR
// }}}RME

#endif /* roombaProgram_H */

// }}}RME
