/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chughes <chughes@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 14:50:16 by chughes           #+#    #+#             */
/*   Updated: 2022/08/29 14:50:56 by chughes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

// Checks if the current tile is a collectable or exit
void	check_tile(void)
{
	t_data	*d;

	d = get_data();
	if (d->map[d->x_P][d->y_P] == 'C')
	{
		d->map[d->x_P][d->y_P] = '0';
		d->collec -= 1;
	}
	if (d->map[d->x_P][d->y_P] == 'E' && d->collec == 0)
		close_window(&d);
	return ;
}

// Move player sprite up one space
void	move_up(t_data **data)
{
	t_data	*d;

	d = (*data);
	if (d->map[d->x_P][d->y_P - 1] == '1')
		return ;
	d->y_P -= 1;
	d->moves += 1;
	printf("%i\n", d->moves);
	return ;
}

// Move player sprite down one space
void	move_dn(t_data **data)
{
	t_data	*d;

	d = (*data);
	if (d->map[d->x_P][d->y_P + 1] == '1')
		return ;
	d->y_P += 1;
	d->moves += 1;
	printf("%i\n", d->moves);
	return ;
}

// Move player sprite left one space
void	move_lf(t_data **data)
{
	t_data	*d;

	d = (*data);
	if (d->map[d->x_P - 1][d->y_P] == '1')
		return ;
	d->x_P -= 1;
	d->moves += 1;
	printf("%i\n", d->moves);
	return ;
}

// Move player sprite right one space
void	move_rg(t_data **data)
{
	t_data	*d;

	d = (*data);
	if (d->map[d->x_P + 1][d->y_P] == '1')
		return ;
	d->x_P += 1;
	d->moves += 1;
	printf("%i\n", d->moves);
	return ;
}
