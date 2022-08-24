/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsemlali <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 09:11:07 by lsemlali          #+#    #+#             */
/*   Updated: 2021/11/27 10:19:36 by lsemlali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	size_t		i;
	size_t		p;

	if (!s)
		return ;
	p = ft_strlen(s);
	i = 0;
	while (i < p)
	{
		f(i, &s[i]);
		i++;
	}
}
