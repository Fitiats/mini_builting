/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_split_token.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmory <tmory@student.42antananarivo.mg>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 11:09:23 by trahanta          #+#    #+#             */
/*   Updated: 2024/12/03 15:56:32 by tmory            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

static void	count_word_loop(const char *s, char c, int *i)
{
	while (s[*i] != c && s[*i] != '|' && s[*i] != '<' && s[*i] != '>' && s[*i])
	{
		if (s[*i] == '"')
		{
			ms_recursive_quotes(s, i);
			continue ;
		}
		else if (s[*i] == '\'')
		{
			ms_recursive_singlequotes(s, i);
			continue ;
		}
		(*i)++;
	}
}

static bool	ft_ismetacharacters(char const *s, int *i)
{
	if (s[*i] == '<' && s[(*i) + 1] == '<')
		return ((*i) += 2, true);
	if (s[*i] == '>' && s[(*i) + 1] == '>')
		return ((*i) += 2, true);
	if (s[*i] == '|' || s[*i] == '<' || s[*i] == '>')
		return ((*i)++, true);
	return (false);
}

static int	count_word(const char *s, char c)
{
	int	i;
	int	count;

	count = 0;
	i = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (ft_ismetacharacters(s, &i) == true)
		{
			count++;
			continue ;
		}
		if (s[i])
			count++;
		if (ms_is_quotes(s[i]) == 1)
			ms_recursive_quotes(s, &i);
		else if (ms_is_singlequotes(s[i]) == 1)
			ms_recursive_singlequotes(s, &i);
		count_word_loop(s, c, &i);
	}
	return (count);
}

static int	ms_spltk_expand_cleanquotes(t_token *temp, t_env *env,
		t_token **token)
{
	if (ms_expand(temp, env))
		return (1);
	if (ms_clean_quotes(temp))
		return (1);
	ms_lstadd_back(token, temp);
	return (0);
}

t_token	*ms_split_token(char const *s, t_env *env, char c)
{
	t_token	*token;
	int		word_count;
	int		i;
	int		j;
	t_token	*temp;

	i = 0;
	j = 0;
	token = NULL;
	word_count = count_word(s, c);
	while (*s && i++ < word_count)
	{
		temp = (t_token *)malloc(sizeof(t_token));
		if (!temp)
			return (ft_free_split(token), NULL);
		else
			ms_spltk_init_token(temp, i);
		if (ms_split_byword(&j, temp, s))
			return (ft_free_split(token), NULL);
		if (ms_spltk_expand_cleanquotes(temp, env, &token))
			return (ft_free_split(token), NULL);
	}
	return (token);
}
