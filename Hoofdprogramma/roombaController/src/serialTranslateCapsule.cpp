// {{{RME classifier 'Logical View::Serial::serialTranslateCapsule'

#if defined( PRAGMA ) && ! defined( PRAGMA_IMPLEMENTED )
#pragma implementation "serialTranslateCapsule.h"
#endif

#include <RTSystem/roombaController.h>
#include <serialTranslateCapsule.h>
#include <serialProperties.h>

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
	int i;
	for(i = 0; i <= b.size(); i++){
	    if(!this->inCommand){
	        if(b.get(i) == 19){ //Sensor stream
	            //This is the sensor stream. The next byte is the length
	            this->inCommand = true;
	            this->lengthNotYetReceived = true;
	            this->buffer.append(b.get(i));
	        }
	    }else if(this->inCommand && this->lengthNotYetReceived == true){
	        this->commandLength = b.get(i)+2;
	        this->lengthNotYetReceived = false;
	        this->buffer.append(b.get(i));
	    }else{
	        this->buffer.append(b.get(i));
	        //cout << "STR: Buff size: " << this->buffer.size() << "/" << this->commandLength << endl;
	        if(this->buffer.size() >= this->commandLength){
	            //Complete packet received. Handle it plox.
	            //Trigger event
	            serialOut.commandReceived(this->buffer).send();
	            //Clear buffer
	            this->buffer.clear();
	            this->inCommand = false;
	            this->commandLength = 0;
	        }
	    }
	}


	cout << "STR: Data received: ";// << (char *)b.getAll() << endl;
	b.print();
	// }}}USR
}
// }}}RME

// {{{RME transition ':TOP:S1:J5193551C029A:sendCommand'
INLINE_METHODS void serialTranslateCapsule_Actor::transition3_sendCommand( const byteArray * rtdata, serialProtocol::Base * rtport )
{
	// {{{USR
	byteArray b = *rtdata;

	unsigned char data[b.size()];
	int i = 0;
	for(i = 0; i <= b.size(); i++){
	    data[i] = b.getAll().Contents[i];
	}

	RS232_SendBuf(COM_PORT, data, b.size());

	//cout << "STR: Sending data: ";
	//b.print();
	// }}}USR
}
// }}}RME

// {{{RME transition ':TOP:S1:J519B507801FB:comOpened'
INLINE_METHODS void serialTranslateCapsule_Actor::transition4_comOpened( const void * rtdata, serialRawProtocol::Conjugate * rtport )
{
	// {{{USR
	serialOut.comOpened().send();
	// }}}USR
}
// }}}RME

// {{{RME transition ':TOP:S1:J519B50B801E5:comError'
INLINE_METHODS void serialTranslateCapsule_Actor::transition5_comError( const void * rtdata, serialRawProtocol::Conjugate * rtport )
{
	// {{{USR
	serialOut.comError().send();
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

INLINE_CHAINS void serialTranslateCapsule_Actor::chain4_comOpened( void )
{
	// transition ':TOP:S1:J519B507801FB:comOpened'
	rtgChainBegin( 2, "comOpened" );
	exitState( rtg_parent_state );
	rtgTransitionBegin();
	transition4_comOpened( msg->data, (serialRawProtocol::Conjugate *)msg->sap() );
	rtgTransitionEnd();
	enterState( 2 );
}

INLINE_CHAINS void serialTranslateCapsule_Actor::chain5_comError( void )
{
	// transition ':TOP:S1:J519B50B801E5:comError'
	rtgChainBegin( 2, "comError" );
	exitState( rtg_parent_state );
	rtgTransitionBegin();
	transition5_comError( msg->data, (serialRawProtocol::Conjugate *)msg->sap() );
	rtgTransitionEnd();
	enterState( 2 );
}

INLINE_CHAINS void serialTranslateCapsule_Actor::chain3_sendCommand( void )
{
	// transition ':TOP:S1:J5193551C029A:sendCommand'
	rtgChainBegin( 2, "sendCommand" );
	exitState( rtg_parent_state );
	rtgTransitionBegin();
	transition3_sendCommand( (const byteArray *)msg->data, (serialProtocol::Base *)msg->sap() );
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
				case serialRawProtocol::Conjugate::rti_comOpened:
					chain4_comOpened();
					return;
				case serialRawProtocol::Conjugate::rti_comError:
					chain5_comError();
					return;
				default:
					break;
				}
				break;
				// }}}RME
			case 2:
				// {{{RME port 'serialOut'
				switch( signalIndex )
				{
				case serialProtocol::Base::rti_sendCommand:
					chain3_sendCommand();
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
  , 5
  , serialTranslateCapsule_Actor::rtg_serialTranslateCapsule_fields
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

const RTFieldDescriptor serialTranslateCapsule_Actor::rtg_serialTranslateCapsule_fields[] =
{
	// {{{RME classAttribute 'firstByte'
	{
		"firstByte"
	  , RTOffsetOf( serialTranslateCapsule_Actor, firstByte )
		// {{{RME tool 'OT::CppTargetRTS' property 'TypeDescriptor'
	  , &RTType_char
		// }}}RME
		// {{{RME tool 'OT::CppTargetRTS' property 'GenerateTypeModifier'
	  , (const RTTypeModifier *)0
		// }}}RME
	}
	// }}}RME
	// {{{RME classAttribute 'inCommand'
  , {
		"inCommand"
	  , RTOffsetOf( serialTranslateCapsule_Actor, inCommand )
		// {{{RME tool 'OT::CppTargetRTS' property 'TypeDescriptor'
	  , &RTType_bool
		// }}}RME
		// {{{RME tool 'OT::CppTargetRTS' property 'GenerateTypeModifier'
	  , (const RTTypeModifier *)0
		// }}}RME
	}
	// }}}RME
	// {{{RME classAttribute 'commandLength'
  , {
		"commandLength"
	  , RTOffsetOf( serialTranslateCapsule_Actor, commandLength )
		// {{{RME tool 'OT::CppTargetRTS' property 'TypeDescriptor'
	  , &RTType_int
		// }}}RME
		// {{{RME tool 'OT::CppTargetRTS' property 'GenerateTypeModifier'
	  , (const RTTypeModifier *)0
		// }}}RME
	}
	// }}}RME
	// {{{RME classAttribute 'buffer'
  , {
		"buffer"
	  , RTOffsetOf( serialTranslateCapsule_Actor, buffer )
		// {{{RME tool 'OT::CppTargetRTS' property 'TypeDescriptor'
	  , (const RTObject_class *)0
		// }}}RME
		// {{{RME tool 'OT::CppTargetRTS' property 'GenerateTypeModifier'
	  , (const RTTypeModifier *)0
		// }}}RME
	}
	// }}}RME
	// {{{RME classAttribute 'lengthNotYetReceived'
  , {
		"lengthNotYetReceived"
	  , RTOffsetOf( serialTranslateCapsule_Actor, lengthNotYetReceived )
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
