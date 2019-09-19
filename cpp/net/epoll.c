#include <stdio.h>
#include <unistd.h>
#include <epoll.h>

int main(int argc, char *argv[]) {
	int epoll_fd =  epoll_create(1);
	struct epoll_event event;
	event.data.fd = 0;
	event.events = EPOLLIN;
	int epoll_ctl_ret = epoll_ctl(epoll_fd, EPOLL_CTL_ADD, 0, &event);
	struct epoll_event revent[1];
	char buff[1024] = {0};
	for(;;) {
		int epoll_wait_ret = epoll_wait(epoll_fd, revent, 1, -1);
		if(revent[0].events & EPOLLIN) {
			int read_size = read(revent[0].data.fd, buff, sizeof(buff) - 1);
			buff[read_size] = '\0';
			printf("buff = %s", buff);
		}
	}

	return 0;
}
