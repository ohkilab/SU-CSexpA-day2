#include "exp1.h"
#include "exp1lib.h"

int main(int argc, char** argv) {
	int sock_listen;
	int sock_client;
	struct sockaddr addr;
	int len = 0;
	int ret = 0;
	char buf[1024];

	sock_listen = exp1_tcp_listen(11111);
	sock_client = accept(sock_listen, &addr, (socklen_t*) &len);
	ret = recv(sock_client, buf, 1024, 0);
	write(1, buf, ret);
	close(sock_client);
	close(sock_listen);

	return 0;
}

