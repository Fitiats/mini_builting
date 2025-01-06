/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trahanta <trahanta@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 12:58:22 by trahanta          #+#    #+#             */
/*   Updated: 2025/01/06 09:49:40 by trahanta         ###   ########.fr       */
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
static void print_token(t_token *tkn)
{
	t_token *temp;
	
	temp = tkn;
	while (temp)
		{
			printf("%s", temp->word);
			if (temp->next)
				printf(" ");
			temp = temp->next;
		}
}
int	ms_echo(t_token *tkn)
{
	t_token	*temp;

	temp = tkn;
	temp = temp->next;
	if (valid_option(temp->word) == 0)
	{
		temp = temp->next;
		print_token(temp);
	}
	else
	{
		print_token(temp);
		printf("\n");
	}
	return (0);
}
