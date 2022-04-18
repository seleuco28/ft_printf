/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vertedero.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvarovelazquez <alvarovelazquez@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 16:54:47 by alvelazq          #+#    #+#             */
/*   Updated: 2022/04/18 09:33:56 by alvarovelaz      ###   ########.fr       */
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


/*
void	ft_dec_a_hex(int n, int fb)
{
	int r;

	while (n > 0)
	{
		r = n % 16;
		if (r < 10)
			r = r + 48;
		else
			r = r + 55;
		write (1, &r, 1);
		n = n / 16;
	}
}
*/

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
			if (str[i] == 'c' || str[i] == 's')
			{
				ft_putstr_fd(va_arg(args, char *), 1);
				i++;
			}
            else if (str[i] == 'd' || str[i] == 'i')
			{
                ft_putnbr_fd(va_arg(args, int), 1);
				i++;
			}
			else if (str[i] == 'p')
			{
				i++;
			}
			else if (str[i] == 'x')
			{
				ft_dec_a_hex(va_arg(args, int), 1); // HACERLO minusculo
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
	//ft_printf("numero %d y %i letra es %c string %s porcentaje %% \n", 24, 25, "A", "lvaro");
	//printf("Mi numero sin signo es %u\n", -21);

	ft_printf("%x\n", 960);
	printf("Mi numero hexadecimal %x\n", 960);
    return (0);
}