/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgejno <vgejno@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 12:49:02 by vgejno            #+#    #+#             */
/*   Updated: 2022/05/02 13:15:16 by vgejno           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <sys/stat.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <string.h>
# include <stdio.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

char	*get_next_line(int fd);
char	*ft_unrefined(int fd, char *remainder);
char	*ft_pureline(char *remainder);
char	*ft_restremainder(char *remainder);
char	*ft_strjoin(char *s1, char *s2);
size_t	ft_strlen(char *str);
char	*ft_strchr(char *s, int c);

#endif