/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvarovelazquez <alvarovelazquez@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 09:38:07 by alvelazq          #+#    #+#             */
/*   Updated: 2022/04/22 14:15:22 by alvarovelaz      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

#include "ft_printf_xX.c"
#include "ft_printf_u.c"
#include "ft_printf_p.c"
#include "ft_printf_cs.c"
#include "ft_printf_di.c"

#include <stdlib.h>

size_t	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

int	ft_printpercent(void)
{
	write(1, "%", 1);
	return (1);
}

int	ft_printf(char const *str, ...)
{
	va_list	args;
	int		num_args;
	int		i;

	num_args = ft_strlen(str);
	va_start (args, str);
	i = 0;
	while (str[i])
	{
		if (str[i] == '%')
		{
			i++;
			if (str[i] == 's')
				ft_putstr(va_arg(args, char *));
			else if (str[i] == 'c')
				ft_putchar(va_arg(args, int));
			else if (str[i] == 'd' || str[i] == 'i')
				ft_putnbr(va_arg(args, int));
			else if (str[i] == 'p')
				ft_print_ptr(va_arg(args, unsigned long long));
			else if (str[i] == 'u')
				ft_print_unsigned(va_arg(args, unsigned int));
			else if (str[i] == 'x')
				ft_dec_a_hex_min(va_arg(args, int));
			else if (str[i] == 'X')
				ft_dec_a_hex(va_arg(args, int));
			else if (str[i] == '%')
				ft_printpercent();
			i++;
		}
		write(1, &str[i], 1);
		i++;
	}
	va_end(args);
	return (num_args);
}
