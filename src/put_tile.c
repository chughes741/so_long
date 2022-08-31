/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_tile.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chughes <chughes@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 14:50:16 by chughes           #+#    #+#             */
/*   Updated: 2022/07/07 14:50:56 by chughes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

// Draws tile to screen
void	put_tile(char tile, int x, int y)
{
	t_data	*data;

	data = get_data();
	if (tile == '0')
		mlx_put_image_to_window(data->mlx, data->win, data->empty, x, y);
	else if (tile == 'C')
		mlx_put_image_to_window(data->mlx, data->win, data->collec, x, y);
	else if (tile == 'P')
		mlx_put_image_to_window(data->mlx, data->win, data->charac, x, y);
	else if (tile == '1')
		mlx_put_image_to_window(data->mlx, data->win, data->wall, x, y);
	else if (tile == 'E' && data->n_col == 0)
		mlx_put_image_to_window(data->mlx, data->win, data->exit, x, y);
	else
		mlx_put_image_to_window(data->mlx, data->win, data->empty, x, y);
	return ;
}
