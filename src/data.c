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
	static t_data* data = NULL;

	if (data == NULL)
		data = ft_calloc(1, sizeof(t_data));
	return (data);
}

void	exit_error(void)
{
	t_data	*data;

	data = get_data();
	del_data();
	perror("Error\n");
	exit(1);
}

void	check_input(int argc, char *argv[])
{
	t_data	*data;

	data = get_data();
	if (argc != 2)
		exit_error();
	data->map_fd = open(ft_strjoin("maps/", argv[1]), O_RDONLY);
	if (data->map_fd < 0)
		exit_error();
	return ;
}

// Initialized data struct
void	init_data(int argc, char *argv[])
{
	t_data	*d;
	int		w;
	int		h;

	d = get_data();
	check_input(argc, argv);
	d->img = ft_calloc(1, sizeof(t_img *));
	d->img->wall = mlx_xpm_file_to_image(d->mlx, "./assets/1.xpm", &w, &h);
	d->img->empty = mlx_xpm_file_to_image(d->mlx, "./assets/0.xpm", &w, &h);
	d->img->exit = mlx_xpm_file_to_image(d->mlx, "./assets/E.xpm", &w, &h);
	d->img->collec = mlx_xpm_file_to_image(d->mlx, "./assets/C.xpm", &w, &h);
	d->img->charac = mlx_xpm_file_to_image(d->mlx, "./assets/P.xpm", &w, &h);
	return ;
}

// Frees data and its contents
void	del_data(void)
{
	t_data	*data;

	data = get_data();
	if (data->img)
		free(data->img);
	free(data);
	return ;
}
