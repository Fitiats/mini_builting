/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmory < tmory@student.42antananarivo.mg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 17:38:56 by tmory             #+#    #+#             */
/*   Updated: 2024/08/12 14:50:00 by tmory            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *nptr)
{
	int		i;
	int		sign;
	int		ret;
	char	*str;

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
