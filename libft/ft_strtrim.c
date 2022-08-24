/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsemlali <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 09:19:11 by lsemlali          #+#    #+#             */
/*   Updated: 2021/11/29 10:40:08 by lsemlali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	beg_rem(char *s1, char *set)
{
	int	i;
	int	j;
	int	p;

	i = 0;
	j = 0;
	p = -1;
	while (s1[i])
	{
		while (set[j])
		{
			if (s1[i] == set[j])
				p = i;
			j++;
		}
		if (p != i)
			return (i);
		j = 0;
		i++;
	}
	return (p + 1);
}

static int	end_rem(char *s1, char *set)
{
	int	i;
	int	j;
	int	p;

	i = ft_strlen(s1) - 1;
	j = 0;
	p = 0;
	while (i >= 0)
	{
		while (set[j])
		{
			if (s1[i] == set[j])
				p = i;
			j++;
		}
		if (p != i)
			return (i);
		j = 0;
		i--;
	}
	if (p == 0)
		return (p);
	return (p - 1);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		i;
	int		start;
	int		end;
	char	*str;

	if (!s1 || !set)
		return (0);
	start = beg_rem((char *)s1, (char *)set);
	end = end_rem((char *)s1, (char *)set);
	if (end == 0)
	{
		str = malloc(1);
		str[0] = '\0';
		return (str);
	}
	str = malloc((end - start + 1) + 1);
	if (str == NULL)
		return (0);
	i = 0;
	while (start <= end)
		str[i++] = s1[start++];
	str[i] = '\0';
	return (str);
}
