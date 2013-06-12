// {{{RME classifier 'Logical View::logEntry'

#if defined( PRAGMA ) && ! defined( PRAGMA_IMPLEMENTED )
#pragma implementation "logEntry.h"
#endif

#include <RTSystem/roombaController.h>
#include <logEntry.h>

// {{{RME tool 'OT::Cpp' property 'ImplementationPreface'
// {{{USR

// }}}USR
// }}}RME

static void rtg_logEntry_init( const RTObject_class * type, logEntry * target )
{
	(void)new( target ) logEntry;
}

static void rtg_logEntry_copy( const RTObject_class * type, logEntry * target, const logEntry * source )
{
	(void)new( target ) logEntry( *source );
}

static void rtg_logEntry_destroy( const RTObject_class * type, logEntry * target )
{
	target->~logEntry();
}

const RTObject_class RTType_logEntry =
{
	(const RTObject_class *)0
  , (RTSuperAccessFunction)0
  , "logEntry"
  , (RTVersionId)0
  , (RTFieldOffset)sizeof( logEntry )
  , (RTInitFunction)rtg_logEntry_init
  , (RTCopyFunction)rtg_logEntry_copy
#if OBJECT_DECODE
  , RTstruct_decode
#endif
#if OBJECT_ENCODE
  , RTstruct_encode
#endif
  , (RTDestroyFunction)rtg_logEntry_destroy
  , 2
  , logEntry::rtg_logEntry_fields
};

// {{{RME tool 'OT::Cpp' property 'GenerateDefaultConstructor'
logEntry::logEntry( void )
{
}
// }}}RME

// {{{RME tool 'OT::Cpp' property 'GenerateDestructor'
logEntry::~logEntry( void )
{
}
// }}}RME

// {{{RME tool 'OT::Cpp' property 'GenerateCopyConstructor'
logEntry::logEntry( const logEntry & rtg_arg )
	: timeOfEntry( rtg_arg.timeOfEntry )
	, entry( rtg_arg.entry )
{
}
// }}}RME

// {{{RME tool 'OT::Cpp' property 'GenerateAssignmentOperator'
logEntry & logEntry::operator=( const logEntry & rtg_arg )
{
	if( this != &rtg_arg )
	{
		timeOfEntry = rtg_arg.timeOfEntry;
		entry = rtg_arg.entry;
	}
	return *this;
}
// }}}RME

// {{{RME operation 'logEntry(std::string)'
logEntry::logEntry( std::string entry )
	// {{{RME tool 'OT::Cpp' property 'ConstructorInitializer'
	// {{{USR
	:
	timeOfEntry(time(0)),
	entry(entry)
	// }}}USR
	// }}}RME
{
	// {{{USR
	// current date/time based on current system
	//this->tm *ltm = localtime(&now);
	// }}}USR
}
// }}}RME

// {{{RME operation 'generateJson()'
Json::Value logEntry::generateJson( void )
{
	// {{{USR
	Json::Value ret;
	//Generate different timeset for easy reading and stringification
	struct tm  tstruct;
	char       buf[80];
	tstruct = *localtime(&this->timeOfEntry);
	// Visit http://www.cplusplus.com/reference/clibrary/ctime/strftime/
	// for more information about date/time format
	strftime(buf, sizeof(buf), "%Y-%m-%d.%X", &tstruct);


	ret["Time"] = buf;
	ret["Entry"] = this->entry;

	return ret;
	// }}}USR
}
// }}}RME

const RTFieldDescriptor logEntry::rtg_logEntry_fields[] =
{
	// {{{RME classAttribute 'timeOfEntry'
	{
		"timeOfEntry"
	  , RTOffsetOf( logEntry, timeOfEntry )
		// {{{RME tool 'OT::CppTargetRTS' property 'TypeDescriptor'
	  , (const RTObject_class *)0
		// }}}RME
		// {{{RME tool 'OT::CppTargetRTS' property 'GenerateTypeModifier'
	  , (const RTTypeModifier *)0
		// }}}RME
	}
	// }}}RME
	// {{{RME classAttribute 'entry'
  , {
		"entry"
	  , RTOffsetOf( logEntry, entry )
		// {{{RME tool 'OT::CppTargetRTS' property 'TypeDescriptor'
	  , (const RTObject_class *)0
		// }}}RME
		// {{{RME tool 'OT::CppTargetRTS' property 'GenerateTypeModifier'
	  , (const RTTypeModifier *)0
		// }}}RME
	}
	// }}}RME
};

#if OBJECT_DECODE
RTTypeInstaller rtg_logEntry_installer( RTType_logEntry );
#endif

// {{{RME tool 'OT::Cpp' property 'ImplementationEnding'
// {{{USR

// }}}USR
// }}}RME

// }}}RME
