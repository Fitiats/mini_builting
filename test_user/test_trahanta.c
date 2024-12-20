/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_trahanta.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trahanta <trahanta@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 13:56:58 by trahanta          #+#    #+#             */
/*   Updated: 2024/12/17 11:15:39 by trahanta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"
#include <stdio.h>

int print_split(t_token *token)
{
	int i;
	t_token *temp;

	i = 0;
	temp = token;
	while (token)
	{
		token = token->next;
		i++;
	}
	printf("==> token :%d\n", i);
	token = temp;
	while (token)
	{
		printf("%s, rank %d, type %d\n", token->word, token->rank, token->type);
		token = token->next;
		i++;
	}
	return (i);
}

void print_charpp(char **tab)
{
	for (int i = 0; tab[i]; i++)
		printf("%s\n", tab[i]);
}

void print_pars(t_parsing *pars)
{
	int i;
	t_redir *temp;

	i = 0;
	temp = pars->redir;
	printf("\n\nPARSING\n");
	printf("CMD = \033[32m%s\033[0m\n", pars->cmd);
	printf("ARG :");
	if (pars->arg)
	{
		while (pars->arg[i])
		{
			printf(" \033[32m%s\033[0m", pars->arg[i]);
			i++;
		}
	}
	else
	{
		printf("\033[91mno arg\033[0m\n");
	}
	printf("\n REDIRECTION :");
	if (!temp)
		printf("\033[91mno redirection\033[0m\n");
	while (temp)
	{
		printf(" (%d)%s ", temp->type, temp->file);
		temp = temp->next;
	}
	printf("\n");
	
}
