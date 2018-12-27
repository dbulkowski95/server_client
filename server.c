#include <unistd.h>
#include <stdio.h>
#include <sys/socket.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <string.h>

#define MAX_AMOUNT_OF_CONNECTION 10
#define MAX_MSG_LEN 1000

int main(void)
{
	/*Variables for server*/
	struct sockaddr_in serverAddres, clientAddres;
	int serverSocket, serverBind, serverListen;
	const char* buffer[255];
	/*Creating socket handler for server and check value error*/
	serverSocket = socket(AF_INET, SOCK_STREAM, 0);
	if(serverSocket == -1)
	{
		fprintf(stderr, "Socket did not create...\n");
		exit(1);
	}
	/*AF_INET - IPv4 protocol
	 * SOCK_STREAM - TCP socket*/

	/*Fill sockaddr_in struct*/
	const uint16_t port = 50000;
	serverAddres.sin_addr.s_addr = INADDR_ANY;
	serverAddres.sin_port = htons(port);
	serverAddres.sin_family = AF_INET;
	socklen_t serverAddresLength = sizeof(serverAddres);

	/*Bind socket to local address*/
	serverBind = bind(serverSocket, (struct sockaddr *)&serverAddres, serverAddresLength);
	if(serverBind == -1)
	{
		fprintf(stderr, "Socket did not bind...\n");
		exit(1);
	}
	/*Socket listen for server to 128*/
	serverListen = listen(serverSocket, SOMAXCONN);
	if(serverListen == -1)
	{
		fprintf(stderr, "Socket listen error...\n");
		exit(1);
	}
	socklen_t clientAddresLength = sizeof(clientAddres);
	do
	{
		int acceptConnection = accept(serverSocket, (struct sockaddr *)&clientAddres, &clientAddresLength);
		if(acceptConnection == -1)
		{
			fprintf(stderr, "Accept failed...\n");
		}
		else
		{
			memset(buffer, 0, sizeof(buffer));

		}
	}
	while(1);

	shutdown(serverSocket, SHUT_RDWR);
	return 0;
}
