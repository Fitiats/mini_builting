/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_split_byword_utils.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmory <tmory@student.42antananarivo.mg>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 16:30:26 by tmory             #+#    #+#             */
/*   Updated: 2024/12/04 17:39:58 by tmory            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int	ms_sbw_dupmetachar(t_token *token, int *k, char *dup, int type)
{
	token->word = ft_strdup(dup);
	if (!token->word)
		return (ft_free_split(token), 1);
	token->type = type;
	(*k)++;
	return (0);
}

int	ms_sbw_dupmetachar2(t_token *token, int *k, char *dup, int type)
{
	token->word = ft_strdup(dup);
	if (!token->word)
		return (ft_free_split(token), 1);
	token->type = type;
	*k += 2;
	return (0);
}

void	ms_sbw_count_len2(int *quote_indic, t_sbw_variables *var)
{
	int			*i;
	const char	*s;

	i = var->j;
	s = var->s;
	if (ms_is_quotes(s[*i]) == 1)
	{
		*quote_indic = 1;
		(*i)++;
	}
	else if (ms_is_singlequotes(s[*i]) == 1)
	{
		*quote_indic = 2;
		(*i)++;
	}
	while (*quote_indic == 1)
	{
		if (ms_is_quotes(s[*i]) == 1)
		{
			*quote_indic = 0;
			break ;
		}
		(*i)++;
	}
}

void	ms_sbw_whileloop_2(int *quote_indic, t_sbw_variables *var, int *k,
		t_token *token)
{
	if (ms_is_quotes(var->s[*k]) == 1)
	{
		*quote_indic = 1;
		token->word[(*var->j)++] = var->s[(*k)++];
	}
	else if (ms_is_singlequotes(var->s[*k]) == 1)
	{
		*quote_indic = 2;
		token->word[(*var->j)++] = var->s[(*k)++];
	}
	while (*quote_indic == 1)
	{
		if (ms_is_quotes(var->s[*k]) == 1)
		{
			*quote_indic = 0;
			break ;
		}
		token->word[(*var->j)++] = var->s[(*k)++];
	}
}
