/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmory < tmory@student.42antananarivo.mg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 14:32:05 by tmory             #+#    #+#             */
/*   Updated: 2024/08/12 15:12:11 by tmory            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, char *src, size_t size)
{
	size_t	i;
	size_t	k;

	k = ft_strlen(dst);
	i = 0;
	if (size == 0 || size <= k)
		return (ft_strlen(src) + size);
	while (src[i] != '\0' && i < size - k - 1)
	{
		dst[k + i] = src[i];
		i++;
	}
	dst[k + i] = '\0';
	return (ft_strlen(src) + k);
}
