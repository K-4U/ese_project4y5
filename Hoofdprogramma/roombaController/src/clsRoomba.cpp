// {{{RME classifier 'Logical View::Roomba::clsRoomba'

#if defined( PRAGMA ) && ! defined( PRAGMA_IMPLEMENTED )
#pragma implementation "clsRoomba.h"
#endif

#include <RTSystem/roombaController.h>
#include <clsRoomba.h>

// {{{RME tool 'OT::Cpp' property 'ImplementationPreface'
// {{{USR

// }}}USR
// }}}RME
// {{{RME classifier 'clsBumpers' tool 'OT::Cpp' property 'ImplementationPreface'
// {{{USR

// }}}USR
// }}}RME

static void rtg_clsRoomba_init( const RTObject_class * type, clsRoomba * target )
{
	(void)new( target ) clsRoomba;
}

static void rtg_clsRoomba_copy( const RTObject_class * type, clsRoomba * target, const clsRoomba * source )
{
	(void)new( target ) clsRoomba( *source );
}

static void rtg_clsRoomba_destroy( const RTObject_class * type, clsRoomba * target )
{
	target->~clsRoomba();
}

const RTObject_class RTType_clsRoomba =
{
	(const RTObject_class *)0
  , (RTSuperAccessFunction)0
  , "clsRoomba"
  , (RTVersionId)0
  , (RTFieldOffset)sizeof( clsRoomba )
  , (RTInitFunction)rtg_clsRoomba_init
  , (RTCopyFunction)rtg_clsRoomba_copy
#if OBJECT_DECODE
  , RTstruct_decode
#endif
#if OBJECT_ENCODE
  , RTstruct_encode
#endif
  , (RTDestroyFunction)rtg_clsRoomba_destroy
  , 1
  , clsRoomba::rtg_clsRoomba_fields
};

// {{{RME classifier 'clsBumpers'

// {{{RME tool 'OT::Cpp' property 'GenerateDefaultConstructor'
clsRoomba::clsBumpers::clsBumpers( void )
{
}
// }}}RME

// {{{RME tool 'OT::Cpp' property 'GenerateDestructor'
clsRoomba::clsBumpers::~clsBumpers( void )
{
}
// }}}RME

// {{{RME tool 'OT::Cpp' property 'GenerateCopyConstructor'
clsRoomba::clsBumpers::clsBumpers( const clsBumpers & rtg_arg )
	: left( rtg_arg.left )
	, right( rtg_arg.right )
	, frontLeft( rtg_arg.frontLeft )
	, frontRight( rtg_arg.frontRight )
{
}
// }}}RME

// {{{RME tool 'OT::Cpp' property 'GenerateAssignmentOperator'
clsRoomba::clsBumpers & clsRoomba::clsBumpers::operator=( const clsBumpers & rtg_arg )
{
	if( this != &rtg_arg )
	{
		left = rtg_arg.left;
		right = rtg_arg.right;
		frontLeft = rtg_arg.frontLeft;
		frontRight = rtg_arg.frontRight;
	}
	return *this;
}
// }}}RME
// }}}RME

const RTObject_class clsRoomba::RTType_clsBumpers =
{
	(const RTObject_class *)0
  , (RTSuperAccessFunction)0
  , "clsBumpers"
  , (RTVersionId)0
  , (RTFieldOffset)sizeof( clsBumpers )
  , (RTInitFunction)&clsRoomba::rtg_clsBumpers_init
  , (RTCopyFunction)&clsRoomba::rtg_clsBumpers_copy
#if OBJECT_DECODE
  , RTstruct_decode
#endif
#if OBJECT_ENCODE
  , RTstruct_encode
#endif
  , (RTDestroyFunction)&clsRoomba::rtg_clsBumpers_destroy
  , 4
  , clsRoomba::rtg_clsBumpers_fields
};

void clsRoomba::rtg_clsBumpers_init( const RTObject_class * type, clsBumpers * target )
{
	(void)new( target ) clsBumpers;
}

void clsRoomba::rtg_clsBumpers_copy( const RTObject_class * type, clsBumpers * target, const clsBumpers * source )
{
	(void)new( target ) clsBumpers( *source );
}

void clsRoomba::rtg_clsBumpers_destroy( const RTObject_class * type, clsBumpers * target )
{
	target->~clsBumpers();
}

const RTFieldDescriptor clsRoomba::rtg_clsBumpers_fields[] =
{
	// {{{RME classifier 'clsBumpers' classAttribute 'left'
	{
		"left"
	  , RTOffsetOf( clsBumpers, left )
		// {{{RME tool 'OT::CppTargetRTS' property 'TypeDescriptor'
	  , &RTType_bool
		// }}}RME
		// {{{RME tool 'OT::CppTargetRTS' property 'GenerateTypeModifier'
	  , (const RTTypeModifier *)0
		// }}}RME
	}
	// }}}RME
	// {{{RME classifier 'clsBumpers' classAttribute 'right'
  , {
		"right"
	  , RTOffsetOf( clsBumpers, right )
		// {{{RME tool 'OT::CppTargetRTS' property 'TypeDescriptor'
	  , &RTType_bool
		// }}}RME
		// {{{RME tool 'OT::CppTargetRTS' property 'GenerateTypeModifier'
	  , (const RTTypeModifier *)0
		// }}}RME
	}
	// }}}RME
	// {{{RME classifier 'clsBumpers' classAttribute 'frontLeft'
  , {
		"frontLeft"
	  , RTOffsetOf( clsBumpers, frontLeft )
		// {{{RME tool 'OT::CppTargetRTS' property 'TypeDescriptor'
	  , &RTType_bool
		// }}}RME
		// {{{RME tool 'OT::CppTargetRTS' property 'GenerateTypeModifier'
	  , (const RTTypeModifier *)0
		// }}}RME
	}
	// }}}RME
	// {{{RME classifier 'clsBumpers' classAttribute 'frontRight'
  , {
		"frontRight"
	  , RTOffsetOf( clsBumpers, frontRight )
		// {{{RME tool 'OT::CppTargetRTS' property 'TypeDescriptor'
	  , &RTType_bool
		// }}}RME
		// {{{RME tool 'OT::CppTargetRTS' property 'GenerateTypeModifier'
	  , (const RTTypeModifier *)0
		// }}}RME
	}
	// }}}RME
};

// {{{RME tool 'OT::Cpp' property 'GenerateDefaultConstructor'
clsRoomba::clsRoomba( void )
{
}
// }}}RME

// {{{RME tool 'OT::Cpp' property 'GenerateDestructor'
clsRoomba::~clsRoomba( void )
{
}
// }}}RME

// {{{RME tool 'OT::Cpp' property 'GenerateCopyConstructor'
clsRoomba::clsRoomba( const clsRoomba & rtg_arg )
	: bumpers( rtg_arg.bumpers )
{
}
// }}}RME

// {{{RME tool 'OT::Cpp' property 'GenerateAssignmentOperator'
clsRoomba & clsRoomba::operator=( const clsRoomba & rtg_arg )
{
	if( this != &rtg_arg )
		bumpers = rtg_arg.bumpers;
	return *this;
}
// }}}RME

const RTFieldDescriptor clsRoomba::rtg_clsRoomba_fields[] =
{
	// {{{RME classAttribute 'bumpers'
	{
		"bumpers"
	  , RTOffsetOf( clsRoomba, bumpers )
		// {{{RME tool 'OT::CppTargetRTS' property 'TypeDescriptor'
	  , &clsRoomba::RTType_clsBumpers
		// }}}RME
		// {{{RME tool 'OT::CppTargetRTS' property 'GenerateTypeModifier'
	  , (const RTTypeModifier *)0
		// }}}RME
	}
	// }}}RME
};

#if OBJECT_DECODE
RTTypeInstaller rtg_clsRoomba_clsBumpers_installer( clsRoomba::RTType_clsBumpers );
#endif

#if OBJECT_DECODE
RTTypeInstaller rtg_clsRoomba_installer( RTType_clsRoomba );
#endif

// {{{RME tool 'OT::Cpp' property 'ImplementationEnding'
// {{{USR

// }}}USR
// }}}RME
// {{{RME classifier 'clsBumpers' tool 'OT::Cpp' property 'ImplementationEnding'
// {{{USR

// }}}USR
// }}}RME

// }}}RME
