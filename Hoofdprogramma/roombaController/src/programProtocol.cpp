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
  , 7
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
		"isCharging"
	  , &RTType_int
	  , programProtocol::Base::rti_isCharging
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
		"sideBrushOverCurrent"
	  , &RTType_void
	  , programProtocol::Base::rti_sideBrushOverCurrent
	}
  , {
		"start"
	  , &RTType_int
	  , programProtocol::Base::rti_start
	}
  , {
		"stop"
	  , &RTType_void
	  , programProtocol::Base::rti_stop
	}
};

const RTProtocolDescriptor programProtocol::Conjugate::rt_class =
{
	&RTRootProtocol::rt_class
  , &programProtocol::Base::rt_class
  , "programProtocol"
  , 0
  , 9
  , programProtocol::Conjugate::rt_signals
#if RTRUNTIMEBC
  , &RTProtocolDescriptor::getUnknownGlobalSignal, &RTProtocolDescriptor::getUnknownLocalSignal
#endif
};

const RTSignalDescriptor programProtocol::Conjugate::rt_signals[] =
{
	{
		"doSend"
	  , &RTType_byteArray
	  , programProtocol::Conjugate::rti_doSend
	}
  , {
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
		"log"
	  , &RTType_logEntry
	  , programProtocol::Conjugate::rti_log
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
		"setMotors"
	  , &clsRoomba::RTType_clsMotors
	  , programProtocol::Conjugate::rti_setMotors
	}
  , {
		"stopProgram"
	  , &RTType_int
	  , programProtocol::Conjugate::rti_stopProgram
	}
};

// }}}RME
