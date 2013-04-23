// {{{RME classifier 'Logical View::UserInterface::AGui'

#ifndef AGui_H
#define AGui_H

#ifdef PRAGMA
#pragma interface "AGui.h"
#endif

#include <RTSystem/WarmeDrankenAutomaatComponent.h>
#include <PGuiInit.h>

// {{{RME tool 'OT::Cpp' property 'HeaderPreface'
// {{{USR

// }}}USR
// }}}RME

extern const RTActorClass AGui;

#define SUPER RTActor
class AGui_Actor : public RTActor
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

protected:
	// {{{RME port 'pGuiInit'
	PGuiInit::Base pGuiInit;
	// }}}RME

public:
	AGui_Actor( RTController * rtg_rts, RTActorRef * rtg_ref );
	virtual ~AGui_Actor( void );
	virtual int _followInV( RTBindingEnd & rtg_end, int rtg_portId, int rtg_repIndex );

protected:
	// {{{RME transition ':TOP:waitForInit:J4BB86BDA03DA:initReceived'
	INLINE_METHODS void transition2_initReceived( const void * rtdata, PGuiInit::Base * rtport );
	// }}}RME

private:
	INLINE_CHAINS void chain1_Initial( void );
	INLINE_CHAINS void chain2_initReceived( void );

public:
	virtual void rtsBehavior( int signalIndex, int portIndex );
	virtual const RTActor_class * getActorData( void ) const;

protected:
	static const RTActor_class rtg_class;

public:
	static const RTStateId rtg_parent_state[];

private:
	static const RTPortDescriptor rtg_ports[];
};
#undef SUPER

// {{{RME tool 'OT::Cpp' property 'HeaderEnding'
// {{{USR

// }}}USR
// }}}RME

#endif /* AGui_H */

// }}}RME
