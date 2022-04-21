/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_xX.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvarovelazquez <alvarovelazquez@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 15:14:55 by alvarovelaz       #+#    #+#             */
/*   Updated: 2022/04/21 15:37:38 by alvarovelaz      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void ft_dec_a_hex(int n, int fd)
{
	char *base;
	int i;

	base = "0123456789ABCDEF";
	if (n > 16)
	{
		ft_dec_a_hex(n / 16 , fd);
		n = (n % 16);
	}
	if (n <= 16)
	{
		i = 0;
		while (i < n)
			i++;
		write (fd, &base[i], 1);
	}
}

void ft_dec_a_hex_min(int n, int fd)
{
	char *base;
	int i;

	base = "0123456789abcdef";
	if (n > 16)
	{
		ft_dec_a_hex_min(n / 16 , fd);
		n = (n % 16);
	}
	if (n <= 16)
	{
		i = 0;
		while (i < n)
			i++;
		write (fd, &base[i], 1);
	}
}
