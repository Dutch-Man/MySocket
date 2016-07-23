#include <stdio.h>


#include <stdio.h>
#include <winsock2.h>
#pragma comment(lib, "ws2_32.lib") 
#include <string>
#include <iostream>
using namespace std;
class UDPServer
{
public:
	WSADATA wsaData;
	sockaddr_in serAddr;
	SOCKET serSocket;
	sockaddr_in remoteAddr;
	int nAddrLen = sizeof(remoteAddr);
public:
	UDPServer();
	int startserver(int port);
	string reveiveData();
	void test();
};