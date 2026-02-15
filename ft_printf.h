/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fharutyu <fharutyu@student.42vienna.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/02 12:43:54 by fharutyu          #+#    #+#             */
/*   Updated: 2026/02/02 13:06:07 by fharutyu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <stdarg.h>
# include <stdint.h>

int		fail_check(int *total, int current_return);
int		print_hex_address(void *address);
int		print_recursively(uintptr_t addr);
int		unsigned_to_hex(unsigned int num, char x);
int		print_unsigned(unsigned int num);
int		fn_putchar(char c);
size_t	fn_strlen(const char *s);
int		fn_putstr(char *s);
int		fn_putnbr(int n);
int		fn_print_format(char format, va_list args);
int		ft_printf(const char *format, ...);

#endif
