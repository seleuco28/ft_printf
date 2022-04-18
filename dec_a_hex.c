/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dec_a_hex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvarovelazquez <alvarovelazquez@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 12:07:19 by alvelazq          #+#    #+#             */
/*   Updated: 2022/04/18 10:02:50 by alvarovelaz      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void ft_dec_a_hex_min(int n, int fd)
{
	char *base;
	int i;

	base = "0123456789abcdef";
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

int main(void)
{
    ft_dec_a_hex_min(960, 1);
    return(0);
}