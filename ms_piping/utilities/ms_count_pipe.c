/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_count_pipe.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmory <tmory@student.42antananarivo.mg>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 15:25:23 by tmory             #+#    #+#             */
/*   Updated: 2024/12/09 15:39:30 by tmory            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int ms_count_pipe(t_token *token)
{
	t_token *temp;
	int pipe_number;

	temp = token;
	pipe_number = 0;
	while (temp)
	{
		if (temp->type == PIPE)
			pipe_number++;
		temp = temp->next;
	}
	return (pipe_number);
}
