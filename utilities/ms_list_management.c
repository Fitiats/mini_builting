/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_list_management.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmory <tmory@student.42antananarivo.mg>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 15:18:25 by tmory             #+#    #+#             */
/*   Updated: 2024/12/16 06:54:24 by tmory            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../minishell.h"

void	ft_free_split_char(char	**tab_s)
{
	int	i;

	i = 0;
	if (!tab_s)
		return ;
	while (tab_s[i])
	{
		free(tab_s[i]);
		i++;
	}
	free(tab_s);
	return ;
}

void	ms_lstadd_back(t_token **lst, t_token *new)
{
	t_token	*temp;

	if (!(*lst))
	{
		*lst = new;
		return ;
	}
	temp = *lst;
	while (temp->next)
		temp = temp->next;
	temp->next = new;
}
void ms_free_env(t_env *env)
{
	t_env *temp;
	if (!env)
		return;
	while (env)
	{
		temp = env;
		free(env->var_name);
		// free(env->var_value);
		env = env->next;
		free(temp);
	}
	return ;
}
void	ft_free_split(t_token *token)
{
	t_token *temp;

	if (!token)
		return;
	while (token)
	{
		temp = token;
		free(token->word);
		token->rank = 0;
		token->type = 0;
		token = token->next;
		free(temp);
	}
	return ;
}

