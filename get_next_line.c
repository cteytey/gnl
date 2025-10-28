/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: judehon <judehon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 14:34:51 by judehon           #+#    #+#             */
/*   Updated: 2025/10/28 17:07:24 by judehon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*ft_read_join(int fd)
{
	char		*buffer;
	static char	*s;
	int			size;
	char		*tmp;

	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	size = 1;
	while (!ft_strchr(buffer, '\n') && size > 0)
	{
		size = read(fd, buffer, BUFFER_SIZE);
		buffer[size] = '\0';
		if (!s)
			s = ft_strdup(buffer);
		else
		{
			tmp = ft_strjoin(s, buffer);
			free(s);
			s = tmp;
		}
	}
	free(buffer);
	return (s);
}

#include <stdio.h>
int	main()
{
	printf("%s\n", ft_read_join(open("get_next_line.c", O_RDWR)));
}