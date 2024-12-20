/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_check_quotes.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmory <tmory@student.42antananarivo.mg>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 14:29:43 by trahanta          #+#    #+#             */
/*   Updated: 2024/10/31 09:30:42 by tmory            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int ms_is_quotes(char c)
{
    if(c == '"')
        return (1);
    return (0);
}
int ms_is_singlequotes(char c)
{
    if(c == '\'')
        return (1);
    return (0);
}

int ms_is_allquotes(char c)
{
    if(ms_is_singlequotes(c) == 1 || ms_is_quotes(c) == 1)
        return (1);
    return (0);
}
