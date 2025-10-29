/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: judehon <judehon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 14:34:51 by judehon           #+#    #+#             */
/*   Updated: 2025/10/29 17:27:02 by judehon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_remove_end(char *str)
{
	int	i;
	int	j;
	int	tmp;
	char	*new;

	i = ft_strlen(str);
	while (str[i] != '\n')
		i--;
	tmp = i;
	new = malloc(sizeof(char) * tmp + 1);
	if (!new)
		return (NULL);
	i = 0;
	j = 0;
	while (j < tmp)
		new[j++] = str[i++];
	new[j] = '\0';
	return (new);
}

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
	s = ft_remove_end(s);
	return (s);
}

char	*get_next_line(int fd)
{

}

#include <stdio.h>
int	main()
{
	printf("%s\n", ft_read_join(open("test.txt", O_RDWR)));
	printf("%s\n", ft_read_join(open("test.txt", O_RDWR)));
}