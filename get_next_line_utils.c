/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maragao <maragao@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/04 15:07:13 by maragao           #+#    #+#             */
/*   Updated: 2022/06/11 14:11:24 by maragao          ###   ########.rio      */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strdup(const char *s)
{
	int		i;
	char	*ptr;
	int		len;

	len = 0;
	while (s[len])
		len++;
	ptr = (char *) malloc((len + 1));
	if (ptr == NULL)
		return (NULL);
	i = 0;
	while (s[i])
	{
		ptr[i] = s[i];
		i++;
	}
	ptr[i] = 0;
	return (ptr);
}

void	*ft_calloc(size_t size)
{
	void		*ptr;
	unsigned char	*str;
	size_t		i;

	ptr = (void *) malloc(size);
	if (!ptr)
		return (NULL);
	str = (unsigned char *)ptr;
	i = 0;
	while (i < size)
	{
		str[i] = 0;
		i++;
	}
	return (ptr);
}

int		ft_strchr_mod(char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] != 0)
	{
		if (s[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

/*char	*ft_strcpy(char *dst, const char *src)
{
	size_t	i;

	i = 0;
	while (src[i++])
		dst[i] = src[i];
	dst[i] = 0;
	return (dst);
}*/

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	len_dst;
	size_t	len_src;

	len_dst = 0;
	while (dst[len_dst])
		len_dst++;
	len_src = 0;
	while (src[len_src])
		len_src++;
	if (size == 0)
		return (len_src);
	if (size <= len_dst)
		return (size + len_src);
	i = 0;
	while (src[i] && (len_dst + i < size - 1))
	{
		dst[len_dst + i] = src[i];
		i++;
	}
	dst[len_dst + i] = 0;
	return (len_src + len_dst);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*ptr;
	size_t	len;
	size_t	len_s1;
	size_t	len_s2;

	len_s1 = 0;
	len_s2 = 0;
	if (!s1)
		return (NULL);
	while (s1[len_s1])
		len_s1++;
	while (s2[len_s2])
		len_s2++;
	len = len_s1 + len_s2 + 1;
	ptr = (char *)ft_calloc(len);
	if (!ptr)
		return (NULL);
	ft_strlcat(ptr, s1, len);
	ft_strlcat (ptr, s2, len);
	return (ptr);
}

