// {{{RME classifier 'Logical View::UserInterface::AUserInterface'

#if defined( PRAGMA ) && ! defined( PRAGMA_IMPLEMENTED )
#pragma implementation "AUserInterface.h"
#endif

#include <RTSystem/WarmeDrankenAutomaatComponent.h>
#include <AUserInterface.h>
extern const RTActorClass AGui;
extern const RTActorClass ATCPServer_QtSocket;

// {{{RME tool 'OT::Cpp' property 'ImplementationPreface'
// {{{USR

// }}}USR
// }}}RME

static const RTRelayDescriptor rtg_relays[] =
{
	{
		"pUserInterface"
	  , &PUserInterface::Base::rt_class
	  , 1 // cardinality
	}
};

static RTActor * new_AUserInterface_Actor( RTController * _rts, RTActorRef * _ref )
{
	return new AUserInterface_Actor( _rts, _ref );
}

const RTActorClass AUserInterface =
{
	(const RTActorClass *)0
  , "AUserInterface"
  , (RTVersionId)0
  , 1
  , rtg_relays
  , new_AUserInterface_Actor
};

static const char * const rtg_state_names[] =
{
	"TOP"
  , "klaarVoorAanvraag"
};

static const RTInterfaceDescriptor rtg_interfaces_aGui[] =
{
	{
		"pGuiInit"
	  , 1
	}
};

static const RTBindingDescriptor rtg_bindings_aGui[] =
{
	{
		0
	  , &PGuiInit::Conjugate::rt_class
	}
};

static const RTInterfaceDescriptor rtg_interfaces_aTCPServer_QtSocket[] =
{
	{
		"pGuiConnection"
	  , 1
	}
};

static const RTBindingDescriptor rtg_bindings_aTCPServer_QtSocket[] =
{
	{
		0
	  , &PGuiConnection::Conjugate::rt_class
	}
};

#define SUPER RTActor

AUserInterface_Actor::AUserInterface_Actor( RTController * rtg_rts, RTActorRef * rtg_ref )
	: RTActor( rtg_rts, rtg_ref )
	, clientSocket( 0 )
{
}

AUserInterface_Actor::~AUserInterface_Actor( void )
{
}

int AUserInterface_Actor::_followInV( RTBindingEnd & rtg_end, int rtg_portId, int rtg_repIndex )
{
	switch( rtg_portId )
	{
	case 0:
		// pUserInterface
		if( rtg_repIndex < 1 )
		{
			rtg_end.port = &pUserInterface;
			rtg_end.index = rtg_repIndex;
			return 1;
		}
		break;
	default:
		break;
	}
	return RTActor::_followInV( rtg_end, rtg_portId, rtg_repIndex );
}

int AUserInterface_Actor::_followOutV( RTBindingEnd & rtg_end, int rtg_compId, int rtg_portId, int rtg_repIndex )
{
	switch( rtg_compId )
	{
	case 1:
		// aGui
		switch( rtg_portId )
		{
		case 0:
			// pGuiInit
			if( rtg_repIndex < 1 )
			{
				// pGuiInit
				rtg_end.port = &pGuiInit;
				rtg_end.index = rtg_repIndex;
				return 1;
			}
			break;
		default:
			break;
		}
	case 2:
		// aTCPServer_QtSocket
		switch( rtg_portId )
		{
		case 0:
			// pGuiConnection
			if( rtg_repIndex < 1 )
			{
				// pGuiConnection
				rtg_end.port = &pGuiConnection;
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
INLINE_METHODS void AUserInterface_Actor::transition1_Initial( const void * rtdata, RTProtocol * rtport )
{
	// {{{USR
	//maak object voor de GUI
	frame.incarnate(aGui,AGui,EmptyObject,ThreadUserInterface);

	//maak object voor de tcp verbinding
	frame.incarnate(aTCPServer_QtSocket,ATCPServer_QtSocket,EmptyObject,ThreadUserInterface);
	// }}}USR
}
// }}}RME

// {{{RME transition ':TOP:klaarVoorAanvraag:J4BB87B9D02F0:receivedExternalEvent'
INLINE_METHODS void AUserInterface_Actor::transition2_receivedExternalEvent( const RTString * rtdata, PGuiConnection::Conjugate * rtport )
{
	// {{{USR
	cout << " door aUserInterface external event ontvangen" << endl;
	//stuur bericht naar de besturingseenheid
	pUserInterface.cacao().send();

	// }}}USR
}
// }}}RME

// {{{RME transition ':TOP:klaarVoorAanvraag:J4BDEC76C009E:ready'
INLINE_METHODS void AUserInterface_Actor::transition3_ready( const void * rtdata, PUserInterface::Base * rtport )
{
	// {{{USR
	//pGuiInit.ready().send();
	cout << "aUserInterface heeft bericht \"drank gereed\" ontvangen" << endl;

	int iSendResult = 0;

	//een object sendbuf van de c++ "string" klasse als zendbuffer
	string sendbuf = "drank gereed \r\n";

	// stuur data naar TCP Socket
	cout << "stuur data door naar TCP Socket" << endl;
	iSendResult = send( clientSocket, sendbuf.c_str(), sendbuf.length(), 0 );
	if (iSendResult == SOCKET_ERROR) 
	{
	    printf("send failed: %d\n", WSAGetLastError());
		// zenden niet gelukt
	}
	printf("Bytes sent: %d\n", iSendResult);
	// zenden gelukt

	// }}}USR
}
// }}}RME

// {{{RME transition ':TOP:J4BE68AD702F0:receivedSocketNumber'
INLINE_METHODS void AUserInterface_Actor::transition4_receivedSocketNumber( const unsigned * rtdata, PGuiConnection::Conjugate * rtport )
{
	// {{{USR
	clientSocket = *rtdata;
	// }}}USR
}
// }}}RME

// {{{RME transition ':TOP:J4BE68B2C00CB:cancelledSocket'
INLINE_METHODS void AUserInterface_Actor::transition5_cancelledSocket( const void * rtdata, PGuiConnection::Conjugate * rtport )
{
	// {{{USR
	clientSocket = 0;
	// }}}USR
}
// }}}RME

INLINE_CHAINS void AUserInterface_Actor::chain1_Initial( void )
{
	// transition ':TOP:Initial:Initial'
	rtgChainBegin( 1, "Initial" );
	rtgTransitionBegin();
	transition1_Initial( msg->data, msg->sap() );
	rtgTransitionEnd();
	enterState( 2 );
}

INLINE_CHAINS void AUserInterface_Actor::chain4_receivedSocketNumber( void )
{
	// transition ':TOP:J4BE68AD702F0:receivedSocketNumber'
	rtgChainBegin( 1, "receivedSocketNumber" );
	exitToChainState( 1, rtg_parent_state );
	rtgTransitionBegin();
	transition4_receivedSocketNumber( (const unsigned *)msg->data, (PGuiConnection::Conjugate *)msg->sap() );
	rtgTransitionEnd();
	processHistory();
}

INLINE_CHAINS void AUserInterface_Actor::chain5_cancelledSocket( void )
{
	// transition ':TOP:J4BE68B2C00CB:cancelledSocket'
	rtgChainBegin( 1, "cancelledSocket" );
	exitToChainState( 1, rtg_parent_state );
	rtgTransitionBegin();
	transition5_cancelledSocket( msg->data, (PGuiConnection::Conjugate *)msg->sap() );
	rtgTransitionEnd();
	processHistory();
}

INLINE_CHAINS void AUserInterface_Actor::chain3_ready( void )
{
	// transition ':TOP:klaarVoorAanvraag:J4BDEC76C009E:ready'
	rtgChainBegin( 2, "ready" );
	exitState( rtg_parent_state );
	rtgTransitionBegin();
	transition3_ready( msg->data, (PUserInterface::Base *)msg->sap() );
	rtgTransitionEnd();
	enterState( 2 );
}

INLINE_CHAINS void AUserInterface_Actor::chain2_receivedExternalEvent( void )
{
	// transition ':TOP:klaarVoorAanvraag:J4BB87B9D02F0:receivedExternalEvent'
	rtgChainBegin( 2, "receivedExternalEvent" );
	exitState( rtg_parent_state );
	rtgTransitionBegin();
	transition2_receivedExternalEvent( (const RTString *)msg->data, (PGuiConnection::Conjugate *)msg->sap() );
	rtgTransitionEnd();
	enterState( 2 );
}

void AUserInterface_Actor::rtsBehavior( int signalIndex, int portIndex )
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
			case 4:
				// {{{RME port 'pGuiConnection'
				switch( signalIndex )
				{
				case PGuiConnection::Conjugate::rti_sock:
					chain4_receivedSocketNumber();
					return;
				case PGuiConnection::Conjugate::rti_noSock:
					chain5_cancelledSocket();
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
			// {{{RME state ':TOP:klaarVoorAanvraag'
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
				// {{{RME port 'pUserInterface'
				switch( signalIndex )
				{
				case PUserInterface::Base::rti_drankGereed:
					chain3_ready();
					return;
				default:
					break;
				}
				break;
				// }}}RME
			case 4:
				// {{{RME port 'pGuiConnection'
				switch( signalIndex )
				{
				case PGuiConnection::Conjugate::rti_data:
					chain2_receivedExternalEvent();
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

const RTActor_class * AUserInterface_Actor::getActorData( void ) const
{
	return &AUserInterface_Actor::rtg_class;
}

const RTActor_class AUserInterface_Actor::rtg_class =
{
	(const RTActor_class *)0
  , rtg_state_names
  , 2
  , AUserInterface_Actor::rtg_parent_state
  , &AUserInterface
  , 2
  , AUserInterface_Actor::rtg_capsule_roles
  , 4
  , AUserInterface_Actor::rtg_ports
  , 0
  , (const RTLocalBindingDescriptor *)0
  , 0
  , (const RTFieldDescriptor *)0
};

const RTStateId AUserInterface_Actor::rtg_parent_state[] =
{
	0
  , 1
};

const RTComponentDescriptor AUserInterface_Actor::rtg_capsule_roles[] =
{
	{
		"aGui"
	  , &AGui
	  , RTOffsetOf( AUserInterface_Actor, aGui )
	  , 1
	  , RTComponentDescriptor::Optional
	  , 1
	  , 1 // cardinality
	  , 1
	  , rtg_interfaces_aGui
	  , 1
	  , rtg_bindings_aGui
	}
  , {
		"aTCPServer_QtSocket"
	  , &ATCPServer_QtSocket
	  , RTOffsetOf( AUserInterface_Actor, aTCPServer_QtSocket )
	  , 2
	  , RTComponentDescriptor::Optional
	  , 1
	  , 1 // cardinality
	  , 1
	  , rtg_interfaces_aTCPServer_QtSocket
	  , 1
	  , rtg_bindings_aTCPServer_QtSocket
	}
};

const RTPortDescriptor AUserInterface_Actor::rtg_ports[] =
{
	{
		"pUserInterface"
	  , (const char *)0
	  , &PUserInterface::Base::rt_class
	  , RTOffsetOf( AUserInterface_Actor, AUserInterface_Actor::pUserInterface )
	  , 1 // cardinality
	  , 1
	  , RTPortDescriptor::KindWired + RTPortDescriptor::NotificationDisabled + RTPortDescriptor::RegisterNotPermitted + RTPortDescriptor::VisibilityPublic
	}
  , {
		"pGuiInit"
	  , (const char *)0
	  , &PGuiInit::Conjugate::rt_class
	  , RTOffsetOf( AUserInterface_Actor, AUserInterface_Actor::pGuiInit )
	  , 1 // cardinality
	  , 2
	  , RTPortDescriptor::KindWired + RTPortDescriptor::NotificationDisabled + RTPortDescriptor::RegisterNotPermitted + RTPortDescriptor::VisibilityProtected
	}
  , {
		"frame"
	  , (const char *)0
	  , &Frame::Base::rt_class
	  , RTOffsetOf( AUserInterface_Actor, AUserInterface_Actor::frame )
	  , 1 // cardinality
	  , 3
	  , RTPortDescriptor::KindSpecial + RTPortDescriptor::NotificationDisabled + RTPortDescriptor::RegisterNotPermitted + RTPortDescriptor::VisibilityProtected
	}
  , {
		"pGuiConnection"
	  , (const char *)0
	  , &PGuiConnection::Conjugate::rt_class
	  , RTOffsetOf( AUserInterface_Actor, AUserInterface_Actor::pGuiConnection )
	  , 1 // cardinality
	  , 4
	  , RTPortDescriptor::KindWired + RTPortDescriptor::NotificationDisabled + RTPortDescriptor::RegisterNotPermitted + RTPortDescriptor::VisibilityProtected
	}
};

#undef SUPER

// {{{RME tool 'OT::Cpp' property 'ImplementationEnding'
// {{{USR

// }}}USR
// }}}RME

// }}}RME
