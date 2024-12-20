/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_split_byword.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmory <tmory@student.42antananarivo.mg>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 18:09:27 by tmory             #+#    #+#             */
/*   Updated: 2024/12/16 09:54:45 by tmory            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

static int	ms_sbw_count_len(const char *s, char c)
{
	int				i;
	int				quote_indic;
	t_sbw_variables	var;

	var.s = s;
	i = 0;
	quote_indic = 0;
	var.j = &i;
	while (s[i] && s[i] != c && s[i] != '|' && s[i] != '<' && s[i] != '>')
	{
		ms_sbw_count_len2(&quote_indic, &var);
		while (quote_indic == 2)
		{
			if (ms_is_singlequotes(s[i]) == 1)
			{
				quote_indic = 0;
				break ;
			}
			i++;
		}
		i++;
	}
	return (i);
}

int	ms_sbw_whileloop(t_token *token, int *k, const char *s)
{
	int				quote_indic;
	t_sbw_variables	var;
	int				j;

	j = 0;
	quote_indic = 0;
	var.s = s;
	var.j = &j;
	while (s[*k] && s[*k] != ' ' && s[*k] != '|' && s[*k] != '<'
		&& s[*k] != '>')
	{
		ms_sbw_whileloop_2(&quote_indic, &var, k, token);
		while (quote_indic == 2)
		{
			if (ms_is_singlequotes(s[*k]) == 1)
			{
				quote_indic = 0;
				break ;
			}
			token->word[j++] = s[(*k)++];
		}
		token->word[j++] = s[(*k)++];
	}
	token->word[j] = '\0';
	return (0);
}

static int	ms_spw_ifloop(const char *s, t_token *token, int *k)
{
	if (s[*k] == '|')
	{
		if (ms_sbw_dupmetachar(token, k, "|", PIPE))
			return (1);
	}
	else if (s[*k] == '<' && s[(*k) + 1] == '<')
	{
		if (ms_sbw_dupmetachar2(token, k, "<<", HEREDOC))
			return (1);
	}
	else if (s[*k] == '>' && s[(*k) + 1] == '>')
	{
		if (ms_sbw_dupmetachar2(token, k, ">>", OUT_HEREDOC))
			return (1);
	}
	else if (s[*k] == '<' && s[(*k) + 1] != '<')
	{
		if (ms_sbw_dupmetachar(token, k, "<", INPUT))
			return (1);
	}
	return (0);
}

int	ms_split_byword(int *k, t_token *token, const char *s)
{
	int	count_len;

	while (s[*k] == ' ')
		(*k)++;
	if (s[*k] == '>' && s[(*k) + 1] != '>')
	{
		if (ms_sbw_dupmetachar(token, k, ">", OUTPUT))
			return (1);
	}
	else if (s[*k] == '|' || s[*k] == '<' || s[*k] == '>')
	{
		if (ms_spw_ifloop(s, token, k))
			return (1);
	}
	else
	{
		count_len = ms_sbw_count_len((s + (*k)), ' ');
		token->word = (char *)malloc(sizeof(char) * (count_len + 1));
		if (!token->word)
			return (ft_free_split(token), 1);
		ms_sbw_whileloop(token, k, s);
	}
	return (0);
}
