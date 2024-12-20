/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_function_built.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trahanta <trahanta@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 10:25:13 by trahanta          #+#    #+#             */
/*   Updated: 2024/12/20 10:04:51 by trahanta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../minishell.h"

t_token *ms_take_first_token(t_token *tkn, unsigned int rank)
{
    t_token *temp;

    if(tkn == NULL)
        return (NULL);
    temp = tkn;
    while(temp)
    {
        if(temp->rank == rank)
        {   
           // printf("atoo\n");
            return (temp);
        }
    
        // printf("rank = %d, word = %s", temp->rank, temp->word);
        temp = temp->next;
    }
    return (NULL);
}

void test_built(t_token *tkn, t_env *env)
{
    (void)env;
    t_token *temp;
    
    temp = tkn;
    if(temp->rank == 1 && (ft_strcmp(temp->word, "echo") == 0))
    {
        ms_echo(tkn);
    }
}