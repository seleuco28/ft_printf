/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_cs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvarovelazquez <alvarovelazquez@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 15:13:16 by alvarovelaz       #+#    #+#             */
/*   Updated: 2022/04/23 18:06:21 by alvarovelaz      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr(char *s)
{
	int	c;

	c = 0;
	if (!s)
	{
		write(1, "(null)", 6);
		return (6);
	}
	while (s[c] != '\0')
	{
		ft_putchar(s[c]);
		c++;
	}
	return (c);
}
