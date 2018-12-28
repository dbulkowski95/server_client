#include <unistd.h>
#include <stdio.h>
#include <sys/socket.h>
#include <stdlib.h>
#include <arpa/inet.h>
#include <string.h>

#define MAX_MSG_LEN 255
#define PORT 50000
#define IP_ADDRESS "127.0.0.1"

int main(void)
{
	/*Variables for server*/
	struct sockaddr_in clientAddres;
	int clientSocket, clientConnect;
//	const char* buffer[MAX_MSG_LEN];

	/*Creating socket handler for server and check value error*/
	clientSocket = socket(AF_INET, SOCK_STREAM, 0);
	if(clientSocket == -1)
	{
		fprintf(stderr, "Socket did not create...\n");
		exit(1);
	}
	/*AF_INET - IPv4 protocol
	 * SOCK_STREAM - TCP socket*/

	/*Fill sockaddr_in struct*/
	memset(&clientAddres, 0, sizeof(clientAddres));
	clientAddres.sin_family = AF_INET;
	clientAddres.sin_addr.s_addr = inet_addr(IP_ADDRESS);
	clientAddres.sin_port = htons(PORT);
	socklen_t clientAddresLength = sizeof(clientAddres);

	clientConnect = connect(clientSocket, (struct sockaddr *)&clientAddres, clientAddresLength);
	if(clientConnect == -1)
	{
		fprintf(stderr, "Client did not connect...\n");
		exit(1);
	}

	shutdown(clientSocket, SHUT_RDWR);
	return 0;
}
