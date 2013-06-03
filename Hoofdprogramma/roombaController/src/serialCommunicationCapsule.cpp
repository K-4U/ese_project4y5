// {{{RME classifier 'Logical View::Serial::serialCommunicationCapsule'

#if defined( PRAGMA ) && ! defined( PRAGMA_IMPLEMENTED )
#pragma implementation "serialCommunicationCapsule.h"
#endif

#include <RTSystem/roombaController.h>
#include <serialCommunicationCapsule.h>
#include <serialProperties.h>

// {{{RME tool 'OT::Cpp' property 'ImplementationPreface'
// {{{USR

// }}}USR
// }}}RME

static const RTRelayDescriptor rtg_relays[] =
{
	{
		"serialPort"
	  , &serialRawProtocol::Base::rt_class
	  , 1 // cardinality
	}
};

static RTActor * new_serialCommunicationCapsule_Actor( RTController * _rts, RTActorRef * _ref )
{
	return new serialCommunicationCapsule_Actor( _rts, _ref );
}

const RTActorClass serialCommunicationCapsule =
{
	(const RTActorClass *)0
  , "serialCommunicationCapsule"
  , (RTVersionId)0
  , 1
  , rtg_relays
  , new_serialCommunicationCapsule_Actor
};

static const char * const rtg_state_names[] =
{
	"TOP"
  , "Ready"
  , "Error"
  , "pollData"
  , "openPort"
  , "ClosePort"
};

#define SUPER RTActor

serialCommunicationCapsule_Actor::serialCommunicationCapsule_Actor( RTController * rtg_rts, RTActorRef * rtg_ref )
	: RTActor( rtg_rts, rtg_ref )
{
}

serialCommunicationCapsule_Actor::~serialCommunicationCapsule_Actor( void )
{
}

int serialCommunicationCapsule_Actor::_followInV( RTBindingEnd & rtg_end, int rtg_portId, int rtg_repIndex )
{
	switch( rtg_portId )
	{
	case 0:
		// serialPort
		if( rtg_repIndex < 1 )
		{
			rtg_end.port = &serialPort;
			rtg_end.index = rtg_repIndex;
			return 1;
		}
		break;
	default:
		break;
	}
	return RTActor::_followInV( rtg_end, rtg_portId, rtg_repIndex );
}

// {{{RME enter ':TOP:Ready'
INLINE_METHODS void serialCommunicationCapsule_Actor::enter2_Ready( void )
{
	// {{{USR
	timer.informIn(RTTimespec(0,10000000));
	//timer.informIn(10);
	// }}}USR
}
// }}}RME

void serialCommunicationCapsule_Actor::enterStateV( void )
{
	switch( getCurrentState() )
	{
	case 2:
		enter2_Ready();
		break;
	case 4:
		enter4_pollData();
		break;
	default:
		RTActor::enterStateV();
		break;
	}
}

// {{{RME enter ':TOP:pollData'
INLINE_METHODS void serialCommunicationCapsule_Actor::enter4_pollData( void )
{
	// {{{USR
	int i = 0;
	int n = 0;

	unsigned char buf[4096];

	n = RS232_PollComport(COM_PORT, buf, 4095);

	if(n > 0)
	{
	  //buf[n] = 0;   /* always put a "null" at the end of a string! */
	  byteArray data(buf, n-1);
	  //cout << "SER: Received " << n << " bytes: ";
	  //data.print();
	  serialPort.dataReceived(data).send();
	}
	// }}}USR
}
// }}}RME

// {{{RME transition ':TOP:Initial:Initial'
INLINE_METHODS void serialCommunicationCapsule_Actor::transition1_Initial( const void * rtdata, RTProtocol * rtport )
{
	// {{{USR
	cout << "Serial capsule initialized" << endl;
	// }}}USR
}
// }}}RME

// {{{RME transition ':TOP:openPort:False'
INLINE_METHODS void serialCommunicationCapsule_Actor::transition2_False( const void * rtdata, RTProtocol * rtport )
{
	// {{{USR
	cout << "COM: Could not open port." << endl;
	serialPort.comError().send();

	// }}}USR
}
// }}}RME

// {{{RME transition ':TOP:openPort:True'
INLINE_METHODS void serialCommunicationCapsule_Actor::transition3_True( const void * rtdata, RTProtocol * rtport )
{
	// {{{USR
	serialPort.comOpened().send();
	// }}}USR
}
// }}}RME

INLINE_CHAINS void serialCommunicationCapsule_Actor::chain1_Initial( void )
{
	// transition ':TOP:Initial:Initial'
	rtgChainBegin( 1, "Initial" );
	rtgTransitionBegin();
	transition1_Initial( msg->data, msg->sap() );
	rtgTransitionEnd();
	if( choicePoint1_openPort( msg->data, msg->sap() ) )
		chain3_True();
	else
		chain2_False();
}

// {{{RME choicePoint ':TOP:openPort'
INLINE_METHODS int serialCommunicationCapsule_Actor::choicePoint1_openPort( const void * rtdata, RTProtocol * rtport )
{
	// {{{USR
	if(RS232_OpenComport(COM_PORT, BAUD))
	{
	  cout << "SER: Can not open COM-Port" << endl;
	  return false;
	}

	else
	{
	  cout << "SER: COM-Port open" << endl;
	  return true;
	}

	// }}}USR
}
// }}}RME

INLINE_CHAINS void serialCommunicationCapsule_Actor::chain3_True( void )
{
	// transition ':TOP:openPort:True'
	rtgChainBegin( 5, "True" );
	rtgTransitionBegin();
	transition3_True( msg->data, msg->sap() );
	rtgTransitionEnd();
	enterState( 2 );
}

INLINE_CHAINS void serialCommunicationCapsule_Actor::chain2_False( void )
{
	// transition ':TOP:openPort:False'
	rtgChainBegin( 5, "False" );
	rtgTransitionBegin();
	transition2_False( msg->data, msg->sap() );
	rtgTransitionEnd();
	enterState( 3 );
}

INLINE_CHAINS void serialCommunicationCapsule_Actor::chain5_timer( void )
{
	// transition ':TOP:Ready:J519C85FA02CA:timer'
	rtgChainBegin( 2, "timer" );
	exitState( rtg_parent_state );
	rtgTransitionBegin();
	rtgTransitionEnd();
	enterState( 4 );
	// transition ':TOP:pollData:J519C895A03AA:timer'
	rtgChainBegin( 4, "timer" );
	rtgTransitionBegin();
	rtgTransitionEnd();
	// transition ':TOP:pollData:J519C89550142:True'
	rtgChainBegin( 4, "True" );
	exitState( rtg_parent_state );
	rtgTransitionBegin();
	rtgTransitionEnd();
	enterState( 2 );
}

void serialCommunicationCapsule_Actor::rtsBehavior( int signalIndex, int portIndex )
{
	for( int stateIndex = getCurrentState(); ; stateIndex = rtg_parent_state[ stateIndex - 1 ] )
		switch( stateIndex )
		{
		case 1:
			// {{{RME state ':TOP'
			switch( portIndex )
			{
			case 0:
				switch( signalIndex )
				{
				case 1:
					chain1_Initial();
					return;
				default:
					break;
				}
				break;
			default:
				break;
			}
			unexpectedMessage();
			return;
			// }}}RME
		case 2:
			// {{{RME state ':TOP:Ready'
			switch( portIndex )
			{
			case 0:
				switch( signalIndex )
				{
				case 1:
					return;
				default:
					break;
				}
				break;
			case 2:
				// {{{RME port 'timer'
				switch( signalIndex )
				{
				case Timing::Base::rti_timeout:
					chain5_timer();
					return;
				default:
					break;
				}
				break;
				// }}}RME
			default:
				break;
			}
			break;
			// }}}RME
		case 3:
			// {{{RME state ':TOP:Error'
			switch( portIndex )
			{
			case 0:
				switch( signalIndex )
				{
				case 1:
					return;
				default:
					break;
				}
				break;
			default:
				break;
			}
			break;
			// }}}RME
		case 4:
			// {{{RME state ':TOP:pollData'
			switch( portIndex )
			{
			case 0:
				switch( signalIndex )
				{
				case 1:
					return;
				default:
					break;
				}
				break;
			default:
				break;
			}
			break;
			// }}}RME
		default:
			unexpectedState();
			return;
		}
}

// {{{RME choicePoint ':TOP:ClosePort'
INLINE_METHODS int serialCommunicationCapsule_Actor::choicePoint2_ClosePort( const void * rtdata, RTProtocol * rtport )
{
	// {{{USR
	RS232_CloseComport(COM_PORT);
	// }}}USR
}
// }}}RME

const RTActor_class * serialCommunicationCapsule_Actor::getActorData( void ) const
{
	return &serialCommunicationCapsule_Actor::rtg_class;
}

const RTActor_class serialCommunicationCapsule_Actor::rtg_class =
{
	(const RTActor_class *)0
  , rtg_state_names
  , 4
  , serialCommunicationCapsule_Actor::rtg_parent_state
  , &serialCommunicationCapsule
  , 0
  , (const RTComponentDescriptor *)0
  , 2
  , serialCommunicationCapsule_Actor::rtg_ports
  , 0
  , (const RTLocalBindingDescriptor *)0
  , 0
  , (const RTFieldDescriptor *)0
};

const RTStateId serialCommunicationCapsule_Actor::rtg_parent_state[] =
{
	0
  , 1
  , 1
  , 1
};

const RTPortDescriptor serialCommunicationCapsule_Actor::rtg_ports[] =
{
	{
		"serialPort"
	  , (const char *)0
	  , &serialRawProtocol::Base::rt_class
	  , RTOffsetOf( serialCommunicationCapsule_Actor, serialCommunicationCapsule_Actor::serialPort )
	  , 1 // cardinality
	  , 1
	  , RTPortDescriptor::KindWired + RTPortDescriptor::NotificationDisabled + RTPortDescriptor::RegisterNotPermitted + RTPortDescriptor::VisibilityPublic
	}
  , {
		"timer"
	  , (const char *)0
	  , &Timing::Base::rt_class
	  , RTOffsetOf( serialCommunicationCapsule_Actor, serialCommunicationCapsule_Actor::timer )
	  , 1 // cardinality
	  , 2
	  , RTPortDescriptor::KindSpecial + RTPortDescriptor::NotificationDisabled + RTPortDescriptor::RegisterNotPermitted + RTPortDescriptor::VisibilityProtected
	}
};

#undef SUPER

// {{{RME tool 'OT::Cpp' property 'ImplementationEnding'
// {{{USR

// }}}USR
// }}}RME

// }}}RME
