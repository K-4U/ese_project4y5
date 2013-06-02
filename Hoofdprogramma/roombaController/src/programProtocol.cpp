// {{{RME classifier 'Logical View::Roomba::programProtocol'

#if defined( PRAGMA ) && ! defined( PRAGMA_IMPLEMENTED )
#pragma implementation "programProtocol.h"
#endif

#include <RTSystem/roombaController.h>
#include <programProtocol.h>

const RTProtocolDescriptor programProtocol::Base::rt_class =
{
	&RTRootProtocol::rt_class
  , &programProtocol::Conjugate::rt_class
  , "programProtocol"
  , 0
  , 5
  , programProtocol::Base::rt_signals
#if RTRUNTIMEBC
  , &RTProtocolDescriptor::getUnknownGlobalSignal, &RTProtocolDescriptor::getUnknownLocalSignal
#endif
};

const RTSignalDescriptor programProtocol::Base::rt_signals[] =
{
	{
		"bumpersTriggered"
	  , &clsRoomba::RTType_clsBumpersAndCliff
	  , programProtocol::Base::rti_bumpersTriggered
	}
  , {
		"rtBound"
	  , (const RTObject_class *)0
	  , programProtocol::Base::rti_rtBound
	}
  , {
		"rtUnbound"
	  , (const RTObject_class *)0
	  , programProtocol::Base::rti_rtUnbound
	}
  , {
		"start"
	  , &RTType_int
	  , programProtocol::Base::rti_start
	}
  , {
		"totalAngle"
	  , &RTType_int
	  , programProtocol::Base::rti_totalAngle
	}
};

const RTProtocolDescriptor programProtocol::Conjugate::rt_class =
{
	&RTRootProtocol::rt_class
  , &programProtocol::Base::rt_class
  , "programProtocol"
  , 0
  , 7
  , programProtocol::Conjugate::rt_signals
#if RTRUNTIMEBC
  , &RTProtocolDescriptor::getUnknownGlobalSignal, &RTProtocolDescriptor::getUnknownLocalSignal
#endif
};

const RTSignalDescriptor programProtocol::Conjugate::rt_signals[] =
{
	{
		"drive"
	  , &RTType_clsDriveCommand
	  , programProtocol::Conjugate::rti_drive
	}
  , {
		"getSensor"
	  , &RTType_byteArray
	  , programProtocol::Conjugate::rti_getSensor
	}
  , {
		"getTotalAngle"
	  , &RTType_bool
	  , programProtocol::Conjugate::rti_getTotalAngle
	}
  , {
		"playSong"
	  , &RTType_int
	  , programProtocol::Conjugate::rti_playSong
	}
  , {
		"rtBound"
	  , (const RTObject_class *)0
	  , programProtocol::Conjugate::rti_rtBound
	}
  , {
		"rtUnbound"
	  , (const RTObject_class *)0
	  , programProtocol::Conjugate::rti_rtUnbound
	}
  , {
		"stopProgram"
	  , &RTType_int
	  , programProtocol::Conjugate::rti_stopProgram
	}
};

// }}}RME
