/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgejno <vgejno@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 12:48:33 by vgejno            #+#    #+#             */
/*   Updated: 2022/05/06 17:33:29 by vgejno           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_unrefined(int fd, char *remainder)
{
	char		*buf;
	int			byte_was_read;

	buf = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buf)
		return (NULL);
	byte_was_read = 1;
	while ((byte_was_read != 0) && (!ft_strchr(remainder, '\n')))
	{
		byte_was_read = read(fd, buf, BUFFER_SIZE);
		if (byte_was_read == -1)
		{
			free(buf);
			return (NULL);
		}
		buf[byte_was_read] = '\0';
		remainder = ft_strjoin(remainder, buf);
	}
	free (buf);
	return (remainder);
}

char	*ft_pureline(char *remainder)
{
	int		i;
	char	*line;

	i = 0;
	if (!remainder[i])
		return (NULL);
	while (remainder[i] && remainder[i] != '\n')
		i++;
	line = (char *)malloc(sizeof(char) * (i + 2));
	if (!line)
		return (NULL);
	i = 0;
	while (remainder[i] && remainder[i] != '\n')
	{
		line[i] = remainder[i];
		i++;
	}
	if (remainder[i] == '\n')
	{
		line[i] = remainder[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

char	*ft_restremainder(char *remainder)
{
	int		i;
	int		j;
	char	*line;

	i = 0;
	while (remainder[i] && remainder[i] != '\n')
		i++;
	if (!remainder[i])
	{
		free (remainder);
		return (NULL);
	}
	line = (char *)malloc(sizeof(char) * (ft_strlen(remainder) - i + 2));
	if (!line)
		return (NULL);
	i++;
	j = 0;
	while (remainder[i])
		line[j++] = remainder[i++];
	line[j] = '\0';
	free (remainder);
	return (line);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*remainder;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	remainder = ft_unrefined(fd, remainder);
	if (!remainder)
		return (NULL);
	line = ft_pureline(remainder);
	remainder = ft_restremainder(remainder);
	return (line);
}
