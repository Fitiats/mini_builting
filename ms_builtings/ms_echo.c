/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trahanta <trahanta@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 12:58:22 by trahanta          #+#    #+#             */
/*   Updated: 2024/12/20 15:21:02 by trahanta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

// void	ms_rm_new_ligne(t_token *tkn)
// {
// 	t_token	*temp;
// 	int		i;
// 	int		count;

// 	i = 0;
// 	temp = tkn;
// 	while (temp->word[i])
// 	{
// 		if (ft_strchr(temp->word, '\n'))
// 		{
// 			count = ft_strlen(temp->word);
// 		}
// 		i++;
// 	}
// }

// int	ms_count_token(t_token *tkn)
// {
// 	int		count;
// 	t_token	*temp;

// 	temp = tkn;
// 	while (temp)
// 	{
// 		count++;
// 		temp = temp->next;
// 	}
// 	return (count);
// }

int valid_option(char *s)
{
	int i;

	i = 0;
	while(s[i])
	{
		if(s[i] == '-' && s[i + 1] == 'n')
			return (1);
		i++;
	}
	return (0);
}
int	ms_echo(t_token *tkn)
{
	t_token	*temp;

	temp = tkn;
	temp = temp->next;
	// if (ft_strcmp(temp->word, "-n") == 0)
	if (valid_option(temp->word) == 1)
	{
		temp = temp->next;
		while (temp)
		{
			printf("%s", temp->word);
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
