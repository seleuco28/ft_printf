/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvarovelazquez <alvarovelazquez@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 16:29:34 by alvarovelaz       #+#    #+#             */
/*   Updated: 2022/05/10 15:32:58 by alvarovelaz      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.c"

int main(void)
{
	//General con el fallo enconctrado
	//ft_printf("cspiduxX%\n"); // aqui si da fallo no salta el \n
	//printf("cspiduxX%\n");

	ft_printf("cspiduxX%ñ\n"); // aqui te tiene que printar la ñ y hacer el salto de linea
	printf("cspiduxX%ñ\n");

	//GENERAL
	//ft_printf("numero %d y %i letra es %c string %s porcentaje %% \n", 24, -25, 'A', "lvaro");
    //printf("numero %d y %i letra es %c string %s porcentaje %% \n", 24, -25, 'A', "lvaro");

	//CHAR
	/*
	int prueba;
	int original;
	prueba = ft_printf("el char es: %c, y el otro es %c\n", 'A', 'L');
	original = printf("el char es: %c, y el otro es %c\n", 'A', 'L');
	printf("%d\n", prueba);
	printf("%d\n", original);
	*/
	//STRING nulo
	/*
	int prueba;
	int original;
	prueba = ft_printf(" NULL %s\n", NULL);
	original = printf(" NULL %s\n", NULL);
	printf("%d\n", prueba);
	printf("%d\n", original);
	*/
	//NUMEROS (d e i)
	/*
	int prueba;
	int original;
	prueba = ft_printf("numero con d: %d y numero con i: %i\n", -23, -24);
	original = printf("numero con d: %d y numero con i: %i\n", -23, -24);
	printf("%d\n", prueba);
	printf("%d\n", original);
	*/
	//PORCENTAJE
	/*
	ft_printf("%%\n");
	printf("%%\n");
	*/
	//STRING
	/*
	int prueba;
	int original;
	prueba = ft_printf("mi string es:  %s y gora %s\n" , "kaixo egun on" , "quien tu ya sabes");
	original = printf("mi string es:  %s y gora %s\n" , "kaixo egun on" , "quien tu ya sabes");
	printf("%d\n", prueba);
	printf("%d\n", original);
	*/
	//CARACTER
	/*
	int prueba;
	int original;
	prueba = ft_printf("%c\n", 'h');
	original = printf("%c\n", 'h');
	printf("%d\n", prueba);
	printf("%d\n", original);
	*/
	//HEXADECIMALES
	/*
	int prueba;
	int original;
	prueba = ft_printf("%x\n", -1234);
	original = printf("%x\n", -1234);
	printf("%d\n", prueba);
	printf("%d\n", original);
	*/
	//PUNTEROS
	/*
	int x = -999;
	int *pt1;
	pt1 = &x;
	int prueba;
	int original;
	prueba = ft_printf("%p\n", pt1);
	original = printf("%p\n", pt1);
	printf("%d\n", prueba);
	printf("%d\n", original);
	*/
	//UNSIGNED
	/*
	int prueba;
	int original;
	prueba = ft_printf("%u\n", 0);
	original = printf("%u\n", 0);
	printf("%d\n", prueba);
	printf("%d\n", original);
	*/
    return (0);
}
