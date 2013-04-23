// {{{RME classifier 'Logical View::UserInterface::PGuiConnection'

#ifndef PGuiConnection_H
#define PGuiConnection_H

#ifdef PRAGMA
#pragma interface "PGuiConnection.h"
#endif

#include <RTSystem/WarmeDrankenAutomaatComponent.h>

struct PGuiConnection
{
	class Base : public RTRootProtocol
	{
	public:
		inline Base( void );
		inline ~Base( void );

	protected:
		enum { rtiLast_PGuiConnection = rtiLast_RTRootProtocol };

	public:
		// {{{RME inSignal 'data'
		// {{{RME general 'documentation'
		/* {{{USR

		   }}}USR */
		// }}}RME
		inline RTOutSignal data( const RTTypedValue_RTString & data );
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
			rti_data = rtiLast_RTRootProtocol + 1
		  , rti_sock
		  , rti_noSock
		};

	protected:
		enum { rtiLast_PGuiConnection = rti_noSock };

	public:
		// {{{RME outSignal 'data'
		// {{{RME general 'documentation'
		/* {{{USR

		   }}}USR */
		// }}}RME
		inline RTInSignal data( void );
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

inline PGuiConnection::Base::Base( void )
	: RTRootProtocol()
{
}

inline PGuiConnection::Base::~Base( void )
{
}

// {{{RME inSignal 'data'
// {{{RME general 'documentation'
/* {{{USR

   }}}USR */
// }}}RME
inline RTOutSignal PGuiConnection::Base::data( const RTTypedValue_RTString & data )
{
	return RTOutSignal( this, Conjugate::rti_data, data.data, data.type );
}
// }}}RME

// {{{RME inSignal 'sock'
// {{{RME general 'documentation'
/* {{{USR

   }}}USR */
// }}}RME
inline RTOutSignal PGuiConnection::Base::sock( const unsigned & data )
{
	return RTOutSignal( this, Conjugate::rti_sock, &data, &RTType_unsigned );
}
// }}}RME

// {{{RME inSignal 'noSock'
// {{{RME general 'documentation'
/* {{{USR

   }}}USR */
// }}}RME
inline RTOutSignal PGuiConnection::Base::noSock( void )
{
	return RTOutSignal( this, Conjugate::rti_noSock, (const void *)0, &RTType_void );
}
// }}}RME

inline PGuiConnection::Conjugate::Conjugate( void )
	: RTRootProtocol()
{
}

inline PGuiConnection::Conjugate::~Conjugate( void )
{
}

// {{{RME outSignal 'data'
// {{{RME general 'documentation'
/* {{{USR

   }}}USR */
// }}}RME
inline RTInSignal PGuiConnection::Conjugate::data( void )
{
	return RTInSignal( this, rti_data );
}
// }}}RME

// {{{RME outSignal 'sock'
// {{{RME general 'documentation'
/* {{{USR

   }}}USR */
// }}}RME
inline RTInSignal PGuiConnection::Conjugate::sock( void )
{
	return RTInSignal( this, rti_sock );
}
// }}}RME

// {{{RME outSignal 'noSock'
// {{{RME general 'documentation'
/* {{{USR

   }}}USR */
// }}}RME
inline RTInSignal PGuiConnection::Conjugate::noSock( void )
{
	return RTInSignal( this, rti_noSock );
}
// }}}RME

#endif /* PGuiConnection_H */

// }}}RME
