/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: judehon <judehon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 14:34:51 by judehon           #+#    #+#             */
/*   Updated: 2025/10/24 17:04:02 by judehon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char	*buffer;
	char	*s;
	static char	*tmp;
	int		size;

	buffer = malloc(BUFFER_SIZE + 1);
	read(fd, buffer, BUFFER_SIZE);
	while (*buffer != '\n')
	{
		s += malloc(sizeof(char) * (BUFFER_SIZE + 1));
		if (!s)
			return (NULL);
		*(s++) = *(buffer++);
	}
	return (s);
}

#include <stdio.h>
int	main()
{
	printf("%s\n", get_next_line(open("get_next_line.c", O_RDWR)));
}