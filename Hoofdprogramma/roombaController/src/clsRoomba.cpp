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
// {{{RME classifier 'clsMotors' tool 'OT::Cpp' property 'ImplementationPreface'
// {{{USR

// }}}USR
// }}}RME
// {{{RME classifier 'clsButtons' tool 'OT::Cpp' property 'ImplementationPreface'
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
  , 13
  , clsRoomba::rtg_clsRoomba_fields
};

// {{{RME classifier 'clsBumpersAndCliff'

// {{{RME tool 'OT::Cpp' property 'GenerateDefaultConstructor'
clsRoomba::clsBumpersAndCliff::clsBumpersAndCliff( void )
	: left( false )
	, right( false )
	, frontLeft( false )
	, frontRight( false )
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

// {{{RME classifier 'clsMotors'

// {{{RME tool 'OT::Cpp' property 'GenerateDefaultConstructor'
clsRoomba::clsMotors::clsMotors( void )
{
}
// }}}RME

// {{{RME tool 'OT::Cpp' property 'GenerateDestructor'
clsRoomba::clsMotors::~clsMotors( void )
{
}
// }}}RME

// {{{RME tool 'OT::Cpp' property 'GenerateCopyConstructor'
clsRoomba::clsMotors::clsMotors( const clsMotors & rtg_arg )
	: mainBrush( rtg_arg.mainBrush )
	, sideBrush( rtg_arg.sideBrush )
	, vacuum( rtg_arg.vacuum )
{
}
// }}}RME

// {{{RME tool 'OT::Cpp' property 'GenerateAssignmentOperator'
clsRoomba::clsMotors & clsRoomba::clsMotors::operator=( const clsMotors & rtg_arg )
{
	if( this != &rtg_arg )
	{
		mainBrush = rtg_arg.mainBrush;
		sideBrush = rtg_arg.sideBrush;
		vacuum = rtg_arg.vacuum;
	}
	return *this;
}
// }}}RME
// }}}RME

const RTObject_class clsRoomba::RTType_clsMotors =
{
	(const RTObject_class *)0
  , (RTSuperAccessFunction)0
  , "clsMotors"
  , (RTVersionId)0
  , (RTFieldOffset)sizeof( clsMotors )
  , (RTInitFunction)&clsRoomba::rtg_clsMotors_init
  , (RTCopyFunction)&clsRoomba::rtg_clsMotors_copy
#if OBJECT_DECODE
  , RTstruct_decode
#endif
#if OBJECT_ENCODE
  , RTstruct_encode
#endif
  , (RTDestroyFunction)&clsRoomba::rtg_clsMotors_destroy
  , 3
  , clsRoomba::rtg_clsMotors_fields
};

void clsRoomba::rtg_clsMotors_init( const RTObject_class * type, clsMotors * target )
{
	(void)new( target ) clsMotors;
}

void clsRoomba::rtg_clsMotors_copy( const RTObject_class * type, clsMotors * target, const clsMotors * source )
{
	(void)new( target ) clsMotors( *source );
}

void clsRoomba::rtg_clsMotors_destroy( const RTObject_class * type, clsMotors * target )
{
	target->~clsMotors();
}

const RTFieldDescriptor clsRoomba::rtg_clsMotors_fields[] =
{
	// {{{RME classifier 'clsMotors' classAttribute 'mainBrush'
	{
		"mainBrush"
	  , RTOffsetOf( clsMotors, mainBrush )
		// {{{RME tool 'OT::CppTargetRTS' property 'TypeDescriptor'
	  , &RTType_bool
		// }}}RME
		// {{{RME tool 'OT::CppTargetRTS' property 'GenerateTypeModifier'
	  , (const RTTypeModifier *)0
		// }}}RME
	}
	// }}}RME
	// {{{RME classifier 'clsMotors' classAttribute 'sideBrush'
  , {
		"sideBrush"
	  , RTOffsetOf( clsMotors, sideBrush )
		// {{{RME tool 'OT::CppTargetRTS' property 'TypeDescriptor'
	  , &RTType_bool
		// }}}RME
		// {{{RME tool 'OT::CppTargetRTS' property 'GenerateTypeModifier'
	  , (const RTTypeModifier *)0
		// }}}RME
	}
	// }}}RME
	// {{{RME classifier 'clsMotors' classAttribute 'vacuum'
  , {
		"vacuum"
	  , RTOffsetOf( clsMotors, vacuum )
		// {{{RME tool 'OT::CppTargetRTS' property 'TypeDescriptor'
	  , &RTType_bool
		// }}}RME
		// {{{RME tool 'OT::CppTargetRTS' property 'GenerateTypeModifier'
	  , (const RTTypeModifier *)0
		// }}}RME
	}
	// }}}RME
};

// {{{RME classifier 'clsButtons'

// {{{RME tool 'OT::Cpp' property 'GenerateDefaultConstructor'
clsRoomba::clsButtons::clsButtons( void )
	: clean( false )
	, spot( false )
	, dock( false )
{
}
// }}}RME

// {{{RME tool 'OT::Cpp' property 'GenerateDestructor'
clsRoomba::clsButtons::~clsButtons( void )
{
}
// }}}RME

// {{{RME tool 'OT::Cpp' property 'GenerateCopyConstructor'
clsRoomba::clsButtons::clsButtons( const clsButtons & rtg_arg )
	: clean( rtg_arg.clean )
	, spot( rtg_arg.spot )
	, dock( rtg_arg.dock )
{
}
// }}}RME

// {{{RME tool 'OT::Cpp' property 'GenerateAssignmentOperator'
clsRoomba::clsButtons & clsRoomba::clsButtons::operator=( const clsButtons & rtg_arg )
{
	if( this != &rtg_arg )
	{
		clean = rtg_arg.clean;
		spot = rtg_arg.spot;
		dock = rtg_arg.dock;
	}
	return *this;
}
// }}}RME
// }}}RME

const RTObject_class clsRoomba::RTType_clsButtons =
{
	(const RTObject_class *)0
  , (RTSuperAccessFunction)0
  , "clsButtons"
  , (RTVersionId)0
  , (RTFieldOffset)sizeof( clsButtons )
  , (RTInitFunction)&clsRoomba::rtg_clsButtons_init
  , (RTCopyFunction)&clsRoomba::rtg_clsButtons_copy
#if OBJECT_DECODE
  , RTstruct_decode
#endif
#if OBJECT_ENCODE
  , RTstruct_encode
#endif
  , (RTDestroyFunction)&clsRoomba::rtg_clsButtons_destroy
  , 3
  , clsRoomba::rtg_clsButtons_fields
};

void clsRoomba::rtg_clsButtons_init( const RTObject_class * type, clsButtons * target )
{
	(void)new( target ) clsButtons;
}

void clsRoomba::rtg_clsButtons_copy( const RTObject_class * type, clsButtons * target, const clsButtons * source )
{
	(void)new( target ) clsButtons( *source );
}

void clsRoomba::rtg_clsButtons_destroy( const RTObject_class * type, clsButtons * target )
{
	target->~clsButtons();
}

const RTFieldDescriptor clsRoomba::rtg_clsButtons_fields[] =
{
	// {{{RME classifier 'clsButtons' classAttribute 'clean'
	{
		"clean"
	  , RTOffsetOf( clsButtons, clean )
		// {{{RME tool 'OT::CppTargetRTS' property 'TypeDescriptor'
	  , &RTType_bool
		// }}}RME
		// {{{RME tool 'OT::CppTargetRTS' property 'GenerateTypeModifier'
	  , (const RTTypeModifier *)0
		// }}}RME
	}
	// }}}RME
	// {{{RME classifier 'clsButtons' classAttribute 'spot'
  , {
		"spot"
	  , RTOffsetOf( clsButtons, spot )
		// {{{RME tool 'OT::CppTargetRTS' property 'TypeDescriptor'
	  , &RTType_bool
		// }}}RME
		// {{{RME tool 'OT::CppTargetRTS' property 'GenerateTypeModifier'
	  , (const RTTypeModifier *)0
		// }}}RME
	}
	// }}}RME
	// {{{RME classifier 'clsButtons' classAttribute 'dock'
  , {
		"dock"
	  , RTOffsetOf( clsButtons, dock )
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
	, motors( rtg_arg.motors )
	, buttons( rtg_arg.buttons )
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
		motors = rtg_arg.motors;
		buttons = rtg_arg.buttons;
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
	    case 18:
	        this->buttons.clean = (bool)(value & (0x01));
	        this->buttons.spot = (bool)(value & (0x02));
	        this->buttons.dock = (bool)(value & (0x04));
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

// {{{RME operation 'setMotors(bool,bool,bool)'
void clsRoomba::setMotors( bool mainBrush, bool sideBrush, bool vacuum )
{
	// {{{USR

	this->motors.mainBrush = mainBrush;
	this->motors.sideBrush = sideBrush;
	this->motors.vacuum = vacuum;

	std::cout << "RMB: Arg: " << mainBrush << " STOR: " << this->motors.mainBrush << endl;
	// }}}USR
}
// }}}RME

// {{{RME operation 'getMotors(bool*,bool*,bool*)'
void clsRoomba::getMotors( bool * mainBrush, bool * sideBrush, bool * vacuum )
{
	// {{{USR
	std::cout << "RMB: MAIN: " << this->motors.mainBrush << endl;
	*mainBrush = this->motors.mainBrush;
	*sideBrush = this->motors.sideBrush;
	*vacuum = this->motors.vacuum;
	// }}}USR
}
// }}}RME

// {{{RME operation 'getButtons()'
clsRoomba::clsButtons clsRoomba::getButtons( void )
{
	// {{{USR
	return this->buttons;
	// }}}USR
}
// }}}RME

// {{{RME operation 'getBumpers()'
clsRoomba::clsBumpersAndCliff clsRoomba::getBumpers( void )
{
	// {{{USR
	return this->bumpers;
	// }}}USR
}
// }}}RME

// {{{RME operation 'getSensor(int)'
int clsRoomba::getSensor( int index )
{
	// {{{USR
	switch(index){
	    case 9:
	        return (this->cliff.left?1:0);
	        break;
	    case 10:
	        return (this->cliff.frontLeft?1:0);
	        break;
	    case 11:
	        return (this->cliff.frontRight?1:0);
	        break;
	    case 12:
	        return (this->cliff.right?1:0);
	        break;
	    case 19:
	        return this->distance;
	        break;
	    case 20:
	        return this->angle;
	        break;
	    case 21:
	        //Sorry, i just don't know how to work with enums in Rational Rose Realtime..
	        return this->chargingState;
	        break;
	    case 24:
	        return this->temperature;
	        break;
	    case 25:
	        return this->battCharge;
	        break;
	    case 26:
	        return this->battCapac;
	        break;
	    case 35:
	        return this->oiMode;
	        break;
	}
	// }}}USR
}
// }}}RME

// {{{RME operation 'getAndResetTotalDistance()'
int clsRoomba::getAndResetTotalDistance( void )
{
	// {{{USR
	int d = this->totalDistance;
	this->totalDistance = 0;
	return d;
	// }}}USR
}
// }}}RME

// {{{RME operation 'getAndResetTotalAngle()'
int clsRoomba::getAndResetTotalAngle( void )
{
	// {{{USR
	int d = this->totalAngle;
	this->totalAngle = 0;
	return d;
	// }}}USR
}
// }}}RME

// {{{RME operation 'getTotalDistance()'
int clsRoomba::getTotalDistance( void )
{
	// {{{USR
	return this->totalDistance;
	// }}}USR
}
// }}}RME

// {{{RME operation 'getTotalAngle()'
int clsRoomba::getTotalAngle( void )
{
	// {{{USR
	return this->totalAngle;
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
	// {{{RME classAttribute 'motors'
  , {
		"motors"
	  , RTOffsetOf( clsRoomba, motors )
		// {{{RME tool 'OT::CppTargetRTS' property 'TypeDescriptor'
	  , &clsRoomba::RTType_clsMotors
		// }}}RME
		// {{{RME tool 'OT::CppTargetRTS' property 'GenerateTypeModifier'
	  , (const RTTypeModifier *)0
		// }}}RME
	}
	// }}}RME
	// {{{RME classAttribute 'buttons'
  , {
		"buttons"
	  , RTOffsetOf( clsRoomba, buttons )
		// {{{RME tool 'OT::CppTargetRTS' property 'TypeDescriptor'
	  , &clsRoomba::RTType_clsButtons
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
RTTypeInstaller rtg_clsRoomba_clsMotors_installer( clsRoomba::RTType_clsMotors );
#endif

#if OBJECT_DECODE
RTTypeInstaller rtg_clsRoomba_clsButtons_installer( clsRoomba::RTType_clsButtons );
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
// {{{RME classifier 'clsMotors' tool 'OT::Cpp' property 'ImplementationEnding'
// {{{USR

// }}}USR
// }}}RME
// {{{RME classifier 'clsButtons' tool 'OT::Cpp' property 'ImplementationEnding'
// {{{USR

// }}}USR
// }}}RME

// }}}RME
