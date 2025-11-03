#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <stdint.h>
#include "libft.h"

static int	print_recursively(uintptr_t addr);

int	fail_check(int *total, int current_return)
{
	if (current_return == -1)
		return (-1);
	*total = *total + current_return;
	return (0);
}
	



static int	print_hex_address(void *address)
{
	uintptr_t	addr;
	int			counter;
	
	addr = (uintptr_t)address;
	counter = print_recursively(addr);
	if (counter == -1)
		return (-1);
	return (counter);
}

static int	print_recursively(uintptr_t addr)
{
	int			counter;
	int		current_return;
	const char	*hex_digits;

	counter = 0;	
	hex_digits = "0123456789abcdef";

	if (addr < 16)
	{
		current_return = write(1, "0x", 2);
		if (fail_check(&counter, current_return) == -1)
			return (-1);
		current_return = write(1, &hex_digits[addr], 1);
		if (fail_check(&counter, current_return) == -1)
			return (-1);
		return (counter);
	}
	current_return = print_recursively((addr / 16));
	if (fail_check(&counter, current_return) == -1)
		return (-1);
	current_return = write(1, &hex_digits[addr % 16], 1);
	if (fail_check(&counter, current_return) == -1)
			return (-1);
	return (counter);
}

static int	unsigned_to_hex(unsigned int num, char x)
{
	int			counter;
	int		current_return;
	const char	*hex_digits;

	counter = 0;
	if (x == 'x')
		hex_digits = "0123456789abcdef";
	else if (x == 'X')
		hex_digits = "0123456789ABCDEF";
	if (num < 16)
	{
		current_return = write(1, &hex_digits[num], 1);
		if (fail_check(&counter, current_return) == -1)
			return (-1);
		return (counter);
	}
	current_return = unsigned_to_hex((num / 16), x);
	if (fail_check(&counter, current_return) == -1)
		return (-1);
	current_return = write(1, &hex_digits[num % 16], 1);
	if (fail_check(&counter, current_return) == -1)
		return (-1);
	return (counter);
}

static int	print_unsigned(unsigned int num)
{
	char	nbr;
	int		counter;
	int		current_return;
	
	counter = 0;
	if (num <= 9)
	{
		nbr = num + '0';
		current_return = write(1, &nbr, 1);
		if (fail_check(&counter, current_return) == -1)
			return (-1);
		return (counter);
	}
	current_return = print_unsigned(num / 10);
	if (fail_check(&counter, current_return) == -1)
		return (-1);
	nbr = (num % 10) + '0';
	current_return = write(1, &nbr, 1);
	if (fail_check(&counter, current_return) == -1)
		return (-1);
	return (counter);
}

static int	fn_putchar(char c)
{
	if (write(1, &c, 1) == -1)
		return (-1);
	return (1);
}

static int	putstr(char *s)
{
	int	counter;

	if (!s)
		return (0);
	counter = ft_strlen(s);
	if (write(1, s, counter) == -1)
		return (-1);
	return (counter);
}

static int	char_counter(int n)
{
	int	counter;

	counter = 0;
	if (n == 0)
		return (1);
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
		counter += write(1, &nbr, 1);
		return (counter);
	}
	putnbr(l_int / 10);
	nbr = (l_int % 10) + '0';
	counter += write(1, &nbr, 1);
	return (counter);
}

static int	fn_print_format(char format, va_list args)
{
	int	char_counter;
	int	current_return;

	char_counter = 0;
	if (format == 'c')
		current_return = fn_putchar(va_arg(args, int));
	else if (format == 's')
		current_return = putstr(va_arg(args, char *));
	else if (format == 'p')
		current_return = print_hex_address(va_arg(args, void *));
	else if (format == 'd' || format == 'i')
		current_return = putnbr(va_arg(args, int));
	else if (format == 'u')
		current_return = print_unsigned(va_arg(args, unsigned));
	else if (format == 'x')
		current_return = unsigned_to_hex(va_arg(args, unsigned), 'x');
	else if (format == 'X')
		current_return = unsigned_to_hex(va_arg(args, unsigned), 'X');
	else if (format == '%')
		current_return = write(1, "%", 1);
	if (fail_check(&char_counter, current_return) == -1)
		return (-1);
	return (char_counter);
}

int	ft_printf(const char *format, ...)
{
	int		char_counter;
	int		current_return;
	
	va_list	args;
	va_start(args, format);
	char_counter = 0;
	while (*format != '\0')
	{
		if (*format == '%')
		{
			current_return = fn_print_format(format[1], args);
			if (fail_check(&char_counter, current_return) == -1)
				return (va_end(args), -1);
			format++;
		}
		else
		{
			current_return = write(1, format, 1);
			if (fail_check(&char_counter, current_return) == -1)
				return (va_end(args), -1);
		}
		format++;
	}
	va_end(args);
	return (char_counter);
}

int main(void)
{
	char *c = "FELIX";
   //unsigned int x = 665462;
    //int *p = &x;
	printf("%i", ft_printf("%%", c));
}
