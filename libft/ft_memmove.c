/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmory < tmory@student.42antananarivo.mg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 09:31:41 by tmory             #+#    #+#             */
/*   Updated: 2024/08/12 15:07:58 by tmory            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*dst;
	unsigned char	*s;

	dst = (unsigned char *)dest;
	s = (unsigned char *)src;
	if (!dest && !src)
		return (NULL);
	if (dst < s)
	{
		while (n--)
		{
			*dst++ = *s++;
		}
	}
	else if (dst > s)
	{
		dst += n - 1;
		s += n - 1;
		while (n--)
		{
			*dst-- = *s--;
		}
	}
	return (dest);
}
