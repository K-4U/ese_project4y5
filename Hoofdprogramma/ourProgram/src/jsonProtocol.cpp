// {{{RME classifier 'Logical View::TCPIP::jsonProtocol'

#if defined( PRAGMA ) && ! defined( PRAGMA_IMPLEMENTED )
#pragma implementation "jsonProtocol.h"
#endif

#include <RTSystem/ourProgram.h>
#include <jsonProtocol.h>

const RTProtocolDescriptor jsonProtocol::Base::rt_class =
{
	&RTRootProtocol::rt_class
  , &jsonProtocol::Conjugate::rt_class
  , "jsonProtocol"
  , 0
  , 3
  , jsonProtocol::Base::rt_signals
#if RTRUNTIMEBC
  , &RTProtocolDescriptor::getUnknownGlobalSignal, &RTProtocolDescriptor::getUnknownLocalSignal
#endif
};

const RTSignalDescriptor jsonProtocol::Base::rt_signals[] =
{
	{
		"rtBound"
	  , (const RTObject_class *)0
	  , jsonProtocol::Base::rti_rtBound
	}
  , {
		"rtUnbound"
	  , (const RTObject_class *)0
	  , jsonProtocol::Base::rti_rtUnbound
	}
  , {
		"sendCommand"
	  , &RTType_jsonCommand
	  , jsonProtocol::Base::rti_sendCommand
	}
};

const RTProtocolDescriptor jsonProtocol::Conjugate::rt_class =
{
	&RTRootProtocol::rt_class
  , &jsonProtocol::Base::rt_class
  , "jsonProtocol"
  , 0
  , 3
  , jsonProtocol::Conjugate::rt_signals
#if RTRUNTIMEBC
  , &RTProtocolDescriptor::getUnknownGlobalSignal, &RTProtocolDescriptor::getUnknownLocalSignal
#endif
};

const RTSignalDescriptor jsonProtocol::Conjugate::rt_signals[] =
{
	{
		"commandReceived"
	  , &RTType_jsonCommand
	  , jsonProtocol::Conjugate::rti_commandReceived
	}
  , {
		"rtBound"
	  , (const RTObject_class *)0
	  , jsonProtocol::Conjugate::rti_rtBound
	}
  , {
		"rtUnbound"
	  , (const RTObject_class *)0
	  , jsonProtocol::Conjugate::rti_rtUnbound
	}
};

// }}}RME
