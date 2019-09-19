#include <poll.h>
#include <stdio.h>
#include <unistd.h>

int main(int argc, char *argv[]) {

	struct pollfd pfd[1];
	pfd[0].fd = 0;
	pfd[0].events = POLLIN | POLLPRI;
	pfd[0].revents = 0;
	char buff[1024];

	for(;;) {
	
		int poll_ret = poll(pfd, 1, -1);
    if(pfd[0].revents & POLLIN) {
		  size_t read_ret = read(pfd[0].fd, buff, sizeof(buff) - 1);
			if(read_ret > 0) {
				buff[read_ret] = '\0';
			}
			printf("buff = %s \n", buff);
		}
	}

}
