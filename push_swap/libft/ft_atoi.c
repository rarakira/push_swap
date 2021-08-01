/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbaela <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/18 16:16:51 by lbaela            #+#    #+#             */
/*   Updated: 2021/07/31 11:54:17 by lbaela           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	isspace(int ch)
{
	if (ch == ' ' || ch == '\f' || ch == '\n')
		return (1);
	if (ch == '\r' || ch == '\t' || ch == '\v')
		return (1);
	return (0);
}

/* Function converts the initial portion of the string pointed to by 'str'
to int representation. */
long	ft_atoi(const char *str)
{
	int		i;
	int		sign;
	long	result;

	i = 0;
	result = 0;
	sign = 1;
	while ((isspace(str[i])) && str[i] != '\0')
	{
		if (isspace(str[i]))
			i++;
	}
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while ((str[i] >= '0' && str[i] <= '9') && str[i] != '\0')
	{
		result = result * 10 + (str[i] - '0');
		i++;
	}
	return (result * sign);
}
