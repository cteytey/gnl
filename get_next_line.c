/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 14:34:51 by judehon           #+#    #+#             */
/*   Updated: 2025/10/31 21:19:40 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	ft_readloop(int fd, char **s, char *buffer)
{
	int		size;
	char	*tmp;

	size = 1;
	while (!ft_strchr(*s, '\n') && size > 0)
	{
		size = read(fd, buffer, BUFFER_SIZE);
		if (size <= 0)
			return (size);
		buffer[size] = '\0';
		tmp = ft_strjoin(*s, buffer);
		free(*s);
		*s = tmp;
	}
	return (size);
}

static char	*ft_readsave(int fd, char *s)
{
	char	*buffer;
	int		size;

	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	if (!s)
	{
		s = malloc(1);
		if (!s)
			return (free (buffer), NULL);
		s[0] = '\0';
	}
	size = ft_readloop(fd, &s, buffer);
	free(buffer);
	if (size <= 0)
	{
		if (size == 0 && s[0] != '\0')
			return (s);
		free(s);
		return (NULL);
	}
	return (s);
}

static char	*ft_get_line(char *s)
{
	char	*line;
	int		i;

	i = 0;
	while (s[i] && s[i] != '\n')
		i++;
	line = malloc(sizeof(char) * (i + (s[i] == '\n') + 1));
	if (!line)
		return (NULL);
	i = 0;
	while (s[i] && s[i] != '\n')
	{
		line[i] = s[i];
		i++;
	}
	if (s[i] == '\n')
	{
		line[i] = '\n';
		i++;
	}
	line[i] = '\0';
	return (line);
}

static char	*ft_save_rest(char *s)
{
	char	*rest;
	int		i;
	int		j;

	i = 0;
	while (s[i] && s[i] != '\n')
		i++;
	if (!s[i])
	{
		free (s);
		return (NULL);
	}
	rest = malloc(sizeof(char) * (ft_strlen(s) - i + 1));
	if (!rest)
		return (NULL);
	i++;
	j = 0;
	while (s[i])
		rest[j++] = s[i++];
	rest[j] = '\0';
	free (s);
	return (rest);
}

char	*get_next_line(int fd)
{
	static char	*rest;
	char		*line;

	rest = ft_readsave(fd, rest);
	if (!rest)
		return (NULL);
	line = ft_get_line(rest);
	if (!line)
	{
		free(rest);
		rest = NULL;
		return (NULL);
	}
	rest = ft_save_rest(rest);
	return (line);
}

/*
#include <stdio.h>
int	main()
{
	int	fd = open("get_next_line.c", O_RDONLY);
	char	*line;
	while ((line = get_next_line(fd)))
	{
		printf("%s", line);
		free (line);
	}
	close (fd);
}*/