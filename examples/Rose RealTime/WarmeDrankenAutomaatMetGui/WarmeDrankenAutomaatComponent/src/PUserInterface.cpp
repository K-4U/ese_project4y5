// {{{RME classifier 'Logical View::DomainLogic::PUserInterface'

#if defined( PRAGMA ) && ! defined( PRAGMA_IMPLEMENTED )
#pragma implementation "PUserInterface.h"
#endif

#include <RTSystem/WarmeDrankenAutomaatComponent.h>
#include <PUserInterface.h>

const RTProtocolDescriptor PUserInterface::Base::rt_class =
{
	&RTRootProtocol::rt_class
  , &PUserInterface::Conjugate::rt_class
  , "PUserInterface"
  , 0
  , 3
  , PUserInterface::Base::rt_signals
#if RTRUNTIMEBC
  , &RTProtocolDescriptor::getUnknownGlobalSignal, &RTProtocolDescriptor::getUnknownLocalSignal
#endif
};

const RTSignalDescriptor PUserInterface::Base::rt_signals[] =
{
	{
		"drankGereed"
	  , &RTType_void
	  , PUserInterface::Base::rti_drankGereed
	}
  , {
		"rtBound"
	  , (const RTObject_class *)0
	  , PUserInterface::Base::rti_rtBound
	}
  , {
		"rtUnbound"
	  , (const RTObject_class *)0
	  , PUserInterface::Base::rti_rtUnbound
	}
};

const RTProtocolDescriptor PUserInterface::Conjugate::rt_class =
{
	&RTRootProtocol::rt_class
  , &PUserInterface::Base::rt_class
  , "PUserInterface"
  , 0
  , 3
  , PUserInterface::Conjugate::rt_signals
#if RTRUNTIMEBC
  , &RTProtocolDescriptor::getUnknownGlobalSignal, &RTProtocolDescriptor::getUnknownLocalSignal
#endif
};

const RTSignalDescriptor PUserInterface::Conjugate::rt_signals[] =
{
	{
		"cacao"
	  , &RTType_void
	  , PUserInterface::Conjugate::rti_cacao
	}
  , {
		"rtBound"
	  , (const RTObject_class *)0
	  , PUserInterface::Conjugate::rti_rtBound
	}
  , {
		"rtUnbound"
	  , (const RTObject_class *)0
	  , PUserInterface::Conjugate::rti_rtUnbound
	}
};

// }}}RME
