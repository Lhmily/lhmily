#include <stdio.h>
#include "select_test.h"
#include <sys/select.h>

int main(int argc, char *argv[]) {
	printf("__FDBITS_TEST = %d\n", __NFDBITS_TEST);
	printf("__FD_ELT_TEST(3) = %d\n", __FD_ELT_TEST(3));
	printf("__FD_MASK_TEST(3) = %d\n", __FD_MASK_TEST(3));
	printf("sizeof(fd_set_test) = %d\n", sizeof(fd_set_test));
	fd_set_test rset;
	printf("original rset = %d\n", __FDS_BITS_TEST(&rset));
	FD_CLR_TEST(3, &rset);
	printf("FD_CLRfd = %d\n", __FDS_BITS_TEST(&rset));
	
	return 0;
}
