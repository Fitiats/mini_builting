/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trahanta <trahanta@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 12:58:22 by trahanta          #+#    #+#             */
/*   Updated: 2025/01/08 00:10:33 by trahanta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	valid_option(char *s)
{
	int	i;

	i = 0;
	if (s[i] == '-' && s[i + 1] == 'n')
	{
		i += 2;
		while (s[i] == 'n')
		{
			i++;
		}
		if (s[i] == '\0')
			return (0);
	}
	return (1);
}
// static char *get_var_value(t_env *env, char *var_name)
// {
// 	t_env *temp;

// 	while(temp)
// 	{
// 		if(ft_strcmp(temp->var_name, var_name) == 0)
// 			return (temp->var_value);
// 		temp = temp->next;
// 	}
// 	return (NULL);
// }
static void	print_token(t_token *tkn)
{
	t_token	*temp;

	temp = tkn;
	while (temp)
	{
		if(temp->word[0] == '\\')
			printf("%s", temp->word + 1);
		else
			printf("%s", temp->word);
		if (temp->next)
			printf(" ");
		temp = temp->next;
	}
}
int	ms_echo(t_token *tkn)
{
	t_token	*temp;
	// char *value;

	temp = tkn;
	temp = temp->next;
	if (temp == NULL)
		printf("\n");
	// if(temp->word[0] == '$')
	// {
	// 	value = get_var_value(env, temp->word + 1);
	// }
	if (temp && valid_option(temp->word) == 0)
	{
		temp = temp->next;
		while (temp && valid_option(temp->word) == 0)
		{
			temp = temp->next;
		}
		if (temp)
			print_token(temp);
	}
	else
	{
		print_token(temp);
		printf("\n");
	}
	return (0);
}
