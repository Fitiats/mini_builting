/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trahanta <trahanta@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 12:58:22 by trahanta          #+#    #+#             */
/*   Updated: 2024/12/29 23:23:01 by trahanta         ###   ########.fr       */
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
int	ms_echo(t_token *tkn)
{
	t_token	*temp;

	temp = tkn;
	temp = temp->next;
	if (valid_option(temp->word) == 0)
	{
		temp = temp->next;
		while (temp)
		{
			printf("%s", temp->word);
			if (temp->next)
				printf(" ");
			temp = temp->next;
		}
	}
	else
	{
		while (temp)
		{
			printf("%s", temp->word);
			if (temp->next)
				printf(" ");
			temp = temp->next;
		}
		printf("\n");
	}
	return (0);
}
