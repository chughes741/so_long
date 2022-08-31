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
	t_data	*d;

	d = get_data();
	d->mlx = mlx_init();
	init_data(argc, argv);
	d->win = mlx_new_window(d->mlx, d->width * 64, d->height * 64, "so_long");
	// for (int i = 0; i < d->height; ++i)
		// printf("%s", d->map[i]);
	mlx_hook(d->win, ON_DESTROY, 0, exit_window, &d);
	mlx_hook(d->win, ON_KEYDOWN, 0, keydown, &d);
	mlx_loop_hook(d->mlx, render_frame, NULL);
	mlx_loop(d->mlx);
	return (0);
}
