#include "ft_printf.h"

int	fail_check(int *total, int current_return)
{
	if (current_return == -1)
		return (-1);
	*total = *total + current_return;
	return (*total);
}

static int	putstr(char *s)
{
	int	counter;

	counter = 0;
	if (!s)
		s = "(null)";
	while (s[counter])
		counter++;
	if (write(1, s, counter) == -1)
		return (-1);
	return (counter);
}

static int	putnbr(int n)
{
	char	nbr;
	long	l_int;
	int		counter;

	counter = 0;
	l_int = n;
	if (n < 0)
	{
		if (fail_check(&counter, write(1, "-", 1)) == -1)
			return (-1);
		l_int = l_int * (-1);
	}
	if (l_int <= 9)
	{
		nbr = l_int + '0';
		if (fail_check(&counter, write(1, &nbr, 1)) == -1)
			return (-1);
		return (counter);
	}
	if (fail_check(&counter, putnbr(l_int / 10)) == -1)
		return (-1);
	nbr = (l_int % 10) + '0';
	if (fail_check(&counter, write(1, &nbr, 1)) == -1)
		return (-1);
	return (counter);
}

static int	fn_print_format(char format, va_list args)
{
	int	counter;
	int	current_return;

	counter = 0;
	if (format == 'c')
		current_return = fn_putchar(va_arg(args, int));
	else if (format == 's')
		current_return = putstr(va_arg(args, char *));
	else if (format == 'p')
		current_return = print_hex_address(va_arg(args, void *));
	else if (format == 'd' || format == 'i')
		current_return = putnbr(va_arg(args, int));
	else if (format == 'u')
		current_return = print_unsigned(va_arg(args, unsigned int));
	else if (format == 'x')
		current_return = unsigned_to_hex(va_arg(args, unsigned int), 'x');
	else if (format == 'X')
		current_return = unsigned_to_hex(va_arg(args, unsigned int), 'X');
	else if (format == '%')
		current_return = write(1, "%", 1);
	if (fail_check(&counter, current_return) == -1)
		return (-1);
	return (counter);
}

int	ft_printf(const char *format, ...)
{
	int		counter;
	int		current_return;
	va_list	args;

	va_start(args, format);
	counter = 0;
	while (*format != '\0')
	{
		if (*format == '%')
		{
			format++;
			if (*format == '\0')
				return (va_end(args), -1);
			current_return = fn_print_format(*format, args);
			if (fail_check(&counter, current_return) == -1)
				return (va_end(args), -1);
		}
		else
			if (fail_check(&counter, write(1, format, 1)) == -1)
				return (va_end(args), -1);
		format++;
	}
	va_end(args);
	return (counter);
}
