#include <winsock.h>
#include <Windows.h>
#include <stdio.h>
#pragma comment (lib, "ws2_32.lib")

int changeTOip(void)  //호스트를 IP주소로 바꿔주는 함수
{
	WSADATA wsaData = { 0, };
	struct in_addr addr = { 0, };
	struct hostent * res;
	int i = 0;
	
	WSAStartup(MAKEWORD(2, 2), &wsaData);

	res = gethostbyname("ec2-13-58-62-28.us-east-2.compute.amazonaws.com"); //학생 이름을 받아 hostent 구조체에 넣음
	while (res->h_addr_list[i] != 0)  //널이아닐때까지 돌며 res의 구조체 정보를 출력해줌
	{
		addr.s_addr = *(u_long *)res->h_addr_list[i++];
		printf("원격지 아마존 서버의 ec2 인스턴스를 통한 mysql 접속 학생관리 프로그램\n");  
		printf("서버의 호스트 이름 :\tec2-13-58-62-28.us-east-2.compute.amazonaws.com\n");
		printf("원격지 서버의 IP Address: %s\n", inet_ntoa(addr));

	}

	WSACleanup();
}
