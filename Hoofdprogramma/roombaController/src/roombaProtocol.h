// {{{RME classifier 'Logical View::Roomba::roombaProtocol'

#ifndef roombaProtocol_H
#define roombaProtocol_H

#ifdef PRAGMA
#pragma interface "roombaProtocol.h"
#endif

#include <RTSystem/roombaController.h>
#include <byteArray.h>
#include <jsonCommand.h>

struct roombaProtocol
{
	class Base : public RTRootProtocol
	{
	public:
		inline Base( void );
		inline ~Base( void );
		enum
		{
			rti_dataReceived = rtiLast_RTRootProtocol + 1
		  , rti_commandReceived
		  , rti_ready
		};

	protected:
		enum { rtiLast_roombaProtocol = rti_ready };

	public:
		// {{{RME inSignal 'dataReceived'
		// {{{RME general 'documentation'
		/* {{{USR

		   }}}USR */
		// }}}RME
		inline RTInSignal dataReceived( void );
		// }}}RME
		// {{{RME inSignal 'commandReceived'
		// {{{RME general 'documentation'
		/* {{{USR

		   }}}USR */
		// }}}RME
		inline RTInSignal commandReceived( void );
		// }}}RME
		// {{{RME inSignal 'ready'
		// {{{RME general 'documentation'
		/* {{{USR

		   }}}USR */
		// }}}RME
		inline RTInSignal ready( void );
		// }}}RME
		// {{{RME inSignal 'sendData'
		// {{{RME general 'documentation'
		/* {{{USR

		   }}}USR */
		// }}}RME
		inline RTOutSignal sendData( const RTTypedValue_byteArray & data );
		// }}}RME
		// {{{RME inSignal 'setCommandLength'
		// {{{RME general 'documentation'
		/* {{{USR

		   }}}USR */
		// }}}RME
		inline RTOutSignal setCommandLength( const int & data );
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
			rti_sendData = rtiLast_RTRootProtocol + 1
		  , rti_setCommandLength
		};

	protected:
		enum { rtiLast_roombaProtocol = rti_setCommandLength };

	public:
		// {{{RME outSignal 'sendData'
		// {{{RME general 'documentation'
		/* {{{USR

		   }}}USR */
		// }}}RME
		inline RTInSignal sendData( void );
		// }}}RME
		// {{{RME outSignal 'setCommandLength'
		// {{{RME general 'documentation'
		/* {{{USR

		   }}}USR */
		// }}}RME
		inline RTInSignal setCommandLength( void );
		// }}}RME
		// {{{RME outSignal 'dataReceived'
		// {{{RME general 'documentation'
		/* {{{USR

		   }}}USR */
		// }}}RME
		inline RTOutSignal dataReceived( const RTTypedValue_byteArray & data );
		// }}}RME
		// {{{RME outSignal 'commandReceived'
		// {{{RME general 'documentation'
		/* {{{USR

		   }}}USR */
		// }}}RME
		inline RTOutSignal commandReceived( const RTTypedValue_jsonCommand & data );
		// }}}RME
		// {{{RME outSignal 'ready'
		// {{{RME general 'documentation'
		/* {{{USR

		   }}}USR */
		// }}}RME
		inline RTOutSignal ready( void );
		// }}}RME
		static const RTProtocolDescriptor rt_class;

	private:
		static const RTSignalDescriptor rt_signals[];
	};
};

inline roombaProtocol::Base::Base( void )
	: RTRootProtocol()
{
}

inline roombaProtocol::Base::~Base( void )
{
}

// {{{RME inSignal 'dataReceived'
// {{{RME general 'documentation'
/* {{{USR

   }}}USR */
// }}}RME
inline RTInSignal roombaProtocol::Base::dataReceived( void )
{
	return RTInSignal( this, rti_dataReceived );
}
// }}}RME

// {{{RME inSignal 'commandReceived'
// {{{RME general 'documentation'
/* {{{USR

   }}}USR */
// }}}RME
inline RTInSignal roombaProtocol::Base::commandReceived( void )
{
	return RTInSignal( this, rti_commandReceived );
}
// }}}RME

// {{{RME inSignal 'ready'
// {{{RME general 'documentation'
/* {{{USR

   }}}USR */
// }}}RME
inline RTInSignal roombaProtocol::Base::ready( void )
{
	return RTInSignal( this, rti_ready );
}
// }}}RME

// {{{RME inSignal 'sendData'
// {{{RME general 'documentation'
/* {{{USR

   }}}USR */
// }}}RME
inline RTOutSignal roombaProtocol::Base::sendData( const RTTypedValue_byteArray & data )
{
	return RTOutSignal( this, Conjugate::rti_sendData, data.data, data.type );
}
// }}}RME

// {{{RME inSignal 'setCommandLength'
// {{{RME general 'documentation'
/* {{{USR

   }}}USR */
// }}}RME
inline RTOutSignal roombaProtocol::Base::setCommandLength( const int & data )
{
	return RTOutSignal( this, Conjugate::rti_setCommandLength, &data, &RTType_int );
}
// }}}RME

inline roombaProtocol::Conjugate::Conjugate( void )
	: RTRootProtocol()
{
}

inline roombaProtocol::Conjugate::~Conjugate( void )
{
}

// {{{RME outSignal 'sendData'
// {{{RME general 'documentation'
/* {{{USR

   }}}USR */
// }}}RME
inline RTInSignal roombaProtocol::Conjugate::sendData( void )
{
	return RTInSignal( this, rti_sendData );
}
// }}}RME

// {{{RME outSignal 'setCommandLength'
// {{{RME general 'documentation'
/* {{{USR

   }}}USR */
// }}}RME
inline RTInSignal roombaProtocol::Conjugate::setCommandLength( void )
{
	return RTInSignal( this, rti_setCommandLength );
}
// }}}RME

// {{{RME outSignal 'dataReceived'
// {{{RME general 'documentation'
/* {{{USR

   }}}USR */
// }}}RME
inline RTOutSignal roombaProtocol::Conjugate::dataReceived( const RTTypedValue_byteArray & data )
{
	return RTOutSignal( this, Base::rti_dataReceived, data.data, data.type );
}
// }}}RME

// {{{RME outSignal 'commandReceived'
// {{{RME general 'documentation'
/* {{{USR

   }}}USR */
// }}}RME
inline RTOutSignal roombaProtocol::Conjugate::commandReceived( const RTTypedValue_jsonCommand & data )
{
	return RTOutSignal( this, Base::rti_commandReceived, data.data, data.type );
}
// }}}RME

// {{{RME outSignal 'ready'
// {{{RME general 'documentation'
/* {{{USR

   }}}USR */
// }}}RME
inline RTOutSignal roombaProtocol::Conjugate::ready( void )
{
	return RTOutSignal( this, Base::rti_ready, (const void *)0, &RTType_void );
}
// }}}RME

#endif /* roombaProtocol_H */

// }}}RME
