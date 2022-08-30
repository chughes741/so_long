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

int	main(int argc, char *argv[])
{
	t_data	*data;

	data = get_data();
	data->mlx = mlx_init();
	init_data(argc, argv);

	data->win = mlx_new_window(data->mlx, data->width * 64, data->height * 64, "so_long");

	mlx_hook(data->win, ON_DESTROY, 0, exit_window, &data);
	mlx_hook(data->win, ON_KEYDOWN, 0, keydown, &data);
	mlx_loop_hook(data->mlx, render_frame, NULL);
	mlx_loop(data->mlx);

	return (0);
}
