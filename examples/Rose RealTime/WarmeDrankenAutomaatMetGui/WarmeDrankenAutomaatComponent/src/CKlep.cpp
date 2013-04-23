// {{{RME classifier 'Logical View::DataAccess::CKlep'

#if defined( PRAGMA ) && ! defined( PRAGMA_IMPLEMENTED )
#pragma implementation "CKlep.h"
#endif

#include <RTSystem/WarmeDrankenAutomaatComponent.h>
#include <CKlep.h>

// {{{RME tool 'OT::Cpp' property 'ImplementationPreface'
// {{{USR

// }}}USR
// }}}RME

static void rtg_CKlep_init( const RTObject_class * type, CKlep * target )
{
	(void)new( target ) CKlep;
}

static void rtg_CKlep_copy( const RTObject_class * type, CKlep * target, const CKlep * source )
{
	(void)new( target ) CKlep( *source );
}

static void rtg_CKlep_destroy( const RTObject_class * type, CKlep * target )
{
	target->~CKlep();
}

const RTObject_class RTType_CKlep =
{
	(const RTObject_class *)0
  , (RTSuperAccessFunction)0
  , "CKlep"
  , (RTVersionId)0
  , (RTFieldOffset)sizeof( CKlep )
  , (RTInitFunction)rtg_CKlep_init
  , (RTCopyFunction)rtg_CKlep_copy
#if OBJECT_DECODE
  , RTstruct_decode
#endif
#if OBJECT_ENCODE
  , RTstruct_encode
#endif
  , (RTDestroyFunction)rtg_CKlep_destroy
  , 0
  , (const RTFieldDescriptor *)0
};

// {{{RME tool 'OT::Cpp' property 'GenerateDefaultConstructor'
CKlep::CKlep( void )
{
}
// }}}RME

// {{{RME tool 'OT::Cpp' property 'GenerateDestructor'
CKlep::~CKlep( void )
{
}
// }}}RME

// {{{RME tool 'OT::Cpp' property 'GenerateCopyConstructor'
CKlep::CKlep( const CKlep & rtg_arg )
{
}
// }}}RME

// {{{RME tool 'OT::Cpp' property 'GenerateAssignmentOperator'
CKlep & CKlep::operator=( const CKlep & rtg_arg )
{
	if( this != &rtg_arg )
	{
	}
	return *this;
}
// }}}RME

// {{{RME operation 'setKlep(bool)'
void CKlep::setKlep( bool position )
{
	// {{{USR
	cout << "cacao klep open is : " << position << endl;
	// }}}USR
}
// }}}RME

#if OBJECT_DECODE
RTTypeInstaller rtg_CKlep_installer( RTType_CKlep );
#endif

// {{{RME tool 'OT::Cpp' property 'ImplementationEnding'
// {{{USR

// }}}USR
// }}}RME

// }}}RME
