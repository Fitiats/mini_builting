/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_envcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trahanta <trahanta@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 11:11:32 by tmory             #+#    #+#             */
/*   Updated: 2025/01/07 11:03:40 by trahanta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

static void	ms_envadd_back(t_env **lst, t_env *new)
{
	t_env	*temp;

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

static void	ms_initenv(t_env *lst)
{
	lst->var_name = NULL;
	lst->var_value = NULL;
	lst->next = NULL;
}

unsigned int	ms_envcpy(t_env **env, char **src)
{
	int		i;
	t_env	*temp;

	i = 0;
	while (src[i])
	{
		temp = (t_env *)malloc(sizeof(t_env));
		if (!temp)
			return (ms_free_env(*env), 1);
		ms_initenv(temp);
		temp->var_name = ft_substr(src[i], 0, (ft_strchr(src[i], '='))
				- src[i]);
		if (!(temp->var_name))
			return (ms_free_env(*env), 1);
		temp->var_value = ft_strdup(getenv(temp->var_name));
		if (!(temp->var_value))
			return (ms_free_env(*env), 1);
		ms_envadd_back(env, temp);
		i++;
	}
	return (0);
}
