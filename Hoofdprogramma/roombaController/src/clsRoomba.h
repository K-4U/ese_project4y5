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
// {{{RME classifier 'clsBumpersAndCliff' tool 'OT::Cpp' property 'HeaderPreface'
// {{{USR

// }}}USR
// }}}RME
// {{{RME classifier 'clsMotors' tool 'OT::Cpp' property 'HeaderPreface'
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
	// {{{RME classifier 'clsBumpersAndCliff'
	struct clsBumpersAndCliff
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
		clsBumpersAndCliff( void );
		// }}}RME
		// {{{RME tool 'OT::Cpp' property 'GenerateDestructor'
		virtual ~clsBumpersAndCliff( void );
		// }}}RME
		// {{{RME tool 'OT::Cpp' property 'GenerateCopyConstructor'
		clsBumpersAndCliff( const clsBumpersAndCliff & rtg_arg );
		// }}}RME
		// {{{RME tool 'OT::Cpp' property 'GenerateAssignmentOperator'
		clsBumpersAndCliff & operator=( const clsBumpersAndCliff & rtg_arg );
		// }}}RME
	};
	// }}}RME
	static const RTObject_class RTType_clsBumpersAndCliff;

private:
	static void rtg_clsBumpersAndCliff_init( const RTObject_class * type, clsBumpersAndCliff * target );
	static void rtg_clsBumpersAndCliff_copy( const RTObject_class * type, clsBumpersAndCliff * target, const clsBumpersAndCliff * source );
	static void rtg_clsBumpersAndCliff_destroy( const RTObject_class * type, clsBumpersAndCliff * target );
	static const RTFieldDescriptor rtg_clsBumpersAndCliff_fields[];

public:
	struct RTTypedValue_clsBumpersAndCliff
	{
		const void * data;
		const RTObject_class * type;
		inline RTTypedValue_clsBumpersAndCliff( const clsBumpersAndCliff & rtg_value )
			: data( &rtg_value ), type( &RTType_clsBumpersAndCliff )
		{
		}
		inline RTTypedValue_clsBumpersAndCliff( const clsBumpersAndCliff & rtg_value, const RTObject_class * rtg_type )
			: data( &rtg_value ), type( rtg_type )
		{
		}
		inline ~RTTypedValue_clsBumpersAndCliff( void )
		{
		}
	};
	// {{{RME classifier 'clsMotors'
	class clsMotors
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
		// {{{RME classAttribute 'mainBrush'
		bool mainBrush;
		// }}}RME
		// {{{RME classAttribute 'sideBrush'
		bool sideBrush;
		// }}}RME
		// {{{RME classAttribute 'vacuum'
		bool vacuum;
		// }}}RME
		// {{{RME tool 'OT::Cpp' property 'GenerateDefaultConstructor'
		clsMotors( void );
		// }}}RME
		// {{{RME tool 'OT::Cpp' property 'GenerateDestructor'
		virtual ~clsMotors( void );
		// }}}RME
		// {{{RME tool 'OT::Cpp' property 'GenerateCopyConstructor'
		clsMotors( const clsMotors & rtg_arg );
		// }}}RME
		// {{{RME tool 'OT::Cpp' property 'GenerateAssignmentOperator'
		clsMotors & operator=( const clsMotors & rtg_arg );
		// }}}RME
	};
	// }}}RME
	static const RTObject_class RTType_clsMotors;

private:
	static void rtg_clsMotors_init( const RTObject_class * type, clsMotors * target );
	static void rtg_clsMotors_copy( const RTObject_class * type, clsMotors * target, const clsMotors * source );
	static void rtg_clsMotors_destroy( const RTObject_class * type, clsMotors * target );
	static const RTFieldDescriptor rtg_clsMotors_fields[];

public:
	struct RTTypedValue_clsMotors
	{
		const void * data;
		const RTObject_class * type;
		inline RTTypedValue_clsMotors( const clsMotors & rtg_value )
			: data( &rtg_value ), type( &RTType_clsMotors )
		{
		}
		inline RTTypedValue_clsMotors( const clsMotors & rtg_value, const RTObject_class * rtg_type )
			: data( &rtg_value ), type( rtg_type )
		{
		}
		inline ~RTTypedValue_clsMotors( void )
		{
		}
	};

private:
	// {{{RME classAttribute 'bumpers'
	clsBumpersAndCliff bumpers;
	// }}}RME
	// {{{RME classAttribute 'cliff'
	clsBumpersAndCliff cliff;
	// }}}RME
	// {{{RME classAttribute 'distance'
	int distance;
	// }}}RME
	// {{{RME classAttribute 'totalDistance'
	int totalDistance;
	// }}}RME
	// {{{RME classAttribute 'angle'
	int angle;
	// }}}RME
	// {{{RME classAttribute 'totalAngle'
	int totalAngle;
	// }}}RME
	// {{{RME classAttribute 'chargingState'
	int chargingState;
	// }}}RME
	// {{{RME classAttribute 'temperature'
	int temperature;
	// }}}RME
	// {{{RME classAttribute 'battCharge'
	int battCharge;
	// }}}RME
	// {{{RME classAttribute 'battCapac'
	int battCapac;
	// }}}RME
	// {{{RME classAttribute 'oiMode'
	int oiMode;
	// }}}RME
	// {{{RME classAttribute 'motors'
	clsMotors motors;
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
	// {{{RME operation 'setSensor(int,int)'
	void setSensor( int index, int value );
	// }}}RME
	// {{{RME operation 'printSensors()'
	void printSensors( void );
	// }}}RME
	// {{{RME operation 'setMotors(bool,bool,bool)'
	void setMotors( bool mainBrush, bool sideBrush, bool vacuum );
	// }}}RME
	// {{{RME operation 'getMotors(bool*,bool*,bool*)'
	void getMotors( bool * mainBrush, bool * sideBrush, bool * vacuum );
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
// {{{RME classifier 'clsBumpersAndCliff' tool 'OT::Cpp' property 'HeaderEnding'
// {{{USR

// }}}USR
// }}}RME
// {{{RME classifier 'clsMotors' tool 'OT::Cpp' property 'HeaderEnding'
// {{{USR

// }}}USR
// }}}RME

#endif /* clsRoomba_H */

// }}}RME
