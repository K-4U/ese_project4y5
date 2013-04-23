// {{{RME classifier 'Logical View::DomainLogic::PUserInterface'

#ifndef PUserInterface_H
#define PUserInterface_H

#ifdef PRAGMA
#pragma interface "PUserInterface.h"
#endif

#include <RTSystem/WarmeDrankenAutomaatComponent.h>

struct PUserInterface
{
	class Base : public RTRootProtocol
	{
	public:
		inline Base( void );
		inline ~Base( void );
		enum { rti_drankGereed = rtiLast_RTRootProtocol + 1 };

	protected:
		enum { rtiLast_PUserInterface = rti_drankGereed };

	public:
		// {{{RME inSignal 'drankGereed'
		// {{{RME general 'documentation'
		/* {{{USR

		   }}}USR */
		// }}}RME
		inline RTInSignal drankGereed( void );
		// }}}RME
		// {{{RME inSignal 'cacao'
		// {{{RME general 'documentation'
		/* {{{USR

		   }}}USR */
		// }}}RME
		inline RTOutSignal cacao( void );
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
		enum { rti_cacao = rtiLast_RTRootProtocol + 1 };

	protected:
		enum { rtiLast_PUserInterface = rti_cacao };

	public:
		// {{{RME outSignal 'cacao'
		// {{{RME general 'documentation'
		/* {{{USR

		   }}}USR */
		// }}}RME
		inline RTInSignal cacao( void );
		// }}}RME
		// {{{RME outSignal 'drankGereed'
		// {{{RME general 'documentation'
		/* {{{USR

		   }}}USR */
		// }}}RME
		inline RTOutSignal drankGereed( void );
		// }}}RME
		static const RTProtocolDescriptor rt_class;

	private:
		static const RTSignalDescriptor rt_signals[];
	};
};

inline PUserInterface::Base::Base( void )
	: RTRootProtocol()
{
}

inline PUserInterface::Base::~Base( void )
{
}

// {{{RME inSignal 'drankGereed'
// {{{RME general 'documentation'
/* {{{USR

   }}}USR */
// }}}RME
inline RTInSignal PUserInterface::Base::drankGereed( void )
{
	return RTInSignal( this, rti_drankGereed );
}
// }}}RME

// {{{RME inSignal 'cacao'
// {{{RME general 'documentation'
/* {{{USR

   }}}USR */
// }}}RME
inline RTOutSignal PUserInterface::Base::cacao( void )
{
	return RTOutSignal( this, Conjugate::rti_cacao, (const void *)0, &RTType_void );
}
// }}}RME

inline PUserInterface::Conjugate::Conjugate( void )
	: RTRootProtocol()
{
}

inline PUserInterface::Conjugate::~Conjugate( void )
{
}

// {{{RME outSignal 'cacao'
// {{{RME general 'documentation'
/* {{{USR

   }}}USR */
// }}}RME
inline RTInSignal PUserInterface::Conjugate::cacao( void )
{
	return RTInSignal( this, rti_cacao );
}
// }}}RME

// {{{RME outSignal 'drankGereed'
// {{{RME general 'documentation'
/* {{{USR

   }}}USR */
// }}}RME
inline RTOutSignal PUserInterface::Conjugate::drankGereed( void )
{
	return RTOutSignal( this, Base::rti_drankGereed, (const void *)0, &RTType_void );
}
// }}}RME

#endif /* PUserInterface_H */

// }}}RME
