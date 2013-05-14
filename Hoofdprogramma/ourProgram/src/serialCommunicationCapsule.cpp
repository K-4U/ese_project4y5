// {{{RME classifier 'Logical View::Serial::serialCommunicationCapsule'

#if defined( PRAGMA ) && ! defined( PRAGMA_IMPLEMENTED )
#pragma implementation "serialCommunicationCapsule.h"
#endif

#include <RTSystem/ourProgram.h>
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
  , "Reset"
  , "openPort"
  , "getChars"
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

// {{{RME enter ':TOP:Reset'
INLINE_METHODS void serialCommunicationCapsule_Actor::enter2_Reset( void )
{
	// {{{USR
	cout << "in reset terecht gekomen" << endl;
	// }}}USR
}
// }}}RME

void serialCommunicationCapsule_Actor::enterStateV( void )
{
	switch( getCurrentState() )
	{
	case 2:
		enter2_Reset();
		break;
	default:
		RTActor::enterStateV();
		break;
	}
}

// {{{RME transition ':TOP:Initial:Initial'
INLINE_METHODS void serialCommunicationCapsule_Actor::transition1_Initial( const void * rtdata, RTProtocol * rtport )
{
	// {{{USR
	cout << "Serial capsule initialized" << endl;
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
	/* 9600 baud */
	/* /dev/ttyS0 (COM1 on windows) */
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
	rtgChainBegin( 3, "True" );
	rtgTransitionBegin();
	rtgTransitionEnd();
	if( choicePoint2_getChars( msg->data, msg->sap() ) )
		chain4_True();
	else
		chain5_False();
}

// {{{RME choicePoint ':TOP:getChars'
INLINE_METHODS int serialCommunicationCapsule_Actor::choicePoint2_getChars( const void * rtdata, RTProtocol * rtport )
{
	// {{{USR
	int i, n;

	unsigned char buf[4096];

	n = RS232_PollComport(COM_PORT, buf, 4095);

	if(n > 0)
	{
	  buf[n] = 0;   /* always put a "null" at the end of a string! */

	  for(i=0; i < n; i++)
	  {
	    if(buf[i] < 32)  /* replace unreadable control-codes by dots */
	    {
	      buf[i] = '.';
	    }
	  }
	  cout << "SER: Received " << n << " bytes: " << (char *)buf << endl;
	  byteArray data((char *) buf);
	  serialPort.dataReceived(data).send();
	}

#ifdef _WIN32
	    Sleep(100);
#else
	    usleep(100000);  /* sleep for 100 milliSeconds */
#endif

	return true;
	// }}}USR
}
// }}}RME

INLINE_CHAINS void serialCommunicationCapsule_Actor::chain4_True( void )
{
	// transition ':TOP:getChars:True'
	rtgChainBegin( 4, "True" );
	rtgTransitionBegin();
	rtgTransitionEnd();
	if( choicePoint2_getChars( msg->data, msg->sap() ) )
		chain4_True();
	else
		chain5_False();
}

INLINE_CHAINS void serialCommunicationCapsule_Actor::chain5_False( void )
{
	// transition ':TOP:getChars:False'
	rtgChainBegin( 4, "False" );
	rtgTransitionBegin();
	rtgTransitionEnd();
	enterState( 2 );
}

INLINE_CHAINS void serialCommunicationCapsule_Actor::chain2_False( void )
{
	// transition ':TOP:openPort:False'
	rtgChainBegin( 3, "False" );
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
			// {{{RME state ':TOP:Reset'
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
INLINE_METHODS int serialCommunicationCapsule_Actor::choicePoint3_ClosePort( const void * rtdata, RTProtocol * rtport )
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
  , 2
  , serialCommunicationCapsule_Actor::rtg_parent_state
  , &serialCommunicationCapsule
  , 0
  , (const RTComponentDescriptor *)0
  , 1
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
};

#undef SUPER

// {{{RME tool 'OT::Cpp' property 'ImplementationEnding'
// {{{USR

// }}}USR
// }}}RME

// }}}RME
