// {{{RME classifier 'Logical View::Serial::serialRawProtocol'

#ifndef serialRawProtocol_H
#define serialRawProtocol_H

#ifdef PRAGMA
#pragma interface "serialRawProtocol.h"
#endif

#include <RTSystem/ourProgram.h>
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
		static const RTProtocolDescriptor rt_class;

	private:
		static const RTSignalDescriptor rt_signals[];
	};
	class Conjugate : public RTRootProtocol
	{
	public:
		inline Conjugate( void );
		inline ~Conjugate( void );
		enum { rti_dataReceived = rtiLast_RTRootProtocol + 1 };

	protected:
		enum { rtiLast_serialRawProtocol = rti_dataReceived };

	public:
		// {{{RME outSignal 'dataReceived'
		// {{{RME general 'documentation'
		/* {{{USR

		   }}}USR */
		// }}}RME
		inline RTInSignal dataReceived( void );
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

#endif /* serialRawProtocol_H */

// }}}RME
