// {{{RME classifier 'Logical View::SerialProtocol'

#if defined( PRAGMA ) && ! defined( PRAGMA_IMPLEMENTED )
#pragma implementation "SerialProtocol.h"
#endif

#include <RTSystem/Program.h>
#include <SerialProtocol.h>

const RTProtocolDescriptor SerialProtocol::Base::rt_class =
{
	&RTRootProtocol::rt_class
  , &SerialProtocol::Conjugate::rt_class
  , "SerialProtocol"
  , 0
  , 2
  , SerialProtocol::Base::rt_signals
#if RTRUNTIMEBC
  , &RTProtocolDescriptor::getUnknownGlobalSignal, &RTProtocolDescriptor::getUnknownLocalSignal
#endif
};

const RTSignalDescriptor SerialProtocol::Base::rt_signals[] =
{
	{
		"rtBound"
	  , (const RTObject_class *)0
	  , SerialProtocol::Base::rti_rtBound
	}
  , {
		"rtUnbound"
	  , (const RTObject_class *)0
	  , SerialProtocol::Base::rti_rtUnbound
	}
};

const RTProtocolDescriptor SerialProtocol::Conjugate::rt_class =
{
	&RTRootProtocol::rt_class
  , &SerialProtocol::Base::rt_class
  , "SerialProtocol"
  , 0
  , 3
  , SerialProtocol::Conjugate::rt_signals
#if RTRUNTIMEBC
  , &RTProtocolDescriptor::getUnknownGlobalSignal, &RTProtocolDescriptor::getUnknownLocalSignal
#endif
};

const RTSignalDescriptor SerialProtocol::Conjugate::rt_signals[] =
{
	{
		"DataReceived"
	  , &RTType_RTString
	  , SerialProtocol::Conjugate::rti_DataReceived
	}
  , {
		"rtBound"
	  , (const RTObject_class *)0
	  , SerialProtocol::Conjugate::rti_rtBound
	}
  , {
		"rtUnbound"
	  , (const RTObject_class *)0
	  , SerialProtocol::Conjugate::rti_rtUnbound
	}
};

// }}}RME
