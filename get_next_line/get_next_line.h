/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wewang <wewang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 11:37:58 by wewang            #+#    #+#             */
/*   Updated: 2022/10/31 10:45:51 by wewang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 2048
# endif

# include <stdlib.h>
# include <unistd.h>

size_t	ft_strlen(char const *str);
char	*ft_strdup(char const *s);
char	*ft_strjoin(char const *s1, char const *s2);
int		ft_find_nl(char *str);
char	*ft_get_new_save(char *save);
char	*ft_get_line(char *save);
char	*ft_read_file(char *save, int fd);
char	*get_next_line(int fd);

#endif