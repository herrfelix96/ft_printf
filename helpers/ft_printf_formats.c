/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_formats.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fharutyu <fharutyu@student.42vienna.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/02 13:04:43 by fharutyu          #+#    #+#             */
/*   Updated: 2026/02/02 13:04:46 by fharutyu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	fn_print_format(char format, va_list args)
{
	int	counter;
	int	current_return;

	current_return = 0;
	counter = 0;
	if (format == 'c')
		current_return = fn_putchar(va_arg(args, int));
	else if (format == 's')
		current_return = fn_putstr(va_arg(args, char *));
	else if (format == 'p')
		current_return = print_hex_address(va_arg(args, void *));
	else if (format == 'd' || format == 'i')
		current_return = fn_putnbr(va_arg(args, int));
	else if (format == 'u')
		current_return = print_unsigned(va_arg(args, unsigned int));
	else if (format == 'x')
		current_return = unsigned_to_hex(va_arg(args, unsigned int), 'x');
	else if (format == 'X')
		current_return = unsigned_to_hex(va_arg(args, unsigned int), 'X');
	else if (format == '%')
		current_return = write(1, "%", 1);
	if (fail_check(&counter, current_return) == -1) //Checks if any of the previous calls returned -1
		return (-1);
	return (counter);
}
