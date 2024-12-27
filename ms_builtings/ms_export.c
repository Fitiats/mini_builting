/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trahanta <trahanta@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 10:22:46 by trahanta          #+#    #+#             */
/*   Updated: 2024/12/27 10:43:10 by trahanta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"


 void  print_env(t_env *env)
{
    t_env *temp_env;

    temp_env = env;
    while(temp_env)
    {
        // if(ft_strcmp(temp_env->var_name, temp_env->next->var_name) > 0)
        // {
        //      printf("export %s=%s\n", temp_env->next->var_name, temp_env->next->var_value);
        // }
        // else 
        // {
        //      printf("export %s=%s\n", temp_env->var_name, temp_env->var_value);
        // }
        printf("export %s=%s\n", temp_env->var_name, temp_env->var_value);
        temp_env = temp_env->next;
    }
 }

int ms_export_var(t_token *tkn, t_env *env)
{
    t_token *temp;
    // char **list_var;

    temp = tkn;
    temp = temp->next;
    
    if(temp == NULL)
        print_env(env);
    return (0);
}