/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksanches <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 17:32:53 by ksanches          #+#    #+#             */
/*   Updated: 2024/05/17 16:02:44 by ksanches         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../minitalk.h"

int	ft_atoi(const char *nptr)
{
	int	i;
	int	neg;
	int	num;

	i = 0;
	num = 0;
	neg = 1;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			neg = -1;
		if (nptr[i + 1] == '-' || nptr[i + 1] == '+')
			return (0);
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		num = num * 10 + (nptr[i] - 48);
		i++;
	}
	return (num * neg);
}