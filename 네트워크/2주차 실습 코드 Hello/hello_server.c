#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>

void error_handling(char *message);

int main(int argc, char *argv[])
{
	int serv_sock; // 서버소켓 fd
	int clnt_sock; // 클라이언트 소켓 fd

	struct sockaddr_in serv_addr; // 서버 주고 구조체
	struct sockaddr_in clnt_addr; // 클라이언트 주소 구조체
	socklen_t clnt_addr_size;

	char message[] = "Hello World!";
	
	if(argc!=2){
		printf("Usage : %s <port>\n", argv[0]);
		exit(1);
	}
	
	serv_sock =. socket(PF_INET, SOCK_STREAM, 0); // 서버 소켓 생성
	if(serv_sock == -1)
		error_handling("socket() error");
	
	memset(&serv_addr, 0, sizeof(serv_addr)); // serv_addr을 0으로 초기화
	serv_addr.sin_family = AF_INET; // serv_addr.sin_familly를 IPV4로 설정
	serv_addr.sin_addr.s_addr = htonl(INADDR_ANY);// 모든 IP에 대하여 수용
	serv_addr.sin_port=htons(atoi(argv[1])); // atoi, host to network short
	
	if(bind(serv_sock, (struct sockaddr*) &serv_addr, sizeof(serv_addr))==-1 ) // 소켓에 주소 할당
		error_handling("bind() error"); 
	
	if(listen(serv_sock, 5)==-1) // 소켓 listen -> 대기큐 생성..
		error_handling("listen() error");
	
	clnt_addr_size=sizeof(clnt_addr);
	clnt_sock = accept(serv_sock, (struct sockaddr*)&clnt_addr,&clnt_addr_size); // 연결 요청 허용
	if(clnt_sock==-1)
		error_handling("accept() error");  
	
	write(clnt_sock, message, sizeof(message));
	close(clnt_sock);	
	close(serv_sock);
	return 0;
}

void error_handling(char *message)
{
	fputs(message, stderr);
	fputc('\n', stderr);
	exit(1);
}
