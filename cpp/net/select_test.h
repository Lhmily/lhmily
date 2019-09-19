#ifndef NET_SELECT_TEST_H
#define NET_SELECT_TEST_H
typedef long int __fd_mask_test;

#undef __NFDBITS_TEST
#define __NFDBITS_TEST (8 * (int) sizeof(__fd_mask_test))
#define __FD_ELT_TEST(d) ((d) / __NFDBITS_TEST)
#define __FD_MASK_TEST(d) ((__fd_mask_test) (1UL << ((d) % __NFDBITS_TEST)))
#define __FD_SETSIZE_TEST 1024

typedef struct {
	__fd_mask_test fds_bits[__FD_SETSIZE_TEST /__NFDBITS_TEST];
#define __FDS_BITS_TEST(set) ((set)->fds_bits)
} fd_set_test;

#define NFDBITS_TEST __NFDBITS_TEST

#define FD_SET_TEST(d, s) \
	((void) (__FDS_BITS_TEST(s)[__FD_ELT_TEST(d)] |= __FD_MASK_TEST(d)))
#define FD_CLR_TEST(d, s) \
	((void) (__FDS_BITS_TEST(s)[__FD_ELT_TEST(d)] &= ~__FD_MASK_TEST(d)))

#endif
