/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_cs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvarovelazquez <alvarovelazquez@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 15:13:16 by alvarovelaz       #+#    #+#             */
/*   Updated: 2022/04/21 17:41:39 by alvarovelaz      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "ft_printf_p.c"

void	ft_putstr_fd(char *s, int fd)
{
	int	c;

	c = 0;
	if (!s)
		return ;
	while (s[c] != '\0')
	{
		ft_putchar_fd(s[c], fd);
		c++;
	}
}
