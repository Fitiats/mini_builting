/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmory < tmory@student.42antananarivo.mg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 14:50:12 by tmory             #+#    #+#             */
/*   Updated: 2024/08/12 15:18:12 by tmory            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long int	ft_atol(const char *nptr)
{
	int			i;
	long int	sign;
	long int	ret;
	char		*str;

	str = (char *) nptr;
	i = 0;
	sign = 1;
	ret = 0;
	while (*(str + i) != '\0'
		&& ((*(str + i) >= '\t' && *(str + i) <= '\r') || *(str + i) == 32))
		i++;
	if (*(str + i) == '-' || *(str + i) == '+')
	{
		if (*(str + i) == '-')
			sign = -1;
		i++;
	}
	while (*(str + i) >= '0' && *(str + i) <= '9' && *(str + i) != '\0')
	{
		ret = (*(str + i) - 48) + (ret * 10);
		i++;
	}
	return (ret * sign);
}
