// {{{RME classifier 'Logical View::Roomba::clsRoomba'

#ifndef clsRoomba_H
#define clsRoomba_H

#ifdef PRAGMA
#pragma interface "clsRoomba.h"
#endif

#include <RTSystem/roombaController.h>

// {{{RME tool 'OT::Cpp' property 'HeaderPreface'
// {{{USR

// }}}USR
// }}}RME
// {{{RME classifier 'clsBumpers' tool 'OT::Cpp' property 'HeaderPreface'
// {{{USR

// }}}USR
// }}}RME

extern const RTObject_class RTType_clsRoomba;

class clsRoomba
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
	// {{{RME classifier 'clsBumpers'
	struct clsBumpers
	{
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
		// {{{RME classAttribute 'left'
		bool left;
		// }}}RME
		// {{{RME classAttribute 'right'
		bool right;
		// }}}RME
		// {{{RME classAttribute 'frontLeft'
		bool frontLeft;
		// }}}RME
		// {{{RME classAttribute 'frontRight'
		bool frontRight;
		// }}}RME
		// {{{RME tool 'OT::Cpp' property 'GenerateDefaultConstructor'
		clsBumpers( void );
		// }}}RME
		// {{{RME tool 'OT::Cpp' property 'GenerateDestructor'
		virtual ~clsBumpers( void );
		// }}}RME
		// {{{RME tool 'OT::Cpp' property 'GenerateCopyConstructor'
		clsBumpers( const clsBumpers & rtg_arg );
		// }}}RME
		// {{{RME tool 'OT::Cpp' property 'GenerateAssignmentOperator'
		clsBumpers & operator=( const clsBumpers & rtg_arg );
		// }}}RME
	};
	// }}}RME
	static const RTObject_class RTType_clsBumpers;

private:
	static void rtg_clsBumpers_init( const RTObject_class * type, clsBumpers * target );
	static void rtg_clsBumpers_copy( const RTObject_class * type, clsBumpers * target, const clsBumpers * source );
	static void rtg_clsBumpers_destroy( const RTObject_class * type, clsBumpers * target );
	static const RTFieldDescriptor rtg_clsBumpers_fields[];

public:
	struct RTTypedValue_clsBumpers
	{
		const void * data;
		const RTObject_class * type;
		inline RTTypedValue_clsBumpers( const clsBumpers & rtg_value )
			: data( &rtg_value ), type( &RTType_clsBumpers )
		{
		}
		inline RTTypedValue_clsBumpers( const clsBumpers & rtg_value, const RTObject_class * rtg_type )
			: data( &rtg_value ), type( rtg_type )
		{
		}
		inline ~RTTypedValue_clsBumpers( void )
		{
		}
	};

private:
	// {{{RME classAttribute 'bumpers'
	clsBumpers bumpers;
	// }}}RME

public:
	// {{{RME tool 'OT::Cpp' property 'GenerateDefaultConstructor'
	clsRoomba( void );
	// }}}RME
	// {{{RME tool 'OT::Cpp' property 'GenerateDestructor'
	virtual ~clsRoomba( void );
	// }}}RME
	// {{{RME tool 'OT::Cpp' property 'GenerateCopyConstructor'
	clsRoomba( const clsRoomba & rtg_arg );
	// }}}RME
	// {{{RME tool 'OT::Cpp' property 'GenerateAssignmentOperator'
	clsRoomba & operator=( const clsRoomba & rtg_arg );
	// }}}RME
	static const RTFieldDescriptor rtg_clsRoomba_fields[];
};

struct RTTypedValue_clsRoomba
{
	const void * data;
	const RTObject_class * type;
	inline RTTypedValue_clsRoomba( const clsRoomba & rtg_value )
		: data( &rtg_value ), type( &RTType_clsRoomba )
	{
	}
	inline RTTypedValue_clsRoomba( const clsRoomba & rtg_value, const RTObject_class * rtg_type )
		: data( &rtg_value ), type( rtg_type )
	{
	}
	inline ~RTTypedValue_clsRoomba( void )
	{
	}
};

// {{{RME tool 'OT::Cpp' property 'HeaderEnding'
// {{{USR

// }}}USR
// }}}RME
// {{{RME classifier 'clsBumpers' tool 'OT::Cpp' property 'HeaderEnding'
// {{{USR

// }}}USR
// }}}RME

#endif /* clsRoomba_H */

// }}}RME
