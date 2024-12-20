/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_execution.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trahanta <trahanta@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 14:22:55 by tmory             #+#    #+#             */
/*   Updated: 2024/12/18 14:52:37 by trahanta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"
#include <stdio.h>

static int ms_srch_path(t_env *env, char **path)
{
	t_env *temp;
	
	temp = env;
	while (temp)
	{
		if (ft_strcmp(temp->var_name, "PATH") == 0)
		{
			*path = ft_strdup(temp->var_value);
			if (!*path)
				return (1);
			return (0);
		}
		temp = temp->next;
	}
	return (0);
}
static int ms_exec_noredir(t_parsing *pars, char **path, char *path_string, char **envp)
{
	int i;
	pid_t pid;
	char *pathxc;
	
	pathxc = NULL;
	i = 0;
	while (path[i])
	{
		pathxc = ft_strjoin(path[i], pars->cmd);
		if (!pathxc)
		{
			printf("\033[91merror in ft_strjoin in pathxc\033[0m\n");
			free(path_string);
			ms_free_pars(pars);
			return (ft_free_split_char(path), 1);
		}
		if (access(pathxc, F_OK | X_OK) < 0)
		{
			free(pathxc);
			i++;
			continue ;
		}
		else
		{
			pid = fork();
			if (pid == 0)
			{
				execve(pathxc, pars->arg, envp);
			}
			else if (pid == -1)
			{
				printf("\033[91mERROR in fork() in ms_execution\033[0m\n");
				return (1111);
			}
			wait(NULL);
			free(pathxc);
			ft_free_split_char(envp);

			break;
		}
		free(pathxc);
		// ft_free_split_char(envp);
		
		pathxc = NULL;
		i++;
	}
	return (0);
}

int ms_execution(t_env *env_lst, t_parsing *pars)
{
	char **path;
	char *path_string;
	char **envp;

	path_string = NULL;
	path = NULL;
	envp = NULL;
	if (ms_srch_path(env_lst, &path_string))
		return (1);
	if (!path_string)
		return 0;
	path = ft_ms_split(path_string, ':');
	if (!path)
	{
		free(path_string);
		return (ft_free_split_char(path), 1);
	}
	envp = (char **)malloc(sizeof(char *) * (ms_count_env(env_lst) + 1));
	if (!envp)
		return (1);
	if (ms_env_to_char(env_lst, envp))
		return (1111);
	//execution if redir != NULL
	if (pars->redir == NULL)
	{
		if (ms_exec_noredir(pars, path, path_string, envp))
			return (1111);
	}
	else
	{
		printf("\033[32m MANAGE IF REDIR \033[0m\n");
		if (ms_exec_withredir(pars, path, path_string, envp))
			return (1111);
	}
	free(path_string);
	return (ft_free_split_char(path),0);
}
