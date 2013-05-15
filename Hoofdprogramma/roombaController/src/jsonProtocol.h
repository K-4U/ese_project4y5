// {{{RME classifier 'Logical View::TCPIP::jsonProtocol'

#ifndef jsonProtocol_H
#define jsonProtocol_H

#ifdef PRAGMA
#pragma interface "jsonProtocol.h"
#endif

#include <RTSystem/roombaController.h>
#include <jsonCommand.h>

struct jsonProtocol
{
	class Base : public RTRootProtocol
	{
	public:
		inline Base( void );
		inline ~Base( void );
		enum { rti_sendCommand = rtiLast_RTRootProtocol + 1 };

	protected:
		enum { rtiLast_jsonProtocol = rti_sendCommand };

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
		inline RTOutSignal commandReceived( const RTTypedValue_jsonCommand & data );
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
		enum { rtiLast_jsonProtocol = rti_commandReceived };

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
		inline RTOutSignal sendCommand( const RTTypedValue_jsonCommand & data );
		// }}}RME
		static const RTProtocolDescriptor rt_class;

	private:
		static const RTSignalDescriptor rt_signals[];
	};
};

inline jsonProtocol::Base::Base( void )
	: RTRootProtocol()
{
}

inline jsonProtocol::Base::~Base( void )
{
}

// {{{RME inSignal 'sendCommand'
// {{{RME general 'documentation'
/* {{{USR

   }}}USR */
// }}}RME
inline RTInSignal jsonProtocol::Base::sendCommand( void )
{
	return RTInSignal( this, rti_sendCommand );
}
// }}}RME

// {{{RME inSignal 'commandReceived'
// {{{RME general 'documentation'
/* {{{USR

   }}}USR */
// }}}RME
inline RTOutSignal jsonProtocol::Base::commandReceived( const RTTypedValue_jsonCommand & data )
{
	return RTOutSignal( this, Conjugate::rti_commandReceived, data.data, data.type );
}
// }}}RME

inline jsonProtocol::Conjugate::Conjugate( void )
	: RTRootProtocol()
{
}

inline jsonProtocol::Conjugate::~Conjugate( void )
{
}

// {{{RME outSignal 'commandReceived'
// {{{RME general 'documentation'
/* {{{USR

   }}}USR */
// }}}RME
inline RTInSignal jsonProtocol::Conjugate::commandReceived( void )
{
	return RTInSignal( this, rti_commandReceived );
}
// }}}RME

// {{{RME outSignal 'sendCommand'
// {{{RME general 'documentation'
/* {{{USR

   }}}USR */
// }}}RME
inline RTOutSignal jsonProtocol::Conjugate::sendCommand( const RTTypedValue_jsonCommand & data )
{
	return RTOutSignal( this, Base::rti_sendCommand, data.data, data.type );
}
// }}}RME

#endif /* jsonProtocol_H */

// }}}RME
