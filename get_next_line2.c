/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maragao <maragao@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 13:34:43 by maragao           #+#    #+#             */
/*   Updated: 2022/06/11 15:35:57 by maragao          ###   ########.rio      */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

int		strlen_mod(char *buffer)
{
	int count;

	count = 0;
	while (buffer[count] != '\n' && buffer[count])
		count++;
	if (buffer[count] == '\n')
		count++;
	return (count + 1);
}

char	*ft_join(char *bank, char *buffer)
{
	char *line;

	line = ft_strjoin(bank, buffer);
	if (!line)
		return (NULL);
	return (line);
}

char	*return_line(char *bank)
{
	int		 i;
	char	*line;

	i = 0;
	line = (char *)malloc(strlen_mod(bank));
	if (!line)
		return (NULL);
	while (bank[i] != '\n' && bank[i])
	{
		line[i] = bank[i];
		i++;
	}
	if (bank[i] == '\n')
		line[i++] = '\n';
	line[i] = 0;
	return (line);
}

char	*last_static(char *bank)
{
	char	*aux;
	int		len_bank;
	int		i;
	int		j;
	
	len_bank = 0;
	while (bank[len_bank])
		len_bank++;
	i = 0;
	while (bank[i] != '\n' && bank[i])
		i++;
	aux = (char *) malloc(len_bank - i + 1);
	if (!aux)
		return (NULL);
	j = 0;
	while (bank[++i])
		aux[j++] = bank[i];
	free (bank);
	return (aux);
}
	
char	*read_line(int fd, char *bank)
{
	char	*buffer;
	char	*line;
	int		bytes_read;

	bytes_read = 1;
	while (bytes_read > 0 && !ft_strchr_mod(bank))
	{
		buffer = (char *) malloc(BUFFER_SIZE + 1);
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		buffer[bytes_read] = 0;
		bank = ft_join(bank, buffer);
		free(buffer);
	}
	line = return_line(bank);
	printf("bank : %s\n", bank);
	bank = last_static(bank);
	printf("bank2: %s\n", bank);
	return (line);
}

char *get_next_line(int fd)
{
	char		*line;
	static char	*bank;

	if (bank == NULL)
		bank = malloc(1);
	line = read_line(fd, bank);
	printf("bank3: %s\n", bank);
	return (line);
}

int main()
{
	int fd = open("oi.txt", O_RDWR);
	char *res;

	res = get_next_line(fd);
	printf("%s", res);
}
