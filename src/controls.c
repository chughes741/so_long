/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chughes <chughes@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 14:50:16 by chughes           #+#    #+#             */
/*   Updated: 2022/08/30 14:50:56 by chughes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"


int	exit_window(int keycode, t_data **data)
{
	exit(0);
}

void	close_window(t_data **data)
{
	mlx_destroy_window((*data)->mlx, (*data)->win);
	exit(0);
}

int	keydown(int keycode, t_data **data)
{
	if (keycode == 53)
		close_window(data);
	if (keycode == 13)
		move_up(data);
	if (keycode == 1)
		move_dn(data);
	if (keycode == 0)
		move_lf(data);
	if (keycode == 2)
		move_rg(data);
	check_tile();
	return (0);
}
