// {{{RME classifier 'Logical View::DataAccess::CKlep'

#ifndef CKlep_H
#define CKlep_H

#ifdef PRAGMA
#pragma interface "CKlep.h"
#endif

#include <RTSystem/WarmeDrankenAutomaatComponent.h>

// {{{RME tool 'OT::Cpp' property 'HeaderPreface'
// {{{USR

// }}}USR
// }}}RME

extern const RTObject_class RTType_CKlep;

class CKlep
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

public:
	// {{{RME tool 'OT::Cpp' property 'GenerateDefaultConstructor'
	CKlep( void );
	// }}}RME
	// {{{RME tool 'OT::Cpp' property 'GenerateDestructor'
	virtual ~CKlep( void );
	// }}}RME
	// {{{RME tool 'OT::Cpp' property 'GenerateCopyConstructor'
	CKlep( const CKlep & rtg_arg );
	// }}}RME
	// {{{RME tool 'OT::Cpp' property 'GenerateAssignmentOperator'
	CKlep & operator=( const CKlep & rtg_arg );
	// }}}RME
	// {{{RME operation 'setKlep(bool)'
	void setKlep( bool position = false );
	// }}}RME
};

struct RTTypedValue_CKlep
{
	const void * data;
	const RTObject_class * type;
	inline RTTypedValue_CKlep( const CKlep & rtg_value )
		: data( &rtg_value ), type( &RTType_CKlep )
	{
	}
	inline RTTypedValue_CKlep( const CKlep & rtg_value, const RTObject_class * rtg_type )
		: data( &rtg_value ), type( rtg_type )
	{
	}
	inline ~RTTypedValue_CKlep( void )
	{
	}
};

// {{{RME tool 'OT::Cpp' property 'HeaderEnding'
// {{{USR

// }}}USR
// }}}RME

#endif /* CKlep_H */

// }}}RME
