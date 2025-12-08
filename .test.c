#include "ft_printf.h"
#include <stdio.h>

int	main()
{
	char *str = "hello!@#$";
	char c = 'h';
	int	int_min = -2147483648;
	int	int_max = 2147483647;
	int *ptr = &int_min;

	printf("My function:\n");
	int res1 = ft_printf("Printing all these~~~%c %i %p %% %s %u %d %x %X\n", c, int_min, ptr, str, int_max, int_max, int_max, int_max);
	printf("Return value: %d\n", res1);
	printf("Original function:\n");
	int res2 = printf("Printing all these~~~%c %i %p %% %s %u %d %x %X\n", c, int_min, ptr, str, int_max, int_max, int_max, int_max);
	printf("Return value: %d\n", res2);
}