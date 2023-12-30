/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suibrahi <suibrahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 02:26:13 by suibrahi          #+#    #+#             */
/*   Updated: 2023/11/26 19:33:29 by suibrahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	free_args(char **av, int flag)
{
	int	i;

	i = 0;
	if (flag == 1)
	{
		write(2, "Error\n", 7);
	}
	if (av[i])
	{
		while (av[i])
		{
			free(av[i]);
			i++;
		}
		free (av);
	}
}

int	ft_atoi(char *str, char **args, int *flag)
{
	int			sign;
	long long	res;

	res = 0;
	sign = 1;
	while (*str == 32 || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '-')
		sign *= -1;
	if (*str == '-' || *str == '+')
		str++;
	while (*str >= '0' && *str <= '9' )
	{
		res = res * 10 + *str - '0';
		if (res > 2147483647 || res < -2147483648)
		{
			free_args(args, 1);
			*flag = 1;
			return (0);
		}
		str++;
	}
	return (res * sign); 
}
