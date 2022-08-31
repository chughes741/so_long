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

void	put_tile(char tile, int x, int y)
{
	t_data	*data;

	data = get_data();
	if (tile == '0')
		mlx_put_image_to_window(data->mlx, data->win, data->img->empty, x, y);
	else if (tile == 'C')
		mlx_put_image_to_window(data->mlx, data->win, data->img->collec, x, y);
	else if (tile == 'P')
		mlx_put_image_to_window(data->mlx, data->win, data->img->charac, x, y);
	else if (tile == '1')
		mlx_put_image_to_window(data->mlx, data->win, data->img->wall, x, y);
	else if (tile == 'E' && data->collec == 0)
		mlx_put_image_to_window(data->mlx, data->win, data->img->exit, x, y);
	else
		mlx_put_image_to_window(data->mlx, data->win, data->img->empty, x, y);
	return ;
}
