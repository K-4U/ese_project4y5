// {{{RME classifier 'Logical View::Serial::serialProtocol'

#if defined( PRAGMA ) && ! defined( PRAGMA_IMPLEMENTED )
#pragma implementation "serialProtocol.h"
#endif

#include <RTSystem/roombaController.h>
#include <serialProtocol.h>

const RTProtocolDescriptor serialProtocol::Base::rt_class =
{
	&RTRootProtocol::rt_class
  , &serialProtocol::Conjugate::rt_class
  , "serialProtocol"
  , 0
  , 3
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
  , {
		"sendCommand"
	  , &RTType_byteArray
	  , serialProtocol::Base::rti_sendCommand
	}
};

const RTProtocolDescriptor serialProtocol::Conjugate::rt_class =
{
	&RTRootProtocol::rt_class
  , &serialProtocol::Base::rt_class
  , "serialProtocol"
  , 0
  , 5
  , serialProtocol::Conjugate::rt_signals
#if RTRUNTIMEBC
  , &RTProtocolDescriptor::getUnknownGlobalSignal, &RTProtocolDescriptor::getUnknownLocalSignal
#endif
};

const RTSignalDescriptor serialProtocol::Conjugate::rt_signals[] =
{
	{
		"comError"
	  , &RTType_void
	  , serialProtocol::Conjugate::rti_comError
	}
  , {
		"comOpened"
	  , &RTType_void
	  , serialProtocol::Conjugate::rti_comOpened
	}
  , {
		"commandReceived"
	  , &RTType_byteArray
	  , serialProtocol::Conjugate::rti_commandReceived
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
