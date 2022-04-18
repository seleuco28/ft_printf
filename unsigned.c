/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unsigned.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvarovelazquez <alvarovelazquez@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 13:01:46 by alvarovelaz       #+#    #+#             */
/*   Updated: 2022/04/18 16:30:37 by alvarovelaz      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <stdarg.h>

size_t	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

int	ft_printstr(char *str)
{
	int	i;

	i = 0;
	if (str == NULL)
		return(1);
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
	return (i);
}

int	ft_num_len(unsigned	int num)
{
	int	len;

	len = 0;
	while (num != 0)
	{
		len++;
		num = num / 10;
	}
	return (len);
}

char	*ft_uitoa(unsigned int n)
{
	char	*num;
	int		len;

	len = ft_num_len(n);
	num = (char *)malloc(sizeof(char) * (len + 1));
	if (!num)
		return (0);
	num[len] = '\0';
	while (n != 0)
	{
        len--;
		num[len] = n % 10 + 48;
		n = n / 10;
	}
	return (num);
}

int	ft_print_unsigned(unsigned int n)
{
	int		print_length;
	char	*num;

	print_length = 0;
	if (n == 0)
		print_length += write(1, "0", 1);
	else
	{
		num = ft_uitoa(n);
		print_length += ft_printstr(num);
		free(num);
	}
	return (print_length);
}

int ft_printf(char const *str, ...)
{
    int num_args = ft_strlen(str);

    va_list args;
    va_start (args, str);

    int i;

    i = 0;
    while (str[i])
    {
        if (str[i] == '%')
        {
			i++;
			if (str[i] == 'u') // si le paso un numero negativo, lo pasa a binario puro y lo devuelve raro
			{
				ft_print_unsigned(va_arg(args, unsigned int));
				i++;
			}
		}
        write(1, &str[i], 1);
        i++;
    } 
    va_end(args);
    return (0);
}

int main(void)
{

    ft_printf("%u\n", -121); // es este binario 11111111111111111111111110000111 signado y 4294967175 sin signar
	printf("%u\n", -121);
    return (0);
}