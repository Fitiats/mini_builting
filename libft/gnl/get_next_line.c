/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmory@student.42antananarivo.mg <tmory>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 13:40:14 by tmory             #+#    #+#             */
/*   Updated: 2024/08/31 12:32:56 by tmory@stude      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*ft_size_condition(int *size, char *buf, char *rest)
{
	char	*temp;

	buf[*size] = '\0';
	if (!rest)
		rest = ft_strjoin("", buf);
	else
	{
		temp = ft_strjoin("", rest);
		free(rest);
		rest = ft_strjoin(temp, buf);
		free(temp);
	}
	return (rest);
}

static char	*ft_read(char *rest, int fd, int *size)
{
	char	*buf;

	buf = (char *)malloc(BUFFER_SIZE + 1);
	if (!buf)
		return (NULL);
	*size = read(fd, buf, BUFFER_SIZE);
	if (*size < 0)
		return (free(buf), NULL);
	else if (*size == 0)
	{
		if (!rest)
			return (free(buf), NULL);
		return (free(buf), rest);
	}
	rest = ft_size_condition(size, buf, rest);
	return (free(buf), rest);
}

static char	*ft_put_into_line(int *k, char *rest)
{
	int		size;
	int		i;
	char	*line;

	line = (char *)malloc(*k + 1);
	size = *k;
	i = -1;
	while (rest[++i] != '\0' && rest[i] != '\n')
		line[i] = rest[i];
	line[i] = '\0';
	if (rest[i] == '\n')
	{
		i = -1;
		free (line);
		line = (char *)malloc(size + 2);
		while (rest[++i] != '\n')
			line[i] = rest[i];
		line[i] = '\n';
		line[i + 1] = '\0';
	}
	return (line);
}

char	*ft_is_begin_by_nl(char *rest, int *k)
{
	char	*line;

	if (rest[0] == '\n')
	{
		line = (char *)malloc(2);
		line[0] = '\n';
		line[1] = '\0';
	}
	else
		line = ft_put_into_line(k, rest);
	return (free(rest), line);
}

char	*get_next_line(int fd)
{
	char		*line;
	char		*temp;
	int			size;
	int			i;
	static char	*rest;

	i = 0;
	size = 1;
	line = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	while (i == 0 && size != 0)
	{
		rest = ft_read(rest, fd, &size);
		if (!rest)
			return (NULL);
		i = ft_check_new_line(rest);
	}
	if (rest[0] == '\0')
		return (free(rest), NULL);
	i = ft_i(rest);
	temp = ft_substr(rest, i + 1, ft_strlen(rest) - (i + 1));
	line = ft_is_begin_by_nl(rest, &i);
	rest = ft_strjoin("", temp);
	return (free(temp), line);
}
