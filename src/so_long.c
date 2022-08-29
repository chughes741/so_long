/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chughes <chughes@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 14:50:16 by chughes           #+#    #+#             */
/*   Updated: 2022/07/07 14:50:56 by chughes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"
#include <stdio.h>

int	exit_window(int keycode, t_data **data)
{
	exit(0);
}

int	close_window(int keycode, t_data **data)
{
	if (keycode != 53 && keycode > 0)
		return (0);
	mlx_destroy_window((*data)->mlx, (*data)->win);
	exit(0);
}

void	put_tile(int tile, int x, int y)
{
	t_data	*data;

	data = get_data();
	if (tile == WALL_TILE)
		mlx_put_image_to_window(data->mlx, data->win, data->img->wall, x, y);
	if (tile == EMPTY_TILE)
		mlx_put_image_to_window(data->mlx, data->win, data->img->empty, x, y);
	if (tile == EXIT_TILE)
		mlx_put_image_to_window(data->mlx, data->win, data->img->exit, x, y);
	if (tile == COLLEC_TILE)
		mlx_put_image_to_window(data->mlx, data->win, data->img->collec, x, y);
	if (tile == CHARAC_TILE)
		mlx_put_image_to_window(data->mlx, data->win, data->img->charac, x, y);
	return ;
}

int	main(int argc, char *argv[])
{
	t_data	*data;

	data = get_data();
	data->mlx = mlx_init();
	init_data(argc, argv);

	data->win = mlx_new_window(data->mlx, data->width, data->height, "Beep");

	mlx_hook(data->win, ON_DESTROY, 0, exit_window, &data);
	mlx_hook(data->win, ON_KEYDOWN, 0, close_window, &data);
	mlx_loop(data->mlx);

	return (0);
}
