/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_split_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmory <tmory@student.42antananarivo.mg>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 15:06:28 by tmory             #+#    #+#             */
/*   Updated: 2024/12/03 15:28:21 by tmory            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int	**ft_free_malloc(char **p, int i)
{
	while (p[i--])
		free(p[i]);
	free(p);
	return (NULL);
}

void	ms_spltk_init_token(t_token *token, int i)
{
	token->word = NULL;
	token->rank = i + 1;
	token->type = WORD;
	token->next = NULL;
	return ;
}

int	ft_strcmp(const char *s1, const char *s2)
{
	size_t	i;

	i = 0;
	if (ft_strlen(s1) != ft_strlen(s2))
		return (1);
	while ((*s1 != '\0' || *s2 != '\0'))
	{
		if (*s1 != *s2)
		{
			return (*(unsigned char *)s1 - *(unsigned char *)s2);
		}
		s1++;
		s2++;
		i++;
	}
	return (0);
}

void	ms_recursive_quotes(const char *s, int *i)
{
	(*i)++;
	while (ms_is_quotes(s[*i]) == 0 && s[*i])
		(*i)++;
	(*i)++;
	if (*i > (int)ft_strlen(s))
		(*i)--;
	if (ms_is_quotes(s[*i]) == 1)
		ms_recursive_quotes(s, i);
	return ;
}

void	ms_recursive_singlequotes(const char *s, int *i)
{
	(*i)++;
	while (ms_is_singlequotes(s[*i]) == 0 && s[*i])
		(*i)++;
	(*i)++;
	if (*i > (int)ft_strlen(s))
		(*i)--;
	if (ms_is_singlequotes(s[*i]) == 1)
		ms_recursive_singlequotes(s, i);
	return ;
}
