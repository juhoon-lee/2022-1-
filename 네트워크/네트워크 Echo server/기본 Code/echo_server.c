#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>

#define BUF_SIZE 1024
void error_handling(char *message);

int main(int argc, char *argv[])
{
	int serv_sock, clnt_sock;
	char message[BUF_SIZE];
	int str_len, i;
	
	struct sockaddr_in serv_adr;
	struct sockaddr_in clnt_adr;
	socklen_t clnt_adr_sz;
	
	if(argc!=2) {
		printf("Usage : %s <port>\n", argv[0]);
		exit(1);
	}
	
	serv_sock=socket(PF_INET, SOCK_STREAM, 0);   
	if(serv_sock==-1)
		error_handling("socket() error");
	
	memset(&serv_adr, 0, sizeof(serv_adr));
	serv_adr.sin_family=AF_INET;
	serv_adr.sin_addr.s_addr=htonl(INADDR_ANY);
	serv_adr.sin_port=htons(atoi(argv[1]));

	if(bind(serv_sock, (struct sockaddr*)&serv_adr, sizeof(serv_adr))==-1)
		error_handling("bind() error");
	
	if(listen(serv_sock, 5)==-1)
		error_handling("listen() error");
	
	clnt_adr_sz=sizeof(clnt_adr);

	for(i=0; i<5; i++)
	{
		clnt_sock=accept(serv_sock, (struct sockaddr*)&clnt_adr, &clnt_adr_sz);
        
        // 수정한 부분
        // -----------------------------------------------------------------
        char clientIPString[20]; // IP를 보기 쉽게 변환하고 담을 문자열
        char* clientIPPointer = inet_ntoa(clnt_adr.sin_addr); // IP주소를 문자로 변환(clnt_adr.sin_addr에 클라이언트의 IP주소가 있습니다.)
        strcpy(clientIPString,clientIPPointer); // ClientIPPointer -> ClientIPString
        
        unsigned short clientPort = ntohs(clnt_adr.sin_port); // Port 번호(clnt_adr.sin_port에 클라이언트의 포트 번호가 있습니다.)
        
		if(clnt_sock==-1)
			error_handling("accept() error");
		else
            printf("Client's IP : %s \n", clientIPString); // IP 출력(보기 쉽게 변환된 ClientIPString을 출력합니다.)
            printf("Client's Port : %u \n", clientPort); // Port 출력(10진수로 출력합니다.)
			printf("Connected client %d \n", i+1);
        // -----------------------------------------------------------------
		while((str_len=read(clnt_sock, message, BUF_SIZE))!=0)
			write(clnt_sock, message, str_len);

		close(clnt_sock);
	}

	close(serv_sock);
	return 0;
}

void error_handling(char *message)
{
	fputs(message, stderr);
	fputc('\n', stderr);
	exit(1);
}
