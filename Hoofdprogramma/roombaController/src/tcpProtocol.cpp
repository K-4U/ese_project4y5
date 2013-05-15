// {{{RME classifier 'Logical View::TCPIP::tcpProtocol'

#if defined( PRAGMA ) && ! defined( PRAGMA_IMPLEMENTED )
#pragma implementation "tcpProtocol.h"
#endif

#include <RTSystem/roombaController.h>
#include <tcpProtocol.h>

const RTProtocolDescriptor tcpProtocol::Base::rt_class =
{
	&RTRootProtocol::rt_class
  , &tcpProtocol::Conjugate::rt_class
  , "tcpProtocol"
  , 0
  , 2
  , tcpProtocol::Base::rt_signals
#if RTRUNTIMEBC
  , &RTProtocolDescriptor::getUnknownGlobalSignal, &RTProtocolDescriptor::getUnknownLocalSignal
#endif
};

const RTSignalDescriptor tcpProtocol::Base::rt_signals[] =
{
	{
		"rtBound"
	  , (const RTObject_class *)0
	  , tcpProtocol::Base::rti_rtBound
	}
  , {
		"rtUnbound"
	  , (const RTObject_class *)0
	  , tcpProtocol::Base::rti_rtUnbound
	}
};

const RTProtocolDescriptor tcpProtocol::Conjugate::rt_class =
{
	&RTRootProtocol::rt_class
  , &tcpProtocol::Base::rt_class
  , "tcpProtocol"
  , 0
  , 5
  , tcpProtocol::Conjugate::rt_signals
#if RTRUNTIMEBC
  , &RTProtocolDescriptor::getUnknownGlobalSignal, &RTProtocolDescriptor::getUnknownLocalSignal
#endif
};

const RTSignalDescriptor tcpProtocol::Conjugate::rt_signals[] =
{
	{
		"dataReceived"
	  , &RTType_RTString
	  , tcpProtocol::Conjugate::rti_dataReceived
	}
  , {
		"noSock"
	  , &RTType_void
	  , tcpProtocol::Conjugate::rti_noSock
	}
  , {
		"rtBound"
	  , (const RTObject_class *)0
	  , tcpProtocol::Conjugate::rti_rtBound
	}
  , {
		"rtUnbound"
	  , (const RTObject_class *)0
	  , tcpProtocol::Conjugate::rti_rtUnbound
	}
  , {
		"sock"
	  , &RTType_unsigned
	  , tcpProtocol::Conjugate::rti_sock
	}
};

// }}}RME
