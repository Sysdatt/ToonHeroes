#include <winsock.h>
#include <Windows.h>
#include <stdio.h>
#pragma comment (lib, "ws2_32.lib")

int changeTOip(void)  //ȣ��Ʈ�� IP�ּҷ� �ٲ��ִ� �Լ�
{
	WSADATA wsaData = { 0, };
	struct in_addr addr = { 0, };
	struct hostent * res;
	int i = 0;
	
	WSAStartup(MAKEWORD(2, 2), &wsaData);

	res = gethostbyname("ec2-13-58-62-28.us-east-2.compute.amazonaws.com"); //�л� �̸��� �޾� hostent ����ü�� ����
	while (res->h_addr_list[i] != 0)  //���̾ƴҶ����� ���� res�� ����ü ������ �������
	{
		addr.s_addr = *(u_long *)res->h_addr_list[i++];
		printf("������ �Ƹ��� ������ ec2 �ν��Ͻ��� ���� mysql ���� �л����� ���α׷�\n");  
		printf("������ ȣ��Ʈ �̸� :\tec2-13-58-62-28.us-east-2.compute.amazonaws.com\n");
		printf("������ ������ IP Address: %s\n", inet_ntoa(addr));

	}

	WSACleanup();
}
