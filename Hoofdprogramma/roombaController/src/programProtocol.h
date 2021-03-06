// {{{RME classifier 'Logical View::Roomba::programProtocol'

#ifndef programProtocol_H
#define programProtocol_H

#ifdef PRAGMA
#pragma interface "programProtocol.h"
#endif

#include <RTSystem/roombaController.h>
#include <byteArray.h>
#include <clsDriveCommand.h>
#include <clsRoomba.h>
#include <logEntry.h>

struct programProtocol
{
	class Base : public RTRootProtocol
	{
	public:
		inline Base( void );
		inline ~Base( void );
		enum
		{
			rti_start = rtiLast_RTRootProtocol + 1
		  , rti_bumpersTriggered
		  , rti_stop
		  , rti_sideBrushOverCurrent
		  , rti_isCharging
		};

	protected:
		enum { rtiLast_programProtocol = rti_isCharging };

	public:
		// {{{RME inSignal 'start'
		// {{{RME general 'documentation'
		/* {{{USR
		Argument carries the battery level in percentage
		   }}}USR */
		// }}}RME
		inline RTInSignal start( void );
		// }}}RME
		// {{{RME inSignal 'bumpersTriggered'
		// {{{RME general 'documentation'
		/* {{{USR

		   }}}USR */
		// }}}RME
		inline RTInSignal bumpersTriggered( void );
		// }}}RME
		// {{{RME inSignal 'stop'
		// {{{RME general 'documentation'
		/* {{{USR

		   }}}USR */
		// }}}RME
		inline RTInSignal stop( void );
		// }}}RME
		// {{{RME inSignal 'sideBrushOverCurrent'
		// {{{RME general 'documentation'
		/* {{{USR

		   }}}USR */
		// }}}RME
		inline RTInSignal sideBrushOverCurrent( void );
		// }}}RME
		// {{{RME inSignal 'isCharging'
		// {{{RME general 'documentation'
		/* {{{USR

		   }}}USR */
		// }}}RME
		inline RTInSignal isCharging( void );
		// }}}RME
		// {{{RME inSignal 'playSong'
		// {{{RME general 'documentation'
		/* {{{USR

		   }}}USR */
		// }}}RME
		inline RTOutSignal playSong( const int & data );
		// }}}RME
		// {{{RME inSignal 'stopProgram'
		// {{{RME general 'documentation'
		/* {{{USR
		Argument gives reason code:
		1 - Battery empty or too low.
		2 - Requested from GUI
		   }}}USR */
		// }}}RME
		inline RTOutSignal stopProgram( const int & data );
		// }}}RME
		// {{{RME inSignal 'drive'
		// {{{RME general 'documentation'
		/* {{{USR

		   }}}USR */
		// }}}RME
		inline RTOutSignal drive( const RTTypedValue_clsDriveCommand & data );
		// }}}RME
		// {{{RME inSignal 'getSensor'
		// {{{RME general 'documentation'
		/* {{{USR
		byteArray is just a list of integers that we want to know here!
		   }}}USR */
		// }}}RME
		inline RTOutSignal getSensor( const RTTypedValue_byteArray & data );
		// }}}RME
		// {{{RME inSignal 'doSend'
		// {{{RME general 'documentation'
		/* {{{USR

		   }}}USR */
		// }}}RME
		inline RTOutSignal doSend( const RTTypedValue_byteArray & data );
		// }}}RME
		// {{{RME inSignal 'setMotors'
		// {{{RME general 'documentation'
		/* {{{USR

		   }}}USR */
		// }}}RME
		inline RTOutSignal setMotors( const clsRoomba::RTTypedValue_clsMotors & data );
		// }}}RME
		// {{{RME inSignal 'log'
		// {{{RME general 'documentation'
		/* {{{USR

		   }}}USR */
		// }}}RME
		inline RTOutSignal log( const RTTypedValue_logEntry & data );
		// }}}RME
		static const RTProtocolDescriptor rt_class;

	private:
		static const RTSignalDescriptor rt_signals[];
	};
	class Conjugate : public RTRootProtocol
	{
	public:
		inline Conjugate( void );
		inline ~Conjugate( void );
		enum
		{
			rti_playSong = rtiLast_RTRootProtocol + 1
		  , rti_stopProgram
		  , rti_drive
		  , rti_getSensor
		  , rti_doSend
		  , rti_setMotors
		  , rti_log
		};

	protected:
		enum { rtiLast_programProtocol = rti_log };

	public:
		// {{{RME outSignal 'playSong'
		// {{{RME general 'documentation'
		/* {{{USR

		   }}}USR */
		// }}}RME
		inline RTInSignal playSong( void );
		// }}}RME
		// {{{RME outSignal 'stopProgram'
		// {{{RME general 'documentation'
		/* {{{USR
		Argument gives reason code:
		1 - Battery empty or too low.
		2 - Requested from GUI
		   }}}USR */
		// }}}RME
		inline RTInSignal stopProgram( void );
		// }}}RME
		// {{{RME outSignal 'drive'
		// {{{RME general 'documentation'
		/* {{{USR

		   }}}USR */
		// }}}RME
		inline RTInSignal drive( void );
		// }}}RME
		// {{{RME outSignal 'getSensor'
		// {{{RME general 'documentation'
		/* {{{USR
		byteArray is just a list of integers that we want to know here!
		   }}}USR */
		// }}}RME
		inline RTInSignal getSensor( void );
		// }}}RME
		// {{{RME outSignal 'doSend'
		// {{{RME general 'documentation'
		/* {{{USR

		   }}}USR */
		// }}}RME
		inline RTInSignal doSend( void );
		// }}}RME
		// {{{RME outSignal 'setMotors'
		// {{{RME general 'documentation'
		/* {{{USR

		   }}}USR */
		// }}}RME
		inline RTInSignal setMotors( void );
		// }}}RME
		// {{{RME outSignal 'log'
		// {{{RME general 'documentation'
		/* {{{USR

		   }}}USR */
		// }}}RME
		inline RTInSignal log( void );
		// }}}RME
		// {{{RME outSignal 'start'
		// {{{RME general 'documentation'
		/* {{{USR
		Argument carries the battery level in percentage
		   }}}USR */
		// }}}RME
		inline RTOutSignal start( const int & data );
		// }}}RME
		// {{{RME outSignal 'bumpersTriggered'
		// {{{RME general 'documentation'
		/* {{{USR

		   }}}USR */
		// }}}RME
		inline RTOutSignal bumpersTriggered( const clsRoomba::RTTypedValue_clsBumpersAndCliff & data );
		// }}}RME
		// {{{RME outSignal 'stop'
		// {{{RME general 'documentation'
		/* {{{USR

		   }}}USR */
		// }}}RME
		inline RTOutSignal stop( void );
		// }}}RME
		// {{{RME outSignal 'sideBrushOverCurrent'
		// {{{RME general 'documentation'
		/* {{{USR

		   }}}USR */
		// }}}RME
		inline RTOutSignal sideBrushOverCurrent( void );
		// }}}RME
		// {{{RME outSignal 'isCharging'
		// {{{RME general 'documentation'
		/* {{{USR

		   }}}USR */
		// }}}RME
		inline RTOutSignal isCharging( const int & data );
		// }}}RME
		static const RTProtocolDescriptor rt_class;

	private:
		static const RTSignalDescriptor rt_signals[];
	};
};

inline programProtocol::Base::Base( void )
	: RTRootProtocol()
{
}

inline programProtocol::Base::~Base( void )
{
}

// {{{RME inSignal 'start'
// {{{RME general 'documentation'
/* {{{USR
Argument carries the battery level in percentage
   }}}USR */
// }}}RME
inline RTInSignal programProtocol::Base::start( void )
{
	return RTInSignal( this, rti_start );
}
// }}}RME

// {{{RME inSignal 'bumpersTriggered'
// {{{RME general 'documentation'
/* {{{USR

   }}}USR */
// }}}RME
inline RTInSignal programProtocol::Base::bumpersTriggered( void )
{
	return RTInSignal( this, rti_bumpersTriggered );
}
// }}}RME

// {{{RME inSignal 'stop'
// {{{RME general 'documentation'
/* {{{USR

   }}}USR */
// }}}RME
inline RTInSignal programProtocol::Base::stop( void )
{
	return RTInSignal( this, rti_stop );
}
// }}}RME

// {{{RME inSignal 'sideBrushOverCurrent'
// {{{RME general 'documentation'
/* {{{USR

   }}}USR */
// }}}RME
inline RTInSignal programProtocol::Base::sideBrushOverCurrent( void )
{
	return RTInSignal( this, rti_sideBrushOverCurrent );
}
// }}}RME

// {{{RME inSignal 'isCharging'
// {{{RME general 'documentation'
/* {{{USR

   }}}USR */
// }}}RME
inline RTInSignal programProtocol::Base::isCharging( void )
{
	return RTInSignal( this, rti_isCharging );
}
// }}}RME

// {{{RME inSignal 'playSong'
// {{{RME general 'documentation'
/* {{{USR

   }}}USR */
// }}}RME
inline RTOutSignal programProtocol::Base::playSong( const int & data )
{
	return RTOutSignal( this, Conjugate::rti_playSong, &data, &RTType_int );
}
// }}}RME

// {{{RME inSignal 'stopProgram'
// {{{RME general 'documentation'
/* {{{USR
Argument gives reason code:
1 - Battery empty or too low.
2 - Requested from GUI
   }}}USR */
// }}}RME
inline RTOutSignal programProtocol::Base::stopProgram( const int & data )
{
	return RTOutSignal( this, Conjugate::rti_stopProgram, &data, &RTType_int );
}
// }}}RME

// {{{RME inSignal 'drive'
// {{{RME general 'documentation'
/* {{{USR

   }}}USR */
// }}}RME
inline RTOutSignal programProtocol::Base::drive( const RTTypedValue_clsDriveCommand & data )
{
	return RTOutSignal( this, Conjugate::rti_drive, data.data, data.type );
}
// }}}RME

// {{{RME inSignal 'getSensor'
// {{{RME general 'documentation'
/* {{{USR
byteArray is just a list of integers that we want to know here!
   }}}USR */
// }}}RME
inline RTOutSignal programProtocol::Base::getSensor( const RTTypedValue_byteArray & data )
{
	return RTOutSignal( this, Conjugate::rti_getSensor, data.data, data.type );
}
// }}}RME

// {{{RME inSignal 'doSend'
// {{{RME general 'documentation'
/* {{{USR

   }}}USR */
// }}}RME
inline RTOutSignal programProtocol::Base::doSend( const RTTypedValue_byteArray & data )
{
	return RTOutSignal( this, Conjugate::rti_doSend, data.data, data.type );
}
// }}}RME

// {{{RME inSignal 'setMotors'
// {{{RME general 'documentation'
/* {{{USR

   }}}USR */
// }}}RME
inline RTOutSignal programProtocol::Base::setMotors( const clsRoomba::RTTypedValue_clsMotors & data )
{
	return RTOutSignal( this, Conjugate::rti_setMotors, data.data, data.type );
}
// }}}RME

// {{{RME inSignal 'log'
// {{{RME general 'documentation'
/* {{{USR

   }}}USR */
// }}}RME
inline RTOutSignal programProtocol::Base::log( const RTTypedValue_logEntry & data )
{
	return RTOutSignal( this, Conjugate::rti_log, data.data, data.type );
}
// }}}RME

inline programProtocol::Conjugate::Conjugate( void )
	: RTRootProtocol()
{
}

inline programProtocol::Conjugate::~Conjugate( void )
{
}

// {{{RME outSignal 'playSong'
// {{{RME general 'documentation'
/* {{{USR

   }}}USR */
// }}}RME
inline RTInSignal programProtocol::Conjugate::playSong( void )
{
	return RTInSignal( this, rti_playSong );
}
// }}}RME

// {{{RME outSignal 'stopProgram'
// {{{RME general 'documentation'
/* {{{USR
Argument gives reason code:
1 - Battery empty or too low.
2 - Requested from GUI
   }}}USR */
// }}}RME
inline RTInSignal programProtocol::Conjugate::stopProgram( void )
{
	return RTInSignal( this, rti_stopProgram );
}
// }}}RME

// {{{RME outSignal 'drive'
// {{{RME general 'documentation'
/* {{{USR

   }}}USR */
// }}}RME
inline RTInSignal programProtocol::Conjugate::drive( void )
{
	return RTInSignal( this, rti_drive );
}
// }}}RME

// {{{RME outSignal 'getSensor'
// {{{RME general 'documentation'
/* {{{USR
byteArray is just a list of integers that we want to know here!
   }}}USR */
// }}}RME
inline RTInSignal programProtocol::Conjugate::getSensor( void )
{
	return RTInSignal( this, rti_getSensor );
}
// }}}RME

// {{{RME outSignal 'doSend'
// {{{RME general 'documentation'
/* {{{USR

   }}}USR */
// }}}RME
inline RTInSignal programProtocol::Conjugate::doSend( void )
{
	return RTInSignal( this, rti_doSend );
}
// }}}RME

// {{{RME outSignal 'setMotors'
// {{{RME general 'documentation'
/* {{{USR

   }}}USR */
// }}}RME
inline RTInSignal programProtocol::Conjugate::setMotors( void )
{
	return RTInSignal( this, rti_setMotors );
}
// }}}RME

// {{{RME outSignal 'log'
// {{{RME general 'documentation'
/* {{{USR

   }}}USR */
// }}}RME
inline RTInSignal programProtocol::Conjugate::log( void )
{
	return RTInSignal( this, rti_log );
}
// }}}RME

// {{{RME outSignal 'start'
// {{{RME general 'documentation'
/* {{{USR
Argument carries the battery level in percentage
   }}}USR */
// }}}RME
inline RTOutSignal programProtocol::Conjugate::start( const int & data )
{
	return RTOutSignal( this, Base::rti_start, &data, &RTType_int );
}
// }}}RME

// {{{RME outSignal 'bumpersTriggered'
// {{{RME general 'documentation'
/* {{{USR

   }}}USR */
// }}}RME
inline RTOutSignal programProtocol::Conjugate::bumpersTriggered( const clsRoomba::RTTypedValue_clsBumpersAndCliff & data )
{
	return RTOutSignal( this, Base::rti_bumpersTriggered, data.data, data.type );
}
// }}}RME

// {{{RME outSignal 'stop'
// {{{RME general 'documentation'
/* {{{USR

   }}}USR */
// }}}RME
inline RTOutSignal programProtocol::Conjugate::stop( void )
{
	return RTOutSignal( this, Base::rti_stop, (const void *)0, &RTType_void );
}
// }}}RME

// {{{RME outSignal 'sideBrushOverCurrent'
// {{{RME general 'documentation'
/* {{{USR

   }}}USR */
// }}}RME
inline RTOutSignal programProtocol::Conjugate::sideBrushOverCurrent( void )
{
	return RTOutSignal( this, Base::rti_sideBrushOverCurrent, (const void *)0, &RTType_void );
}
// }}}RME

// {{{RME outSignal 'isCharging'
// {{{RME general 'documentation'
/* {{{USR

   }}}USR */
// }}}RME
inline RTOutSignal programProtocol::Conjugate::isCharging( const int & data )
{
	return RTOutSignal( this, Base::rti_isCharging, &data, &RTType_int );
}
// }}}RME

#endif /* programProtocol_H */

// }}}RME
