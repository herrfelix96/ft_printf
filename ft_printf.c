/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fharutyu <fharutyu@student.42vienna.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/02 12:43:45 by fharutyu          #+#    #+#             */
/*   Updated: 2026/02/02 12:43:49 by fharutyu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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
