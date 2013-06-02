// {{{RME classifier 'Logical View::Serial::byteArray'

#if defined( PRAGMA ) && ! defined( PRAGMA_IMPLEMENTED )
#pragma implementation "byteArray.h"
#endif

#include <RTSystem/roombaController.h>
#include <byteArray.h>

// {{{RME tool 'OT::Cpp' property 'ImplementationPreface'
// {{{USR

// }}}USR
// }}}RME

static void rtg_byteArray_init( const RTObject_class * type, byteArray * target )
{
	(void)new( target ) byteArray;
}

static void rtg_byteArray_copy( const RTObject_class * type, byteArray * target, const byteArray * source )
{
	(void)new( target ) byteArray( *source );
}

static void rtg_byteArray_destroy( const RTObject_class * type, byteArray * target )
{
	target->~byteArray();
}

const RTObject_class RTType_byteArray =
{
	(const RTObject_class *)0
  , (RTSuperAccessFunction)0
  , "byteArray"
  , (RTVersionId)0
  , (RTFieldOffset)sizeof( byteArray )
  , (RTInitFunction)rtg_byteArray_init
  , (RTCopyFunction)rtg_byteArray_copy
#if OBJECT_DECODE
  , RTstruct_decode
#endif
#if OBJECT_ENCODE
  , RTstruct_encode
#endif
  , (RTDestroyFunction)rtg_byteArray_destroy
  , 1
  , byteArray::rtg_byteArray_fields
};

// {{{RME tool 'OT::Cpp' property 'GenerateDefaultConstructor'
byteArray::byteArray( void )
{
}
// }}}RME

// {{{RME tool 'OT::Cpp' property 'GenerateCopyConstructor'
byteArray::byteArray( const byteArray & rtg_arg )
	: data( rtg_arg.data )
{
}
// }}}RME

// {{{RME tool 'OT::Cpp' property 'GenerateAssignmentOperator'
byteArray & byteArray::operator=( const byteArray & rtg_arg )
{
	if( this != &rtg_arg )
		data = rtg_arg.data;
	return *this;
}
// }}}RME

// {{{RME operation 'byteArray(unsigned char[],int)'
byteArray::byteArray( unsigned char chars[], int length )
	// {{{RME tool 'OT::Cpp' property 'ConstructorInitializer'
	// {{{USR

	// }}}USR
	// }}}RME
{
	// {{{USR
	int i;
	for(i=0; i<= length; i++){
	    this->data.push_back(chars[i]);
	}
	// }}}USR
}
// }}}RME

// {{{RME operation 'get(int)'
unsigned char byteArray::get( int index )
{
	// {{{USR
	if(index <= this->data.size()){
	    return this->data[index];
	}else{

	}
	// }}}USR
}
// }}}RME

// {{{RME operation 'size()'
int byteArray::size( void )
{
	// {{{USR
	return this->data.size();
	// }}}USR
}
// }}}RME

// {{{RME operation 'getAll()'
RTString byteArray::getAll( void )
{
	// {{{USR
	char data[this->data.size()];
	int i = 0;
	for(i = 0; i <= this->data.size(); i++){
	    data[i] = this->data[i];
	}

	return (RTString) data;
	// }}}USR
}
// }}}RME

// {{{RME operation 'append(unsigned char)'
void byteArray::append( unsigned char charToAdd )
{
	// {{{USR
	this->data.push_back(charToAdd);
	// }}}USR
}
// }}}RME

// {{{RME operation 'remove(int)'
void byteArray::remove( int index )
{
	// {{{USR
	this->data.erase (this->data.begin()+index);
	// }}}USR
}
// }}}RME

// {{{RME operation 'clear()'
void byteArray::clear( void )
{
	// {{{USR
	this->data.clear();
	// }}}USR
}
// }}}RME

// {{{RME operation 'print()'
void byteArray::print( void )
{
	// {{{USR
#define HEX( x ) "0x" << setw(2) << setfill('0') << hex << (int)( x )
	int i;
	for(i = 0; i < this->data.size(); i++){
	    cout << HEX(this->data[i]) << " ";
	}
	cout << endl;
	// }}}USR
}
// }}}RME

const RTFieldDescriptor byteArray::rtg_byteArray_fields[] =
{
	// {{{RME classAttribute 'data'
	{
		"data"
	  , RTOffsetOf( byteArray, data )
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
RTTypeInstaller rtg_byteArray_installer( RTType_byteArray );
#endif

// {{{RME tool 'OT::Cpp' property 'ImplementationEnding'
// {{{USR

// }}}USR
// }}}RME

// }}}RME
