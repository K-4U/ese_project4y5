// {{{RME classifier 'Logical View::mainCapsule'

#if defined( PRAGMA ) && ! defined( PRAGMA_IMPLEMENTED )
#pragma implementation "mainCapsule.h"
#endif

#include <RTSystem/Program.h>
#include <mainCapsule.h>

// {{{RME tool 'OT::Cpp' property 'ImplementationPreface'
// {{{USR

// }}}USR
// }}}RME

static const RTRelayDescriptor rtg_relays[] =
{
	{
		"Serial"
	  , &SerialProtocol::Conjugate::rt_class
	  , 1 // cardinality
	}
};

static RTActor * new_mainCapsule_Actor( RTController * _rts, RTActorRef * _ref )
{
	return new mainCapsule_Actor( _rts, _ref );
}

const RTActorClass mainCapsule =
{
	(const RTActorClass *)0
  , "mainCapsule"
  , (RTVersionId)0
  , 1
  , rtg_relays
  , new_mainCapsule_Actor
};

static const char * const rtg_state_names[] =
{
	"TOP"
  , "ready"
};

#define SUPER RTActor

mainCapsule_Actor::mainCapsule_Actor( RTController * rtg_rts, RTActorRef * rtg_ref )
	: RTActor( rtg_rts, rtg_ref )
{
}

mainCapsule_Actor::~mainCapsule_Actor( void )
{
}

int mainCapsule_Actor::_followInV( RTBindingEnd & rtg_end, int rtg_portId, int rtg_repIndex )
{
	switch( rtg_portId )
	{
	case 0:
		// Serial
		if( rtg_repIndex < 1 )
		{
			rtg_end.port = &Serial;
			rtg_end.index = rtg_repIndex;
			return 1;
		}
		break;
	default:
		break;
	}
	return RTActor::_followInV( rtg_end, rtg_portId, rtg_repIndex );
}

// {{{RME enter ':TOP:ready'
INLINE_METHODS void mainCapsule_Actor::enter2_ready( void )
{
	// {{{USR
	cout << "topCapsule initialized" << endl;
	// }}}USR
}
// }}}RME

void mainCapsule_Actor::enterStateV( void )
{
	switch( getCurrentState() )
	{
	case 2:
		enter2_ready();
		break;
	default:
		RTActor::enterStateV();
		break;
	}
}

// {{{RME transition ':TOP:ready:J51921871008A:DataReceived'
INLINE_METHODS void mainCapsule_Actor::transition2_DataReceived( const RTString * rtdata, SerialProtocol::Conjugate * rtport )
{
	// {{{USR
	cout << "Data reveived" << endl;
	// }}}USR
}
// }}}RME

INLINE_CHAINS void mainCapsule_Actor::chain1_Initial( void )
{
	// transition ':TOP:Initial:Initial'
	rtgChainBegin( 1, "Initial" );
	rtgTransitionBegin();
	rtgTransitionEnd();
	enterState( 2 );
}

INLINE_CHAINS void mainCapsule_Actor::chain2_DataReceived( void )
{
	// transition ':TOP:ready:J51921871008A:DataReceived'
	rtgChainBegin( 2, "DataReceived" );
	exitState( rtg_parent_state );
	rtgTransitionBegin();
	transition2_DataReceived( (const RTString *)msg->data, (SerialProtocol::Conjugate *)msg->sap() );
	rtgTransitionEnd();
	enterState( 2 );
}

void mainCapsule_Actor::rtsBehavior( int signalIndex, int portIndex )
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
			// {{{RME state ':TOP:ready'
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
				// {{{RME port 'Serial'
				switch( signalIndex )
				{
				case SerialProtocol::Conjugate::rti_DataReceived:
					chain2_DataReceived();
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

const RTActor_class * mainCapsule_Actor::getActorData( void ) const
{
	return &mainCapsule_Actor::rtg_class;
}

const RTActor_class mainCapsule_Actor::rtg_class =
{
	(const RTActor_class *)0
  , rtg_state_names
  , 2
  , mainCapsule_Actor::rtg_parent_state
  , &mainCapsule
  , 0
  , (const RTComponentDescriptor *)0
  , 2
  , mainCapsule_Actor::rtg_ports
  , 0
  , (const RTLocalBindingDescriptor *)0
  , 0
  , (const RTFieldDescriptor *)0
};

const RTStateId mainCapsule_Actor::rtg_parent_state[] =
{
	0
  , 1
};

const RTPortDescriptor mainCapsule_Actor::rtg_ports[] =
{
	{
		"frame"
	  , (const char *)0
	  , &Frame::Base::rt_class
	  , RTOffsetOf( mainCapsule_Actor, mainCapsule_Actor::frame )
	  , 1 // cardinality
	  , 1
	  , RTPortDescriptor::KindSpecial + RTPortDescriptor::NotificationDisabled + RTPortDescriptor::RegisterNotPermitted + RTPortDescriptor::VisibilityProtected
	}
  , {
		"Serial"
	  , (const char *)0
	  , &SerialProtocol::Conjugate::rt_class
	  , RTOffsetOf( mainCapsule_Actor, mainCapsule_Actor::Serial )
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
