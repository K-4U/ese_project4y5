// {{{RME classifier 'Logical View::Serial::serialRawProtocol'

#ifndef serialRawProtocol_H
#define serialRawProtocol_H

#ifdef PRAGMA
#pragma interface "serialRawProtocol.h"
#endif

#include <RTSystem/roombaController.h>
#include <byteArray.h>

struct serialRawProtocol
{
	class Base : public RTRootProtocol
	{
	public:
		inline Base( void );
		inline ~Base( void );

	protected:
		enum { rtiLast_serialRawProtocol = rtiLast_RTRootProtocol };

	public:
		// {{{RME inSignal 'dataReceived'
		// {{{RME general 'documentation'
		/* {{{USR

		   }}}USR */
		// }}}RME
		inline RTOutSignal dataReceived( const RTTypedValue_byteArray & data );
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
			rti_dataReceived = rtiLast_RTRootProtocol + 1
		  , rti_comOpened
		  , rti_comError
		};

	protected:
		enum { rtiLast_serialRawProtocol = rti_comError };

	public:
		// {{{RME outSignal 'dataReceived'
		// {{{RME general 'documentation'
		/* {{{USR

		   }}}USR */
		// }}}RME
		inline RTInSignal dataReceived( void );
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
		static const RTProtocolDescriptor rt_class;

	private:
		static const RTSignalDescriptor rt_signals[];
	};
};

inline serialRawProtocol::Base::Base( void )
	: RTRootProtocol()
{
}

inline serialRawProtocol::Base::~Base( void )
{
}

// {{{RME inSignal 'dataReceived'
// {{{RME general 'documentation'
/* {{{USR

   }}}USR */
// }}}RME
inline RTOutSignal serialRawProtocol::Base::dataReceived( const RTTypedValue_byteArray & data )
{
	return RTOutSignal( this, Conjugate::rti_dataReceived, data.data, data.type );
}
// }}}RME

// {{{RME inSignal 'comOpened'
// {{{RME general 'documentation'
/* {{{USR

   }}}USR */
// }}}RME
inline RTOutSignal serialRawProtocol::Base::comOpened( void )
{
	return RTOutSignal( this, Conjugate::rti_comOpened, (const void *)0, &RTType_void );
}
// }}}RME

// {{{RME inSignal 'comError'
// {{{RME general 'documentation'
/* {{{USR

   }}}USR */
// }}}RME
inline RTOutSignal serialRawProtocol::Base::comError( void )
{
	return RTOutSignal( this, Conjugate::rti_comError, (const void *)0, &RTType_void );
}
// }}}RME

inline serialRawProtocol::Conjugate::Conjugate( void )
	: RTRootProtocol()
{
}

inline serialRawProtocol::Conjugate::~Conjugate( void )
{
}

// {{{RME outSignal 'dataReceived'
// {{{RME general 'documentation'
/* {{{USR

   }}}USR */
// }}}RME
inline RTInSignal serialRawProtocol::Conjugate::dataReceived( void )
{
	return RTInSignal( this, rti_dataReceived );
}
// }}}RME

// {{{RME outSignal 'comOpened'
// {{{RME general 'documentation'
/* {{{USR

   }}}USR */
// }}}RME
inline RTInSignal serialRawProtocol::Conjugate::comOpened( void )
{
	return RTInSignal( this, rti_comOpened );
}
// }}}RME

// {{{RME outSignal 'comError'
// {{{RME general 'documentation'
/* {{{USR

   }}}USR */
// }}}RME
inline RTInSignal serialRawProtocol::Conjugate::comError( void )
{
	return RTInSignal( this, rti_comError );
}
// }}}RME

#endif /* serialRawProtocol_H */

// }}}RME
