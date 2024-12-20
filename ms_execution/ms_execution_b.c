/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_execution_b.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trahanta <trahanta@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 07:38:51 by tmory             #+#    #+#             */
/*   Updated: 2024/12/17 15:07:27 by trahanta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int ms_exec_withredir(t_parsing *pars, char **path, char *path_string, char **envp)
{
	int i;
	pid_t pid;
	char *pathxc;
	t_redir *temp_redir;
	
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
			int fd;
			
			if (pid == 0)
			{
				temp_redir = pars->redir;
				while (temp_redir)
				{
					if (temp_redir->type == OUTPUT)
						fd  = open(temp_redir->file, O_WRONLY | O_CREAT | O_TRUNC, 0644);
					else if (temp_redir->type == OUT_HEREDOC)
						fd  = open(temp_redir->file, O_WRONLY | O_CREAT | O_APPEND, 0644);
					else if (temp_redir->type == INPUT)
					{
						fd  = open(temp_redir->file, O_RDONLY);
						if (fd < 0)
							return (perror("minishell :"), 1111);
						dup2(fd, STDIN_FILENO);
						execve(pathxc, pars->arg, envp); // EXECVE
					}
					if (fd < 0)
						return (1111);
					if (temp_redir->next)
						close(fd);
					temp_redir = temp_redir->next;
				}
				dup2(fd, STDOUT_FILENO);
				execve(pathxc, pars->arg, envp); // EXECVE
			}
			else if (pid == -1)
			{
				printf("\033[91mERROR in fork() in ms_execution\033[0m\n");
				return (1111);
			}
			wait(NULL);
			ft_free_split_char(envp);
			free(pathxc);
			pathxc = NULL;
			break;
		}
		i++;
	}
	return (0);
}
