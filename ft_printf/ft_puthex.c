/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suibrahi <suibrahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/12 21:30:45 by suibrahi          #+#    #+#             */
/*   Updated: 2023/12/07 19:00:21 by suibrahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_hex(unsigned int n, const char c)
{
	if (n >= 16)
	{
		ft_puthex(n / 16, c);
		ft_puthex(n % 16, c);
	}
	else
	{
		if (n <= 9)
			ft_putchar(n + '0');
		else
		{
			if (c == 'x')
				ft_putchar(n - 10 + 'a');
			else if (c == 'X')
				ft_putchar(n - 10 + 'A');
		}
	}
}

int	ft_puthex(unsigned int n, const char c)
{
	int	len;

	len = 0;
	if (n == 0)
		return (write(1, "0", 1));
	else
		ft_hex(n, c);
	len += ft_ptrlen(n);
	return (len);
}
