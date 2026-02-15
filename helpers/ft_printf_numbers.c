/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_numbers.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fharutyu <fharutyu@student.42vienna.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/02 13:05:05 by fharutyu          #+#    #+#             */
/*   Updated: 2026/02/02 13:05:07 by fharutyu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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

int	fn_putnbr(int n)
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
	if (fail_check(&counter, fn_putnbr(l_int / 10)) == -1)
		return (-1);
	nbr = (l_int % 10) + '0';
	if (fail_check(&counter, write(1, &nbr, 1)) == -1)
		return (-1);
	return (counter);
}
