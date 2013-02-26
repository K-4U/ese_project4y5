#include "stdafx.h"
#include "serialConn.h"

using namespace std;

serialConn::serialConn(String^ portName, int baudrate)
	:portName(portName)
	,baudrate(baudrate)
{
	sPort = gcnew SerialPort();
	sPort->PortName = this->portName;
	sPort->BaudRate = this->baudrate;
	cout << "Serial port initialized" << endl;
}


serialConn::~serialConn(void){

}
