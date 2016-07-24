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

//�󶨵��˿�port���ɹ�����0��ʧ�ܷ���-1
int UDPServer::startserver(int port)
{
	serAddr.sin_family = AF_INET;
	serAddr.sin_port = htons(port);
	serAddr.sin_addr.S_un.S_addr = INADDR_ANY;
	int flag = bind(serSocket, (sockaddr *)&serAddr, sizeof(serAddr)) == SOCKET_ERROR;
	//bind����0��ʾ�ɹ�������-1��ʾʧ��
	if (flag == SOCKET_ERROR)
	{
		printf("bind error !");
		closesocket(serSocket);
		return -1;
	}
	return 0;
}


string UDPServer::reveiveData()
{
	char recvData[255];
	int ret = recvfrom(serSocket, recvData, 255, 0, (sockaddr *)&remoteAddr, &nAddrLen);
	if (ret > 0)
	{
		recvData[ret] = 0x00;
		//printf("���ܵ�һ�����ӣ�%s \r\n", inet_ntoa(remoteAddr.sin_addr));

		printf(recvData);
	}
	string s = "cace";
	return s;
}


