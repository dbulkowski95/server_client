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
	struct sockaddr_in serverAddres;
	int serverSocket, serverBind, serverListen;

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
	return 0;
}
