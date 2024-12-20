/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_env_to_char.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trahanta <trahanta@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 10:04:06 by trahanta          #+#    #+#             */
/*   Updated: 2024/12/17 14:51:08 by trahanta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	*ft_strjoin_equal(char const *s1, char c, char const *s2)
{
	char	*str;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!s1 && !s2)
		return (NULL);
	str = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 2);
	if (!str)
		return (NULL);
	while (s1[i] != '\0')
	{
		str[i] = (char)s1[i];
		i++;
	}
	str[i] = c;
	i++;
	while (s2[j] != '\0')
	{
		str[i++] = (char)s2[j++];
	}
	str[i] = '\0';
	return (str);
}

int	ms_count_env(t_env *env)
{
	t_env	*temp;
	int		count;

	count = 0;
	temp = env;
	while (temp)
	{
		count++;
		temp = temp->next;
	}
	return (count);
}
int	ms_env_to_char(t_env *env, char **list_env)
{
	int		count;
	t_env	*temp;

	temp = env;
	count = 0;
	while (temp)
	{
		list_env[count] = ft_strjoin_equal(temp->var_name, '=',
				temp->var_value);
		if (!list_env)
			return (ft_free_split_char(list_env), 1);
		temp = temp->next;
		count++;
	}
	list_env[count] = NULL;
	if (list_env[0] == NULL)
		return (1111);
	return (0);
}
