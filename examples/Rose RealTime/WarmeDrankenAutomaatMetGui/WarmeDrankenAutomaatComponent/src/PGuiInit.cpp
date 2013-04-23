// {{{RME classifier 'Logical View::DomainLogic::PGuiInit'

#if defined( PRAGMA ) && ! defined( PRAGMA_IMPLEMENTED )
#pragma implementation "PGuiInit.h"
#endif

#include <RTSystem/WarmeDrankenAutomaatComponent.h>
#include <PGuiInit.h>

const RTProtocolDescriptor PGuiInit::Base::rt_class =
{
	&RTRootProtocol::rt_class
  , &PGuiInit::Conjugate::rt_class
  , "PGuiInit"
  , 0
  , 3
  , PGuiInit::Base::rt_signals
#if RTRUNTIMEBC
  , &RTProtocolDescriptor::getUnknownGlobalSignal, &RTProtocolDescriptor::getUnknownLocalSignal
#endif
};

const RTSignalDescriptor PGuiInit::Base::rt_signals[] =
{
	{
		"init"
	  , (const RTObject_class *)0
	  , PGuiInit::Base::rti_init
	}
  , {
		"rtBound"
	  , (const RTObject_class *)0
	  , PGuiInit::Base::rti_rtBound
	}
  , {
		"rtUnbound"
	  , (const RTObject_class *)0
	  , PGuiInit::Base::rti_rtUnbound
	}
};

const RTProtocolDescriptor PGuiInit::Conjugate::rt_class =
{
	&RTRootProtocol::rt_class
  , &PGuiInit::Base::rt_class
  , "PGuiInit"
  , 0
  , 2
  , PGuiInit::Conjugate::rt_signals
#if RTRUNTIMEBC
  , &RTProtocolDescriptor::getUnknownGlobalSignal, &RTProtocolDescriptor::getUnknownLocalSignal
#endif
};

const RTSignalDescriptor PGuiInit::Conjugate::rt_signals[] =
{
	{
		"rtBound"
	  , (const RTObject_class *)0
	  , PGuiInit::Conjugate::rti_rtBound
	}
  , {
		"rtUnbound"
	  , (const RTObject_class *)0
	  , PGuiInit::Conjugate::rti_rtUnbound
	}
};

// }}}RME
