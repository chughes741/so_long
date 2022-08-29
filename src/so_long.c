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

void	put_tile(char tile, int x, int y)
{
	t_data	*data;

	data = get_data();
	if (tile == '1')
		mlx_put_image_to_window(data->mlx, data->win, data->img->wall, x, y);
	if (tile == '0')
		mlx_put_image_to_window(data->mlx, data->win, data->img->empty, x, y);
	if (tile == 'E')
		mlx_put_image_to_window(data->mlx, data->win, data->img->exit, x, y);
	if (tile == 'C')
		mlx_put_image_to_window(data->mlx, data->win, data->img->collec, x, y);
	if (tile == 'P')
		mlx_put_image_to_window(data->mlx, data->win, data->img->charac, x, y);
	return ; 
}

int	render_frame(void)
{
	t_data	*data;
	int		i;
	int		j;

	data = get_data();
	j = -1;
	while (++j < data->height)
	{
		i = -1;
		while (++i < data->width)
			put_tile(data->map[j][i], i * 64, j * 64);
	}
	put_tile('P', data->x_P * 64, data->y_P * 64);
	return (0);
}

int	main(int argc, char *argv[])
{
	t_data	*data;

	data = get_data();
	data->mlx = mlx_init();
	init_data(argc, argv);

	data->win = mlx_new_window(data->mlx, data->width * 64, data->height * 64, "so_long");

	mlx_hook(data->win, ON_DESTROY, 0, exit_window, &data);
	mlx_hook(data->win, ON_KEYDOWN, 0, close_window, &data);
	mlx_loop_hook(data->mlx, render_frame, NULL);
	mlx_loop(data->mlx);

	return (0);
}
