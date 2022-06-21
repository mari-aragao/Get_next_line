/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maragao <maragao@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/04 15:07:25 by maragao           #+#    #+#             */
/*   Updated: 2022/06/17 15:42:26 by maragao          ###   ########.rio      */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <unistd.h>
# include <stdlib.h>

size_t	ft_strlen(char *str);
int		ft_strchr_mod(char *s);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_return_line(char *buffer);
char	*last_static(char *bank);
char	*ft_read_line(int fd, char *bank);
char	*get_next_line(int fd);

#endif
