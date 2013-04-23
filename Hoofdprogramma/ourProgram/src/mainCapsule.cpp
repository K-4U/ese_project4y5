// {{{RME classifier 'Logical View::mainCapsule'

#if defined( PRAGMA ) && ! defined( PRAGMA_IMPLEMENTED )
#pragma implementation "mainCapsule.h"
#endif

#include <RTSystem/ourProgram.h>
#include <mainCapsule.h>
extern const RTActorClass tcpCapsule;

// {{{RME tool 'OT::Cpp' property 'ImplementationPreface'
// {{{USR

// }}}USR
// }}}RME

static const RTRelayDescriptor rtg_relays[] =
{
	{
		"tcpConnection"
	  , &tcpProtocol::Conjugate::rt_class
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
  , "KlaarVoorData"
};

static const RTInterfaceDescriptor rtg_interfaces_instanceTcpCapsule[] =
{
	{
		"mainConnection"
	  , 0
	}
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
		// tcpConnection
		if( rtg_repIndex < 1 )
		{
			rtg_end.port = &tcpConnection;
			rtg_end.index = rtg_repIndex;
			return 1;
		}
		break;
	default:
		break;
	}
	return RTActor::_followInV( rtg_end, rtg_portId, rtg_repIndex );
}

// {{{RME transition ':TOP:Initial:Initial'
INLINE_METHODS void mainCapsule_Actor::transition1_Initial( const void * rtdata, RTProtocol * rtport )
{
	// {{{USR
	//maak object voor de tcp verbinding
	frame.incarnate(instanceTcpCapsule,tcpCapsule,EmptyObject,ThreadUserInterface);
	// }}}USR
}
// }}}RME

// {{{RME transition ':TOP:KlaarVoorData:J5176823800F4:dataReceived'
INLINE_METHODS void mainCapsule_Actor::transition2_dataReceived( const RTString * rtdata, tcpProtocol::Conjugate * rtport )
{
	// {{{USR
	cout << "Data received" << *rtdata << endl;
	// }}}USR
}
// }}}RME

INLINE_CHAINS void mainCapsule_Actor::chain1_Initial( void )
{
	// transition ':TOP:Initial:Initial'
	rtgChainBegin( 1, "Initial" );
	rtgTransitionBegin();
	transition1_Initial( msg->data, msg->sap() );
	rtgTransitionEnd();
	enterState( 2 );
}

INLINE_CHAINS void mainCapsule_Actor::chain2_dataReceived( void )
{
	// transition ':TOP:KlaarVoorData:J5176823800F4:dataReceived'
	rtgChainBegin( 2, "dataReceived" );
	exitState( rtg_parent_state );
	rtgTransitionBegin();
	transition2_dataReceived( (const RTString *)msg->data, (tcpProtocol::Conjugate *)msg->sap() );
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
			// {{{RME state ':TOP:KlaarVoorData'
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
				// {{{RME port 'tcpConnection'
				switch( signalIndex )
				{
				case tcpProtocol::Conjugate::rti_dataReceived:
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
  , 1
  , mainCapsule_Actor::rtg_capsule_roles
  , 2
  , mainCapsule_Actor::rtg_ports
  , 0
  , (const RTLocalBindingDescriptor *)0
  , 1
  , mainCapsule_Actor::rtg_mainCapsule_fields
};

const RTStateId mainCapsule_Actor::rtg_parent_state[] =
{
	0
  , 1
};

const RTComponentDescriptor mainCapsule_Actor::rtg_capsule_roles[] =
{
	{
		"instanceTcpCapsule"
	  , &tcpCapsule
	  , RTOffsetOf( mainCapsule_Actor, instanceTcpCapsule )
	  , 1
	  , RTComponentDescriptor::Fixed
	  , 1
	  , 1 // cardinality
	  , 1
	  , rtg_interfaces_instanceTcpCapsule
	  , 0
	  , (const RTBindingDescriptor *)0
	}
};

const RTPortDescriptor mainCapsule_Actor::rtg_ports[] =
{
	{
		"tcpConnection"
	  , (const char *)0
	  , &tcpProtocol::Conjugate::rt_class
	  , RTOffsetOf( mainCapsule_Actor, mainCapsule_Actor::tcpConnection )
	  , 1 // cardinality
	  , 1
	  , RTPortDescriptor::KindWired + RTPortDescriptor::NotificationDisabled + RTPortDescriptor::RegisterNotPermitted + RTPortDescriptor::VisibilityPublic
	}
  , {
		"frame"
	  , (const char *)0
	  , &Frame::Base::rt_class
	  , RTOffsetOf( mainCapsule_Actor, mainCapsule_Actor::frame )
	  , 1 // cardinality
	  , 2
	  , RTPortDescriptor::KindSpecial + RTPortDescriptor::NotificationDisabled + RTPortDescriptor::RegisterNotPermitted + RTPortDescriptor::VisibilityProtected
	}
};

const RTFieldDescriptor mainCapsule_Actor::rtg_mainCapsule_fields[] =
{
	// {{{RME classAttribute 'clientSocket'
	{
		"clientSocket"
	  , RTOffsetOf( mainCapsule_Actor, clientSocket )
		// {{{RME tool 'OT::CppTargetRTS' property 'TypeDescriptor'
	  , (const RTObject_class *)0
		// }}}RME
		// {{{RME tool 'OT::CppTargetRTS' property 'GenerateTypeModifier'
	  , (const RTTypeModifier *)0
		// }}}RME
	}
	// }}}RME
};
#undef SUPER

// {{{RME tool 'OT::Cpp' property 'ImplementationEnding'
// {{{USR

// }}}USR
// }}}RME

// }}}RME
