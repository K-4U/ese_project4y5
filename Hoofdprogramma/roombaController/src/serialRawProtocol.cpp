// {{{RME classifier 'Logical View::Serial::serialRawProtocol'

#if defined( PRAGMA ) && ! defined( PRAGMA_IMPLEMENTED )
#pragma implementation "serialRawProtocol.h"
#endif

#include <RTSystem/roombaController.h>
#include <serialRawProtocol.h>

const RTProtocolDescriptor serialRawProtocol::Base::rt_class =
{
	&RTRootProtocol::rt_class
  , &serialRawProtocol::Conjugate::rt_class
  , "serialRawProtocol"
  , 0
  , 2
  , serialRawProtocol::Base::rt_signals
#if RTRUNTIMEBC
  , &RTProtocolDescriptor::getUnknownGlobalSignal, &RTProtocolDescriptor::getUnknownLocalSignal
#endif
};

const RTSignalDescriptor serialRawProtocol::Base::rt_signals[] =
{
	{
		"rtBound"
	  , (const RTObject_class *)0
	  , serialRawProtocol::Base::rti_rtBound
	}
  , {
		"rtUnbound"
	  , (const RTObject_class *)0
	  , serialRawProtocol::Base::rti_rtUnbound
	}
};

const RTProtocolDescriptor serialRawProtocol::Conjugate::rt_class =
{
	&RTRootProtocol::rt_class
  , &serialRawProtocol::Base::rt_class
  , "serialRawProtocol"
  , 0
  , 3
  , serialRawProtocol::Conjugate::rt_signals
#if RTRUNTIMEBC
  , &RTProtocolDescriptor::getUnknownGlobalSignal, &RTProtocolDescriptor::getUnknownLocalSignal
#endif
};

const RTSignalDescriptor serialRawProtocol::Conjugate::rt_signals[] =
{
	{
		"dataReceived"
	  , &RTType_byteArray
	  , serialRawProtocol::Conjugate::rti_dataReceived
	}
  , {
		"rtBound"
	  , (const RTObject_class *)0
	  , serialRawProtocol::Conjugate::rti_rtBound
	}
  , {
		"rtUnbound"
	  , (const RTObject_class *)0
	  , serialRawProtocol::Conjugate::rti_rtUnbound
	}
};

// }}}RME
