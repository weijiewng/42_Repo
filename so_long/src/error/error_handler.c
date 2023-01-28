/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wewang <wewang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 11:36:30 by wewang            #+#    #+#             */
/*   Updated: 2022/11/23 12:11:43 by wewang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

void	ft_handle_more_error(int error_code)
{
	if (error_code == -10)
		perror(NO_COLLECTIBLES);
	else if (error_code == -11)
		perror(NO_VALID_PATH);
	else if (error_code == -12)
		perror(NO_GAME_INITIALIZATION);
	else if (error_code == -13)
		perror(NO_WINDOW_CREATION);
	else if (error_code == -14)
		perror(NO_IMAGE);
}

int	ft_handle_error(t_data *data, int error_code)
{
	if (error_code == 0)
		perror(MALLOC_ERROR);
	else if (error_code == -1)
		perror(NO_FILE);
	else if (error_code == -2)
		perror(NOT_BIG_MAP);
	else if (error_code == -3)
		perror(NOT_RECTANGULAR);
	else if (error_code == -4)
		perror(NOT_SURROUNDED_WALL);
	else if (error_code == -5)
		perror(FORBIDDEN_CHARACTERS);
	else if (error_code == -6)
		perror(MANY_START);
	else if (error_code == -7)
		perror(MANY_EXIT);
	else if (error_code == -8)
		perror(NO_START);
	else if (error_code == -9)
		perror(NO_EXIT);
	else
		ft_handle_more_error(error_code);
	ft_handle_close(data);
	return (0);
}
