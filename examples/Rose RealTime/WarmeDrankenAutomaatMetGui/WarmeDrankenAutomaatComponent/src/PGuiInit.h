// {{{RME classifier 'Logical View::DomainLogic::PGuiInit'

#ifndef PGuiInit_H
#define PGuiInit_H

#ifdef PRAGMA
#pragma interface "PGuiInit.h"
#endif

#include <RTSystem/WarmeDrankenAutomaatComponent.h>

struct PGuiInit
{
	class Base : public RTRootProtocol
	{
	public:
		inline Base( void );
		inline ~Base( void );
		enum { rti_init = rtiLast_RTRootProtocol + 1 };

	protected:
		enum { rtiLast_PGuiInit = rti_init };

	public:
		// {{{RME inSignal 'init'
		// {{{RME general 'documentation'
		/* {{{USR

		   }}}USR */
		// }}}RME
		inline RTInSignal init( void );
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

	protected:
		enum { rtiLast_PGuiInit = rtiLast_RTRootProtocol };

	public:
		// {{{RME outSignal 'init'
		// {{{RME general 'documentation'
		/* {{{USR

		   }}}USR */
		// }}}RME
		inline RTOutSignal init( const RTTypedValue & value );
		// }}}RME
		inline RTOutSignal init( void );
		static const RTProtocolDescriptor rt_class;

	private:
		static const RTSignalDescriptor rt_signals[];
	};
};

inline PGuiInit::Base::Base( void )
	: RTRootProtocol()
{
}

inline PGuiInit::Base::~Base( void )
{
}

// {{{RME inSignal 'init'
// {{{RME general 'documentation'
/* {{{USR

   }}}USR */
// }}}RME
inline RTInSignal PGuiInit::Base::init( void )
{
	return RTInSignal( this, rti_init );
}
// }}}RME

inline PGuiInit::Conjugate::Conjugate( void )
	: RTRootProtocol()
{
}

inline PGuiInit::Conjugate::~Conjugate( void )
{
}

// {{{RME outSignal 'init'
// {{{RME general 'documentation'
/* {{{USR

   }}}USR */
// }}}RME
inline RTOutSignal PGuiInit::Conjugate::init( const RTTypedValue & value )
{
	return RTOutSignal( this, Base::rti_init, value.data, value.type );
}
// }}}RME

inline RTOutSignal PGuiInit::Conjugate::init( void )
{
	return RTOutSignal( this, Base::rti_init, (void *)0, &RTType_void );
}

#endif /* PGuiInit_H */

// }}}RME
