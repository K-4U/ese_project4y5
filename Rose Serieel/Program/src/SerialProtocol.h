// {{{RME classifier 'Logical View::SerialProtocol'

#ifndef SerialProtocol_H
#define SerialProtocol_H

#ifdef PRAGMA
#pragma interface "SerialProtocol.h"
#endif

#include <RTSystem/Program.h>

struct SerialProtocol
{
	class Base : public RTRootProtocol
	{
	public:
		inline Base( void );
		inline ~Base( void );

	protected:
		enum { rtiLast_SerialProtocol = rtiLast_RTRootProtocol };

	public:
		// {{{RME inSignal 'DataReceived'
		// {{{RME general 'documentation'
		/* {{{USR

		   }}}USR */
		// }}}RME
		inline RTOutSignal DataReceived( const RTTypedValue_RTString & data );
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
		enum { rti_DataReceived = rtiLast_RTRootProtocol + 1 };

	protected:
		enum { rtiLast_SerialProtocol = rti_DataReceived };

	public:
		// {{{RME outSignal 'DataReceived'
		// {{{RME general 'documentation'
		/* {{{USR

		   }}}USR */
		// }}}RME
		inline RTInSignal DataReceived( void );
		// }}}RME
		static const RTProtocolDescriptor rt_class;

	private:
		static const RTSignalDescriptor rt_signals[];
	};
};

inline SerialProtocol::Base::Base( void )
	: RTRootProtocol()
{
}

inline SerialProtocol::Base::~Base( void )
{
}

// {{{RME inSignal 'DataReceived'
// {{{RME general 'documentation'
/* {{{USR

   }}}USR */
// }}}RME
inline RTOutSignal SerialProtocol::Base::DataReceived( const RTTypedValue_RTString & data )
{
	return RTOutSignal( this, Conjugate::rti_DataReceived, data.data, data.type );
}
// }}}RME

inline SerialProtocol::Conjugate::Conjugate( void )
	: RTRootProtocol()
{
}

inline SerialProtocol::Conjugate::~Conjugate( void )
{
}

// {{{RME outSignal 'DataReceived'
// {{{RME general 'documentation'
/* {{{USR

   }}}USR */
// }}}RME
inline RTInSignal SerialProtocol::Conjugate::DataReceived( void )
{
	return RTInSignal( this, rti_DataReceived );
}
// }}}RME

#endif /* SerialProtocol_H */

// }}}RME
