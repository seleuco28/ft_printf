/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_xX.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvarovelazquez <alvarovelazquez@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 15:14:55 by alvarovelaz       #+#    #+#             */
/*   Updated: 2022/04/23 09:38:09 by alvarovelaz      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	int	ft_len_hex(int nbr)
{
	int	leng;

	if (nbr <= 0)
		leng = 1;
	else
		leng = 0;
	while (nbr != 0)
	{
		nbr = nbr / 16;
		leng++;
	}
	return (leng);
}

int	ft_dec_a_hex(int n)
{
	char	*base;
	int		i;
	int		num_args;

	num_args = ft_len_hex(n);
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
	return (num_args);
}

int	ft_dec_a_hex_min(int n)
{
	char	*base;
	int		i;
	int		num_args;

	num_args = ft_len_hex(n);
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
	return (num_args);
}
