// {{{RME classifier 'Logical View::DomainLogic::PReservoir'

#ifndef PReservoir_H
#define PReservoir_H

#ifdef PRAGMA
#pragma interface "PReservoir.h"
#endif

#include <RTSystem/WarmeDrankenAutomaatComponent.h>

struct PReservoir
{
	class Base : public RTRootProtocol
	{
	public:
		inline Base( void );
		inline ~Base( void );
		enum
		{
			rti_startLeverProduct = rtiLast_RTRootProtocol + 1
		  , rti_stopLeverProduct
		  , rti_vraagVoorraad
		};

	protected:
		enum { rtiLast_PReservoir = rti_vraagVoorraad };

	public:
		// {{{RME inSignal 'startLeverProduct'
		// {{{RME general 'documentation'
		/* {{{USR

		   }}}USR */
		// }}}RME
		inline RTInSignal startLeverProduct( void );
		// }}}RME
		// {{{RME inSignal 'stopLeverProduct'
		// {{{RME general 'documentation'
		/* {{{USR

		   }}}USR */
		// }}}RME
		inline RTInSignal stopLeverProduct( void );
		// }}}RME
		// {{{RME inSignal 'vraagVoorraad'
		// {{{RME general 'documentation'
		/* {{{USR

		   }}}USR */
		// }}}RME
		inline RTInSignal vraagVoorraad( void );
		// }}}RME
		// {{{RME inSignal 'antwoordVoorraad'
		// {{{RME general 'documentation'
		/* {{{USR

		   }}}USR */
		// }}}RME
		inline RTOutSignal antwoordVoorraad( const bool & data );
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
		enum { rti_antwoordVoorraad = rtiLast_RTRootProtocol + 1 };

	protected:
		enum { rtiLast_PReservoir = rti_antwoordVoorraad };

	public:
		// {{{RME outSignal 'antwoordVoorraad'
		// {{{RME general 'documentation'
		/* {{{USR

		   }}}USR */
		// }}}RME
		inline RTInSignal antwoordVoorraad( void );
		// }}}RME
		// {{{RME outSignal 'startLeverProduct'
		// {{{RME general 'documentation'
		/* {{{USR

		   }}}USR */
		// }}}RME
		inline RTOutSignal startLeverProduct( void );
		// }}}RME
		// {{{RME outSignal 'stopLeverProduct'
		// {{{RME general 'documentation'
		/* {{{USR

		   }}}USR */
		// }}}RME
		inline RTOutSignal stopLeverProduct( void );
		// }}}RME
		// {{{RME outSignal 'vraagVoorraad'
		// {{{RME general 'documentation'
		/* {{{USR

		   }}}USR */
		// }}}RME
		inline RTOutSignal vraagVoorraad( void );
		// }}}RME
		static const RTProtocolDescriptor rt_class;

	private:
		static const RTSignalDescriptor rt_signals[];
	};
};

inline PReservoir::Base::Base( void )
	: RTRootProtocol()
{
}

inline PReservoir::Base::~Base( void )
{
}

// {{{RME inSignal 'startLeverProduct'
// {{{RME general 'documentation'
/* {{{USR

   }}}USR */
// }}}RME
inline RTInSignal PReservoir::Base::startLeverProduct( void )
{
	return RTInSignal( this, rti_startLeverProduct );
}
// }}}RME

// {{{RME inSignal 'stopLeverProduct'
// {{{RME general 'documentation'
/* {{{USR

   }}}USR */
// }}}RME
inline RTInSignal PReservoir::Base::stopLeverProduct( void )
{
	return RTInSignal( this, rti_stopLeverProduct );
}
// }}}RME

// {{{RME inSignal 'vraagVoorraad'
// {{{RME general 'documentation'
/* {{{USR

   }}}USR */
// }}}RME
inline RTInSignal PReservoir::Base::vraagVoorraad( void )
{
	return RTInSignal( this, rti_vraagVoorraad );
}
// }}}RME

// {{{RME inSignal 'antwoordVoorraad'
// {{{RME general 'documentation'
/* {{{USR

   }}}USR */
// }}}RME
inline RTOutSignal PReservoir::Base::antwoordVoorraad( const bool & data )
{
	return RTOutSignal( this, Conjugate::rti_antwoordVoorraad, &data, &RTType_bool );
}
// }}}RME

inline PReservoir::Conjugate::Conjugate( void )
	: RTRootProtocol()
{
}

inline PReservoir::Conjugate::~Conjugate( void )
{
}

// {{{RME outSignal 'antwoordVoorraad'
// {{{RME general 'documentation'
/* {{{USR

   }}}USR */
// }}}RME
inline RTInSignal PReservoir::Conjugate::antwoordVoorraad( void )
{
	return RTInSignal( this, rti_antwoordVoorraad );
}
// }}}RME

// {{{RME outSignal 'startLeverProduct'
// {{{RME general 'documentation'
/* {{{USR

   }}}USR */
// }}}RME
inline RTOutSignal PReservoir::Conjugate::startLeverProduct( void )
{
	return RTOutSignal( this, Base::rti_startLeverProduct, (const void *)0, &RTType_void );
}
// }}}RME

// {{{RME outSignal 'stopLeverProduct'
// {{{RME general 'documentation'
/* {{{USR

   }}}USR */
// }}}RME
inline RTOutSignal PReservoir::Conjugate::stopLeverProduct( void )
{
	return RTOutSignal( this, Base::rti_stopLeverProduct, (const void *)0, &RTType_void );
}
// }}}RME

// {{{RME outSignal 'vraagVoorraad'
// {{{RME general 'documentation'
/* {{{USR

   }}}USR */
// }}}RME
inline RTOutSignal PReservoir::Conjugate::vraagVoorraad( void )
{
	return RTOutSignal( this, Base::rti_vraagVoorraad, (const void *)0, &RTType_void );
}
// }}}RME

#endif /* PReservoir_H */

// }}}RME
