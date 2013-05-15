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
		enum { rti_sendCommand = rtiLast_RTRootProtocol + 1 };

	protected:
		enum { rtiLast_serialProtocol = rti_sendCommand };

	public:
		// {{{RME inSignal 'sendCommand'
		// {{{RME general 'documentation'
		/* {{{USR

		   }}}USR */
		// }}}RME
		inline RTInSignal sendCommand( void );
		// }}}RME
		// {{{RME inSignal 'commandReceived'
		// {{{RME general 'documentation'
		/* {{{USR

		   }}}USR */
		// }}}RME
		inline RTOutSignal commandReceived( const RTTypedValue_byteArray & data );
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
		enum { rti_commandReceived = rtiLast_RTRootProtocol + 1 };

	protected:
		enum { rtiLast_serialProtocol = rti_commandReceived };

	public:
		// {{{RME outSignal 'commandReceived'
		// {{{RME general 'documentation'
		/* {{{USR

		   }}}USR */
		// }}}RME
		inline RTInSignal commandReceived( void );
		// }}}RME
		// {{{RME outSignal 'sendCommand'
		// {{{RME general 'documentation'
		/* {{{USR

		   }}}USR */
		// }}}RME
		inline RTOutSignal sendCommand( const RTTypedValue_byteArray & data );
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

#endif /* serialProtocol_H */

// }}}RME
