#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <stdint.h>
#include "libft.h"

static int	print_address(void *ptr);
static int	print_recursively(uintptr_t addr);

static int	print_hex_address(void *address)
{
	uintptr_t	addr;
	int			counter;
	
	addr = (uintptr_t)address;
	counter = print_recursively(addr);
	return (counter);
}

static int	print_recursively(uintptr_t addr)
{
	int			counter;
	const char	*hex_digits;

	counter = 0;	
	hex_digits = "0123456789abcdef";

	if (addr < 16)
	{
		counter += write(1, "0x", 2);
		counter += write(1, &hex_digits[addr], 1);
		return (counter);
	}
	counter += print_recursively((addr / 16));
	write(1, &hex_digits[addr % 16], 1);
	counter++;
	return (counter);
}

static int	unsigned_to_hex(unsigned int num, char x)
{
	int			counter;
	const char	*hex_digits;

	counter = 0;
	if (x == 'x')
		hex_digits = "0123456789abcdef";
	else if (x == 'X')
		hex_digits = "0123456789ABCDEF";
	if (num < 16)
	{
		counter += write(1, &hex_digits[num], 1);
		return (counter);
	}
	counter += unsigned_to_hex((num / 16), x);
	write(1, &hex_digits[num % 16], 1);
	counter++;
	return (counter);
}

static int	print_unsigned(unsigned int num)
{
	char	nbr;
	int		counter;
	
	counter = 0;
	if (num <= 9)
	{
		nbr = num + '0';
		counter += write(1, &nbr, 1);
		return (counter);
	}
	counter += print_unsigned(num / 10);
	nbr = (num % 10) + '0';
	counter += write(1, &nbr, 1);
	return (counter);
}

static int	fn_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

static int	putstr(char *s)
{
	int	len;

	if (!s)
		return (0);
	len = ft_strlen(s);
	write(1, s, len);
	return (len);
}

static int	char_counter(int n)
{
	int	counter;

	counter = 0;
	while (n != 0)
	{
		n = n / 10;
		counter++;
	}
	return (counter);
}

static int	putnbr(int n)
{
	char	nbr;
	long	l_int;
	int		counter;

	l_int = n;
	counter = char_counter(n);
	if (n < 0)
	{
		counter += write(1, "-", 1);
		l_int = l_int * (-1);
	}
	if (l_int <= 9)
	{
		nbr = l_int + '0';
		write(1, &nbr, 1);
		return (counter);
	}
	putnbr(l_int / 10);
	nbr = (l_int % 10) + '0';
	write(1, &nbr, 1);
	return (counter);
}

static int	fn_print_format(char format, va_list args)
{
	int	char_counter;

	char_counter = 0;
	if (format == 'c')
		char_counter += fn_putchar(va_arg(args, int));
	if (format == 's')
		char_counter += putstr(va_arg(args, char *));
	if (format == 'p')
		char_counter += print_hex_address(va_arg(args, void *));
	if (format == 'd' || format == 'i')
		char_counter += putnbr(va_arg(args, int));
	if (format == 'u')
		char_counter += print_unsigned(va_arg(args, unsigned));
	if (format == 'x')
		char_counter += unsigned_to_hex(va_arg(args, unsigned), 'x');
	if (format == 'X')
		char_counter += unsigned_to_hex(va_arg(args, unsigned), 'X');
	return (char_counter);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	char	*c;
	int		skip_specifier;
	int		char_counter;
	
	va_start(args, format);
	char_counter = 0;
	while (*format != '\0')
	{
		skip_specifier = 0;
		if (*format == '%')
		{
			skip_specifier = 1;
			char_counter += fn_print_format(format[1], args);
			format++;
			if (*format == '%')
				char_counter += write(1, format, 1);
		}
		if (skip_specifier != 1)
			char_counter += write(1, format, 1);
		format++;
	}
	return (char_counter);
}

int main(void)
{
    int x = 42;
	printf("%i", ft_printf("%x\n", 123456));
}
