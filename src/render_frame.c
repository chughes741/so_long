/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_frame.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chughes <chughes@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 14:47:22 by chughes           #+#    #+#             */
/*   Updated: 2022/08/30 14:48:21 by chughes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	render_frame(void)
{
	t_data	*data;
	int		x;
	int		y;

	data = get_data();
	y = -1;
	while (++y < data->height)
	{
		x = -1;
		while (++x < data->width)
			put_tile(data->map[y][x], x * 64, y * 64);
	}
	put_tile('P', data->x_p * 64, data->y_p * 64);
	return (0);
}
