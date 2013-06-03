// {{{RME classifier 'Logical View::Roomba::roombaProtocol'

#if defined( PRAGMA ) && ! defined( PRAGMA_IMPLEMENTED )
#pragma implementation "roombaProtocol.h"
#endif

#include <RTSystem/roombaController.h>
#include <roombaProtocol.h>

const RTProtocolDescriptor roombaProtocol::Base::rt_class =
{
	&RTRootProtocol::rt_class
  , &roombaProtocol::Conjugate::rt_class
  , "roombaProtocol"
  , 0
  , 5
  , roombaProtocol::Base::rt_signals
#if RTRUNTIMEBC
  , &RTProtocolDescriptor::getUnknownGlobalSignal, &RTProtocolDescriptor::getUnknownLocalSignal
#endif
};

const RTSignalDescriptor roombaProtocol::Base::rt_signals[] =
{
	{
		"commandReceived"
	  , &RTType_jsonCommand
	  , roombaProtocol::Base::rti_commandReceived
	}
  , {
		"dataReceived"
	  , &RTType_byteArray
	  , roombaProtocol::Base::rti_dataReceived
	}
  , {
		"ready"
	  , &RTType_void
	  , roombaProtocol::Base::rti_ready
	}
  , {
		"rtBound"
	  , (const RTObject_class *)0
	  , roombaProtocol::Base::rti_rtBound
	}
  , {
		"rtUnbound"
	  , (const RTObject_class *)0
	  , roombaProtocol::Base::rti_rtUnbound
	}
};

const RTProtocolDescriptor roombaProtocol::Conjugate::rt_class =
{
	&RTRootProtocol::rt_class
  , &roombaProtocol::Base::rt_class
  , "roombaProtocol"
  , 0
  , 4
  , roombaProtocol::Conjugate::rt_signals
#if RTRUNTIMEBC
  , &RTProtocolDescriptor::getUnknownGlobalSignal, &RTProtocolDescriptor::getUnknownLocalSignal
#endif
};

const RTSignalDescriptor roombaProtocol::Conjugate::rt_signals[] =
{
	{
		"rtBound"
	  , (const RTObject_class *)0
	  , roombaProtocol::Conjugate::rti_rtBound
	}
  , {
		"rtUnbound"
	  , (const RTObject_class *)0
	  , roombaProtocol::Conjugate::rti_rtUnbound
	}
  , {
		"sendData"
	  , &RTType_byteArray
	  , roombaProtocol::Conjugate::rti_sendData
	}
  , {
		"setCommandLength"
	  , &RTType_int
	  , roombaProtocol::Conjugate::rti_setCommandLength
	}
};

// }}}RME
