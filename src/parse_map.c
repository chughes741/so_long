/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chughes <chughes@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 14:50:16 by chughes           #+#    #+#             */
/*   Updated: 2022/07/07 14:50:56 by chughes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

// Reads map file into an array of strings
void	parse_map(void)
{
	t_data	*data;
	int		i;

	data = get_data();
	i = 0;
	while (i < data->height)
	{
		data->map[i] = get_next_line(data->map_fd);
		++i;
	}
	return ;
}

// Checks validity of map
void	check_map(void)
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
		{
			if (data->map[y][x] == 'P')
			{
				data->x_p = x;
				data->y_p = y;
				data->map[y][x] = '0';
			}
			if (data->map[y][x] == 'C')
				data->collec += 1;
		}
	}
	return ;
}

// Checks input and sets map height
void	check_input(int argc, char *argv[])
{
	t_data	*data;
	char	*temp;

	data = get_data();
	if (argc != 2)
		exit_error();
	data->map_fd = open(ft_strjoin("maps/", argv[1]), O_RDONLY);
	if (data->map_fd < 0)
		exit_error();
	temp = get_next_line(data->map_fd);
	while (temp)
	{
		data->height += 1;
		free(temp);
		temp = get_next_line(data->map_fd);
	}
	data->map = ft_calloc(data->height + 1, sizeof(char *));
	close(data->map_fd);
	data->map_fd = open(ft_strjoin("maps/", argv[1]), O_RDONLY);
	parse_map();
	close(data->map_fd);
	data->width = ft_linelen(data->map[0]);
	check_map();
	return ;
}
