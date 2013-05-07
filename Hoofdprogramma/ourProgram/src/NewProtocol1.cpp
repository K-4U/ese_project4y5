// {{{RME classifier 'Logical View::TCPIP::NewProtocol1'

#if defined( PRAGMA ) && ! defined( PRAGMA_IMPLEMENTED )
#pragma implementation "NewProtocol1.h"
#endif

#include <RTSystem/ourProgram.h>
#include <NewProtocol1.h>

const RTProtocolDescriptor NewProtocol1::Base::rt_class =
{
	&RTRootProtocol::rt_class
  , &NewProtocol1::Conjugate::rt_class
  , "NewProtocol1"
  , 0
  , 2
  , NewProtocol1::Base::rt_signals
#if RTRUNTIMEBC
  , &RTProtocolDescriptor::getUnknownGlobalSignal, &RTProtocolDescriptor::getUnknownLocalSignal
#endif
};

const RTSignalDescriptor NewProtocol1::Base::rt_signals[] =
{
	{
		"rtBound"
	  , (const RTObject_class *)0
	  , NewProtocol1::Base::rti_rtBound
	}
  , {
		"rtUnbound"
	  , (const RTObject_class *)0
	  , NewProtocol1::Base::rti_rtUnbound
	}
};

const RTProtocolDescriptor NewProtocol1::Conjugate::rt_class =
{
	&RTRootProtocol::rt_class
  , &NewProtocol1::Base::rt_class
  , "NewProtocol1"
  , 0
  , 2
  , NewProtocol1::Conjugate::rt_signals
#if RTRUNTIMEBC
  , &RTProtocolDescriptor::getUnknownGlobalSignal, &RTProtocolDescriptor::getUnknownLocalSignal
#endif
};

const RTSignalDescriptor NewProtocol1::Conjugate::rt_signals[] =
{
	{
		"rtBound"
	  , (const RTObject_class *)0
	  , NewProtocol1::Conjugate::rti_rtBound
	}
  , {
		"rtUnbound"
	  , (const RTObject_class *)0
	  , NewProtocol1::Conjugate::rti_rtUnbound
	}
};

// }}}RME
