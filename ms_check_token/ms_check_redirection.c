/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_check_redirection.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmory <tmory@student.42antananarivo.mg>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 12:02:59 by tmory             #+#    #+#             */
/*   Updated: 2024/10/30 16:57:43 by tmory            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	ms_is_relationalop(char c)
{
	if (c == '<' || c == '>')
		return (1);
	return (0);
}

int	ms_is_infdouble(const char *c)
{
	if (*c == '<' && *(c + 1) == '<')
		return (1);
	return (0);
}
int	ms_is_supdouble(const char *c)
{
	if (*c == '>' && *(c + 1) == '>')
		return (1);
	return (0);
}

int	ms_is_relopdouble(const char *c)
{
	if (ms_is_infdouble(c) || ms_is_supdouble(c))
		return (1);
	return (0);
}


