// {{{RME classifier 'Logical View::Serial::serialProtocol'

#ifndef serialProtocol_H
#define serialProtocol_H

#ifdef PRAGMA
#pragma interface "serialProtocol.h"
#endif

#include <RTSystem/roombaController.h>
#include <byteArray.h>

struct serialProtocol
{
	class Base : public RTRootProtocol
	{
	public:
		inline Base( void );
		inline ~Base( void );
		enum
		{
			rti_sendCommand = rtiLast_RTRootProtocol + 1
		  , rti_commandLength
		};

	protected:
		enum { rtiLast_serialProtocol = rti_commandLength };

	public:
		// {{{RME inSignal 'sendCommand'
		// {{{RME general 'documentation'
		/* {{{USR

		   }}}USR */
		// }}}RME
		inline RTInSignal sendCommand( void );
		// }}}RME
		// {{{RME inSignal 'commandLength'
		// {{{RME general 'documentation'
		/* {{{USR

		   }}}USR */
		// }}}RME
		inline RTInSignal commandLength( void );
		// }}}RME
		// {{{RME inSignal 'commandReceived'
		// {{{RME general 'documentation'
		/* {{{USR

		   }}}USR */
		// }}}RME
		inline RTOutSignal commandReceived( const RTTypedValue_byteArray & data );
		// }}}RME
		// {{{RME inSignal 'comOpened'
		// {{{RME general 'documentation'
		/* {{{USR

		   }}}USR */
		// }}}RME
		inline RTOutSignal comOpened( void );
		// }}}RME
		// {{{RME inSignal 'comError'
		// {{{RME general 'documentation'
		/* {{{USR

		   }}}USR */
		// }}}RME
		inline RTOutSignal comError( void );
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
			rti_commandReceived = rtiLast_RTRootProtocol + 1
		  , rti_comOpened
		  , rti_comError
		};

	protected:
		enum { rtiLast_serialProtocol = rti_comError };

	public:
		// {{{RME outSignal 'commandReceived'
		// {{{RME general 'documentation'
		/* {{{USR

		   }}}USR */
		// }}}RME
		inline RTInSignal commandReceived( void );
		// }}}RME
		// {{{RME outSignal 'comOpened'
		// {{{RME general 'documentation'
		/* {{{USR

		   }}}USR */
		// }}}RME
		inline RTInSignal comOpened( void );
		// }}}RME
		// {{{RME outSignal 'comError'
		// {{{RME general 'documentation'
		/* {{{USR

		   }}}USR */
		// }}}RME
		inline RTInSignal comError( void );
		// }}}RME
		// {{{RME outSignal 'sendCommand'
		// {{{RME general 'documentation'
		/* {{{USR

		   }}}USR */
		// }}}RME
		inline RTOutSignal sendCommand( const RTTypedValue_byteArray & data );
		// }}}RME
		// {{{RME outSignal 'commandLength'
		// {{{RME general 'documentation'
		/* {{{USR

		   }}}USR */
		// }}}RME
		inline RTOutSignal commandLength( const int & data );
		// }}}RME
		static const RTProtocolDescriptor rt_class;

	private:
		static const RTSignalDescriptor rt_signals[];
	};
};

inline serialProtocol::Base::Base( void )
	: RTRootProtocol()
{
}

inline serialProtocol::Base::~Base( void )
{
}

// {{{RME inSignal 'sendCommand'
// {{{RME general 'documentation'
/* {{{USR

   }}}USR */
// }}}RME
inline RTInSignal serialProtocol::Base::sendCommand( void )
{
	return RTInSignal( this, rti_sendCommand );
}
// }}}RME

// {{{RME inSignal 'commandLength'
// {{{RME general 'documentation'
/* {{{USR

   }}}USR */
// }}}RME
inline RTInSignal serialProtocol::Base::commandLength( void )
{
	return RTInSignal( this, rti_commandLength );
}
// }}}RME

// {{{RME inSignal 'commandReceived'
// {{{RME general 'documentation'
/* {{{USR

   }}}USR */
// }}}RME
inline RTOutSignal serialProtocol::Base::commandReceived( const RTTypedValue_byteArray & data )
{
	return RTOutSignal( this, Conjugate::rti_commandReceived, data.data, data.type );
}
// }}}RME

// {{{RME inSignal 'comOpened'
// {{{RME general 'documentation'
/* {{{USR

   }}}USR */
// }}}RME
inline RTOutSignal serialProtocol::Base::comOpened( void )
{
	return RTOutSignal( this, Conjugate::rti_comOpened, (const void *)0, &RTType_void );
}
// }}}RME

// {{{RME inSignal 'comError'
// {{{RME general 'documentation'
/* {{{USR

   }}}USR */
// }}}RME
inline RTOutSignal serialProtocol::Base::comError( void )
{
	return RTOutSignal( this, Conjugate::rti_comError, (const void *)0, &RTType_void );
}
// }}}RME

inline serialProtocol::Conjugate::Conjugate( void )
	: RTRootProtocol()
{
}

inline serialProtocol::Conjugate::~Conjugate( void )
{
}

// {{{RME outSignal 'commandReceived'
// {{{RME general 'documentation'
/* {{{USR

   }}}USR */
// }}}RME
inline RTInSignal serialProtocol::Conjugate::commandReceived( void )
{
	return RTInSignal( this, rti_commandReceived );
}
// }}}RME

// {{{RME outSignal 'comOpened'
// {{{RME general 'documentation'
/* {{{USR

   }}}USR */
// }}}RME
inline RTInSignal serialProtocol::Conjugate::comOpened( void )
{
	return RTInSignal( this, rti_comOpened );
}
// }}}RME

// {{{RME outSignal 'comError'
// {{{RME general 'documentation'
/* {{{USR

   }}}USR */
// }}}RME
inline RTInSignal serialProtocol::Conjugate::comError( void )
{
	return RTInSignal( this, rti_comError );
}
// }}}RME

// {{{RME outSignal 'sendCommand'
// {{{RME general 'documentation'
/* {{{USR

   }}}USR */
// }}}RME
inline RTOutSignal serialProtocol::Conjugate::sendCommand( const RTTypedValue_byteArray & data )
{
	return RTOutSignal( this, Base::rti_sendCommand, data.data, data.type );
}
// }}}RME

// {{{RME outSignal 'commandLength'
// {{{RME general 'documentation'
/* {{{USR

   }}}USR */
// }}}RME
inline RTOutSignal serialProtocol::Conjugate::commandLength( const int & data )
{
	return RTOutSignal( this, Base::rti_commandLength, &data, &RTType_int );
}
// }}}RME

#endif /* serialProtocol_H */

// }}}RME
