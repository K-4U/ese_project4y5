// {{{RME classifier 'Logical View::TCPIP::jsonTranslateCapsule'

#if defined( PRAGMA ) && ! defined( PRAGMA_IMPLEMENTED )
#pragma implementation "jsonTranslateCapsule.h"
#endif

#include <RTSystem/roombaController.h>
#include <jsonTranslateCapsule.h>

// {{{RME tool 'OT::Cpp' property 'ImplementationPreface'
// {{{USR

// }}}USR
// }}}RME

static const RTRelayDescriptor rtg_relays[] =
{
	{
		"tcpPort"
	  , &tcpProtocol::Conjugate::rt_class
	  , 1 // cardinality
	}
  , {
		"jsonPort"
	  , &jsonProtocol::Base::rt_class
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
	, depth( 0 )
	, inString( false )
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
		// tcpPort
		if( rtg_repIndex < 1 )
		{
			rtg_end.port = &tcpPort;
			rtg_end.index = rtg_repIndex;
			return 1;
		}
		break;
	case 1:
		// jsonPort
		if( rtg_repIndex < 1 )
		{
			rtg_end.port = &jsonPort;
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
	cout << "J: Data received: " << *rtdata << endl;
	int i;
	for(i=0;i<strlen(rtdata->Contents);i++){
		char b = rtdata->Contents[i];
	    
	    //Very basic JSON completeness checking..
	    if(b == '"'){
	        this->inString = !this->inString;
	    }
	    if(!this->inString){
	    	if(b == '{' || b == '['){
	    		this->depth++;
	    	}else if(b == '}' || b == ']'){
	    		this->depth--;
	    	}else if(depth == 0){
	            b = 0;
	        }
	    }
	    //cout << "J: b = " << b << endl;
		this->jsonBuffer.push_back(b);
	    cout << "J: B.S:" << this->jsonBuffer.size()  << " L:" << this->depth << " IS: " << std::boolalpha << this->inString << endl;
	    if(this->jsonBuffer.size() >= 2 && this->depth == 0 && this->inString == false){
	        //Fetch command
	        jsonCommand newCommand(this->jsonBuffer);

	        jsonPort.commandReceived(newCommand).send();
	        //And clear buffer
	        this->jsonBuffer.clear();
	    }
	}
	//cout << "J: Buffer: " << this->jsonBuffer << endl;

	// }}}USR
}
// }}}RME

// {{{RME transition ':TOP:Initial:Initial'
INLINE_METHODS void jsonTranslateCapsule_Actor::transition2_Initial( const void * rtdata, RTProtocol * rtport )
{
	// {{{USR
	cout << "JsonTranslateCapsule Initialized" << endl;

	// }}}USR
}
// }}}RME

// {{{RME transition ':TOP:J5188EA8C00E2:socketConnected'
INLINE_METHODS void jsonTranslateCapsule_Actor::transition3_socketConnected( const unsigned * rtdata, tcpProtocol::Conjugate * rtport )
{
	// {{{USR
	cout << "Socket connected!" << endl;

	//Todo: Trigger event for main application to know this has happened.
	this->socket = *rtdata;
	// }}}USR
}
// }}}RME

// {{{RME transition ':TOP:J5188EB280304:socketDisconnected'
INLINE_METHODS void jsonTranslateCapsule_Actor::transition4_socketDisconnected( const void * rtdata, tcpProtocol::Conjugate * rtport )
{
	// {{{USR
	cout << "Socket disconnected!" << endl;

	//Todo: Trigger event for main application to know this has happened.
	this->socket = 0;
	// }}}USR
}
// }}}RME

// {{{RME transition ':TOP:KlaarVoorData:J518A1AC6031A:sendCommand'
INLINE_METHODS void jsonTranslateCapsule_Actor::transition5_sendCommand( const jsonCommand * rtdata, jsonProtocol::Base * rtport )
{
	// {{{USR
	jsonCommand commandToSend = *rtdata;

	std::string toSend = commandToSend.createJsonString();

	int iSendResult = send( this->socket, toSend.c_str(), toSend.size(), 0 );
	if (iSendResult == SOCKET_ERROR) {
	    printf("send failed: %d\n", WSAGetLastError());
	    closesocket(this->socket);
	}
	printf("Bytes sent: %d\n", iSendResult);
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

INLINE_CHAINS void jsonTranslateCapsule_Actor::chain3_socketConnected( void )
{
	// transition ':TOP:J5188EA8C00E2:socketConnected'
	rtgChainBegin( 1, "socketConnected" );
	exitToChainState( 1, rtg_parent_state );
	rtgTransitionBegin();
	transition3_socketConnected( (const unsigned *)msg->data, (tcpProtocol::Conjugate *)msg->sap() );
	rtgTransitionEnd();
	processHistory();
}

INLINE_CHAINS void jsonTranslateCapsule_Actor::chain4_socketDisconnected( void )
{
	// transition ':TOP:J5188EB280304:socketDisconnected'
	rtgChainBegin( 1, "socketDisconnected" );
	exitToChainState( 1, rtg_parent_state );
	rtgTransitionBegin();
	transition4_socketDisconnected( msg->data, (tcpProtocol::Conjugate *)msg->sap() );
	rtgTransitionEnd();
	processHistory();
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

INLINE_CHAINS void jsonTranslateCapsule_Actor::chain5_sendCommand( void )
{
	// transition ':TOP:KlaarVoorData:J518A1AC6031A:sendCommand'
	rtgChainBegin( 2, "sendCommand" );
	exitState( rtg_parent_state );
	rtgTransitionBegin();
	transition5_sendCommand( (const jsonCommand *)msg->data, (jsonProtocol::Base *)msg->sap() );
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
			case 1:
				// {{{RME port 'tcpPort'
				switch( signalIndex )
				{
				case tcpProtocol::Conjugate::rti_sock:
					chain3_socketConnected();
					return;
				case tcpProtocol::Conjugate::rti_noSock:
					chain4_socketDisconnected();
					return;
				default:
					break;
				}
				break;
				// }}}RME
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
			case 2:
				// {{{RME port 'jsonPort'
				switch( signalIndex )
				{
				case jsonProtocol::Base::rti_sendCommand:
					chain5_sendCommand();
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
  , 2
  , jsonTranslateCapsule_Actor::rtg_ports
  , 0
  , (const RTLocalBindingDescriptor *)0
  , 5
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
		"tcpPort"
	  , (const char *)0
	  , &tcpProtocol::Conjugate::rt_class
	  , RTOffsetOf( jsonTranslateCapsule_Actor, jsonTranslateCapsule_Actor::tcpPort )
	  , 1 // cardinality
	  , 1
	  , RTPortDescriptor::KindWired + RTPortDescriptor::NotificationDisabled + RTPortDescriptor::RegisterNotPermitted + RTPortDescriptor::VisibilityPublic
	}
  , {
		"jsonPort"
	  , (const char *)0
	  , &jsonProtocol::Base::rt_class
	  , RTOffsetOf( jsonTranslateCapsule_Actor, jsonTranslateCapsule_Actor::jsonPort )
	  , 1 // cardinality
	  , 2
	  , RTPortDescriptor::KindWired + RTPortDescriptor::NotificationDisabled + RTPortDescriptor::RegisterNotPermitted + RTPortDescriptor::VisibilityPublic
	}
};

const RTFieldDescriptor jsonTranslateCapsule_Actor::rtg_jsonTranslateCapsule_fields[] =
{
	// {{{RME classAttribute 'depth'
	{
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
	// {{{RME classAttribute 'jsonReader'
  , {
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
	// {{{RME classAttribute 'socket'
  , {
		"socket"
	  , RTOffsetOf( jsonTranslateCapsule_Actor, socket )
		// {{{RME tool 'OT::CppTargetRTS' property 'TypeDescriptor'
	  , (const RTObject_class *)0
		// }}}RME
		// {{{RME tool 'OT::CppTargetRTS' property 'GenerateTypeModifier'
	  , (const RTTypeModifier *)0
		// }}}RME
	}
	// }}}RME
	// {{{RME classAttribute 'inString'
  , {
		"inString"
	  , RTOffsetOf( jsonTranslateCapsule_Actor, inString )
		// {{{RME tool 'OT::CppTargetRTS' property 'TypeDescriptor'
	  , &RTType_bool
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
