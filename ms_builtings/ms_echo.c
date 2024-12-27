/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trahanta <trahanta@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 12:58:22 by trahanta          #+#    #+#             */
/*   Updated: 2024/12/23 14:47:44 by trahanta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	valid_option(char *s)
{
	int	i;

	i = 0;
	if(s[i] == '-' && s[i + 1] == 'n')
	{
		i += 2;
		while(s[i] == 'n')
		{
			return (0);
		i++;
		}
	}
	return (1);
}
int	ms_echo(t_token *tkn)
{
	t_token	*temp;

	temp = tkn;
	temp = temp->next;
	// if (ft_strcmp(temp->word, "-n") == 0)
	if (valid_option(temp->word) == 0)
	{
		temp = temp->next;
		while (temp)
		{
			printf("%s ", temp->word);
			temp = temp->next;
		}
	}
	else
	{
		while (temp)
		{
			printf("%s ", temp->word);
			temp = temp->next;
		}
		printf("\n");
	}
	return (0);
}
