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
	int num[2];
	int s, res;
	socklen_t clilen;

	struct sockaddr_in srvaddr, cltaddr;

	s = socket(AF_INET, SOCK_DGRAM, 0);

	bzero( (char *) &srvaddr, sizeof(srvaddr));
	srvaddr.sin_family      = AF_INET;
	srvaddr.sin_addr.s_addr = INADDR_ANY;
	srvaddr.sin_port        = htons(port);

	bind(s, (struct sockaddr *) &srvaddr, sizeof(srvaddr));
	clilen = sizeof(cltaddr);

	while(1) {
		recvfrom(s, (char *) num, 2 * sizeof(int), 0, (struct sockaddr *) &cltaddr, &clilen);

		res = num[0] + num[1];

		sendto(s, (char *) &res, sizeof(int), 0, (struct sockaddr *) &cltaddr, clilen);
	}
}