/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmory < tmory@student.42antananarivo.mg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 09:21:25 by tmory             #+#    #+#             */
/*   Updated: 2024/08/12 15:13:51 by tmory            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	int		start;
	int		end;
	char	*str;

	start = 0;
	end = ft_strlen(s1) - 1;
	if (!set)
		return (NULL);
	while (ft_strrchr(set, s1[start]) != NULL)
		start++;
	while (ft_strrchr(set, s1[end]) != NULL)
		end--;
	if (end < start)
		return (ft_strdup(""));
	str = ft_substr(s1, start, (end - start + 1));
	return (str);
}
