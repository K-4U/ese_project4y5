// {{{RME classifier 'Logical View::SerialCommunicationCapsule'

#if defined( PRAGMA ) && ! defined( PRAGMA_IMPLEMENTED )
#pragma implementation "SerialCommunicationCapsule.h"
#endif

#include <RTSystem/Program.h>
#include <SerialCommunicationCapsule.h>
#include <SerialProperties.h>

// {{{RME tool 'OT::Cpp' property 'ImplementationPreface'
// {{{USR

// }}}USR
// }}}RME

static const RTRelayDescriptor rtg_relays[] =
{
	{
		"SerialCommunication"
	  , &SerialProtocol::Base::rt_class
	  , 1 // cardinality
	}
};

static RTActor * new_SerialCommunicationCapsule_Actor( RTController * _rts, RTActorRef * _ref )
{
	return new SerialCommunicationCapsule_Actor( _rts, _ref );
}

const RTActorClass SerialCommunicationCapsule =
{
	(const RTActorClass *)0
  , "SerialCommunicationCapsule"
  , (RTVersionId)0
  , 1
  , rtg_relays
  , new_SerialCommunicationCapsule_Actor
};

static const char * const rtg_state_names[] =
{
	"TOP"
  , "Reset"
  , "OpenPort"
  , "GetCaracters"
  , "ClosePort"
};

#define SUPER RTActor

SerialCommunicationCapsule_Actor::SerialCommunicationCapsule_Actor( RTController * rtg_rts, RTActorRef * rtg_ref )
	: RTActor( rtg_rts, rtg_ref )
{
}

SerialCommunicationCapsule_Actor::~SerialCommunicationCapsule_Actor( void )
{
}

int SerialCommunicationCapsule_Actor::_followInV( RTBindingEnd & rtg_end, int rtg_portId, int rtg_repIndex )
{
	switch( rtg_portId )
	{
	case 0:
		// SerialCommunication
		if( rtg_repIndex < 1 )
		{
			rtg_end.port = &SerialCommunication;
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
INLINE_METHODS void SerialCommunicationCapsule_Actor::enter2_Reset( void )
{
	// {{{USR
	cout << "in reset terecht gekomen" << endl;
	timer.informIn(RTTimespec(4,0));
	// }}}USR
}
// }}}RME

void SerialCommunicationCapsule_Actor::enterStateV( void )
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

INLINE_CHAINS void SerialCommunicationCapsule_Actor::chain1_Initial( void )
{
	// transition ':TOP:Initial:Initial'
	rtgChainBegin( 1, "Initial" );
	rtgTransitionBegin();
	rtgTransitionEnd();
	if( choicePoint1_OpenPort( msg->data, msg->sap() ) )
		chain3_True();
	else
		chain2_False();
}

// {{{RME choicePoint ':TOP:OpenPort'
INLINE_METHODS int SerialCommunicationCapsule_Actor::choicePoint1_OpenPort( const void * rtdata, RTProtocol * rtport )
{
	// {{{USR
	/* 9600 baud */
	/* /dev/ttyS0 (COM1 on windows) */
	if(RS232_OpenComport(COM_PORT, BAUD))
	{
	  cout << "Can not open COM-Port" << endl;
	  return false;
	}

	else
	{
	  cout << "COM-Port open" << endl;
	  return true;
	}

	// }}}USR
}
// }}}RME

INLINE_CHAINS void SerialCommunicationCapsule_Actor::chain3_True( void )
{
	// transition ':TOP:OpenPort:True'
	rtgChainBegin( 3, "True" );
	rtgTransitionBegin();
	rtgTransitionEnd();
	if( choicePoint2_GetCaracters( msg->data, msg->sap() ) )
		chain4_True();
	else
		chain5_False();
}

// {{{RME choicePoint ':TOP:GetCaracters'
INLINE_METHODS int SerialCommunicationCapsule_Actor::choicePoint2_GetCaracters( const void * rtdata, RTProtocol * rtport )
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
	  cout << "received " << n << "bytes " << (char *)buf << endl;
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

INLINE_CHAINS void SerialCommunicationCapsule_Actor::chain4_True( void )
{
	// transition ':TOP:GetCaracters:True'
	rtgChainBegin( 4, "True" );
	rtgTransitionBegin();
	rtgTransitionEnd();
	if( choicePoint2_GetCaracters( msg->data, msg->sap() ) )
		chain4_True();
	else
		chain5_False();
}

INLINE_CHAINS void SerialCommunicationCapsule_Actor::chain5_False( void )
{
	// transition ':TOP:GetCaracters:False'
	rtgChainBegin( 4, "False" );
	rtgTransitionBegin();
	rtgTransitionEnd();
	if( ! choicePoint3_ClosePort( msg->data, msg->sap() ) )
		chain6_False();
}

// {{{RME choicePoint ':TOP:ClosePort'
INLINE_METHODS int SerialCommunicationCapsule_Actor::choicePoint3_ClosePort( const void * rtdata, RTProtocol * rtport )
{
	// {{{USR
	RS232_CloseComport(COM_PORT);
	// }}}USR
}
// }}}RME

INLINE_CHAINS void SerialCommunicationCapsule_Actor::chain6_False( void )
{
	// transition ':TOP:ClosePort:False'
	rtgChainBegin( 5, "False" );
	rtgTransitionBegin();
	rtgTransitionEnd();
	enterState( 2 );
}

INLINE_CHAINS void SerialCommunicationCapsule_Actor::chain2_False( void )
{
	// transition ':TOP:OpenPort:False'
	rtgChainBegin( 3, "False" );
	rtgTransitionBegin();
	rtgTransitionEnd();
	enterState( 2 );
}

void SerialCommunicationCapsule_Actor::rtsBehavior( int signalIndex, int portIndex )
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

const RTActor_class * SerialCommunicationCapsule_Actor::getActorData( void ) const
{
	return &SerialCommunicationCapsule_Actor::rtg_class;
}

const RTActor_class SerialCommunicationCapsule_Actor::rtg_class =
{
	(const RTActor_class *)0
  , rtg_state_names
  , 2
  , SerialCommunicationCapsule_Actor::rtg_parent_state
  , &SerialCommunicationCapsule
  , 0
  , (const RTComponentDescriptor *)0
  , 2
  , SerialCommunicationCapsule_Actor::rtg_ports
  , 0
  , (const RTLocalBindingDescriptor *)0
  , 0
  , (const RTFieldDescriptor *)0
};

const RTStateId SerialCommunicationCapsule_Actor::rtg_parent_state[] =
{
	0
  , 1
};

const RTPortDescriptor SerialCommunicationCapsule_Actor::rtg_ports[] =
{
	{
		"SerialCommunication"
	  , (const char *)0
	  , &SerialProtocol::Base::rt_class
	  , RTOffsetOf( SerialCommunicationCapsule_Actor, SerialCommunicationCapsule_Actor::SerialCommunication )
	  , 1 // cardinality
	  , 1
	  , RTPortDescriptor::KindWired + RTPortDescriptor::NotificationDisabled + RTPortDescriptor::RegisterNotPermitted + RTPortDescriptor::VisibilityPublic
	}
  , {
		"timer"
	  , (const char *)0
	  , &Timing::Base::rt_class
	  , RTOffsetOf( SerialCommunicationCapsule_Actor, SerialCommunicationCapsule_Actor::timer )
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
