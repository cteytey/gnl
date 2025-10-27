/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: judehon <judehon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 14:34:51 by judehon           #+#    #+#             */
/*   Updated: 2025/10/27 17:13:05 by judehon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*ft_print_line(int fd)
{
	char	*buffer;
	static char	*s;
	int		size;
	int		i;

	i = 0;
	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	size = read(fd, buffer, BUFFER_SIZE);
	if (size <= 0)
		return (NULL);
	while (buffer[i] && buffer[i] != '\n')
		s = ft_strdup(buffer);
	free(buffer);
	return (s);
}

char	*get_next_line(int fd)
{
	char	*s;
	int		i;

	i = 0;
	while (s[i] != '\n')
		s = ft_print_line(fd);
	return (s);
}

#include <stdio.h>
int	main()
{
	printf("%s\n", get_next_line(open("get_next_line.c", O_RDWR)));
}