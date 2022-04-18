/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   punteros.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvarovelazquez <alvarovelazquez@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 10:11:57 by alvarovelaz       #+#    #+#             */
/*   Updated: 2022/04/18 12:56:34 by alvarovelaz      ###   ########.fr       */
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

void	ft_putchar_fd(char c, int fd)
{
	write (fd, &c, 1);
}

int	ft_ptr_len(unsigned long num)
{
	int	len;

	len = 0;
	while (num != 0)
	{
		len++;
		num = num / 16;
	}
	return (len);
}

void	ft_put_ptr(unsigned long num)
{
	if (num >= 16)
	{
		ft_put_ptr(num / 16);
		ft_put_ptr(num % 16);
	}
	else
	{
		if (num <= 9)
			ft_putchar_fd((num + '0'), 1);
		else
			ft_putchar_fd((num - 10 + 'a'), 1);
	}
}

int	ft_print_ptr(unsigned long long ptr)
{
	int	print_length;

	print_length = 0;
	print_length += write(1, "0x", 2);
	if (ptr == 0)
		print_length += write(1, "0", 1);
	else
	{
		ft_put_ptr(ptr);
		print_length += ft_ptr_len(ptr);
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
			if (str[i] == 'p')
			{
				ft_print_ptr(va_arg(args, unsigned long long));
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
	int x = 123456789;
	int *pt1;

	pt1 = &x;


	ft_printf("%p\n", pt1);
	printf("%p\n", pt1);
    return (0);
}


