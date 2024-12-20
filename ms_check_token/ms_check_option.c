/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_check_option.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmory <tmory@student.42antananarivo.mg>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 17:12:01 by tmory             #+#    #+#             */
/*   Updated: 2024/10/30 18:15:42 by tmory            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int ms_isdash(char c)
{
    if(c == '-')
        return (1);
    return (0);
}

int	ms_is_doubledash(const char *c)
{
	if (*c == '-' && *(c + 1) == '-')
		return (1);
	return (0);
}

