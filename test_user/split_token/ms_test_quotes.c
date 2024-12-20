/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_test_quotes.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmory <tmory@student.42antananarivo.mg>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 11:45:22 by tmory             #+#    #+#             */
/*   Updated: 2024/11/18 15:36:04 by tmory            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int	ms_test_quotes(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (ms_is_quotes(s[i]) == 1)
		{
			i++;
			while (ms_is_quotes(s[i]) == 0 && s[i])
				i++;
			if (!s[i])
				return (1);
		}
		else if (ms_is_singlequotes(s[i]) == 1)
		{
			i++;
			while (ms_is_singlequotes(s[i]) == 0 && s[i])
				i++;
			if (!s[i])
				return (1);
		}
		i++;
	}
	return (0);
}
