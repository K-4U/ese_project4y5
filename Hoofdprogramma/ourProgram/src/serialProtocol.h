// {{{RME classifier 'Logical View::Serial::serialProtocol'

#ifndef serialProtocol_H
#define serialProtocol_H

#ifdef PRAGMA
#pragma interface "serialProtocol.h"
#endif

#include <RTSystem/ourProgram.h>

struct serialProtocol
{
	class Base : public RTRootProtocol
	{
	public:
		inline Base( void );
		inline ~Base( void );

	protected:
		enum { rtiLast_serialProtocol = rtiLast_RTRootProtocol };

	public:
		// {{{RME inSignal 'dataReceived'
		// {{{RME general 'documentation'
		/* {{{USR

		   }}}USR */
		// }}}RME
		inline RTOutSignal dataReceived( const RTTypedValue_RTString & data );
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
		enum { rtiLast_serialProtocol = rti_dataReceived };

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

inline serialProtocol::Base::Base( void )
	: RTRootProtocol()
{
}

inline serialProtocol::Base::~Base( void )
{
}

// {{{RME inSignal 'dataReceived'
// {{{RME general 'documentation'
/* {{{USR

   }}}USR */
// }}}RME
inline RTOutSignal serialProtocol::Base::dataReceived( const RTTypedValue_RTString & data )
{
	return RTOutSignal( this, Conjugate::rti_dataReceived, data.data, data.type );
}
// }}}RME

inline serialProtocol::Conjugate::Conjugate( void )
	: RTRootProtocol()
{
}

inline serialProtocol::Conjugate::~Conjugate( void )
{
}

// {{{RME outSignal 'dataReceived'
// {{{RME general 'documentation'
/* {{{USR

   }}}USR */
// }}}RME
inline RTInSignal serialProtocol::Conjugate::dataReceived( void )
{
	return RTInSignal( this, rti_dataReceived );
}
// }}}RME

#endif /* serialProtocol_H */

// }}}RME
