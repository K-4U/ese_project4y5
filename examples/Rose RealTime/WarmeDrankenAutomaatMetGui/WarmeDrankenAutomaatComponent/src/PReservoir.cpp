// {{{RME classifier 'Logical View::DomainLogic::PReservoir'

#if defined( PRAGMA ) && ! defined( PRAGMA_IMPLEMENTED )
#pragma implementation "PReservoir.h"
#endif

#include <RTSystem/WarmeDrankenAutomaatComponent.h>
#include <PReservoir.h>

const RTProtocolDescriptor PReservoir::Base::rt_class =
{
	&RTRootProtocol::rt_class
  , &PReservoir::Conjugate::rt_class
  , "PReservoir"
  , 0
  , 5
  , PReservoir::Base::rt_signals
#if RTRUNTIMEBC
  , &RTProtocolDescriptor::getUnknownGlobalSignal, &RTProtocolDescriptor::getUnknownLocalSignal
#endif
};

const RTSignalDescriptor PReservoir::Base::rt_signals[] =
{
	{
		"rtBound"
	  , (const RTObject_class *)0
	  , PReservoir::Base::rti_rtBound
	}
  , {
		"rtUnbound"
	  , (const RTObject_class *)0
	  , PReservoir::Base::rti_rtUnbound
	}
  , {
		"startLeverProduct"
	  , &RTType_void
	  , PReservoir::Base::rti_startLeverProduct
	}
  , {
		"stopLeverProduct"
	  , &RTType_void
	  , PReservoir::Base::rti_stopLeverProduct
	}
  , {
		"vraagVoorraad"
	  , &RTType_void
	  , PReservoir::Base::rti_vraagVoorraad
	}
};

const RTProtocolDescriptor PReservoir::Conjugate::rt_class =
{
	&RTRootProtocol::rt_class
  , &PReservoir::Base::rt_class
  , "PReservoir"
  , 0
  , 3
  , PReservoir::Conjugate::rt_signals
#if RTRUNTIMEBC
  , &RTProtocolDescriptor::getUnknownGlobalSignal, &RTProtocolDescriptor::getUnknownLocalSignal
#endif
};

const RTSignalDescriptor PReservoir::Conjugate::rt_signals[] =
{
	{
		"antwoordVoorraad"
	  , &RTType_bool
	  , PReservoir::Conjugate::rti_antwoordVoorraad
	}
  , {
		"rtBound"
	  , (const RTObject_class *)0
	  , PReservoir::Conjugate::rti_rtBound
	}
  , {
		"rtUnbound"
	  , (const RTObject_class *)0
	  , PReservoir::Conjugate::rti_rtUnbound
	}
};

// }}}RME
