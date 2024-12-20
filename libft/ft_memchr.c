/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmory < tmory@student.42antananarivo.mg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 15:07:06 by tmory             #+#    #+#             */
/*   Updated: 2024/08/12 15:07:08 by tmory            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	int	i;

	i = 0;
	if (n != 0)
	{
		while (i < (int) n)
		{
			if (*(unsigned char *) s == (unsigned char) c)
			{
				return ((void *)s);
			}
			s++;
			i++;
		}
	}
	if (!(unsigned char *)s)
		return (NULL);
	return (NULL);
}
