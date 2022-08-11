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

int	main(void)
{
	t_data	*data;

	data = get_data();
	data->mlx = mlx_init();
	data->win = mlx_new_window(data->mlx, 1920, 1080, "Hello World!");
	data->img = mlx_new_image(data->mlx, 1920, 1080);
	data->addr = mlx_get_data_addr(data->img, &data->bits_per_pixel, 
								&data->line_length, &data->endian);
	mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
	mlx_hook(data->win, ON_DESTROY, 0, exit_window, &data);
	mlx_hook(data->win, ON_KEYDOWN, 0, close_window, &data);
	mlx_loop(data->mlx);

	return (0);
}
