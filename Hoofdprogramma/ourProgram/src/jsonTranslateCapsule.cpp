// {{{RME classifier 'Logical View::TCPIP::jsonTranslateCapsule'

#if defined( PRAGMA ) && ! defined( PRAGMA_IMPLEMENTED )
#pragma implementation "jsonTranslateCapsule.h"
#endif

#include <RTSystem/ourProgram.h>
#include <jsonTranslateCapsule.h>

// {{{RME tool 'OT::Cpp' property 'ImplementationPreface'
// {{{USR

// }}}USR
// }}}RME

static const RTRelayDescriptor rtg_relays[] =
{
	{
		"jsonPort"
	  , &jsonProtocol::Base::rt_class
	  , 1 // cardinality
	}
  , {
		"tcpPort"
	  , &tcpProtocol::Conjugate::rt_class
	  , 1 // cardinality
	}
};

static RTActor * new_jsonTranslateCapsule_Actor( RTController * _rts, RTActorRef * _ref )
{
	return new jsonTranslateCapsule_Actor( _rts, _ref );
}

const RTActorClass jsonTranslateCapsule =
{
	(const RTActorClass *)0
  , "jsonTranslateCapsule"
  , (RTVersionId)0
  , 2
  , rtg_relays
  , new_jsonTranslateCapsule_Actor
};

static const char * const rtg_state_names[] =
{
	"TOP"
  , "KlaarVoorData"
};

#define SUPER RTActor

jsonTranslateCapsule_Actor::jsonTranslateCapsule_Actor( RTController * rtg_rts, RTActorRef * rtg_ref )
	: RTActor( rtg_rts, rtg_ref )
{
}

jsonTranslateCapsule_Actor::~jsonTranslateCapsule_Actor( void )
{
}

int jsonTranslateCapsule_Actor::_followInV( RTBindingEnd & rtg_end, int rtg_portId, int rtg_repIndex )
{
	switch( rtg_portId )
	{
	case 0:
		// jsonPort
		if( rtg_repIndex < 1 )
		{
			rtg_end.port = &jsonPort;
			rtg_end.index = rtg_repIndex;
			return 1;
		}
		break;
	case 1:
		// tcpPort
		if( rtg_repIndex < 1 )
		{
			rtg_end.port = &tcpPort;
			rtg_end.index = rtg_repIndex;
			return 1;
		}
		break;
	default:
		break;
	}
	return RTActor::_followInV( rtg_end, rtg_portId, rtg_repIndex );
}

// {{{RME transition ':TOP:KlaarVoorData:J5176823800F4:dataReceived'
INLINE_METHODS void jsonTranslateCapsule_Actor::transition1_dataReceived( const RTString * rtdata, tcpProtocol::Conjugate * rtport )
{
	// {{{USR
	cout << "-- Data received" << *rtdata << endl;
	int i;
	while(rtdata[i] != NULL){
		char b = *rtdata[i];
		cout << "b = " << b << endl;
		if(b == '{' || b == '['){
			this->depth++;
		}else if(b == '}' || b == ']'){
			this->depth--;
		}
		this->jsonBuffer.append(&b);
	}
	cout << "Buffer: " << this->jsonBuffer << endl;
	// }}}USR
}
// }}}RME

// {{{RME transition ':TOP:Initial:Initial'
INLINE_METHODS void jsonTranslateCapsule_Actor::transition2_Initial( const void * rtdata, RTProtocol * rtport )
{
	// {{{USR
	cout << "JsonTranslateCapsule initialized" << endl;
	// }}}USR
}
// }}}RME

INLINE_CHAINS void jsonTranslateCapsule_Actor::chain2_Initial( void )
{
	// transition ':TOP:Initial:Initial'
	rtgChainBegin( 1, "Initial" );
	rtgTransitionBegin();
	transition2_Initial( msg->data, msg->sap() );
	rtgTransitionEnd();
	enterState( 2 );
}

INLINE_CHAINS void jsonTranslateCapsule_Actor::chain1_dataReceived( void )
{
	// transition ':TOP:KlaarVoorData:J5176823800F4:dataReceived'
	rtgChainBegin( 2, "dataReceived" );
	exitState( rtg_parent_state );
	rtgTransitionBegin();
	transition1_dataReceived( (const RTString *)msg->data, (tcpProtocol::Conjugate *)msg->sap() );
	rtgTransitionEnd();
	enterState( 2 );
}

void jsonTranslateCapsule_Actor::rtsBehavior( int signalIndex, int portIndex )
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
					chain2_Initial();
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
			case 2:
				// {{{RME port 'tcpPort'
				switch( signalIndex )
				{
				case tcpProtocol::Conjugate::rti_dataReceived:
					chain1_dataReceived();
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

const RTActor_class * jsonTranslateCapsule_Actor::getActorData( void ) const
{
	return &jsonTranslateCapsule_Actor::rtg_class;
}

const RTActor_class jsonTranslateCapsule_Actor::rtg_class =
{
	(const RTActor_class *)0
  , rtg_state_names
  , 2
  , jsonTranslateCapsule_Actor::rtg_parent_state
  , &jsonTranslateCapsule
  , 0
  , (const RTComponentDescriptor *)0
  , 3
  , jsonTranslateCapsule_Actor::rtg_ports
  , 0
  , (const RTLocalBindingDescriptor *)0
  , 3
  , jsonTranslateCapsule_Actor::rtg_jsonTranslateCapsule_fields
};

const RTStateId jsonTranslateCapsule_Actor::rtg_parent_state[] =
{
	0
  , 1
};

const RTPortDescriptor jsonTranslateCapsule_Actor::rtg_ports[] =
{
	{
		"jsonPort"
	  , (const char *)0
	  , &jsonProtocol::Base::rt_class
	  , RTOffsetOf( jsonTranslateCapsule_Actor, jsonTranslateCapsule_Actor::jsonPort )
	  , 1 // cardinality
	  , 1
	  , RTPortDescriptor::KindWired + RTPortDescriptor::NotificationDisabled + RTPortDescriptor::RegisterNotPermitted + RTPortDescriptor::VisibilityPublic
	}
  , {
		"tcpPort"
	  , (const char *)0
	  , &tcpProtocol::Conjugate::rt_class
	  , RTOffsetOf( jsonTranslateCapsule_Actor, jsonTranslateCapsule_Actor::tcpPort )
	  , 1 // cardinality
	  , 2
	  , RTPortDescriptor::KindWired + RTPortDescriptor::NotificationDisabled + RTPortDescriptor::RegisterNotPermitted + RTPortDescriptor::VisibilityPublic
	}
  , {
		"frame"
	  , (const char *)0
	  , &Frame::Base::rt_class
	  , RTOffsetOf( jsonTranslateCapsule_Actor, jsonTranslateCapsule_Actor::frame )
	  , 1 // cardinality
	  , 3
	  , RTPortDescriptor::KindSpecial + RTPortDescriptor::NotificationDisabled + RTPortDescriptor::RegisterNotPermitted + RTPortDescriptor::VisibilityProtected
	}
};

const RTFieldDescriptor jsonTranslateCapsule_Actor::rtg_jsonTranslateCapsule_fields[] =
{
	// {{{RME classAttribute 'jsonReader'
	{
		"jsonReader"
	  , RTOffsetOf( jsonTranslateCapsule_Actor, jsonReader )
		// {{{RME tool 'OT::CppTargetRTS' property 'TypeDescriptor'
	  , (const RTObject_class *)0
		// }}}RME
		// {{{RME tool 'OT::CppTargetRTS' property 'GenerateTypeModifier'
	  , (const RTTypeModifier *)0
		// }}}RME
	}
	// }}}RME
	// {{{RME classAttribute 'jsonBuffer'
  , {
		"jsonBuffer"
	  , RTOffsetOf( jsonTranslateCapsule_Actor, jsonBuffer )
		// {{{RME tool 'OT::CppTargetRTS' property 'TypeDescriptor'
	  , (const RTObject_class *)0
		// }}}RME
		// {{{RME tool 'OT::CppTargetRTS' property 'GenerateTypeModifier'
	  , (const RTTypeModifier *)0
		// }}}RME
	}
	// }}}RME
	// {{{RME classAttribute 'depth'
  , {
		"depth"
	  , RTOffsetOf( jsonTranslateCapsule_Actor, depth )
		// {{{RME tool 'OT::CppTargetRTS' property 'TypeDescriptor'
	  , &RTType_int
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
