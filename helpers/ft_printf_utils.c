/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fharutyu <fharutyu@student.42vienna.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/02 13:05:11 by fharutyu          #+#    #+#             */
/*   Updated: 2026/02/02 13:05:13 by fharutyu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	fail_check(int *total, int current_return)
{
	if (current_return == -1)
		return (-1);
	*total = *total + current_return;
	return (*total);
}

int	fn_putchar(char c)
{
	if (write(1, &c, 1) == -1)
		return (-1);
	return (1);
}

size_t	fn_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

int	fn_putstr(char *s) //Bad design, i guess.. Const char would've been better
{
	int	counter;

	counter = 0;
	if (!s)
		s = "(null)";
	counter = fn_strlen(s);
	if (write(1, s, counter) == -1)
		return (-1);
	return (counter);
}
