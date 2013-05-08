// {{{RME classifier 'Logical View::SerialProtocol'

#ifndef SerialProtocol_H
#define SerialProtocol_H

#ifdef PRAGMA
#pragma interface "SerialProtocol.h"
#endif

#include <RTSystem/Program.h>

struct SerialProtocol
{
	class Base : public RTRootProtocol
	{
	public:
		inline Base( void );
		inline ~Base( void );

	protected:
		enum { rtiLast_SerialProtocol = rtiLast_RTRootProtocol };

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
		enum { rtiLast_SerialProtocol = rtiLast_RTRootProtocol };

	public:
		static const RTProtocolDescriptor rt_class;

	private:
		static const RTSignalDescriptor rt_signals[];
	};
};

inline SerialProtocol::Base::Base( void )
	: RTRootProtocol()
{
}

inline SerialProtocol::Base::~Base( void )
{
}

inline SerialProtocol::Conjugate::Conjugate( void )
	: RTRootProtocol()
{
}

inline SerialProtocol::Conjugate::~Conjugate( void )
{
}

#endif /* SerialProtocol_H */

// }}}RME
