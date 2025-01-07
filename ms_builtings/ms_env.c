/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trahanta <trahanta@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 15:11:03 by trahanta          #+#    #+#             */
/*   Updated: 2025/01/07 15:22:55 by trahanta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	ms_env(t_env *env)
{
	t_env *temp_env;

	temp_env = env;
	while (temp_env)
	{
		printf("%s=%s\n", temp_env->var_name, temp_env->var_value);
		temp_env = temp_env->next;
	}
}