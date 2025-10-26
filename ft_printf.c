#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <stdint.h>
#include "libft.h"

static void	print_address(void *ptr);

static void	fn_check_format(char format, va_list args)
{
	if (format == 'c')
		ft_putchar_fd(va_arg(args, int), 1);
	if (format == 's')
		ft_putstr_fd(va_arg(args, char *), 1);
	if (format == 'p')
		print_address(va_arg(args, void *));
	if (format == 'd')
		ft_putnbr_fd(va_arg(args, int), 1);

}

static void	print_address(void *ptr)
{
	uintptr_t	addr;
	
	addr = (uintptr_t)&ptr;
	printf("%li\n", addr);
}



//cspdiuxX%
int	ft_printf(const char *format, ...)
{
	va_list	args;
	char	*c;
	int	skip_specifier;
	//char specifiers[10] = "cspdiuxX%";
	
	va_start(args, format);
	while (*format != '\0')
	{
		skip_specifier = 0;
		if (*format == '%')
		{
			skip_specifier = 1;
			fn_check_format(format[1], args);
			format++;
		}
		if (skip_specifier != 1)
			write(1, format, 1);
		format++;
	}
	return (1);
}

int	main(void)
{
	int x = 5;
	void *ptr = &x;
	ft_printf("FELIX  %c, %s, %d, %p\n", 'C', "HELLO WORLD!", 345934, ptr);
	printf("FELIX  %c, %s, %p\n", 'C', "HELLO WORLD!", ptr);
}

