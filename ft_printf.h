#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdint.h>
# include <unistd.h>

int			fail_check(int *total, int current_return);
int			print_recursively(uintptr_t addr);
int			print_hex_address(void *address);
int			unsigned_to_hex(unsigned int num, char x);
int			print_unsigned(unsigned int num);
int			fn_putchar(char c);
int			ft_printf(const char *format, ...);

#endif
