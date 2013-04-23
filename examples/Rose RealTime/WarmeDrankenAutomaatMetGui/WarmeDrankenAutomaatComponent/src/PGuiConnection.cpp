// {{{RME classifier 'Logical View::UserInterface::PGuiConnection'

#if defined( PRAGMA ) && ! defined( PRAGMA_IMPLEMENTED )
#pragma implementation "PGuiConnection.h"
#endif

#include <RTSystem/WarmeDrankenAutomaatComponent.h>
#include <PGuiConnection.h>

const RTProtocolDescriptor PGuiConnection::Base::rt_class =
{
	&RTRootProtocol::rt_class
  , &PGuiConnection::Conjugate::rt_class
  , "PGuiConnection"
  , 0
  , 2
  , PGuiConnection::Base::rt_signals
#if RTRUNTIMEBC
  , &RTProtocolDescriptor::getUnknownGlobalSignal, &RTProtocolDescriptor::getUnknownLocalSignal
#endif
};

const RTSignalDescriptor PGuiConnection::Base::rt_signals[] =
{
	{
		"rtBound"
	  , (const RTObject_class *)0
	  , PGuiConnection::Base::rti_rtBound
	}
  , {
		"rtUnbound"
	  , (const RTObject_class *)0
	  , PGuiConnection::Base::rti_rtUnbound
	}
};

const RTProtocolDescriptor PGuiConnection::Conjugate::rt_class =
{
	&RTRootProtocol::rt_class
  , &PGuiConnection::Base::rt_class
  , "PGuiConnection"
  , 0
  , 5
  , PGuiConnection::Conjugate::rt_signals
#if RTRUNTIMEBC
  , &RTProtocolDescriptor::getUnknownGlobalSignal, &RTProtocolDescriptor::getUnknownLocalSignal
#endif
};

const RTSignalDescriptor PGuiConnection::Conjugate::rt_signals[] =
{
	{
		"data"
	  , &RTType_RTString
	  , PGuiConnection::Conjugate::rti_data
	}
  , {
		"noSock"
	  , &RTType_void
	  , PGuiConnection::Conjugate::rti_noSock
	}
  , {
		"rtBound"
	  , (const RTObject_class *)0
	  , PGuiConnection::Conjugate::rti_rtBound
	}
  , {
		"rtUnbound"
	  , (const RTObject_class *)0
	  , PGuiConnection::Conjugate::rti_rtUnbound
	}
  , {
		"sock"
	  , &RTType_unsigned
	  , PGuiConnection::Conjugate::rti_sock
	}
};

// }}}RME
