// {{{RME classifier 'Logical View::TCPIP::jsonTranslateCapsule'

#ifndef jsonTranslateCapsule_H
#define jsonTranslateCapsule_H

#ifdef PRAGMA
#pragma interface "jsonTranslateCapsule.h"
#endif

#include <RTSystem/ourProgram.h>
#include <jsonProtocol.h>
#include <tcpProtocol.h>

// {{{RME tool 'OT::Cpp' property 'HeaderPreface'
// {{{USR

// }}}USR
// }}}RME

extern const RTActorClass jsonTranslateCapsule;

#define SUPER RTActor
class jsonTranslateCapsule_Actor : public RTActor
{
public:
	// {{{RME tool 'OT::Cpp' property 'PublicDeclarations'
	// {{{USR

	// }}}USR
	// }}}RME

protected:
	// {{{RME tool 'OT::Cpp' property 'ProtectedDeclarations'
	// {{{USR

	// }}}USR
	// }}}RME

private:
	// {{{RME tool 'OT::Cpp' property 'PrivateDeclarations'
	// {{{USR

	// }}}USR
	// }}}RME
	// {{{RME classAttribute 'jsonReader'
	Json::Reader jsonReader;
	// }}}RME
	// {{{RME classAttribute 'jsonBuffer'
	std::string jsonBuffer;
	// }}}RME
	// {{{RME classAttribute 'depth'
	int depth;
	// }}}RME

protected:
	// {{{RME port 'jsonPort'
	jsonProtocol::Base jsonPort;
	// }}}RME
	// {{{RME port 'tcpPort'
	tcpProtocol::Conjugate tcpPort;
	// }}}RME
	// {{{RME port 'frame'
	Frame::Base frame;
	// }}}RME

public:
	jsonTranslateCapsule_Actor( RTController * rtg_rts, RTActorRef * rtg_ref );
	virtual ~jsonTranslateCapsule_Actor( void );
	virtual int _followInV( RTBindingEnd & rtg_end, int rtg_portId, int rtg_repIndex );

protected:
	// {{{RME transition ':TOP:KlaarVoorData:J5176823800F4:dataReceived'
	INLINE_METHODS void transition1_dataReceived( const RTString * rtdata, tcpProtocol::Conjugate * rtport );
	// }}}RME
	// {{{RME transition ':TOP:Initial:Initial'
	INLINE_METHODS void transition2_Initial( const void * rtdata, RTProtocol * rtport );
	// }}}RME

private:
	INLINE_CHAINS void chain2_Initial( void );
	INLINE_CHAINS void chain1_dataReceived( void );

public:
	virtual void rtsBehavior( int signalIndex, int portIndex );
	virtual const RTActor_class * getActorData( void ) const;

protected:
	static const RTActor_class rtg_class;

public:
	static const RTStateId rtg_parent_state[];

private:
	static const RTPortDescriptor rtg_ports[];

public:
	static const RTFieldDescriptor rtg_jsonTranslateCapsule_fields[];
};
#undef SUPER

// {{{RME tool 'OT::Cpp' property 'HeaderEnding'
// {{{USR

// }}}USR
// }}}RME

#endif /* jsonTranslateCapsule_H */

// }}}RME
