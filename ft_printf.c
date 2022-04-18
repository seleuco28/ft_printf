/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvarovelazquez <alvarovelazquez@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 09:38:07 by alvelazq          #+#    #+#             */
/*   Updated: 2022/04/18 17:38:34 by alvarovelaz      ###   ########.fr       */
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

void	ft_putnbr_fd(int n, int fd)
{
	if (n == -2147483648)
	{
		write(fd, "-2147483648", 11);
	}
	else
	{
		if (n < 0)
		{
			ft_putchar_fd('-', fd);
			n *= -1;
		}
		if (n < 10)
		{
			ft_putchar_fd(n + '0', fd);
		}
		else
		{
			ft_putnbr_fd(n / 10, fd);
			ft_putchar_fd(n % 10 + '0', fd);
		}
	}
}

void	ft_putstr_fd(char *s, int fd)
{
	int	c;

	c = 0;
	if (!s)
		return ;
	while (s[c] != '\0')
	{
		ft_putchar_fd(s[c], 1);
		c++;
	}
}

void ft_dec_a_hex(int n, int fd)
{
	char *base;
	int i;

	base = "0123456789ABCDEF";
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

void ft_dec_a_hex_min(int n, int fd)
{
	char *base;
	int i;

	base = "0123456789abcdef";
	if (n > 16)
	{
		ft_dec_a_hex_min(n / 16 , fd);
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

int	ft_ptr_len(uintptr_t num) // tambien se puede poner unsigned long
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

void	ft_put_ptr(uintptr_t num) // también se puede poner unsigned long
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

// la parte del unsigned
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
			if (str[i] == 's')
			{
				ft_putstr_fd(va_arg(args, char *), 1);
				i++;
			}
			else if (str[i] == 'c')
			{
				ft_putchar_fd(va_arg(args, int), 1);
				i++;
			}
            else if (str[i] == 'd' || str[i] == 'i')
			{
                ft_putnbr_fd(va_arg(args, int), 1);
				i++;
			}
			else if (str[i] == 'p')
			{
				ft_print_ptr(va_arg(args, unsigned long long));
				i++;
			}
			else if (str[i] == 'u')
			{
				ft_print_unsigned(va_arg(args, unsigned int));
				i++;
			}
			else if (str[i] == 'x')
			{
				ft_dec_a_hex_min(va_arg(args, int), 1);
				i++;
			}
			else if (str[i] == 'X')
			{
				ft_dec_a_hex(va_arg(args, int), 1);
				i++;
			}
			else if (str[i] == '%')
			{
				write(1, "%%", 1);
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
	//GENERAL
	ft_printf("numero %d y %i letra es %c string %s porcentaje %% \n", 24, -25, 'A', "lvaro");

	//CARACTER
	//ft_printf("mi caracter es %c\n", 'h');
	//printf("el caracter es: %c\n", 'h');

	//HEXADECIMALES
	//ft_printf("%x\n", 1234);
	//printf("Mi numero hexadecimal %x\n", 1234);

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
