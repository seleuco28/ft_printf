/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvarovelazquez <alvarovelazquez@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 09:38:07 by alvelazq          #+#    #+#             */
/*   Updated: 2022/04/21 16:58:37 by alvarovelaz      ###   ########.fr       */
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

int ft_printf(char const *str, ...)
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
				ft_putstr_fd(va_arg(args, char *), 1);
			else if (str[i] == 'c')
				ft_putchar_fd(va_arg(args, int), 1);
			else if (str[i] == 'd' || str[i] == 'i')
				ft_putnbr_fd(va_arg(args, int), 1);
			else if (str[i] == 'p')
				ft_print_ptr(va_arg(args, unsigned long long));
			else if (str[i] == 'u')
				ft_print_unsigned(va_arg(args, unsigned int));
			else if (str[i] == 'x')
				ft_dec_a_hex_min(va_arg(args, int), 1);
			else if (str[i] == 'X')
				ft_dec_a_hex(va_arg(args, int), 1);
			else if (str[i] == '%')
				write(1, "%%", 1);
			i++;
		}
		write(1, &str[i], 1);
		i++;
	}
	va_end(args);
	return (0);
}

/*
int main(void)
{
	//GENERAL
	//ft_printf("numero %d y %i letra es %c string %s porcentaje %% \n", 24, -25, 'A', "lvaro");

	//NUMEROS (d e i)
	ft_printf("numero con d: %d y numero con i: %i\n", 23, 24);
	printf("numero con d: %d y numero con i: %i\n", 23, 24);

	//PORCENTAJE
	//ft_printf("el simbolo de porcentaje es: %%\n");
	//printf("el simbolo de porcentaje es: %%\n");

	//STRING
	//ft_printf("mi string es:  %s\n" , "kaixo egun on");
	//printf("mi string es:  %s\n", "kaixo egun on");

	//CARACTER
	//ft_printf("mi caracter es %c\n", 'h');
	//printf("el caracter es: %c\n", 'h');

	//HEXADECIMALES
	//ft_printf("%x\n", 1234);
	//printf("Mi numero hexadecimal %x\n", 1234);

	//PUNTEROS
	//int x = 999;
	//int *pt1;
	//pt1 = &x;
	//ft_printf("Mi dirección del puntero %p\n", pt1);
	//printf("La dirección del puntero %p\n", pt1);

	//UNSIGNED
	//ft_printf("%u\n", -22);
	//printf("%u\n", -22);
    return (0);
}
*/
