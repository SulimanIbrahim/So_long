/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suibrahi <suibrahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 05:53:34 by suibrahi          #+#    #+#             */
/*   Updated: 2023/08/15 03:30:00 by suibrahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <stddef.h>
# include <stdlib.h>
# include <string.h>

int				ft_putnum(int num);
int				ft_putstring(char *str);
int				ft_printf(const char *str, ...);
char			*ft_itoa(int n);
int				ft_putchar(int c);
int				ft_formatcheck(va_list arg, char c);
int				ft_putpointer(unsigned long long p);
int				ft_putuint(unsigned int num);
char			*ft_uitoa(unsigned int n);
int				ft_putpercent(void);
int				ft_puthex(unsigned int n, char c);
int				ft_ptrlen(unsigned long n);

#endif