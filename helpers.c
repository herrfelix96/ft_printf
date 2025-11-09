#include "ft_printf.h"

int	print_recursively(uintptr_t addr)
{
	int			counter;
	int			current_return;
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

int	print_hex_address(void *address)
{
	uintptr_t	addr;
	int			counter;

	if (!address)
		return (write(1, "(nil)", 5));
	addr = (uintptr_t)address;
	counter = print_recursively(addr);
	if (counter == -1)
		return (-1);
	return (counter);
}

int	unsigned_to_hex(unsigned int num, char x)
{
	int			counter;
	int			current_return;
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

int	print_unsigned(unsigned int num)
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

int	fn_putchar(char c)
{
	if (write(1, &c, 1) == -1)
		return (-1);
	return (1);
}
