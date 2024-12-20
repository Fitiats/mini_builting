/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmory <tmory@student.42antananarivo.mg>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 13:34:08 by trahanta          #+#    #+#             */
/*   Updated: 2024/12/13 11:20:26 by tmory            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

static void	ms_pars_addback(t_redir **lst, t_redir *new)
{
	t_redir	*temp;

	if (!(*lst))
	{
		*lst = new;
		return ;
	}
	temp = *lst;
	while (temp->next)
		temp = temp->next;
	temp->next = new;
}
static void	ms_cmd_addback(t_char_struct **lst, t_char_struct *new)
{
	t_char_struct	*temp;

	if (!(*lst))
	{
		*lst = new;
		return ;
	}
	temp = *lst;
	while (temp->next)
		temp = temp->next;
	temp->next = new;
}

static void ms_init_pars_struct(t_parsing *lst)
{
    lst->cmd = NULL;
    lst->arg = NULL;
    lst->redir = NULL;
}
static void ms_init_cmd_struct(t_char_struct *lst)
{  
    lst->s = NULL;
    lst->next = NULL;
}

static char	*ms_strdup_splitslash(char *s)
{
	char	*dest;
	int		i;

	i = 1;
	dest = (char *) malloc (sizeof(char) * (ft_strlen(s)));
	if (dest == NULL)
		return (NULL);
	while (s[i])
	{
		dest[i - 1] = s[i];
		i++;
	}
	dest[i - 1] = '\0';
	return (dest);
}

static int ms_pars_cmd_tochar(t_parsing *pars, t_char_struct *cmd)
{
    t_char_struct *temp;
    int i;

    temp = cmd;
    i = 0;
    while (temp)
    {
        i++;
        temp = temp->next;
    }
    pars->arg = malloc(sizeof(char *) * (i + 2));
    if (pars->arg == NULL)
    {
        ms_free_arg(pars);
        return (ms_free_cmd(cmd), 1);
    }
    temp = cmd;
    i = 0;
    pars->arg[i] = ms_strdup_splitslash(pars->cmd);
    if (pars->arg[i] == NULL)
    {
        ms_free_arg(pars);
        return (ms_free_cmd(cmd), 1);
    }
    i++;
    while (temp)
    {
        pars->arg[i] = ft_strdup(temp->s);
        if (pars->arg[i] == NULL)
        {
            ms_free_arg(pars);
            return (ms_free_cmd(cmd), 1);
        }
        i++;
        temp = temp->next;
    }
    pars->arg[i] = NULL;
    ms_free_cmd(cmd);
    return (0);
}

int ms_parsing(t_token *tkn, t_parsing *pars)
{
    t_token *temp;
    t_redir *redir;
    t_char_struct *cmd_arg;
    t_char_struct *new_cmd_arg;
    unsigned int rank;
    int type_redir;
    
    rank = INT_MAX;
    temp = tkn;
    ms_init_pars_struct(pars);
    cmd_arg = NULL;
    while(temp)
    {
        if(temp->type != WORD && temp->next)
        {
            type_redir = temp->type;
            temp = temp->next;
            redir = malloc(sizeof(t_redir));
            if (!redir)
                return (1);
            redir->file = ft_strdup(temp->word);
            if (redir->file == NULL)
                return (1);
            redir->next = NULL;
            redir->type = type_redir;
            ms_pars_addback(&(pars->redir), redir);
        }
        else if(temp->type == WORD && temp->rank < rank)
        {
            pars->cmd = ft_strjoin("/",temp->word);
            // pars->cmd = ft_strdup(temp->word);
            if (pars->cmd == NULL)
                return (1);
            rank = temp->rank;
        }
        else
        {
            new_cmd_arg = malloc(sizeof(t_char_struct));
             if (!new_cmd_arg)
                return (1);
            ms_init_cmd_struct(new_cmd_arg);
            new_cmd_arg->s = ft_strdup(temp->word);
            if (new_cmd_arg->s == NULL)
                return (1);
            ms_cmd_addback(&cmd_arg, new_cmd_arg);
        }
        temp = temp->next;
    }
  
    if (ms_pars_cmd_tochar(pars, cmd_arg))
        return (1);

    return (0);
}