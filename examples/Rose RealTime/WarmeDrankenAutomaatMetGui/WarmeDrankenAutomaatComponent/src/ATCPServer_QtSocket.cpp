// {{{RME classifier 'Logical View::UserInterface::ATCPServer_QtSocket'

#if defined( PRAGMA ) && ! defined( PRAGMA_IMPLEMENTED )
#pragma implementation "ATCPServer_QtSocket.h"
#endif

#include <RTSystem/WarmeDrankenAutomaatComponent.h>
#include <ATCPServer_QtSocket.h>

// {{{RME tool 'OT::Cpp' property 'ImplementationPreface'
// {{{USR

// }}}USR
// }}}RME

static const RTRelayDescriptor rtg_relays[] =
{
	{
		"pGuiConnection"
	  , &PGuiConnection::Base::rt_class
	  , 1 // cardinality
	}
};

static RTActor * new_ATCPServer_QtSocket_Actor( RTController * _rts, RTActorRef * _ref )
{
	return new ATCPServer_QtSocket_Actor( _rts, _ref );
}

const RTActorClass ATCPServer_QtSocket =
{
	(const RTActorClass *)0
  , "ATCPServer_QtSocket"
  , (RTVersionId)0
  , 1
  , rtg_relays
  , new_ATCPServer_QtSocket_Actor
};

static const char * const rtg_state_names[] =
{
	"TOP"
  , "Reset"
  , "addressCorrect"
  , "acceptConnection"
  , "getBytes"
  , "InitializeWinsock"
  , "validSocket"
  , "bindingSuccessfull"
  , "listening"
  , "shutdownConnection"
};

const RTTypeModifier rtg_tm_ATCPServer_QtSocket_Actor_recvbuf =
{
	RTNumberConstant
  , (DEFAULT_BUFLEN)
  , 0
};

#define SUPER RTActor

ATCPServer_QtSocket_Actor::ATCPServer_QtSocket_Actor( RTController * rtg_rts, RTActorRef * rtg_ref )
	: RTActor( rtg_rts, rtg_ref )
	, result( NULL )
	, ptr( NULL )
	, ListenSocket( INVALID_SOCKET )
{
}

ATCPServer_QtSocket_Actor::~ATCPServer_QtSocket_Actor( void )
{
}

int ATCPServer_QtSocket_Actor::_followInV( RTBindingEnd & rtg_end, int rtg_portId, int rtg_repIndex )
{
	switch( rtg_portId )
	{
	case 0:
		// pGuiConnection
		if( rtg_repIndex < 1 )
		{
			rtg_end.port = &pGuiConnection;
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
INLINE_METHODS void ATCPServer_QtSocket_Actor::enter2_Reset( void )
{
	// {{{USR
	// hier een zinvolle actie opnemen om te reageren op fouten
	// voorlopig na een timeout opnieuw beginnen
	cout << "in reset terecht gekomen" << endl;
	timer.informIn(RTTimespec(4,0));

	// }}}USR
}
// }}}RME

void ATCPServer_QtSocket_Actor::enterStateV( void )
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

// {{{RME transition ':TOP:getBytes:False'
INLINE_METHODS void ATCPServer_QtSocket_Actor::transition2_False( const void * rtdata, Timing::Base * rtport )
{
	// {{{USR
	// doorgeven dat socket niet meer is aangesloten
	pGuiConnection.noSock().send();
	// }}}USR
}
// }}}RME

// {{{RME transition ':TOP:acceptConnection:True'
INLINE_METHODS void ATCPServer_QtSocket_Actor::transition16_True( const void * rtdata, Timing::Base * rtport )
{
	// {{{USR
	// stuur SOCKET ook naar de applicatie zodat deze ook kan zenden
	// terwijl deze capsule als server wacht op ontvangen data
	pGuiConnection.sock(ClientSocket).send();
	// }}}USR
}
// }}}RME

INLINE_CHAINS void ATCPServer_QtSocket_Actor::chain3_Initial( void )
{
	// transition ':TOP:Initial:Initial'
	rtgChainBegin( 1, "Initial" );
	rtgTransitionBegin();
	rtgTransitionEnd();
	if( choicePoint4_InitializeWinsock( msg->data, (Timing::Base *)msg->sap() ) )
		chain6_True();
	else
		chain4_False();
}

// {{{RME choicePoint ':TOP:InitializeWinsock'
INLINE_METHODS int ATCPServer_QtSocket_Actor::choicePoint4_InitializeWinsock( const void * rtdata, Timing::Base * rtport )
{
	// {{{USR
	// Initialize Winsock
	iResult = WSAStartup(MAKEWORD(2,2), &wsaData);
	if (iResult != 0) {
	    printf("WSAStartup failed: %d\n", iResult);
	}
	return (iResult==0);

	//The WSAStartup function is called to initiate use of WS2_32.dll.
	//The WSADATA structure contains information about 
	//the Windows Sockets implementation. 
	//The MAKEWORD(2,2) parameter of WSAStartup makes a request 
	//for version 2.2 of Winsock on the system, and sets the passed 
	//version as the highest version of Windows Sockets support 
	//that the caller can use.


	// }}}USR
}
// }}}RME

INLINE_CHAINS void ATCPServer_QtSocket_Actor::chain6_True( void )
{
	// transition ':TOP:InitializeWinsock:True'
	rtgChainBegin( 6, "True" );
	rtgTransitionBegin();
	rtgTransitionEnd();
	if( choicePoint1_addressCorrect( msg->data, (Timing::Base *)msg->sap() ) )
		chain7_True();
	else
		chain5_False();
}

// {{{RME choicePoint ':TOP:addressCorrect'
INLINE_METHODS int ATCPServer_QtSocket_Actor::choicePoint1_addressCorrect( const void * rtdata, Timing::Base * rtport )
{
	// {{{USR
	result = NULL;
	ptr = NULL;


	ZeroMemory( &hints, sizeof(hints) );
	hints.ai_family = AF_INET;
	hints.ai_socktype = SOCK_STREAM;
	hints.ai_protocol = IPPROTO_TCP;
	hints.ai_flags = AI_PASSIVE;

	// Resolve the local address and port to be used by the server
	iResult = getaddrinfo(NULL, DEFAULT_PORT, &hints, &result);
	if ( iResult != 0 ) {
	    printf("getaddrinfo failed: %d\n", iResult);
	    WSACleanup();
		return false;
	}
	else
	{
		return true;
	}

	// }}}USR
}
// }}}RME

INLINE_CHAINS void ATCPServer_QtSocket_Actor::chain7_True( void )
{
	// transition ':TOP:addressCorrect:True'
	rtgChainBegin( 3, "True" );
	rtgTransitionBegin();
	rtgTransitionEnd();
	if( choicePoint5_validSocket( msg->data, (Timing::Base *)msg->sap() ) )
		chain9_True();
	else
		chain8_False();
}

// {{{RME choicePoint ':TOP:validSocket'
INLINE_METHODS int ATCPServer_QtSocket_Actor::choicePoint5_validSocket( const void * rtdata, Timing::Base * rtport )
{
	// {{{USR
	//Call the socket function and return its value to the ListenSocket 
	//variable. For this server application, use the first IP address 
	//returned by the call to getaddrinfo that matched the address family, 
	//socket type, and protocol specified in the hints parameter. 
	//In this example, a TCP stream socket for IPv4 was requested with an 
	//address family of IPv4, a socket type of SOCK_STREAM and a protocol 
	//of IPPROTO_TCP. So an IPv4 address is requested for the ListenSocket. 

	//If the server application wants to listen on IPv6, then the address 
	//family needs to be set to AF_INET6 in the hints parameter. 
	//If a server wants to listen on both IPv6 and IPv4, two listen sockets 
	//must be created, one for IPv6 and one for IPv4. These two sockets 
	//must be handled separately by the application.

	//Windows Vista and later offer the ability to create a single IPv6 
	//socket that is put in dual stack mode to listen on both IPv6 and IPv4. 
	//For more information on this feature, see Dual-Stack Sockets.

	// Create a SOCKET for the server to listen for client connections
	ListenSocket = INVALID_SOCKET;
	ClientSocket = INVALID_SOCKET;

	ListenSocket = socket(result->ai_family, 
	                      result->ai_socktype, 
						  result->ai_protocol);

	if (ListenSocket == INVALID_SOCKET) {
	    printf("Error at socket(): %ld\n", WSAGetLastError());
	    freeaddrinfo(result);
	    WSACleanup();
	    return false;
	}
	else
	{
		return true;
	}
	// }}}USR
}
// }}}RME

INLINE_CHAINS void ATCPServer_QtSocket_Actor::chain9_True( void )
{
	// transition ':TOP:validSocket:True'
	rtgChainBegin( 7, "True" );
	rtgTransitionBegin();
	rtgTransitionEnd();
	if( choicePoint6_bindingSuccessfull( msg->data, (Timing::Base *)msg->sap() ) )
		chain11_True();
	else
		chain10_False();
}

// {{{RME choicePoint ':TOP:bindingSuccessfull'
INLINE_METHODS int ATCPServer_QtSocket_Actor::choicePoint6_bindingSuccessfull( const void * rtdata, Timing::Base * rtport )
{
	// {{{USR
	//Binding
	//For a server to accept client connections, it must be bound to a 
	//network address within the system. The following code demonstrates 
	//how to bind a socket that has already been created to an IP address 
	//and port. Client applications use the IP address and port to connect 
	//to the host network.

	//The sockaddr structure holds information regarding the address family,
	//IP address, and port number. 

	//Call the bind function, passing the created socket and sockaddr 
	//structure returned from the getaddrinfo function as parameters. 
	//Check for general errors.


	// Setup the TCP listening socket
	iResult = bind( ListenSocket, 
	                result->ai_addr, 
					(int)result->ai_addrlen);
	if (iResult == SOCKET_ERROR) 
	{
	    printf("bind failed: %d\n", WSAGetLastError());
	    freeaddrinfo(result);
	    closesocket(ListenSocket);
	    WSACleanup();
	    return false;
	}
	else
	{
		return true;
	}
	// }}}USR
}
// }}}RME

INLINE_CHAINS void ATCPServer_QtSocket_Actor::chain11_True( void )
{
	// transition ':TOP:bindingSuccessfull:True'
	rtgChainBegin( 8, "True" );
	rtgTransitionBegin();
	rtgTransitionEnd();
	if( choicePoint7_listening( msg->data, (Timing::Base *)msg->sap() ) )
		chain13_True();
	else
		chain12_False();
}

// {{{RME choicePoint ':TOP:listening'
INLINE_METHODS int ATCPServer_QtSocket_Actor::choicePoint7_listening( const void * rtdata, Timing::Base * rtport )
{
	// {{{USR
	//Listening on a Socket
	//After the socket is bound to an IP address and port on the system, 
	//the server must then listen on that IP address and port for incoming 
	//connection requests.

	//Call the listen function, passing as parameters the created socket 
	//and a value for the backlog, maximum length of the queue of pending 
	//connections to accept. In this example, the backlog parameter was set 
	//to SOMAXCONN. This value is a special constant that instructs the 
	//Winsock provider for this socket to allow a maximum reasonable number 
	//of pending connections in the queue. 
	//Check the return value for general errors. 
	if ( listen( ListenSocket, SOMAXCONN ) == SOCKET_ERROR ) {
	    printf( "Error at bind(): %ld\n", WSAGetLastError() );
	    closesocket(ListenSocket);
	    WSACleanup();
	    return false;
	}
	else
	{
		cout << "listening to port: " << DEFAULT_PORT << endl;
		return true;
	}
	// }}}USR
}
// }}}RME

INLINE_CHAINS void ATCPServer_QtSocket_Actor::chain13_True( void )
{
	// transition ':TOP:listening:True'
	rtgChainBegin( 9, "True" );
	rtgTransitionBegin();
	rtgTransitionEnd();
	if( choicePoint2_acceptConnection( msg->data, (Timing::Base *)msg->sap() ) )
		chain16_True();
	else
		chain1_False();
}

// {{{RME choicePoint ':TOP:acceptConnection'
INLINE_METHODS int ATCPServer_QtSocket_Actor::choicePoint2_acceptConnection( const void * rtdata, Timing::Base * rtport )
{
	// {{{USR
	//Accepting a Connection
	//Once the socket is listening for a connection, the program must 
	//handle connection requests on that socket.

	//To accept a connection on a socket
	//Create a temporary SOCKET object called ClientSocket for accepting 
	//connections from clients.

	//Normally a server application would create a continuous loop that 
	//checks for connections requests. If a connection request occurs, 
	//call the accept function to handle the request. 
	//Note that in this basic example, the code only accepts a single 
	//connection. 

	//When the client connection has been accepted, a server would normally 
	//pass the accepted connection to a worker thread or an I/O completion 
	//port and continue accepting additional connections. In this basic 
	//example, the server continues to the next step. 

	ClientSocket = INVALID_SOCKET;

	// Accept a client socket
	ClientSocket = accept(ListenSocket, NULL, NULL);
	if (ClientSocket == INVALID_SOCKET) {
	    printf("accept failed: %d\n", WSAGetLastError());
	    closesocket(ListenSocket);
	    WSACleanup();
	    return false;
	}
	else
	{
		return true;
	}

	// }}}USR
}
// }}}RME

INLINE_CHAINS void ATCPServer_QtSocket_Actor::chain16_True( void )
{
	// transition ':TOP:acceptConnection:True'
	rtgChainBegin( 4, "True" );
	rtgTransitionBegin();
	transition16_True( msg->data, (Timing::Base *)msg->sap() );
	rtgTransitionEnd();
	if( choicePoint3_getBytes( msg->data, (Timing::Base *)msg->sap() ) )
		chain17_True();
	else
		chain2_False();
}

// {{{RME choicePoint ':TOP:getBytes'
INLINE_METHODS int ATCPServer_QtSocket_Actor::choicePoint3_getBytes( const void * rtdata, Timing::Base * rtport )
{
	// {{{USR

	int recvbuflen = DEFAULT_BUFLEN;
	int iSendResult = 0;


	// Receive bytes
	// and test peer for shutting down the connection
	do
	{
		iResult = recv(ClientSocket, recvbuf, recvbuflen, 0);
		if (iResult > 0) 
		{
			printf("Bytes received by socket capsule: %d\n", iResult);
			for (int i = 0; i < iResult; i++)
			{
				cout << recvbuf[i];
			}
			cout << endl;

			// send data to the application capsule via the port appPort
			pGuiConnection.data(RTString(recvbuf)).send();

	        // Echo the buffer back to the sender
	        iSendResult = send( ClientSocket, recvbuf, iResult, 0 );
	        if (iSendResult == SOCKET_ERROR) {
	            printf("send failed: %d\n", WSAGetLastError());
	            closesocket(ClientSocket);
	            WSACleanup();
	            return 1;
	        }
	        printf("Bytes sent: %d\n", iSendResult);
		}
		else
		{
			cout << "iResult <= 0 " << "is: " << iResult << endl;
		}
	}
	while (iResult > 0);

	if (iResult<=0)
	{
		printf("Connection closing...\n");
		return false;
	}
	else
	{
		return true;
	}
	// }}}USR
}
// }}}RME

INLINE_CHAINS void ATCPServer_QtSocket_Actor::chain17_True( void )
{
	// transition ':TOP:getBytes:True'
	rtgChainBegin( 5, "True" );
	rtgTransitionBegin();
	rtgTransitionEnd();
	if( choicePoint3_getBytes( msg->data, (Timing::Base *)msg->sap() ) )
		chain17_True();
	else
		chain2_False();
}

INLINE_CHAINS void ATCPServer_QtSocket_Actor::chain2_False( void )
{
	// transition ':TOP:getBytes:False'
	rtgChainBegin( 5, "False" );
	rtgTransitionBegin();
	transition2_False( msg->data, (Timing::Base *)msg->sap() );
	rtgTransitionEnd();
	if( choicePoint8_shutdownConnection( msg->data, (Timing::Base *)msg->sap() ) )
		chain15_True();
	else
		chain14_False();
}

// {{{RME choicePoint ':TOP:shutdownConnection'
INLINE_METHODS int ATCPServer_QtSocket_Actor::choicePoint8_shutdownConnection( const void * rtdata, Timing::Base * rtport )
{
	// {{{USR
	// connection has been closed by the client
	// shutdown the send half of the connection since no more data can be sent
	iResult = shutdown(ClientSocket, SD_SEND);
	if (iResult == SOCKET_ERROR) {
	   	printf("shutdown failed: %d\n", WSAGetLastError());
	    freeaddrinfo(result);
	    closesocket(ListenSocket);
	   	closesocket(ClientSocket);
	   	WSACleanup();
	   	return false;
	}
	else
	{
		return true;
	}



	// }}}USR
}
// }}}RME

INLINE_CHAINS void ATCPServer_QtSocket_Actor::chain15_True( void )
{
	// transition ':TOP:shutdownConnection:True'
	rtgChainBegin( 10, "True" );
	rtgTransitionBegin();
	rtgTransitionEnd();
	if( choicePoint2_acceptConnection( msg->data, (Timing::Base *)msg->sap() ) )
		chain16_True();
	else
		chain1_False();
}

INLINE_CHAINS void ATCPServer_QtSocket_Actor::chain1_False( void )
{
	// transition ':TOP:acceptConnection:False'
	rtgChainBegin( 4, "False" );
	rtgTransitionBegin();
	rtgTransitionEnd();
	enterState( 2 );
}

INLINE_CHAINS void ATCPServer_QtSocket_Actor::chain14_False( void )
{
	// transition ':TOP:shutdownConnection:False'
	rtgChainBegin( 10, "False" );
	rtgTransitionBegin();
	rtgTransitionEnd();
	enterState( 2 );
}

INLINE_CHAINS void ATCPServer_QtSocket_Actor::chain12_False( void )
{
	// transition ':TOP:listening:False'
	rtgChainBegin( 9, "False" );
	rtgTransitionBegin();
	rtgTransitionEnd();
	enterState( 2 );
}

INLINE_CHAINS void ATCPServer_QtSocket_Actor::chain10_False( void )
{
	// transition ':TOP:bindingSuccessfull:False'
	rtgChainBegin( 8, "False" );
	rtgTransitionBegin();
	rtgTransitionEnd();
	enterState( 2 );
}

INLINE_CHAINS void ATCPServer_QtSocket_Actor::chain8_False( void )
{
	// transition ':TOP:validSocket:False'
	rtgChainBegin( 7, "False" );
	rtgTransitionBegin();
	rtgTransitionEnd();
	enterState( 2 );
}

INLINE_CHAINS void ATCPServer_QtSocket_Actor::chain5_False( void )
{
	// transition ':TOP:addressCorrect:False'
	rtgChainBegin( 3, "False" );
	rtgTransitionBegin();
	rtgTransitionEnd();
	enterState( 2 );
}

INLINE_CHAINS void ATCPServer_QtSocket_Actor::chain4_False( void )
{
	// transition ':TOP:InitializeWinsock:False'
	rtgChainBegin( 6, "False" );
	rtgTransitionBegin();
	rtgTransitionEnd();
	enterState( 2 );
}

INLINE_CHAINS void ATCPServer_QtSocket_Actor::chain18_viaResetNaarInit( void )
{
	// transition ':TOP:Reset:J487926A700AC:viaResetNaarInit'
	rtgChainBegin( 2, "viaResetNaarInit" );
	exitState( rtg_parent_state );
	rtgTransitionBegin();
	rtgTransitionEnd();
	if( choicePoint4_InitializeWinsock( msg->data, (Timing::Base *)msg->sap() ) )
		chain6_True();
	else
		chain4_False();
}

void ATCPServer_QtSocket_Actor::rtsBehavior( int signalIndex, int portIndex )
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
					chain3_Initial();
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
			case 2:
				// {{{RME port 'timer'
				switch( signalIndex )
				{
				case Timing::Base::rti_timeout:
					chain18_viaResetNaarInit();
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

const RTActor_class * ATCPServer_QtSocket_Actor::getActorData( void ) const
{
	return &ATCPServer_QtSocket_Actor::rtg_class;
}

const RTActor_class ATCPServer_QtSocket_Actor::rtg_class =
{
	(const RTActor_class *)0
  , rtg_state_names
  , 2
  , ATCPServer_QtSocket_Actor::rtg_parent_state
  , &ATCPServer_QtSocket
  , 0
  , (const RTComponentDescriptor *)0
  , 3
  , ATCPServer_QtSocket_Actor::rtg_ports
  , 0
  , (const RTLocalBindingDescriptor *)0
  , 2
  , ATCPServer_QtSocket_Actor::rtg_ATCPServer_QtSocket_fields
};

const RTStateId ATCPServer_QtSocket_Actor::rtg_parent_state[] =
{
	0
  , 1
};

const RTPortDescriptor ATCPServer_QtSocket_Actor::rtg_ports[] =
{
	{
		"log"
	  , (const char *)0
	  , &Log::Base::rt_class
	  , RTOffsetOf( ATCPServer_QtSocket_Actor, ATCPServer_QtSocket_Actor::log )
	  , 1 // cardinality
	  , 1
	  , RTPortDescriptor::KindSpecial + RTPortDescriptor::NotificationDisabled + RTPortDescriptor::RegisterNotPermitted + RTPortDescriptor::VisibilityProtected
	}
  , {
		"timer"
	  , (const char *)0
	  , &Timing::Base::rt_class
	  , RTOffsetOf( ATCPServer_QtSocket_Actor, ATCPServer_QtSocket_Actor::timer )
	  , 1 // cardinality
	  , 2
	  , RTPortDescriptor::KindSpecial + RTPortDescriptor::NotificationDisabled + RTPortDescriptor::RegisterNotPermitted + RTPortDescriptor::VisibilityProtected
	}
  , {
		"pGuiConnection"
	  , (const char *)0
	  , &PGuiConnection::Base::rt_class
	  , RTOffsetOf( ATCPServer_QtSocket_Actor, ATCPServer_QtSocket_Actor::pGuiConnection )
	  , 1 // cardinality
	  , 3
	  , RTPortDescriptor::KindWired + RTPortDescriptor::NotificationDisabled + RTPortDescriptor::RegisterNotPermitted + RTPortDescriptor::VisibilityPublic
	}
};

const RTFieldDescriptor ATCPServer_QtSocket_Actor::rtg_ATCPServer_QtSocket_fields[] =
{
	// {{{RME classAttribute 'iResult'
	{
		"iResult"
	  , RTOffsetOf( ATCPServer_QtSocket_Actor, iResult )
		// {{{RME tool 'OT::CppTargetRTS' property 'TypeDescriptor'
	  , &RTType_int
		// }}}RME
		// {{{RME tool 'OT::CppTargetRTS' property 'GenerateTypeModifier'
	  , (const RTTypeModifier *)0
		// }}}RME
	}
	// }}}RME
	// {{{RME classAttribute 'recvbuf'
  , {
		"recvbuf"
	  , RTOffsetOf( ATCPServer_QtSocket_Actor, recvbuf[ 0 ] )
		// {{{RME tool 'OT::CppTargetRTS' property 'TypeDescriptor'
	  , &RTType_char
		// }}}RME
		// {{{RME tool 'OT::CppTargetRTS' property 'GenerateTypeModifier'
	  , &rtg_tm_ATCPServer_QtSocket_Actor_recvbuf
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
