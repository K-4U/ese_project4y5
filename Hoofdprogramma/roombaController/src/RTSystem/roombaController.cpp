// {{{RME component 'Component View::roombaController'

#if defined( PRAGMA ) && ! defined( PRAGMA_IMPLEMENTED )
#pragma implementation "RTSystem/roombaController.h"
#endif

#include <RTSystem/roombaController.h>
extern const RTActorClass topCap;

RTController * ThreadJsonTranslate = (RTController *)0;

RTController * ThreadRoomba = (RTController *)0;

RTController * ThreadSerial = (RTController *)0;

RTController * ThreadUserInterface = (RTController *)0;

#if USE_THREADS
static RTPeerController * EigenThreadRTS = (RTPeerController *)0;
static RTThread * OTPhysThr_EigenThread = (RTThread *)0;
static RTPeerController * OtherThreadRTS = (RTPeerController *)0;
static RTThread * OTPhysThr_OtherThread = (RTThread *)0;
static RTPeerController * PSerialRTS = (RTPeerController *)0;
static RTThread * OTPhysThr_PSerial = (RTThread *)0;
static RTPeerController * RoombaPhysRTS = (RTPeerController *)0;
static RTThread * OTPhysThr_RoombaPhys = (RTThread *)0;

void _rtg_createThreads( RTDebugger * debugger )
{
	EigenThreadRTS = new RTPeerController( debugger, "EigenThread" );
	OTPhysThr_EigenThread = new RTThread( EigenThreadRTS, 20000, DEFAULT_MAIN_PRIORITY );
	OtherThreadRTS = new RTPeerController( debugger, "OtherThread" );
	OTPhysThr_OtherThread = new RTThread( OtherThreadRTS, 20000, DEFAULT_MAIN_PRIORITY );
	PSerialRTS = new RTPeerController( debugger, "PSerial" );
	OTPhysThr_PSerial = new RTThread( PSerialRTS, 20000, DEFAULT_MAIN_PRIORITY );
	RoombaPhysRTS = new RTPeerController( debugger, "RoombaPhys" );
	OTPhysThr_RoombaPhys = new RTThread( RoombaPhysRTS, 20000, DEFAULT_MAIN_PRIORITY );
}

void _rtg_mapLogicalThreads( RTController * controller )
{
	ThreadJsonTranslate = OtherThreadRTS;
	ThreadRoomba = RoombaPhysRTS;
	ThreadSerial = PSerialRTS;
	ThreadUserInterface = EigenThreadRTS;
}

void _rtg_deleteThreads( void )
{
	delete OTPhysThr_EigenThread;
	delete EigenThreadRTS;
	delete OTPhysThr_OtherThread;
	delete OtherThreadRTS;
	delete OTPhysThr_PSerial;
	delete PSerialRTS;
	delete OTPhysThr_RoombaPhys;
	delete RoombaPhysRTS;
}
#else

void _rtg_mapLogicalThreads( RTController * controller )
{
	ThreadJsonTranslate = controller;
	ThreadRoomba = controller;
	ThreadSerial = controller;
	ThreadUserInterface = controller;
}
#endif

const char * const default_argv[] = { "topCap" };

static const RTSystemDescriptor _rtg_system =
{
	&topCap
#if USE_THREADS
  , DEFAULT_MAIN_PRIORITY
  , 20000
  , DEFAULT_TIMER_PRIORITY
  , 20000
  , _rtg_createThreads
  , _rtg_deleteThreads
#endif
  , _rtg_mapLogicalThreads
};

int RTMain::entryPoint( int argc, const char * const * argv )
{
	if( argc <= 0 )
	{
		argc = 1;
		argv = default_argv;
	}
	_argc   = argc;
	_argv   = argv;
	_system = &_rtg_system;
	return execute();
}

// }}}RME
