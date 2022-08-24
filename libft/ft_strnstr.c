/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsemlali <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 10:05:41 by lsemlali          #+#    #+#             */
/*   Updated: 2021/11/29 10:40:56 by lsemlali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_search(const char *str, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (str[i] != '\0' && i < len)
	{
		j = 0;
		while (str[i + j] == needle[j] && str[i + j] != '\0' && i + j < len)
		{
			if (needle[j + 1] == '\0')
				return ((char *)&str[i]);
			j++;
		}
		i++;
	}
	return (0);
}

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	if ((!len && needle[0] == '\0') || needle[0] == '\0')
		return ((char *)haystack);
	if (!len)
		return (0);
	return (ft_search(haystack, needle, len));
}
