// {{{RME classifier 'Logical View::Serial::serialTopCapsule'

#if defined( PRAGMA ) && ! defined( PRAGMA_IMPLEMENTED )
#pragma implementation "serialTopCapsule.h"
#endif

#include <RTSystem/roombaController.h>
#include <serialTopCapsule.h>
#include <serialRawProtocol.h>
extern const RTActorClass serialCommunicationCapsule;
extern const RTActorClass serialTranslateCapsule;

// {{{RME tool 'OT::Cpp' property 'ImplementationPreface'
// {{{USR

// }}}USR
// }}}RME

static const RTRelayDescriptor rtg_relays[] =
{
	{
		"externalSerial"
	  , &serialProtocol::Base::rt_class
	  , 1 // cardinality
	}
};

static RTActor * new_serialTopCapsule_Actor( RTController * _rts, RTActorRef * _ref )
{
	return new serialTopCapsule_Actor( _rts, _ref );
}

const RTActorClass serialTopCapsule =
{
	(const RTActorClass *)0
  , "serialTopCapsule"
  , (RTVersionId)0
  , 1
  , rtg_relays
  , new_serialTopCapsule_Actor
};

static const char * const rtg_state_names[] =
{
	"TOP"
  , "ready"
};

static const RTInterfaceDescriptor rtg_interfaces_serialCommunicationInstance[] =
{
	{
		"serialPort"
	  , 1
	}
};

static const RTBindingDescriptor rtg_bindings_serialCommunicationInstance[] =
{
	{
		0
	  , &serialRawProtocol::Conjugate::rt_class
	}
};

static const RTInterfaceDescriptor rtg_interfaces_serialTranslateCapsuleR1[] =
{
	{
		"serialRaw"
	  , 1
	}
  , {
		"serialOut"
	  , 1
	}
};

static const RTBindingDescriptor rtg_bindings_serialTranslateCapsuleR1[] =
{
	{
		0
	  , &serialRawProtocol::Base::rt_class
	}
  , {
		1
	  , &serialProtocol::Conjugate::rt_class
	}
};

#define SUPER RTActor

serialTopCapsule_Actor::serialTopCapsule_Actor( RTController * rtg_rts, RTActorRef * rtg_ref )
	: RTActor( rtg_rts, rtg_ref )
{
}

serialTopCapsule_Actor::~serialTopCapsule_Actor( void )
{
}

int serialTopCapsule_Actor::_followInV( RTBindingEnd & rtg_end, int rtg_portId, int rtg_repIndex )
{
	switch( rtg_portId )
	{
	case 0:
		// externalSerial
		if( rtg_repIndex < 1 )
		{
			rtg_end.port = &externalSerial;
			rtg_end.index = rtg_repIndex;
			return 1;
		}
		break;
	default:
		break;
	}
	return RTActor::_followInV( rtg_end, rtg_portId, rtg_repIndex );
}

int serialTopCapsule_Actor::_followOutV( RTBindingEnd & rtg_end, int rtg_compId, int rtg_portId, int rtg_repIndex )
{
	switch( rtg_compId )
	{
	case 1:
		// serialCommunicationInstance
		switch( rtg_portId )
		{
		case 0:
			// serialPort
			if( rtg_repIndex < 1 )
			{
				// serialTranslateCapsuleR1/serialRaw
				return serialTranslateCapsuleR1._followIn( rtg_end, 0, rtg_repIndex );
			}
			break;
		default:
			break;
		}
	case 2:
		// serialTranslateCapsuleR1
		switch( rtg_portId )
		{
		case 0:
			// serialRaw
			if( rtg_repIndex < 1 )
			{
				// serialCommunicationInstance/serialPort
				return serialCommunicationInstance._followIn( rtg_end, 0, rtg_repIndex );
			}
			break;
		case 1:
			// serialOut
			if( rtg_repIndex < 1 )
			{
				// internalSerial
				rtg_end.port = &internalSerial;
				rtg_end.index = rtg_repIndex;
				return 1;
			}
			break;
		default:
			break;
		}
	default:
		break;
	}
	return RTActor::_followOutV( rtg_end, rtg_compId, rtg_portId, rtg_repIndex );
}

// {{{RME transition ':TOP:Initial:Initial'
INLINE_METHODS void serialTopCapsule_Actor::transition1_Initial( const void * rtdata, RTProtocol * rtport )
{
	// {{{USR
	frame.incarnate(serialCommunicationInstance,serialCommunicationCapsule,EmptyObject,ThreadSerial);

	cout << "serialTopCapsule initialized" << endl;
	// }}}USR
}
// }}}RME

// {{{RME transition ':TOP:ready:J51922F8C025B:commandReceived'
INLINE_METHODS void serialTopCapsule_Actor::transition2_commandReceived( const byteArray * rtdata, serialProtocol::Conjugate * rtport )
{
	// {{{USR
	//Transfer
	externalSerial.commandReceived(*rtdata).send();
	// }}}USR
}
// }}}RME

// {{{RME transition ':TOP:ready:J5193582D0135:sendCommand'
INLINE_METHODS void serialTopCapsule_Actor::transition3_sendCommand( const byteArray * rtdata, serialProtocol::Base * rtport )
{
	// {{{USR
	//Transfer
	internalSerial.sendCommand(*rtdata).send();
	// }}}USR
}
// }}}RME

// {{{RME transition ':TOP:ready:J519B511B0342:comOpened'
INLINE_METHODS void serialTopCapsule_Actor::transition4_comOpened( const void * rtdata, serialProtocol::Conjugate * rtport )
{
	// {{{USR
	externalSerial.comOpened().send();
	// }}}USR
}
// }}}RME

// {{{RME transition ':TOP:ready:J519B513C00E7:comError'
INLINE_METHODS void serialTopCapsule_Actor::transition5_comError( const void * rtdata, serialProtocol::Conjugate * rtport )
{
	// {{{USR
	externalSerial.comError().send();
	// }}}USR
}
// }}}RME

// {{{RME transition ':TOP:ready:J51AC8CD800D7:setCommandLength'
INLINE_METHODS void serialTopCapsule_Actor::transition6_setCommandLength( const int * rtdata, serialProtocol::Base * rtport )
{
	// {{{USR
	internalSerial.commandLength(*rtdata).send();

	// }}}USR
}
// }}}RME

INLINE_CHAINS void serialTopCapsule_Actor::chain1_Initial( void )
{
	// transition ':TOP:Initial:Initial'
	rtgChainBegin( 1, "Initial" );
	rtgTransitionBegin();
	transition1_Initial( msg->data, msg->sap() );
	rtgTransitionEnd();
	enterState( 2 );
}

INLINE_CHAINS void serialTopCapsule_Actor::chain2_commandReceived( void )
{
	// transition ':TOP:ready:J51922F8C025B:commandReceived'
	rtgChainBegin( 2, "commandReceived" );
	exitState( rtg_parent_state );
	rtgTransitionBegin();
	transition2_commandReceived( (const byteArray *)msg->data, (serialProtocol::Conjugate *)msg->sap() );
	rtgTransitionEnd();
	enterState( 2 );
}

INLINE_CHAINS void serialTopCapsule_Actor::chain4_comOpened( void )
{
	// transition ':TOP:ready:J519B511B0342:comOpened'
	rtgChainBegin( 2, "comOpened" );
	exitState( rtg_parent_state );
	rtgTransitionBegin();
	transition4_comOpened( msg->data, (serialProtocol::Conjugate *)msg->sap() );
	rtgTransitionEnd();
	enterState( 2 );
}

INLINE_CHAINS void serialTopCapsule_Actor::chain5_comError( void )
{
	// transition ':TOP:ready:J519B513C00E7:comError'
	rtgChainBegin( 2, "comError" );
	exitState( rtg_parent_state );
	rtgTransitionBegin();
	transition5_comError( msg->data, (serialProtocol::Conjugate *)msg->sap() );
	rtgTransitionEnd();
	enterState( 2 );
}

INLINE_CHAINS void serialTopCapsule_Actor::chain3_sendCommand( void )
{
	// transition ':TOP:ready:J5193582D0135:sendCommand'
	rtgChainBegin( 2, "sendCommand" );
	exitState( rtg_parent_state );
	rtgTransitionBegin();
	transition3_sendCommand( (const byteArray *)msg->data, (serialProtocol::Base *)msg->sap() );
	rtgTransitionEnd();
	enterState( 2 );
}

INLINE_CHAINS void serialTopCapsule_Actor::chain6_setCommandLength( void )
{
	// transition ':TOP:ready:J51AC8CD800D7:setCommandLength'
	rtgChainBegin( 2, "setCommandLength" );
	exitState( rtg_parent_state );
	rtgTransitionBegin();
	transition6_setCommandLength( (const int *)msg->data, (serialProtocol::Base *)msg->sap() );
	rtgTransitionEnd();
	enterState( 2 );
}

void serialTopCapsule_Actor::rtsBehavior( int signalIndex, int portIndex )
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
				// {{{RME port 'internalSerial'
				switch( signalIndex )
				{
				case serialProtocol::Conjugate::rti_commandReceived:
					chain2_commandReceived();
					return;
				case serialProtocol::Conjugate::rti_comOpened:
					chain4_comOpened();
					return;
				case serialProtocol::Conjugate::rti_comError:
					chain5_comError();
					return;
				default:
					break;
				}
				break;
				// }}}RME
			case 3:
				// {{{RME port 'externalSerial'
				switch( signalIndex )
				{
				case serialProtocol::Base::rti_sendCommand:
					chain3_sendCommand();
					return;
				case serialProtocol::Base::rti_commandLength:
					chain6_setCommandLength();
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

const RTActor_class * serialTopCapsule_Actor::getActorData( void ) const
{
	return &serialTopCapsule_Actor::rtg_class;
}

const RTActor_class serialTopCapsule_Actor::rtg_class =
{
	(const RTActor_class *)0
  , rtg_state_names
  , 2
  , serialTopCapsule_Actor::rtg_parent_state
  , &serialTopCapsule
  , 2
  , serialTopCapsule_Actor::rtg_capsule_roles
  , 3
  , serialTopCapsule_Actor::rtg_ports
  , 0
  , (const RTLocalBindingDescriptor *)0
  , 0
  , (const RTFieldDescriptor *)0
};

const RTStateId serialTopCapsule_Actor::rtg_parent_state[] =
{
	0
  , 1
};

const RTComponentDescriptor serialTopCapsule_Actor::rtg_capsule_roles[] =
{
	{
		"serialCommunicationInstance"
	  , &serialCommunicationCapsule
	  , RTOffsetOf( serialTopCapsule_Actor, serialCommunicationInstance )
	  , 1
	  , RTComponentDescriptor::Optional
	  , 1
	  , 1 // cardinality
	  , 1
	  , rtg_interfaces_serialCommunicationInstance
	  , 1
	  , rtg_bindings_serialCommunicationInstance
	}
  , {
		"serialTranslateCapsuleR1"
	  , &serialTranslateCapsule
	  , RTOffsetOf( serialTopCapsule_Actor, serialTranslateCapsuleR1 )
	  , 2
	  , RTComponentDescriptor::Fixed
	  , 1
	  , 1 // cardinality
	  , 2
	  , rtg_interfaces_serialTranslateCapsuleR1
	  , 2
	  , rtg_bindings_serialTranslateCapsuleR1
	}
};

const RTPortDescriptor serialTopCapsule_Actor::rtg_ports[] =
{
	{
		"frame"
	  , (const char *)0
	  , &Frame::Base::rt_class
	  , RTOffsetOf( serialTopCapsule_Actor, serialTopCapsule_Actor::frame )
	  , 1 // cardinality
	  , 1
	  , RTPortDescriptor::KindSpecial + RTPortDescriptor::NotificationDisabled + RTPortDescriptor::RegisterNotPermitted + RTPortDescriptor::VisibilityProtected
	}
  , {
		"internalSerial"
	  , (const char *)0
	  , &serialProtocol::Conjugate::rt_class
	  , RTOffsetOf( serialTopCapsule_Actor, serialTopCapsule_Actor::internalSerial )
	  , 1 // cardinality
	  , 2
	  , RTPortDescriptor::KindWired + RTPortDescriptor::NotificationDisabled + RTPortDescriptor::RegisterNotPermitted + RTPortDescriptor::VisibilityProtected
	}
  , {
		"externalSerial"
	  , (const char *)0
	  , &serialProtocol::Base::rt_class
	  , RTOffsetOf( serialTopCapsule_Actor, serialTopCapsule_Actor::externalSerial )
	  , 1 // cardinality
	  , 3
	  , RTPortDescriptor::KindWired + RTPortDescriptor::NotificationDisabled + RTPortDescriptor::RegisterNotPermitted + RTPortDescriptor::VisibilityPublic
	}
};

#undef SUPER

// {{{RME tool 'OT::Cpp' property 'ImplementationEnding'
// {{{USR

// }}}USR
// }}}RME

// }}}RME
