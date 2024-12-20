/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_expand.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmory <tmory@student.42antananarivo.mg>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 16:52:10 by tmory             #+#    #+#             */
/*   Updated: 2024/12/04 16:26:37 by tmory            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	free_worddivide(char **tab)
{
	if (tab[0])
		free(tab[0]);
	if (tab[1])
		free(tab[1]);
	free(tab);
	return ;
}

static char	*ms_ex_searchvar_env(t_env *env, char *trg)
{
	t_env	*temp;

	temp = env;
	while (temp)
	{
		if (ft_strcmp(temp->var_name, trg) == 0)
			return (temp->var_value);
		temp = temp->next;
	}
	return ("\000");
}

static char	**ms_ex_worddivide(const char *s, int start, int end)
{
	char	**split;

	split = (char **)malloc(sizeof(char *) * 3);
	if (!split)
		return (NULL);
	split[0] = ft_substr(s, 0, start - 1);
	if (!split[0])
		return (free_worddivide(split), NULL);
	split[1] = ft_substr(s, start + end, ft_strlen(s) - start - end);
	if (!split[1])
		return (free_worddivide(split), NULL);
	split[2] = NULL;
	return (split);
}

static int	ms_ex_joinexpand(char **tab, t_token *tkn, t_env *env,
		char *env_var)
{
	char	*temp;
	char	*temp2;

	temp = ft_strjoin(tab[0], ms_ex_searchvar_env(env, env_var));
	if (!temp)
		return (1);
	temp2 = ft_strjoin(temp, tab[1]);
	if (!temp2)
		return (free(temp), 1);
	free(temp);
	free(tkn->word);
	tkn->word = NULL;
	tkn->word = ft_strdup(temp2);
	if (tkn->word == NULL)
		return (free(temp2), 1);
	free(temp2);
	return (0);
}

static void	ms_ex_isdollar_whileloop(t_token *tkn, int *i)
{
	while (tkn->word[*i] == '_' || ft_isalpha(tkn->word[*i])
		|| ft_isalnum(tkn->word[*i]))
		(*i)++;
}

static int	ms_ex_isdollar(t_token *tkn, int *i, char *env_var, t_env *env)
{
	int		start;
	char	**word_tab;

	start = 0;
	if (tkn->word[*i] == '$' && (tkn->word[(*i + 1)] == '_'
			|| ft_isalpha(tkn->word[(*i + 1)]) || ft_isalnum(tkn->word[(*i
						+ 1)])))
	{
		(*i)++;
		start = *i;
		ms_ex_isdollar_whileloop(tkn, i);
		env_var = ft_substr(tkn->word, start, *i - start);
		if (!env_var)
			return (1);
		word_tab = ms_ex_worddivide(tkn->word, start, *i - start);
		if (!word_tab)
			return (free(env_var), 1);
		if (ms_ex_joinexpand(word_tab, tkn, env, env_var))
			return (1);
		*i = (start - 1) + ft_strlen(ms_ex_searchvar_env(env, env_var));
		free_worddivide(word_tab);
		(*i)--;
		free(env_var);
	}
	return (0);
}

static int	ms_rq_expand(t_token *tkn, int *i, char *env_var, t_env *env)
{
	(*i)++;
	while (ms_is_quotes(tkn->word[*i]) == 0 && tkn->word[*i])
	{
		if (ms_ex_isdollar(tkn, i, env_var, env) == 1)
			return (1);
		(*i)++;
	}
	(*i)++;
	if (ms_is_quotes(tkn->word[*i]) == 1)
		ms_recursive_quotes(tkn->word, i);
	return (0);
}

static int	ms_exp_ifloop(t_token *tkn, int *i, char **env_var, t_env *env)
{
	if (ms_is_singlequotes(tkn->word[*i]))
		ms_recursive_singlequotes(tkn->word, i);
	if (ms_is_quotes(tkn->word[*i]))
	{
		if (ms_rq_expand(tkn, i, *env_var, env) == 1)
			return (1);
		return (2);
	}
	if (ms_ex_isdollar(tkn, i, *env_var, env) == 1)
		return (1);
	if (*i < 0)
	{
		(*i)++;
		return (2);
	}
	return (0);
}

int	ms_expand(t_token *tkn, t_env *env)
{
	int		i;
	char	*env_var;

	i = 0;
	env_var = NULL;
	while (tkn->word[i])
	{
		if (ms_exp_ifloop(tkn, &i, &env_var, env) == 1)
			return (1);
		else if (ms_exp_ifloop(tkn, &i, &env_var, env) == 2)
			continue ;
		if (tkn->word[i] == '\0')
			break ;
		i++;
	}
	return (0);
}
