/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmory <tmory@student.42antananarivo.mg>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 13:10:58 by tmory             #+#    #+#             */
/*   Updated: 2024/10/31 09:13:06 by tmory            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"


int	main(int ac, char **av, char **envp)
{
	char *cmd;
	int i; //test

	(void)av;
	(void)envp;
	if (ac != 1)
		return (printf("error\n"), 1);
	while (1)
	{
		i = 0; //test
		cmd = readline("$>");
		//TEST_TOKEN
		if (ms_check_error_nbpipe(cmd) == 1)
			return ( printf("have a ||\n"), 0);
		while (cmd[i])
		{
			if (ms_is_relopdouble(&cmd[i]) == 1)
				return ( printf("have a double <<\n"), 0);
			if (ms_is_relationalop(cmd[i]) == 1)
				return ( printf("have a < or > operator\n"), 0);
			if (ms_is_pipe(cmd[i]) == 1)
				return ( printf("have a | \n"), 0);
			if (ms_is_quotes(cmd[i]) == 1)
				return ( printf("have a \" \n"), 0);
			if (ms_isbackslash(cmd[i]) == 1)
				return ( printf("have a \\ \n"), 0);
			i++;
		}
		printf(" %s\n", cmd);
		//ENDTEST_TOKEN
		
		add_history(cmd);
		free(cmd);
	}
	return (0);
}

