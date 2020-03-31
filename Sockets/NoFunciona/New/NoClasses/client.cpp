#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <netinet/in.h>

#include <stdio.h>     /* fprintf */
#include <stdlib.h>    /* exit */
#include <string.h>    /* memset */
#include <arpa/inet.h> /* inet_addr */

#define PORT 7200

int main(int argc, char *argv[]) {
	int sockfd;
	struct sockaddr_in srv, cln;
	socklen_t srvaddrsize;

	int nums[2] = {10, 15};
	int res     = 0;
	char s[INET_ADDRSTRLEN];


	/* Clear address structs */
	memset(&srv, 0, sizeof srv);
	memset(&cln, 0, sizeof cln);

	/* Configure server address */
	srv.sin_family      = AF_INET;
	srv.sin_port        = htons(PORT); /* Server is listening on port 7200 */
	srv.sin_addr.s_addr = inet_addr("127.0.0.1");

	srvaddrsize = sizeof srv;



	/* Configure client address  */
	cln.sin_family      = AF_INET;
	cln.sin_port        = htons(0);
	srv.sin_addr.s_addr = inet_addr("127.0.0.1"); /* Client's IP is localhost */

	/* Create client UDP socket */
	sockfd = socket(PF_INET, SOCK_DGRAM, 0);

	/* Bind socket to the client address */
	bind(sockfd, (struct sockaddr *) &cln, sizeof cln);

	inet_ntop(AF_INET, (struct sockaddr *) &cln, s, sizeof s);
	printf("Nuestra IP: %s:%d\n", s, cln.sin_port);
	printf("Su IP: %s:%d\n", argv[1], PORT);

	/* Send both numbers */
	sendto(sockfd,
		   (char *) nums,
		   2 * sizeof(int),
		   0,
		   (struct sockaddr *) &srv,
		   srvaddrsize);
	
	/* Receive answer */
	recvfrom(sockfd, 
			 (char *) &res,
			 sizeof(int),
			 0,
			 (struct sockaddr *) &srv,
			 &srvaddrsize);

	printf("%d + %d = %d\n", nums[0], nums[1], res);

	return 0;
}
