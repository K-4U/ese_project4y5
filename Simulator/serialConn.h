#using <System.dll>
#include <iostream>

using namespace System;
using namespace System::IO::Ports;
using namespace System::Threading;

public ref class serialConn{
public:
	serialConn(String^ portName, int baudrate);
	~serialConn(void);

private:
	String^ portName;
	int baudrate;
	static SerialPort^ sPort;
	static bool connected;
};

