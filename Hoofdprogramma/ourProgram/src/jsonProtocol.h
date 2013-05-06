// {{{RME classifier 'Logical View::TCPIP::jsonProtocol'

#ifndef jsonProtocol_H
#define jsonProtocol_H

#ifdef PRAGMA
#pragma interface "jsonProtocol.h"
#endif

#include <RTSystem/ourProgram.h>
#include <jsonCommand.h>

struct jsonProtocol
{
	class Base : public RTRootProtocol
	{
	public:
		inline Base( void );
		inline ~Base( void );

	protected:
		enum { rtiLast_jsonProtocol = rtiLast_RTRootProtocol };

	public:
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

#endif /* jsonProtocol_H */

// }}}RME
