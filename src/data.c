/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chughes <chughes@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 13:33:54 by chughes           #+#    #+#             */
/*   Updated: 2022/06/23 13:37:44 by chughes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

// Singleton itialization and reference getter
t_data	*get_data(void)
{
	static t_data	*data = NULL;

	if (data == NULL)
		data = ft_calloc(1, sizeof(t_data));
	return (data);
}

// Initialized data struct
void	init_data(int argc, char *argv[])
{
	t_data	*d;
	int		w;
	int		h;

	d = get_data();
	d->map_name = argv[1];
	check_input(argc);
	d->mlx = mlx_init();
	d->wall = mlx_xpm_file_to_image(d->mlx, "./assets/1.xpm", &w, &h);
	d->empty = mlx_xpm_file_to_image(d->mlx, "./assets/0.xpm", &w, &h);
	d->exit = mlx_xpm_file_to_image(d->mlx, "./assets/E.xpm", &w, &h);
	d->collec = mlx_xpm_file_to_image(d->mlx, "./assets/C.xpm", &w, &h);
	d->charac = mlx_xpm_file_to_image(d->mlx, "./assets/P.xpm", &w, &h);
	return ;
}

// Frees data and its contents
void	del_data(void)
{
	t_data	*data;
	int		i;

	data = get_data();
	i = -1;
	if (data->map)
	{
		while (data->map[++i])
			free(data->map[i]);
		free(data->map);
	}
	free(data);
	return ;
}
