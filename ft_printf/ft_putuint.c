/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putuint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suibrahi <suibrahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 18:53:40 by suibrahi          #+#    #+#             */
/*   Updated: 2023/08/15 03:32:36 by suibrahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putuint(unsigned int num)
{
	char	*arr;
	int		len;

	arr = ft_uitoa(num);
	len = ft_putstring(arr);
	free(arr);
	return (len);
}
