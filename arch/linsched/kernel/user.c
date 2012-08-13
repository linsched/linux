#include <linux/highuid.h>
#include <linux/bug.h>
#include <linux/string.h>

int overflowuid = DEFAULT_OVERFLOWUID;
int overflowgid = DEFAULT_OVERFLOWGID;

unsigned long __clear_user(void __user *to, unsigned long n)
{
	memset(to, 0, n);
	return 0;
}

long strncpy_from_user(char *dst, const char *src, long  count)
{
	BUG();
	return strncpy(dst, src, count);
}
