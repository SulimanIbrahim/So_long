/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putpointer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suibrahi <suibrahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 22:54:04 by suibrahi          #+#    #+#             */
/*   Updated: 2023/12/07 19:08:21 by suibrahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_pointer(unsigned long p)
{
	if (p >= 16)
	{
		ft_pointer(p / 16);
		ft_pointer(p % 16);
	}
	else
	{
		if (p <= 9)
			ft_putchar(p + '0');
		else
			ft_putchar(p - 10 + 'a');
	}
}

int	ft_putpointer(unsigned long long p)
{
	int	len;

	len = 0;
	len += ft_putstring("0x");
	if (p == 0)
	{
		len += ft_putchar('0');
		return (len);
	}
	ft_pointer(p);
	len += ft_ptrlen(p);
	return (len);
}
