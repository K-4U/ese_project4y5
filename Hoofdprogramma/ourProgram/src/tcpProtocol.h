// {{{RME classifier 'Logical View::tcpProtocol'

#ifndef tcpProtocol_H
#define tcpProtocol_H

#ifdef PRAGMA
#pragma interface "tcpProtocol.h"
#endif

#include <RTSystem/ourProgram.h>

struct tcpProtocol
{
	class Base : public RTRootProtocol
	{
	public:
		inline Base( void );
		inline ~Base( void );

	protected:
		enum { rtiLast_tcpProtocol = rtiLast_RTRootProtocol };

	public:
		// {{{RME inSignal 'dataReceived'
		// {{{RME general 'documentation'
		/* {{{USR

		   }}}USR */
		// }}}RME
		inline RTOutSignal dataReceived( const RTTypedValue_RTString & data );
		// }}}RME
		// {{{RME inSignal 'sock'
		// {{{RME general 'documentation'
		/* {{{USR

		   }}}USR */
		// }}}RME
		inline RTOutSignal sock( const unsigned & data );
		// }}}RME
		// {{{RME inSignal 'noSock'
		// {{{RME general 'documentation'
		/* {{{USR

		   }}}USR */
		// }}}RME
		inline RTOutSignal noSock( void );
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
		  , rti_sock
		  , rti_noSock
		};

	protected:
		enum { rtiLast_tcpProtocol = rti_noSock };

	public:
		// {{{RME outSignal 'dataReceived'
		// {{{RME general 'documentation'
		/* {{{USR

		   }}}USR */
		// }}}RME
		inline RTInSignal dataReceived( void );
		// }}}RME
		// {{{RME outSignal 'sock'
		// {{{RME general 'documentation'
		/* {{{USR

		   }}}USR */
		// }}}RME
		inline RTInSignal sock( void );
		// }}}RME
		// {{{RME outSignal 'noSock'
		// {{{RME general 'documentation'
		/* {{{USR

		   }}}USR */
		// }}}RME
		inline RTInSignal noSock( void );
		// }}}RME
		static const RTProtocolDescriptor rt_class;

	private:
		static const RTSignalDescriptor rt_signals[];
	};
};

inline tcpProtocol::Base::Base( void )
	: RTRootProtocol()
{
}

inline tcpProtocol::Base::~Base( void )
{
}

// {{{RME inSignal 'dataReceived'
// {{{RME general 'documentation'
/* {{{USR

   }}}USR */
// }}}RME
inline RTOutSignal tcpProtocol::Base::dataReceived( const RTTypedValue_RTString & data )
{
	return RTOutSignal( this, Conjugate::rti_dataReceived, data.data, data.type );
}
// }}}RME

// {{{RME inSignal 'sock'
// {{{RME general 'documentation'
/* {{{USR

   }}}USR */
// }}}RME
inline RTOutSignal tcpProtocol::Base::sock( const unsigned & data )
{
	return RTOutSignal( this, Conjugate::rti_sock, &data, &RTType_unsigned );
}
// }}}RME

// {{{RME inSignal 'noSock'
// {{{RME general 'documentation'
/* {{{USR

   }}}USR */
// }}}RME
inline RTOutSignal tcpProtocol::Base::noSock( void )
{
	return RTOutSignal( this, Conjugate::rti_noSock, (const void *)0, &RTType_void );
}
// }}}RME

inline tcpProtocol::Conjugate::Conjugate( void )
	: RTRootProtocol()
{
}

inline tcpProtocol::Conjugate::~Conjugate( void )
{
}

// {{{RME outSignal 'dataReceived'
// {{{RME general 'documentation'
/* {{{USR

   }}}USR */
// }}}RME
inline RTInSignal tcpProtocol::Conjugate::dataReceived( void )
{
	return RTInSignal( this, rti_dataReceived );
}
// }}}RME

// {{{RME outSignal 'sock'
// {{{RME general 'documentation'
/* {{{USR

   }}}USR */
// }}}RME
inline RTInSignal tcpProtocol::Conjugate::sock( void )
{
	return RTInSignal( this, rti_sock );
}
// }}}RME

// {{{RME outSignal 'noSock'
// {{{RME general 'documentation'
/* {{{USR

   }}}USR */
// }}}RME
inline RTInSignal tcpProtocol::Conjugate::noSock( void )
{
	return RTInSignal( this, rti_noSock );
}
// }}}RME

#endif /* tcpProtocol_H */

// }}}RME
