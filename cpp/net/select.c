#include <sys/select.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>

int main(int argc, char *argv[]) {
    fd_set rset;
    char buf[1024] = {0};
    while (1) {
        FD_ZERO(&rset);
        FD_SET(0, &rset);

        select(1, &rset, NULL, NULL, NULL);
        int ret = read(0, buf, 1023);
        if (ret <= 0) {
            printf("unkown error.\n");
            break;
        }
        buf[ret] = '\0';
        if (strcmp("exit\n", buf) == 0) {
            printf("bye\n");
            break;
        }
        printf("buf = %s\n", buf);
    }
    return 0;
}


