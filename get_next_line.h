/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maragao <maragao@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/04 15:07:25 by maragao           #+#    #+#             */
/*   Updated: 2022/06/11 14:48:55 by maragao          ###   ########.rio      */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <unistd.h>
# include <fcntl.h>
//# include <stdio.h>
# include <stdlib.h>

void	*ft_calloc(size_t size);
int		ft_strchr_mod(char *s);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);
size_t	ft_strlcat(char *dst, const char *src, size_t size);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_join(char *bank, char *buffer);
int		ft_strlen_mod(char *buffer);
char	*ft_return_line(char *buffer);
char	*last_static(char *bank);
char	*ft_read_line(int fd, char *bank);
char	*get_next_line(int fd);

#endif
