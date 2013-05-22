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
// {{{RME classifier 'clsBumpersAndCliff' tool 'OT::Cpp' property 'ImplementationPreface'
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
  , 11
  , clsRoomba::rtg_clsRoomba_fields
};

// {{{RME classifier 'clsBumpersAndCliff'

// {{{RME tool 'OT::Cpp' property 'GenerateDefaultConstructor'
clsRoomba::clsBumpersAndCliff::clsBumpersAndCliff( void )
{
}
// }}}RME

// {{{RME tool 'OT::Cpp' property 'GenerateDestructor'
clsRoomba::clsBumpersAndCliff::~clsBumpersAndCliff( void )
{
}
// }}}RME

// {{{RME tool 'OT::Cpp' property 'GenerateCopyConstructor'
clsRoomba::clsBumpersAndCliff::clsBumpersAndCliff( const clsBumpersAndCliff & rtg_arg )
	: left( rtg_arg.left )
	, right( rtg_arg.right )
	, frontLeft( rtg_arg.frontLeft )
	, frontRight( rtg_arg.frontRight )
{
}
// }}}RME

// {{{RME tool 'OT::Cpp' property 'GenerateAssignmentOperator'
clsRoomba::clsBumpersAndCliff & clsRoomba::clsBumpersAndCliff::operator=( const clsBumpersAndCliff & rtg_arg )
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

const RTObject_class clsRoomba::RTType_clsBumpersAndCliff =
{
	(const RTObject_class *)0
  , (RTSuperAccessFunction)0
  , "clsBumpersAndCliff"
  , (RTVersionId)0
  , (RTFieldOffset)sizeof( clsBumpersAndCliff )
  , (RTInitFunction)&clsRoomba::rtg_clsBumpersAndCliff_init
  , (RTCopyFunction)&clsRoomba::rtg_clsBumpersAndCliff_copy
#if OBJECT_DECODE
  , RTstruct_decode
#endif
#if OBJECT_ENCODE
  , RTstruct_encode
#endif
  , (RTDestroyFunction)&clsRoomba::rtg_clsBumpersAndCliff_destroy
  , 4
  , clsRoomba::rtg_clsBumpersAndCliff_fields
};

void clsRoomba::rtg_clsBumpersAndCliff_init( const RTObject_class * type, clsBumpersAndCliff * target )
{
	(void)new( target ) clsBumpersAndCliff;
}

void clsRoomba::rtg_clsBumpersAndCliff_copy( const RTObject_class * type, clsBumpersAndCliff * target, const clsBumpersAndCliff * source )
{
	(void)new( target ) clsBumpersAndCliff( *source );
}

void clsRoomba::rtg_clsBumpersAndCliff_destroy( const RTObject_class * type, clsBumpersAndCliff * target )
{
	target->~clsBumpersAndCliff();
}

const RTFieldDescriptor clsRoomba::rtg_clsBumpersAndCliff_fields[] =
{
	// {{{RME classifier 'clsBumpersAndCliff' classAttribute 'left'
	{
		"left"
	  , RTOffsetOf( clsBumpersAndCliff, left )
		// {{{RME tool 'OT::CppTargetRTS' property 'TypeDescriptor'
	  , &RTType_bool
		// }}}RME
		// {{{RME tool 'OT::CppTargetRTS' property 'GenerateTypeModifier'
	  , (const RTTypeModifier *)0
		// }}}RME
	}
	// }}}RME
	// {{{RME classifier 'clsBumpersAndCliff' classAttribute 'right'
  , {
		"right"
	  , RTOffsetOf( clsBumpersAndCliff, right )
		// {{{RME tool 'OT::CppTargetRTS' property 'TypeDescriptor'
	  , &RTType_bool
		// }}}RME
		// {{{RME tool 'OT::CppTargetRTS' property 'GenerateTypeModifier'
	  , (const RTTypeModifier *)0
		// }}}RME
	}
	// }}}RME
	// {{{RME classifier 'clsBumpersAndCliff' classAttribute 'frontLeft'
  , {
		"frontLeft"
	  , RTOffsetOf( clsBumpersAndCliff, frontLeft )
		// {{{RME tool 'OT::CppTargetRTS' property 'TypeDescriptor'
	  , &RTType_bool
		// }}}RME
		// {{{RME tool 'OT::CppTargetRTS' property 'GenerateTypeModifier'
	  , (const RTTypeModifier *)0
		// }}}RME
	}
	// }}}RME
	// {{{RME classifier 'clsBumpersAndCliff' classAttribute 'frontRight'
  , {
		"frontRight"
	  , RTOffsetOf( clsBumpersAndCliff, frontRight )
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
	, cliff( rtg_arg.cliff )
	, distance( rtg_arg.distance )
	, totalDistance( rtg_arg.totalDistance )
	, angle( rtg_arg.angle )
	, totalAngle( rtg_arg.totalAngle )
	, chargingState( rtg_arg.chargingState )
	, temperature( rtg_arg.temperature )
	, battCharge( rtg_arg.battCharge )
	, battCapac( rtg_arg.battCapac )
	, oiMode( rtg_arg.oiMode )
{
}
// }}}RME

// {{{RME tool 'OT::Cpp' property 'GenerateAssignmentOperator'
clsRoomba & clsRoomba::operator=( const clsRoomba & rtg_arg )
{
	if( this != &rtg_arg )
	{
		bumpers = rtg_arg.bumpers;
		cliff = rtg_arg.cliff;
		distance = rtg_arg.distance;
		totalDistance = rtg_arg.totalDistance;
		angle = rtg_arg.angle;
		totalAngle = rtg_arg.totalAngle;
		chargingState = rtg_arg.chargingState;
		temperature = rtg_arg.temperature;
		battCharge = rtg_arg.battCharge;
		battCapac = rtg_arg.battCapac;
		oiMode = rtg_arg.oiMode;
	}
	return *this;
}
// }}}RME

// {{{RME operation 'setSensor(int,int)'
void clsRoomba::setSensor( int index, int value )
{
	// {{{USR
	switch(index){
	    case 7:
	        //Needs some translating
	        this->bumpers.left = (bool)(value & (0x02));
	        this->bumpers.right = (bool)(value & (0x01));
	        break;
	    case 9:
	        this->cliff.left = (bool)value;
	        break;
	    case 10:
	        this->cliff.frontLeft = (bool)value;
	        break;
	    case 11:
	        this->cliff.frontRight = (bool)value;
	        break;
	    case 12:
	        this->cliff.right = (bool)value;
	        break;
	    case 19:
	        //Distance resets every time you ask for it
	        this->distance = value;
	        this->totalDistance += value;
	        break;
	    case 20:
	        //Angle resets every time you ask for it
	        this->angle = value;
	        this->totalAngle += value;
	        break;
	    case 21:
	        //Sorry, i just don't know how to work with enums in Rational Rose Realtime..
	        this->chargingState = value;
	        break;
	    case 24:
	        this->temperature = value;
	        break;
	    case 25:
	        this->battCharge = value;
	        break;
	    case 26:
	        this->battCapac = value;
	        break;
	    case 35:
	        this->oiMode = value;
	        break;
	}
	// }}}USR
}
// }}}RME

// {{{RME operation 'printSensors()'
void clsRoomba::printSensors( void )
{
	// {{{USR
	cout << "RMB: Sensors:" << endl;
	cout << "\tAngle:\t\t" << this->angle << endl;
	cout << "\tbattCapac:\t" << this->battCapac << endl;
	cout << "\tbattCharge:\t" << this->battCharge << endl;
	cout << "\tchargingState:" << this->chargingState << endl;
	cout << "\tdistance:\t" << this->distance << endl;
	cout << "\toiMode:\t" << this->oiMode << endl;
	cout << "\ttemperature:\t" << this->temperature << endl;

	// }}}USR
}
// }}}RME

const RTFieldDescriptor clsRoomba::rtg_clsRoomba_fields[] =
{
	// {{{RME classAttribute 'bumpers'
	{
		"bumpers"
	  , RTOffsetOf( clsRoomba, bumpers )
		// {{{RME tool 'OT::CppTargetRTS' property 'TypeDescriptor'
	  , &clsRoomba::RTType_clsBumpersAndCliff
		// }}}RME
		// {{{RME tool 'OT::CppTargetRTS' property 'GenerateTypeModifier'
	  , (const RTTypeModifier *)0
		// }}}RME
	}
	// }}}RME
	// {{{RME classAttribute 'cliff'
  , {
		"cliff"
	  , RTOffsetOf( clsRoomba, cliff )
		// {{{RME tool 'OT::CppTargetRTS' property 'TypeDescriptor'
	  , &clsRoomba::RTType_clsBumpersAndCliff
		// }}}RME
		// {{{RME tool 'OT::CppTargetRTS' property 'GenerateTypeModifier'
	  , (const RTTypeModifier *)0
		// }}}RME
	}
	// }}}RME
	// {{{RME classAttribute 'distance'
  , {
		"distance"
	  , RTOffsetOf( clsRoomba, distance )
		// {{{RME tool 'OT::CppTargetRTS' property 'TypeDescriptor'
	  , &RTType_int
		// }}}RME
		// {{{RME tool 'OT::CppTargetRTS' property 'GenerateTypeModifier'
	  , (const RTTypeModifier *)0
		// }}}RME
	}
	// }}}RME
	// {{{RME classAttribute 'totalDistance'
  , {
		"totalDistance"
	  , RTOffsetOf( clsRoomba, totalDistance )
		// {{{RME tool 'OT::CppTargetRTS' property 'TypeDescriptor'
	  , &RTType_int
		// }}}RME
		// {{{RME tool 'OT::CppTargetRTS' property 'GenerateTypeModifier'
	  , (const RTTypeModifier *)0
		// }}}RME
	}
	// }}}RME
	// {{{RME classAttribute 'angle'
  , {
		"angle"
	  , RTOffsetOf( clsRoomba, angle )
		// {{{RME tool 'OT::CppTargetRTS' property 'TypeDescriptor'
	  , &RTType_int
		// }}}RME
		// {{{RME tool 'OT::CppTargetRTS' property 'GenerateTypeModifier'
	  , (const RTTypeModifier *)0
		// }}}RME
	}
	// }}}RME
	// {{{RME classAttribute 'totalAngle'
  , {
		"totalAngle"
	  , RTOffsetOf( clsRoomba, totalAngle )
		// {{{RME tool 'OT::CppTargetRTS' property 'TypeDescriptor'
	  , &RTType_int
		// }}}RME
		// {{{RME tool 'OT::CppTargetRTS' property 'GenerateTypeModifier'
	  , (const RTTypeModifier *)0
		// }}}RME
	}
	// }}}RME
	// {{{RME classAttribute 'chargingState'
  , {
		"chargingState"
	  , RTOffsetOf( clsRoomba, chargingState )
		// {{{RME tool 'OT::CppTargetRTS' property 'TypeDescriptor'
	  , &RTType_int
		// }}}RME
		// {{{RME tool 'OT::CppTargetRTS' property 'GenerateTypeModifier'
	  , (const RTTypeModifier *)0
		// }}}RME
	}
	// }}}RME
	// {{{RME classAttribute 'temperature'
  , {
		"temperature"
	  , RTOffsetOf( clsRoomba, temperature )
		// {{{RME tool 'OT::CppTargetRTS' property 'TypeDescriptor'
	  , &RTType_int
		// }}}RME
		// {{{RME tool 'OT::CppTargetRTS' property 'GenerateTypeModifier'
	  , (const RTTypeModifier *)0
		// }}}RME
	}
	// }}}RME
	// {{{RME classAttribute 'battCharge'
  , {
		"battCharge"
	  , RTOffsetOf( clsRoomba, battCharge )
		// {{{RME tool 'OT::CppTargetRTS' property 'TypeDescriptor'
	  , &RTType_int
		// }}}RME
		// {{{RME tool 'OT::CppTargetRTS' property 'GenerateTypeModifier'
	  , (const RTTypeModifier *)0
		// }}}RME
	}
	// }}}RME
	// {{{RME classAttribute 'battCapac'
  , {
		"battCapac"
	  , RTOffsetOf( clsRoomba, battCapac )
		// {{{RME tool 'OT::CppTargetRTS' property 'TypeDescriptor'
	  , &RTType_int
		// }}}RME
		// {{{RME tool 'OT::CppTargetRTS' property 'GenerateTypeModifier'
	  , (const RTTypeModifier *)0
		// }}}RME
	}
	// }}}RME
	// {{{RME classAttribute 'oiMode'
  , {
		"oiMode"
	  , RTOffsetOf( clsRoomba, oiMode )
		// {{{RME tool 'OT::CppTargetRTS' property 'TypeDescriptor'
	  , &RTType_int
		// }}}RME
		// {{{RME tool 'OT::CppTargetRTS' property 'GenerateTypeModifier'
	  , (const RTTypeModifier *)0
		// }}}RME
	}
	// }}}RME
};

#if OBJECT_DECODE
RTTypeInstaller rtg_clsRoomba_clsBumpersAndCliff_installer( clsRoomba::RTType_clsBumpersAndCliff );
#endif

#if OBJECT_DECODE
RTTypeInstaller rtg_clsRoomba_installer( RTType_clsRoomba );
#endif

// {{{RME tool 'OT::Cpp' property 'ImplementationEnding'
// {{{USR

// }}}USR
// }}}RME
// {{{RME classifier 'clsBumpersAndCliff' tool 'OT::Cpp' property 'ImplementationEnding'
// {{{USR

// }}}USR
// }}}RME

// }}}RME
