/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_pipe_utilities.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trahanta <trahanta@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 14:21:10 by trahanta          #+#    #+#             */
/*   Updated: 2024/12/29 21:46:31 by trahanta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"
#include <stdio.h>

void ms_pars_free_redir(t_redir *lst)
{
	t_redir *temp;

	if (!lst)
		return;
	while (lst)
	{
		temp = lst;
		free(lst->file);
		lst->type = 0;
		lst = lst->next;
		free(temp);
	}
	return ;
}

void ms_free_arg( t_parsing *arg)
{
    int i;
    
    i = 0;
    if (arg->arg == NULL)
        return ;
    while (arg->arg[i])
    {
        free(arg->arg[i]);
        i++;
    }
    free(arg->arg);
    arg->arg = NULL;
}

void ms_free_pars(t_parsing *pars)
{
    if(pars->cmd)
         free(pars->cmd);
    if (pars->redir)
        ms_pars_free_redir(pars->redir);
    if (pars->arg)
        ms_free_arg(pars);
    // if (pars)
    //     free(pars);
}

void ms_free_cmd(t_char_struct *lst)
{
    t_char_struct *temp;
    if (!lst)
		return;
	while (lst)
	{
		temp = lst;
		free(lst->s);
		lst = lst->next;
		free(temp);
	}
	return ;
}

int ms_redir_error(t_token *tkn)
{
    t_token *temp;

    temp = tkn;
    while(temp)
    {
        if((temp->type != WORD && temp->type != PIPE ) && temp->next == NULL)
        {
            ft_putstr_fd("minishell: syntax error near unexpected token \'newline\'", 2);
            ft_putchar_fd('\n', 2);
            return (1);
        }
        if((temp->type != WORD && temp->type != PIPE )&& (temp->next->type != 1 && temp->next->type != 2))
        {
            ft_putstr_fd("minishell: syntax error near unexpected token ", 2);
            ft_putstr_fd(temp->next->word, 2);
            ft_putchar_fd('\n', 2);
            return (1);
        }
        
        temp = temp->next;
    }
    return (0);
}