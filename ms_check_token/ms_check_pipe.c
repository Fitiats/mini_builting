/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_check_pipe.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmory <tmory@student.42antananarivo.mg>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 14:20:31 by trahanta          #+#    #+#             */
/*   Updated: 2024/10/30 16:50:33 by tmory            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int ms_is_pipe(char c)
{
    if(c == '|')
        return (1);
    return (0);
}
int ms_check_error_nbpipe(const char *s)
{
    int i;

    i = 0;
    while(s[i] != '\0')
    {
        if(ms_is_pipe(s[i]) && s[i + 1] == '|')
            return (1);
        i++;
    }
    return (0);
}

int	ms_is_pipedouble(char *c)
{
	if ((*c == '|' && *(c + 1) == '|'))
		return (1);
	return (0);;
}
