/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uitoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suibrahi <suibrahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 19:14:10 by suibrahi          #+#    #+#             */
/*   Updated: 2023/12/07 19:00:56 by suibrahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	int	countnum(unsigned int n)
{
	int	numdigit;

	numdigit = 0;
	while (n != 0)
	{
		n /= 10;
		numdigit++;
	}
	return (numdigit);
}

static char	*zero_case(void)
{
	char	*result;

	result = malloc(2);
	if (result == NULL)
		return (NULL);
	result[0] = '0';
	result[1] = '\0';
	return (result);
}

char	*ft_uitoa(unsigned int n)
{
	char	*str;
	int		i;

	if (n == 0)
		return (zero_case());
	str = (char *)malloc((countnum(n) + 1) * sizeof(char));
	if (str == NULL)
		return (NULL);
	i = countnum(n);
	str[i] = '\0';
	while (i-- > 0)
	{
		str[i] = '0' + (n % 10);
		n /= 10;
	}
	return (str);
}
