/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_clean_quotes.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmory <tmory@student.42antananarivo.mg>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 16:17:10 by tmory             #+#    #+#             */
/*   Updated: 2024/11/21 16:20:57 by tmory            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../minishell.h"

static void	ms_cq_cl_ifloop(char const *s, int *i, int *count, int f(char c))
{
	(*i)++;
	while (f(s[*i]) == 0)
	{
		(*i)++;
		(*count)++;
	}
	(*i)++;
}

static int	ms_cq_count_len(char const *s, int i, int count)
{
	while (s[i])
	{
		if (ms_is_quotes(s[i]) == 1)
		{
			ms_cq_cl_ifloop(s, &i, &count, ms_is_quotes);
			continue ;
		}
		else if (ms_is_singlequotes(s[i]) == 1)
		{
			ms_cq_cl_ifloop(s, &i, &count, ms_is_singlequotes);
			continue ;
		}
		count++;
		i++;
	}
	return (count);
}

static int	ms_cq_assign_char(char *src, char *trg, int i, int j)
{
	while (src[i])
	{
		if (ms_is_quotes(src[i]) == 1)
		{
			i++;
			while (ms_is_quotes(src[i]) == 0)
				trg[j++] = src[i++];
			i++;
			continue ;
		}
		else if (ms_is_singlequotes(src[i]) == 1)
		{
			i++;
			while (ms_is_singlequotes(src[i]) == 0)
				trg[j++] = src[i++];
			i++;
			continue ;
		}
		trg[j++] = src[i++];
	}
	trg[j++] = '\0';
	return (0);
}

int	ms_clean_quotes(t_token *word)
{
	char	*temp;

	temp = (char *)malloc(sizeof(char) * (ms_cq_count_len(word->word, 0, 0)
				+ 1));
	if (!temp)
		return (ft_free_split(word), 1);
	ms_cq_assign_char(word->word, temp, 0, 0);
	free(word->word);
	word->word = NULL;
	word->word = ft_strdup(temp);
	free(temp);
	return (0);
}
