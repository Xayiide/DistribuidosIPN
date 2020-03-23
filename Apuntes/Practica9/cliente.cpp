#include <sys/types.h>
#include <sys/socket.h>
#include <stdio.h>
#include <netinet/in.h>
#include <netdb.h>
#include <strings.h>   /* bzero     */
#include <arpa/inet.h> /* inet_addr */
#include <unistd.h>    /* close     */

int port = 7200;

int main() {
	struct sockaddr_in srvaddr, cltaddr;
	int s, num[2], res;
	
	s = socket(AF_INET, SOCK_DGRAM, 0);
	
	bzero( (char *) &srvaddr, sizeof(srvaddr));
	srvaddr.sin_family      = AF_INET;
	srvaddr.sin_addr.s_addr = inet_addr("127.0.0.1");
	srvaddr.sin_port        = htons(port);

	
	bzero( (char *) &cltaddr, sizeof(cltaddr));
	cltaddr.sin_family = AF_INET;
	cltaddr.sin_addr.s_addr = INADDR_ANY;
	cltaddr.sin_port = htons(0); /* Asigna uno aleatorio */

	bind(s, (struct sockaddr *) &cltaddr, sizeof(cltaddr));

	num[0] = 2;
	num[1] = 5;

	sendto(s, (char *) num, 2 * sizeof(int), 0, (struct sockaddr *) &srvaddr, sizeof(srvaddr));

	recvfrom(s, (char *) &res, sizeof(int), 0, NULL, NULL);

	printf("2 + 5 = %d\n", res);

	close(s);
}