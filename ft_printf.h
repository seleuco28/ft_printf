/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvarovelazquez <alvarovelazquez@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 15:16:32 by alvarovelaz       #+#    #+#             */
/*   Updated: 2022/04/23 17:43:30 by alvarovelaz      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
# include <unistd.h>
# include <string.h>
# include <stdarg.h>
# include <stdlib.h>

int		ft_dec_a_hex(unsigned int n);
int		ft_dec_a_hex_min(unsigned int n);
int		ft_printstr(char *str);
int		ft_num_len(unsigned	int num);
char	*ft_uitoa(unsigned int n);
int		ft_print_unsigned(unsigned int n);
void	ft_putchar(char c);
int		ft_ptr_len(uintptr_t num);
void	ft_put_ptr(uintptr_t num);
int		ft_print_ptr(unsigned long long ptr);
int		ft_putstr(char *s);
int		ft_putnbr(int n);
size_t	ft_strlen(const char *str);
int		ft_printpercent(void);
int		ft_printf(char const *str, ...);

#endif