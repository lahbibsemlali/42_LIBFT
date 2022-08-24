/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsemlali <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 13:24:27 by lsemlali          #+#    #+#             */
/*   Updated: 2021/11/29 10:23:32 by lsemlali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	my_atoi(const char *str)
{
	int	n;
	int	i;

	i = 0;
	n = 0;
	while (str[i] >= '0' && str[i] <= '9' && str[i])
	{
		n = n * 10 + (str[i] - '0');
		i++;
	}
	return (n);
}

static int	my_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i] && str[i] >= '0' && str[i] <= '9')
		i++;
	return (i);
}

static int	my_skip(const char *str)
{
	int	i;

	i = 0;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\v'
		|| str[i] == '\n' || str[i] == '\f' || str[i] == '\r')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		i = i + 1;
		if (str[i - 1] == '-')
			i = -i;
	}
	return (i);
}

int	ft_atoi(const char *str)
{
	int	i;
	int	p;
	int	n;

	p = 1;
	i = my_skip(str);
	if (i < 0)
	{
		i = -i;
		p = -1;
	}
	if (my_atoi(&str[i]) > 2147483647 || my_strlen(&str[i]) > 10)
	{
		if (p == -1)
			return (0);
		return (-1);
	}
	n = 0;
	while (str[i] >= '0' && str[i] <= '9' && str[i])
	{
		n = n * 10 + (str[i] - 48);
		i++;
	}
	return (n * p);
}
