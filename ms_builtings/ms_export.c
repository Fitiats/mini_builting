/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trahanta <trahanta@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 10:22:46 by trahanta          #+#    #+#             */
/*   Updated: 2025/01/02 22:09:15 by trahanta         ###   ########.fr       */
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

void	print_env_shorted(t_env *env)
{
	t_env	*temp_env;
	t_env	*current;
	t_env	*min_temp;
	t_env	*sorted_list;
	t_env	*sorted_tail;

	sorted_list = NULL;
	sorted_tail = NULL;
	temp_env = env;
	while (temp_env)
	{
		min_temp = temp_env;
		current = temp_env->next;
		while (current)
		{
			if (strcmp(current->var_name, min_temp->var_name) < 0)
				min_temp = current;
			current = current->next;
		}
		if (min_temp == temp_env)
		{
			temp_env = temp_env->next;
		}
		else
		{
			current = temp_env;
			while (current->next != min_temp)
			{
				current = current->next;
			}
			current->next = min_temp->next;
		}
		if (!sorted_list)
		{
			sorted_list = min_temp;
			sorted_tail = min_temp;
		}
		else
		{
			sorted_tail->next = min_temp;
			sorted_tail = min_temp;
		}
		sorted_tail->next = NULL;
	}
	print_env(sorted_list);
}

static t_env	*creat_env_var(char *name, char *value)
{
	t_env	*new_var;

	new_var = (t_env *)malloc(sizeof(t_env));
	if (new_var == NULL)
		return (NULL);
	new_var->var_name = ft_strdup(name);
	new_var->var_value = ft_strdup(value);
	new_var->next = NULL;
	return (new_var);
}

static void	add_back(t_env **head, char *name, char *value)
{
	t_env	*new_node;
	t_env	*temp;

	new_node = creat_env_var(name, value);
	if (new_node == NULL)
		return ;
	if (*head == NULL)
		*head = new_node;
	else
	{
		temp = *head;
		while (temp->next != NULL)
		{
			temp = temp->next;
		}
		temp->next = new_node;
	}
}
int	valid_export_name(char *s)
{
	int	i;

	i = 0;
	if (!(ft_isalpha(s[i]) || s[i] == '_'))
	{
		i++;
		return (1);
	}
	while (s[i] && (ft_isalnum(s[i]) || ft_isalpha(s[i]) || s[i] == '_'))
	{
		i++;
		if (s[i] == '\0')
			return (0);
	}
	return (1);
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

char	*check_var_name(char *s)
{
	char	*name;
	int		i;

	i = 0;
	name = NULL;
	while (s[i] && s[i] != '=')
	{
		i++;
	}
	if (i == 0)
		return (NULL);
	name = ft_strndup(s, i);
	if (!name)
		return (NULL);
	return (name);
}

char	*check_var_value(char *s)
{
	char	*value;
	int		i;
	int		j;

	i = 0;
	j = 1;
	value = NULL;
	while (s[i] && s[i] != '=')
	{
		i++;
	}
	if (s[i] == '\0' && s[i] != '=')
		return (NULL);
	j = j + i;
	if (j == '\0')
		return (NULL);
	value = ft_substr(s, j, ft_strlen(s));
	if (!value)
		return (NULL);
	return (value);
}
int	ms_export_var(t_token *tkn, t_env *env)
{
	t_token *temp;
	char *var_name;
	char *var_value;
	// char **list_var;

	temp = tkn;
	temp = temp->next;

	if (temp == NULL)
		print_env_shorted(env);
	else
	{
		while (temp)
		{
			var_name = check_var_name(temp->word);

			if (var_name == NULL)
			{
				ft_putstr_fd("minishell: export: ", 2);
				ft_putstr_fd(temp->word, 2);
				ft_putstr_fd(": not a valid identifier\n", 2);
				temp = temp->next;
				break ;
			}
			var_value = check_var_value(temp->word);
			if (var_value == NULL)
			{
				char *next_name_var;
				if (temp->next != NULL)
				{
					next_name_var = check_var_name(temp->next->word);
					if (next_name_var == NULL)
					{
						ft_putstr_fd("minishell: export: ", 2);
						ft_putstr_fd(temp->word, 2);
						ft_putstr_fd(": not a valid identifier\n", 2);
						temp = temp->next;
						break ;
					}
				}
				else
					add_back(&env, var_name, var_value);
			}
			if (valid_export_name(var_name) == 0)
			{
				add_back(&env, var_name, var_value);
				//	print_split(temp);
			}
			else
			{
				ft_putstr_fd("minishell: export: ", 2);
				ft_putstr_fd(temp->word, 2);
				ft_putstr_fd(": not a valid  identifier\n", 2);
			}
			// print_env(env);
			// if(var_name)
			//     printf("%s\n", var_name);
			// if(var_value)
			//     printf("%s",var_value);
			temp = temp->next;
		}
	}
	return (0);
}