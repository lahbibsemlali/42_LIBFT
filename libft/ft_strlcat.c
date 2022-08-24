/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsemlali <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/03 13:12:34 by lsemlali          #+#    #+#             */
/*   Updated: 2021/11/29 10:48:33 by lsemlali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	p;
	size_t	j;

	j = 0;
	if (size == 0)
		return (ft_strlen(src));
	i = ft_strlen(dest);
	if (size <= i)
		return (size + ft_strlen(src));
	p = size - i - 1;
	while (src[j] != '\0' && j < p)
	{
		dest[j + i] = src[j];
		j++;
	}
	dest[i + j] = '\0';
	return (i + ft_strlen(src));
}
