#include "UDPServer.h"



//#include "UDPServer.h"

UDPServer::UDPServer()
{
	WORD sockVersion = MAKEWORD(2, 2);
	if (WSAStartup(sockVersion, &wsaData) != 0)
	{
		return;
	}
	serSocket = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);
	if (serSocket == INVALID_SOCKET)
	{
		printf("socket error !");
		return;
	}
}

//绑定到端口port，成功返回0，失败返回-1
int UDPServer::startserver(int port)
{
	printf("监听\n");
	serAddr.sin_family = AF_INET;
	serAddr.sin_port = htons(port);
	serAddr.sin_addr.S_un.S_addr = INADDR_ANY;
	int flag = bind(serSocket, (sockaddr *)&serAddr, sizeof(serAddr)) == SOCKET_ERROR;
	//bind返回0表示成功，返回-1表示失败
	if (flag == SOCKET_ERROR)
	{
		printf("bind error !");
		closesocket(serSocket);
		return -1;
	}
	printf("监听\n");
	return 0;
}


string UDPServer::reveiveData()
{
	char recvData[255];
	printf("接受到一个连接：\n");
	cout << "接受到一个连接：\n";
	int ret = recvfrom(serSocket, recvData, 255, 0, (sockaddr *)&remoteAddr, &nAddrLen);
	if (ret > 0)
	{
		recvData[ret] = 0x00;
		//printf("接受到一个连接：%s \r\n", inet_ntoa(remoteAddr.sin_addr));

		printf(recvData);
	}
	string s = "cace";
	return s;
}

void UDPServer::test()
{

	printf("测试：\n\n");

}


