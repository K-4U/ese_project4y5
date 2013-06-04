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
		  , rti_totalAngle
		  , rti_stop
		};

	protected:
		enum { rtiLast_programProtocol = rti_stop };

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
		// {{{RME inSignal 'totalAngle'
		// {{{RME general 'documentation'
		/* {{{USR

		   }}}USR */
		// }}}RME
		inline RTInSignal totalAngle( void );
		// }}}RME
		// {{{RME inSignal 'stop'
		// {{{RME general 'documentation'
		/* {{{USR

		   }}}USR */
		// }}}RME
		inline RTInSignal stop( void );
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
		// {{{RME inSignal 'getTotalAngle'
		// {{{RME general 'documentation'
		/* {{{USR
		Argument tells us wether to reset or not!
		   }}}USR */
		// }}}RME
		inline RTOutSignal getTotalAngle( const bool & data );
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
		  , rti_getTotalAngle
		};

	protected:
		enum { rtiLast_programProtocol = rti_getTotalAngle };

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
		// {{{RME outSignal 'getTotalAngle'
		// {{{RME general 'documentation'
		/* {{{USR
		Argument tells us wether to reset or not!
		   }}}USR */
		// }}}RME
		inline RTInSignal getTotalAngle( void );
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
		// {{{RME outSignal 'totalAngle'
		// {{{RME general 'documentation'
		/* {{{USR

		   }}}USR */
		// }}}RME
		inline RTOutSignal totalAngle( const int & data );
		// }}}RME
		// {{{RME outSignal 'stop'
		// {{{RME general 'documentation'
		/* {{{USR

		   }}}USR */
		// }}}RME
		inline RTOutSignal stop( void );
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

// {{{RME inSignal 'totalAngle'
// {{{RME general 'documentation'
/* {{{USR

   }}}USR */
// }}}RME
inline RTInSignal programProtocol::Base::totalAngle( void )
{
	return RTInSignal( this, rti_totalAngle );
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

// {{{RME inSignal 'getTotalAngle'
// {{{RME general 'documentation'
/* {{{USR
Argument tells us wether to reset or not!
   }}}USR */
// }}}RME
inline RTOutSignal programProtocol::Base::getTotalAngle( const bool & data )
{
	return RTOutSignal( this, Conjugate::rti_getTotalAngle, &data, &RTType_bool );
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

// {{{RME outSignal 'getTotalAngle'
// {{{RME general 'documentation'
/* {{{USR
Argument tells us wether to reset or not!
   }}}USR */
// }}}RME
inline RTInSignal programProtocol::Conjugate::getTotalAngle( void )
{
	return RTInSignal( this, rti_getTotalAngle );
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

// {{{RME outSignal 'totalAngle'
// {{{RME general 'documentation'
/* {{{USR

   }}}USR */
// }}}RME
inline RTOutSignal programProtocol::Conjugate::totalAngle( const int & data )
{
	return RTOutSignal( this, Base::rti_totalAngle, &data, &RTType_int );
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

#endif /* programProtocol_H */

// }}}RME
