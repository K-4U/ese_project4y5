// {{{RME classifier 'Logical View::TCPIP::NewProtocol1'

#ifndef NewProtocol1_H
#define NewProtocol1_H

#ifdef PRAGMA
#pragma interface "NewProtocol1.h"
#endif

#include <RTSystem/ourProgram.h>

struct NewProtocol1
{
	class Base : public RTRootProtocol
	{
	public:
		inline Base( void );
		inline ~Base( void );

	protected:
		enum { rtiLast_NewProtocol1 = rtiLast_RTRootProtocol };

	public:
		static const RTProtocolDescriptor rt_class;

	private:
		static const RTSignalDescriptor rt_signals[];
	};
	class Conjugate : public RTRootProtocol
	{
	public:
		inline Conjugate( void );
		inline ~Conjugate( void );

	protected:
		enum { rtiLast_NewProtocol1 = rtiLast_RTRootProtocol };

	public:
		static const RTProtocolDescriptor rt_class;

	private:
		static const RTSignalDescriptor rt_signals[];
	};
};

inline NewProtocol1::Base::Base( void )
	: RTRootProtocol()
{
}

inline NewProtocol1::Base::~Base( void )
{
}

inline NewProtocol1::Conjugate::Conjugate( void )
	: RTRootProtocol()
{
}

inline NewProtocol1::Conjugate::~Conjugate( void )
{
}

#endif /* NewProtocol1_H */

// }}}RME
