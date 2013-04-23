// {{{RME component 'Component View::ourProgram'

#if defined( PRAGMA ) && ! defined( PRAGMA_IMPLEMENTED )
#pragma implementation "RTSystem/ourProgram.h"
#endif

#include <RTSystem/ourProgram.h>
extern const RTActorClass topCap;

RTController * ThreadUserInterface = (RTController *)0;

#if USE_THREADS
static RTPeerController * EigenThreadRTS = (RTPeerController *)0;
static RTThread * OTPhysThr_EigenThread = (RTThread *)0;

void _rtg_createThreads( RTDebugger * debugger )
{
	EigenThreadRTS = new RTPeerController( debugger, "EigenThread" );
	OTPhysThr_EigenThread = new RTThread( EigenThreadRTS, 20000, DEFAULT_MAIN_PRIORITY );
}

void _rtg_mapLogicalThreads( RTController * controller )
{
	ThreadUserInterface = EigenThreadRTS;
}

void _rtg_deleteThreads( void )
{
	delete OTPhysThr_EigenThread;
	delete EigenThreadRTS;
}
#else

void _rtg_mapLogicalThreads( RTController * controller )
{
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
