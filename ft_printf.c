/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvarovelazquez <alvarovelazquez@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 09:38:07 by alvelazq          #+#    #+#             */
/*   Updated: 2022/05/09 18:02:37 by alvarovelaz      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
/*
#include "ft_printf_xX.c"
#include "ft_printf_u.c"
#include "ft_printf_p.c"
#include "ft_printf_cs.c"
#include "ft_printf_di.c"
*/
#include <stdlib.h>

int	ft_printchar(int c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_printpercent(void)
{
	write(1, "%", 1);
	return (1);
}

int	ft_formats(va_list *args, char const str)
{
	int	num_args;

	num_args = 0;
	if (str == 's')
		num_args += ft_putstr(va_arg(*args, char *));
	else if (str == 'c')
		num_args += ft_printchar(va_arg(*args, int));
	else if (str == 'd' || str == 'i')
		num_args += ft_putnbr(va_arg(*args, int));
	else if (str == 'p')
		num_args += ft_print_ptr(va_arg(*args, unsigned long long));
	else if (str == 'u')
		num_args += ft_print_unsigned(va_arg(*args, unsigned int));
	else if (str == 'x')
		num_args += ft_dec_a_hex_min(va_arg(*args, int));
	else if (str == 'X')
		num_args += ft_dec_a_hex(va_arg(*args, int));
	else if (str == '%')
		num_args += ft_printpercent();
	return (num_args);
}

int	ft_printf(char const *str, ...)
{
	va_list	args;
	int		i;
	int		num_args;

	i = 0;
	num_args = 0;
	va_start (args, str);
	while (str[i])
	{
		if (str[i] == '%')
			num_args += ft_formats(&args, str[++i]);
		else
			num_args += ft_printchar(str[i]);
		i++;
	}
	va_end(args);
	return (num_args);
}
