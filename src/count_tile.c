/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chughes <chughes@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 14:50:16 by chughes           #+#    #+#             */
/*   Updated: 2022/07/07 14:50:56 by chughes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	count_tile(int x, int y)
{
	t_data	*data;

	data = get_data();
	if (data->map[y][x] == 'P')
	{
		data->x_p = x;
		data->y_p = y;
		data->map[y][x] = '0';
		data->n_p += 1;
	}
	else if (data->map[y][x] == 'C')
		data->n_col += 1;
	else if (data->map[y][x] == 'E')
		data->n_ex += 1;
	else if (data->map[y][x] == '0' || data->map[y][x] == '1')
		data->n_col += 0;
	else
		exit_error();
}
