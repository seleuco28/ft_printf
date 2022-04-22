/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvarovelazquez <alvarovelazquez@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 16:29:34 by alvarovelaz       #+#    #+#             */
/*   Updated: 2022/04/22 14:20:30 by alvarovelaz      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.c"

int main(void)
{
	//GENERAL
	ft_printf("numero %d y %i letra es %c string %s porcentaje %% \n", 24, -25, 'A', "lvaro");
    printf("numero %d y %i letra es %c string %s porcentaje %% \n", 24, -25, 'A', "lvaro");

	//NUMEROS (d e i)
	//ft_printf("numero con d: %d y numero con i: %i\n", 23, 24);
	//printf("numero con d: %d y numero con i: %i\n", 23, 24);

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
	//ft_printf("Mi número hexadecimal %x\n", 1234);
	//printf("El numero hexadecimal %x\n", 1234);

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
