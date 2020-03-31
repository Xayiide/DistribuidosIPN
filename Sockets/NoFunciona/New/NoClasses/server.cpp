#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <netinet/in.h>

#include <stdio.h>     /* fprintf */
#include <stdlib.h>    /* exit */
#include <string.h>    /* memset */
#include <arpa/inet.h> /* inet_addr */

#define PORT 7200

int main(void) {
	int sockfd;
	struct sockaddr_in srv, cln;
	socklen_t clnaddrsize;

	char s[INET_ADDRSTRLEN];

	int nums[2];
	int res = 0;

	/* Clear address structs */
	memset(&srv, 0, sizeof srv);
	memset(&cln, 0, sizeof cln);

	/* Configure server address */
	srv.sin_family      = AF_INET;
	srv.sin_port        = htons(PORT);
	srv.sin_addr.s_addr = inet_addr("127.0.0.1");

	clnaddrsize = sizeof cln;

	/* Create server UDP socket */
	sockfd = socket(PF_INET, SOCK_DGRAM, 0);

	/* Bind socke to server address */
	bind(sockfd, (struct sockaddr *) &srv, sizeof srv);

	inet_ntop(AF_INET, (struct sockaddr *) &srv, s, sizeof s);
	printf("Nuestra IP: %s:%d\n", s, srv.sin_port);

	while (1) {
		recvfrom(sockfd,
				 (char *) nums,
				 2 * sizeof(int),
				 0,
				 (struct sockaddr *) &cln,
				 &clnaddrsize);
		
		inet_ntop(AF_INET, (struct sockaddr *) &cln, s, sizeof s);
		printf("Conexion desde: %s:%d\n", s, cln.sin_port);
		
		res = nums[0] + nums[1];
		printf("Recibido: %d y %d. Su suma da %d\n", nums[0], nums[1], res);

		sendto(sockfd,
			   (char *) &res,
			   sizeof(int),
			   0,
			   (struct sockaddr *) &cln,
			   clnaddrsize);

	}

	return 0;
}