// {{{RME classifier 'Logical View::Serial::serialTranslateCapsule'

#if defined( PRAGMA ) && ! defined( PRAGMA_IMPLEMENTED )
#pragma implementation "serialTranslateCapsule.h"
#endif

#include <RTSystem/ourProgram.h>
#include <serialTranslateCapsule.h>

// {{{RME tool 'OT::Cpp' property 'ImplementationPreface'
// {{{USR

// }}}USR
// }}}RME

static const RTRelayDescriptor rtg_relays[] =
{
	{
		"serialRaw"
	  , &serialRawProtocol::Conjugate::rt_class
	  , 1 // cardinality
	}
  , {
		"serialOut"
	  , &serialProtocol::Base::rt_class
	  , 1 // cardinality
	}
};

static RTActor * new_serialTranslateCapsule_Actor( RTController * _rts, RTActorRef * _ref )
{
	return new serialTranslateCapsule_Actor( _rts, _ref );
}

const RTActorClass serialTranslateCapsule =
{
	(const RTActorClass *)0
  , "serialTranslateCapsule"
  , (RTVersionId)0
  , 2
  , rtg_relays
  , new_serialTranslateCapsule_Actor
};

static const char * const rtg_state_names[] =
{
	"TOP"
  , "S1"
};

#define SUPER RTActor

serialTranslateCapsule_Actor::serialTranslateCapsule_Actor( RTController * rtg_rts, RTActorRef * rtg_ref )
	: RTActor( rtg_rts, rtg_ref )
{
}

serialTranslateCapsule_Actor::~serialTranslateCapsule_Actor( void )
{
}

int serialTranslateCapsule_Actor::_followInV( RTBindingEnd & rtg_end, int rtg_portId, int rtg_repIndex )
{
	switch( rtg_portId )
	{
	case 0:
		// serialRaw
		if( rtg_repIndex < 1 )
		{
			rtg_end.port = &serialRaw;
			rtg_end.index = rtg_repIndex;
			return 1;
		}
		break;
	case 1:
		// serialOut
		if( rtg_repIndex < 1 )
		{
			rtg_end.port = &serialOut;
			rtg_end.index = rtg_repIndex;
			return 1;
		}
		break;
	default:
		break;
	}
	return RTActor::_followInV( rtg_end, rtg_portId, rtg_repIndex );
}

// {{{RME transition ':TOP:S1:J519234560116:dataReceived'
INLINE_METHODS void serialTranslateCapsule_Actor::transition2_dataReceived( const byteArray * rtdata, serialRawProtocol::Conjugate * rtport )
{
	// {{{USR
	byteArray b = *rtdata;
	cout << "STR: Data received: " << (char *)b.getAll() << endl;
	// }}}USR
}
// }}}RME

INLINE_CHAINS void serialTranslateCapsule_Actor::chain1_Initial( void )
{
	// transition ':TOP:Initial:Initial'
	rtgChainBegin( 1, "Initial" );
	rtgTransitionBegin();
	rtgTransitionEnd();
	enterState( 2 );
}

INLINE_CHAINS void serialTranslateCapsule_Actor::chain2_dataReceived( void )
{
	// transition ':TOP:S1:J519234560116:dataReceived'
	rtgChainBegin( 2, "dataReceived" );
	exitState( rtg_parent_state );
	rtgTransitionBegin();
	transition2_dataReceived( (const byteArray *)msg->data, (serialRawProtocol::Conjugate *)msg->sap() );
	rtgTransitionEnd();
	enterState( 2 );
}

void serialTranslateCapsule_Actor::rtsBehavior( int signalIndex, int portIndex )
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
			// {{{RME state ':TOP:S1'
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
			case 1:
				// {{{RME port 'serialRaw'
				switch( signalIndex )
				{
				case serialRawProtocol::Conjugate::rti_dataReceived:
					chain2_dataReceived();
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
		default:
			unexpectedState();
			return;
		}
}

const RTActor_class * serialTranslateCapsule_Actor::getActorData( void ) const
{
	return &serialTranslateCapsule_Actor::rtg_class;
}

const RTActor_class serialTranslateCapsule_Actor::rtg_class =
{
	(const RTActor_class *)0
  , rtg_state_names
  , 2
  , serialTranslateCapsule_Actor::rtg_parent_state
  , &serialTranslateCapsule
  , 0
  , (const RTComponentDescriptor *)0
  , 2
  , serialTranslateCapsule_Actor::rtg_ports
  , 0
  , (const RTLocalBindingDescriptor *)0
  , 0
  , (const RTFieldDescriptor *)0
};

const RTStateId serialTranslateCapsule_Actor::rtg_parent_state[] =
{
	0
  , 1
};

const RTPortDescriptor serialTranslateCapsule_Actor::rtg_ports[] =
{
	{
		"serialRaw"
	  , (const char *)0
	  , &serialRawProtocol::Conjugate::rt_class
	  , RTOffsetOf( serialTranslateCapsule_Actor, serialTranslateCapsule_Actor::serialRaw )
	  , 1 // cardinality
	  , 1
	  , RTPortDescriptor::KindWired + RTPortDescriptor::NotificationDisabled + RTPortDescriptor::RegisterNotPermitted + RTPortDescriptor::VisibilityPublic
	}
  , {
		"serialOut"
	  , (const char *)0
	  , &serialProtocol::Base::rt_class
	  , RTOffsetOf( serialTranslateCapsule_Actor, serialTranslateCapsule_Actor::serialOut )
	  , 1 // cardinality
	  , 2
	  , RTPortDescriptor::KindWired + RTPortDescriptor::NotificationDisabled + RTPortDescriptor::RegisterNotPermitted + RTPortDescriptor::VisibilityPublic
	}
};

#undef SUPER

// {{{RME tool 'OT::Cpp' property 'ImplementationEnding'
// {{{USR

// }}}USR
// }}}RME

// }}}RME
