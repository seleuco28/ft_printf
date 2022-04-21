/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvarovelazquez <alvarovelazquez@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 15:16:32 by alvarovelaz       #+#    #+#             */
/*   Updated: 2022/04/21 17:23:48 by alvarovelaz      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
# include <unistd.h>
# include <string.h>
# include <stdarg.h>
# include <stdlib.h>

void	ft_dec_a_hex(int n, int fd);
void	ft_dec_a_hex_min(int n, int fd);
int		ft_printstr(char *str);
int		ft_num_len(unsigned	int num);
char	*ft_uitoa(unsigned int n);
int		ft_print_unsigned(unsigned int n);
void	ft_putchar_fd(char c, int fd);
int		ft_ptr_len(uintptr_t num);
void	ft_put_ptr(uintptr_t num);
int		ft_print_ptr(unsigned long long ptr);
void	ft_putstr_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);

#endif