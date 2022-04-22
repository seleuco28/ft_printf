/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_xX.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvarovelazquez <alvarovelazquez@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 15:14:55 by alvarovelaz       #+#    #+#             */
/*   Updated: 2022/04/22 18:57:36 by alvarovelaz      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_dec_a_hex(int n)
{
	char	*base;
	int		i;

	base = "0123456789ABCDEF";
	i = 0;
	if (n > 16)
	{
		ft_dec_a_hex(n / 16);
		n = (n % 16);
	}
	if (n <= 16)
	{
		while (i < n)
			i++;
		write (1, &base[i], 1);
	}
	return (i);
}

int	ft_dec_a_hex_min(int n)
{
	char	*base;
	int		i;

	base = "0123456789abcdef";
	i = 0;
	if (n > 16)
	{
		ft_dec_a_hex_min(n / 16);
		n = (n % 16);
	}
	if (n <= 16)
	{
		while (i < n)
			i++;
		write (1, &base[i], 1);
	}
	return (i);
}
