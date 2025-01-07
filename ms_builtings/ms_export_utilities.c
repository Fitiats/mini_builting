/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_export_utilities.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trahanta <trahanta@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 10:58:07 by trahanta          #+#    #+#             */
/*   Updated: 2025/01/07 15:39:34 by trahanta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	print_env(t_env *env)
{
	t_env	*temp_env;

	temp_env = env;
	while (temp_env)
	{
		if (temp_env->var_value && temp_env->var_value[0] != '\0')
		{
			printf("export %s=%s\n", temp_env->var_name, temp_env->var_value);
		}
		else
			printf("export %s\n", temp_env->var_name);
		temp_env = temp_env->next;
	}
}
t_env	*find_var(t_env *env, char *var_name)
{
	t_env	*temp_env;

	temp_env = env;
	while (temp_env)
	{
		if (ft_strcmp(temp_env->var_name, var_name) == 0)
			return (temp_env);
		temp_env = temp_env->next;
	}
	return (NULL);
}


char	*ft_strndup(char *s, int n)
{
	char	*dest;
	int		i;

	i = 0;
	dest = (char *)malloc(sizeof(char) * (n + 1));
	if (dest == NULL)
		return (NULL);
	while (i < n && s[i])
	{
		dest[i] = s[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
