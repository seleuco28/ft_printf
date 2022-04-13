/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dec_a_hex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvelazq <alvelazq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 12:07:19 by alvelazq          #+#    #+#             */
/*   Updated: 2022/04/12 13:46:31 by alvelazq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

static	int	ft_len(int nbr)
{
	int	leng;

	if (nbr <= 0)
		leng = 1;
	else
		leng = 0;
	while (nbr != 0)
	{
		nbr = nbr / 10;
		leng++;
	}
	return (leng);
}

char *ft_hex(int numero)
{
    int j;
    int resto;
    char *espacio;

    len = ft_len(numero);
    espacio = malloc(sizeof(char) * len + 1);
    j = 0;
    while (numero != 0)
    {
        resto = numero % 16;
        if (resto < 10)
        {
            espacio[j++] = 48 + resto;
        }
        else
        {
            espacio[j++] = 55 + resto;
        }
        numero = numero / 16;
    }

    return(espacio);
}

int main(void)
{
    ft_hex(960);
    return (0);
}