#include <stdio.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define RCVBUFFSIZE 10240

int main(int argc, char *argv[]){
	int sock;
	struct sockaddr_in serverAddr;
	unsigned short serverPort;
	char *servIP;
	char *message;
	char responseBuffer[RCVBUFFSIZE];
	unsigned int messageLen;
	int bytesRcv, totalByresRvb;
	
	if( (argc < 2) || (argc > 3) ){
		fprintf(stderr, "Usage: %s <NameServer> <Port>\n", argv[0]);
		exit(1);
	}

	servIP = argv[1];
	serverPort = atoi(argv[2]);

	if ( (sock = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP)) < 0 )
		DieWithError("socket() failed");

	memset(&serverAddr, 0, sizeof(serverAddr));
	serverAddr.sin_family = AF_INET;
	serverAddr.sin_addr.s_addr = inet_addr(servIP);
	serverAddr.sin_port = htons(serverPort);
	
	if( connect(sock, (struct sockaddr *) &serverAddr, sizeof(serverAddr)) < 0 )
		DieWithError("connect() failed");

	//TODO Terminar de enviar el mensaje al servidor (ya con el protocolo) y recibir la respuesta

	return 0;
}

void DieWithError(char *errorMessage){ 
	perror(errorMessage);
	exit(1);
}
