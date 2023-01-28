/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wewang <wewang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 11:37:56 by wewang            #+#    #+#             */
/*   Updated: 2022/11/02 09:42:30 by wewang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_get_new_save(char *save)
{
	char	*res;
	size_t	start;

	start = 0;
	while (save[start] && save[start] != '\n')
		start++;
	if (start == ft_strlen(save))
		res = ft_strdup(&save[ft_strlen(save)]);
	else
	{
		start++;
		res = ft_strdup(&save[start]);
	}
	free(save);
	return (res);
}

char	*ft_get_line(char *save)
{
	char	*res;
	int		size;
	int		i;

	size = 0;
	while (save[size] && save[size] != '\n')
		size++;
	if (save[size] == '\n')
		size++;
	res = (char *)malloc(sizeof(char) * (size + 1));
	if (res == NULL)
		return (NULL);
	i = 0;
	while (save[i] && save[i] != '\n')
	{
		res[i] = save[i];
		i++;
	}
	if (save[i] && save[i] == '\n')
		res[i++] = '\n';
	res[i] = '\0';
	return (res);
}

char	*ft_read_file(char *save, int fd)
{
	char	*tmp;
	char	*buffer;
	ssize_t	size;

	buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (buffer == NULL)
		return (NULL);
	while (ft_find_nl(save) == 0)
	{
		size = read(fd, buffer, BUFFER_SIZE);
		if (size == 0)
			break ;
		if (size == -1)
		{
			free(buffer);
			free(save);
			return (NULL);
		}
		buffer[size] = '\0';
		tmp = ft_strjoin(save, buffer);
		free(save);
		save = tmp;
	}
	free(buffer);
	return (save);
}

char	*get_next_line(int fd)
{
	char		*res;
	static char	*save;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!save)
	{
		save = (char *)malloc(sizeof(char) * 1);
		if (save == NULL)
			return (NULL);
		save[0] = '\0';
	}
	save = ft_read_file(save, fd);
	if (save == NULL || save[0] == '\0')
	{
		free(save);
		save = NULL;
		return (NULL);
	}
	res = ft_get_line(save);
	save = ft_get_new_save(save);
	return (res);
}

// #include <stdio.h>
// #include <fcntl.h>
// int main()
// {
// 	int fd = open("test.txt", O_RDONLY);
// 	char *res = get_next_line(fd);
// 	printf("%s", res);
// 	free(res);
// 	res = get_next_line(fd);
// 	printf("%s", res);
// 	free(res);
// 	res = get_next_line(fd);
// 	printf("%s", res);
// 	free(res);
// 	res = get_next_line(fd);
// 	printf("%s", res);
// 	free(res);
// }