/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_formatcheck.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suibrahi <suibrahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/13 16:47:47 by suibrahi          #+#    #+#             */
/*   Updated: 2023/08/15 03:31:18 by suibrahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_formatcheck(va_list arg, char c)
{
	int	len;

	len = 0;
	if (c == 'd' || c == 'i')
		len += ft_putnum(va_arg(arg, int));
	else if (c == 'c')
		len += ft_putchar(va_arg(arg, int));
	else if (c == 's')
		len += ft_putstring(va_arg(arg, char *));
	else if (c == 'p')
		len += ft_putpointer(va_arg(arg, unsigned long long));
	else if (c == 'x' || c == 'X')
		len += ft_puthex(va_arg(arg, unsigned long long), c);
	else if (c == 'u')
		len += ft_putuint(va_arg(arg, unsigned int));
	else if (c == '%')
		len += ft_putpercent();
	return (len);
}
