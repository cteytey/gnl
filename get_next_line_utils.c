/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/25 14:13:04 by marvin            #+#    #+#             */
/*   Updated: 2025/10/25 14:13:04 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	len;
	size_t	i;
	size_t	j;
	char	*final_str;

	if (!s1 || !s2)
		return (NULL);
	len = ft_strlen(s1) + ft_strlen(s2);
	final_str = malloc(sizeof(char) * (len + 1));
	if (!final_str)
		return (NULL);
	i = 0;
	j = 0;
	while (s1[j])
		final_str[i++] = s1[j++];
	j = 0;
	while (s2[j])
		final_str[i++] = s2[j++];
	final_str[i] = '\0';
	return (final_str);
}

char	*ft_strchr(const char *s, int c)
{
	while (*s)
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	if (*s == (char)c)
		return ((char *)s);
	return (NULL);
}

char	*ft_strdup(const char *s)
{
	char	*dest;
	int		i;

	dest = malloc(sizeof(const char) * (ft_strlen(s) + 1));
	i = 0;
	if (!dest)
		return (0);
	while (s[i])
	{
		dest[i] = s[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
