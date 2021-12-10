#include "ft_printf.h"
#include "libft.h"
#include <limits.h>

void	print(int a, int b)
{
	printf("%d\n%d\n\n", a, b);
}

int main()
{
	int real;
	int notreal;

	not real = ft_printf("%s,%s,%s\n",NULL, "j", "Hello, World");
	real = printf("%s,%s,%s\n",NULL, "j", "Hello, World");
	print(real,notreal);

	real = ft_printf("%d,%d,%d,%d\n", INT_MAX + 1, INT_MAX, INT_MIN - 1, INT_MIN);
	notreal = printf("%d,%d,%d,%d\n", INT_MAX + 1, INT_MAX, INT_MIN - 1, INT_MIN);
	print(real,notreal);

	real = ft_printf("%X,%X,%X,%X\n", UINT_MAX + 1, UINT_MAX, INT_MIN - 1, INT_MIN);
	notreal = printf("%X,%X,%X,%X\n", UINT_MAX + 1, UINT_MAX, INT_MIN - 1, INT_MIN);
	print(real,notreal);

	real = ft_printf("%x,%x,%x,%x\n", UINT_MAX + 1, UINT_MAX, INT_MIN - 1, INT_MIN);
	notreal = printf("%x,%x,%x,%x\n", UINT_MAX + 1, UINT_MAX, INT_MIN - 1, INT_MIN);
	print(real,notreal);

	real = ft_printf("%c,%c,%c,%c\n", '-','@', '2', 'c');
	notreal = printf("%c,%c,%c,%c\n", '-','@','2','c');
	print(real,notreal);

	int a =2;
	void *p = &a;
	real = ft_printf("%p,%p\n", NULL, p);
	notreal = printf("%p,%p\n", NULL, p);
	print(real,notreal);

	real = ft_printf("%u,%u,%u,%u,%u\n", UINT_MAX + 1, UINT_MAX, INT_MIN - 1, INT_MIN, 0);
	notreal = printf("%u,%u,%u,%u,%u\n", UINT_MAX + 1, UINT_MAX, INT_MIN - 1, INT_MIN, 0);
	print(real,notreal);
}
