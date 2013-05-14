// {{{RME classifier 'Logical View::Serial::serialProtocol'

#if defined( PRAGMA ) && ! defined( PRAGMA_IMPLEMENTED )
#pragma implementation "serialProtocol.h"
#endif

#include <RTSystem/ourProgram.h>
#include <serialProtocol.h>

const RTProtocolDescriptor serialProtocol::Base::rt_class =
{
	&RTRootProtocol::rt_class
  , &serialProtocol::Conjugate::rt_class
  , "serialProtocol"
  , 0
  , 2
  , serialProtocol::Base::rt_signals
#if RTRUNTIMEBC
  , &RTProtocolDescriptor::getUnknownGlobalSignal, &RTProtocolDescriptor::getUnknownLocalSignal
#endif
};

const RTSignalDescriptor serialProtocol::Base::rt_signals[] =
{
	{
		"rtBound"
	  , (const RTObject_class *)0
	  , serialProtocol::Base::rti_rtBound
	}
  , {
		"rtUnbound"
	  , (const RTObject_class *)0
	  , serialProtocol::Base::rti_rtUnbound
	}
};

const RTProtocolDescriptor serialProtocol::Conjugate::rt_class =
{
	&RTRootProtocol::rt_class
  , &serialProtocol::Base::rt_class
  , "serialProtocol"
  , 0
  , 3
  , serialProtocol::Conjugate::rt_signals
#if RTRUNTIMEBC
  , &RTProtocolDescriptor::getUnknownGlobalSignal, &RTProtocolDescriptor::getUnknownLocalSignal
#endif
};

const RTSignalDescriptor serialProtocol::Conjugate::rt_signals[] =
{
	{
		"dataReceived"
	  , &RTType_RTString
	  , serialProtocol::Conjugate::rti_dataReceived
	}
  , {
		"rtBound"
	  , (const RTObject_class *)0
	  , serialProtocol::Conjugate::rti_rtBound
	}
  , {
		"rtUnbound"
	  , (const RTObject_class *)0
	  , serialProtocol::Conjugate::rti_rtUnbound
	}
};

// }}}RME
