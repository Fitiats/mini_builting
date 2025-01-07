/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_unset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trahanta <trahanta@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 09:58:19 by trahanta          #+#    #+#             */
/*   Updated: 2025/01/08 00:55:27 by trahanta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

// int	ms_unset(t_env *env, t_token *tkn)
// {
// 	t_token	*temp_tkn;
// 	t_env	*temp_env;
// 	t_env	*prev_env;
// 	char	*var_name;

// 	prev_env = NULL;
// 	temp_tkn = tkn->next;
// 	while (temp_tkn)
// 	{
// 		var_name = check_var_name(temp_tkn->word);
// 		temp_env = env;
// 		prev_env = NULL;
// 		while (temp_env)
// 		{
// 			if (ft_strcmp(var_name, temp_env->var_name) == 0)
// 			{
// 				if (prev_env == NULL)
// 				{
// 					env = temp_env->next;
// 				}
// 				else
// 				{
// 					prev_env->next = temp_env->next;
// 				}
// 				free(temp_env->var_name);
// 				free(temp_env->var_value);
// 				free(temp_env);
// 				break ;
// 			}
// 			prev_env = temp_env;
// 			temp_env = temp_env->next;
// 		}
// 		temp_tkn = temp_tkn->next;
// 	}
// 	return (0);
// }

static int	unset_1(t_env **env, const char *var_name)
{
	t_env	*temp_env;
	t_env	*prev_env;

	temp_env = *env;
	prev_env = NULL;
	while (temp_env)
	{
		if (ft_strcmp(var_name, temp_env->var_name) == 0)
		{
			if (prev_env == NULL)
				*env = temp_env->next;
			else
				prev_env->next = temp_env->next;
			free(temp_env->var_name);
			free(temp_env->var_value);
			free(temp_env);
			return (0);
		}
		prev_env = temp_env;
		temp_env = temp_env->next;
	}
	return (1); 
}
int	ms_unset(t_env **env, t_token *tkn)
{
	t_token	*temp_tkn;
	char	*var_name;

	temp_tkn = tkn->next;
	while (temp_tkn)
	{
		var_name = check_var_name(temp_tkn->word);
		unset_1(env, var_name);
		temp_tkn = temp_tkn->next;
	}
	return (0);
}
