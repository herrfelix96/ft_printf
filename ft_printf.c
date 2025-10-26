#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <stdint.h>
#include "libft.h"

static void	print_address(void *ptr, char x);
static void	print_recursively(uintptr_t addr, char x);

void	print_hex_address(void *address, char x)
{
	uintptr_t	addr;

	addr = (uintptr_t)address;
	print_recursively(addr, x);
}

static void	print_recursively(uintptr_t addr, char x)
{
	const char	*hex_digits;
	if (x == 'x')
		hex_digits = "0123456789abcdef";
	else if (x == 'X')
		hex_digits = "0123456789ABCDEF";

	if (addr < 16)
	{
		if (x != 'x' && x != 'X')
			write(1, "0x", 2);
		write(1, &hex_digits[addr], 1);
		return ;
	}
	print_recursively((addr / 16), x);
	write(1, &hex_digits[addr % 16], 1);
}

static void	print_unsigned(unsigned num)
{
	char	nbr;
	
	if (num <= 9)
	{
		nbr = num + '0';
		write(1, &nbr, 1);
		return ;
	}
	print_unsigned(num / 10);
	nbr = (num % 10) + '0';
	write(1, &nbr, 1);
}

static void	fn_print_format(char format, va_list args)
{
	if (format == 'c')
		ft_putchar_fd(va_arg(args, int), 1);
	if (format == 's')
		ft_putstr_fd(va_arg(args, char *), 1);
	if (format == 'p')
		print_hex_address(va_arg(args, void *), 'x');
	if (format == 'd' || format == 'i')
		ft_putnbr_fd(va_arg(args, int), 1);
	if (format == 'u')
		print_unsigned(va_arg(args, unsigned));
	if (format == 'x')
		print_hex_address(va_arg(args, void *), 'x');
	if (format == 'X')
		print_hex_address(va_arg(args, void *), 'X');
}

//cspdiuxX%
int	ft_printf(const char *format, ...)
{
	va_list	args;
	char	*c;
	int		skip_specifier;
	
	va_start(args, format);
	while (*format != '\0')
	{
		skip_specifier = 0;
		if (*format == '%')
		{
			skip_specifier = 1;
			fn_print_format(format[1], args);
			format++;
			if (*format == '%')
				write(1, format, 1);
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
	ft_printf("FELIX  %c, %s, %u, %x, TESTING %% \n", 'C', "HELLO", 429496729, 429496);
	printf("FELIX  %c, %s, %u, %x, TESTING %% \n", 'C', "HELLO", 429496729, 429496);
}

