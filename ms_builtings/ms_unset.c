/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_unset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trahanta <trahanta@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 09:58:19 by trahanta          #+#    #+#             */
/*   Updated: 2025/01/06 10:36:22 by trahanta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	ms_unset(t_env *env, t_token *tkn)
{
	t_token *temp_tkn;
    t_env *temp_env;
	char *var_name;

	temp_tkn = tkn;
    temp_env = env;
    temp_tkn = temp_tkn->next;
	while (temp_tkn)
	{
		var_name = check_var_name(temp_tkn->word);
        while(temp_env)
        {
            if(ft_strcmp(var_name, temp_env->var_name)==0)
            {
                free(temp_env->var_name);
                free(temp_env->var_value);
                free(temp_env);
                return (0);
            }
            temp_env = temp_env->next;
        }
        temp_tkn = temp_tkn->next;
	}
	return (1);
}