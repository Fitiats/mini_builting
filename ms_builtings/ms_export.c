/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trahanta <trahanta@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 10:22:46 by trahanta          #+#    #+#             */
/*   Updated: 2025/01/06 23:29:40 by trahanta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	print_env_shorted(t_env *env)
{
	t_env	*current;
	t_env	*next;
	int		swapped;
	char	*temp_name;
	char	*temp_value;

	if (env == NULL || env->next == NULL)
		return ;
	swapped = 1;
	while (swapped)
	{
		swapped = 0;
		current = env;
		while (current != NULL && current->next != NULL)
		{
			next = current->next;
			if (strcmp(current->var_name, next->var_name) > 0)
			{
				temp_name = current->var_name;
				temp_value = current->var_value;
				current->var_name = next->var_name;
				current->var_value = next->var_value;
				next->var_name = temp_name;
				next->var_value = temp_value;
				swapped = 1;
			}
			current = current->next;
		}
	}
	print_env(env);
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
	t_env	*exist_var;

	exist_var = find_var(*head, name);
	if (exist_var != NULL)
	{
		free(exist_var->var_value);
		exist_var->var_value = ft_strdup(value);
	}
	else
	{
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
static void	print_export_error(char *word)
{
	ft_putstr_fd("minishell: export: ", 2);
	ft_putstr_fd(word, 2);
	ft_putstr_fd(": not a valid identifier\n", 2);
}

int	process_no_value(t_token *temp, char *var_name, t_env *env)
{
	char	*next_name_var;

	next_name_var = NULL;
	if (temp->next != NULL)
	{
		next_name_var = check_var_name(temp->next->word);
		if (next_name_var == NULL)
		{
			print_export_error(temp->next->word);
			free(var_name);
			return (1);
		}
		free(next_name_var);
	}
	add_back(&env, var_name, NULL);
	free(var_name);
	return (0);
}
static int schr_var(t_env *env, char *var_name)
{
	t_env	*temp_env;

	temp_env = env;
	while (temp_env)
	{
		if (ft_strcmp(temp_env->var_name, var_name) == 0)
			return (0);
		temp_env = temp_env->next;
	}
	return (1);
}
int	process_variable(t_token *temp, t_env *env)
{
	char	*var_name;
	char	*var_value;

	var_name = check_var_name(temp->word);
	if (var_name == NULL)
	{
		if (temp->next == NULL)
		{
			print_export_error(temp->word);
			return (1);
		}
		else
		{
			print_export_error(temp->next->word);
			return (1);
		}
	}
	if (valid_export_name(var_name) != 0)
	{
		print_export_error(temp->word);
		free(var_name);
		return (1);
	}
	var_value = check_var_value(temp->word);
	if (var_value == NULL)
		return (process_no_value(temp, var_name, env));
	add_back(&env, var_name, var_value);
	free(var_name);
	free(var_value);
	return (0);
}

int	ms_export_var(t_token *tkn, t_env *env)
{
	t_token	*temp;

	temp = tkn;
	temp = temp->next;
	
	if (temp == NULL || (temp->word[0] == '$' && schr_var(env, temp->word + 1) == 1))
	{
		print_env_shorted(env);
		return (0);
	}
	while (temp)
	{
		if (process_variable(temp, env))
			break ;
		temp = temp->next;
	}
	return (0);
}
