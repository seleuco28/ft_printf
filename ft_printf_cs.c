/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_cs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvarovelazquez <alvarovelazquez@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 15:13:16 by alvarovelaz       #+#    #+#             */
/*   Updated: 2022/05/09 17:24:18 by alvarovelaz      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr(char *s)
{
	int	c;

	c = 0;
	if (!s)
	{
		return (write(1, "(null)", 6));
	}
	while (s[c] != '\0')
	{
		ft_putchar(s[c]);
		c++;
	}
	return (c);
}
