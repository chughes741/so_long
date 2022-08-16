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

static int	linelen(char *str)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != '\n')
		++i;
	return (i);
}

static int	linecount(char *str)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i + 1])
	{
		if (str[i] == '\n')
			count++;
		i++;
	}
	return (count);
}

static void	strtomap(char *str, int **map)
{
	int	i;
	int	x;
	int	y;

	i = -1;
	x = 0;
	y = 0;
	printf("%s\n", str);
	// write(1, "...\n", 4);
	while (str[++i])
	{
		if (str[i] == '1')
			map[x][y] = WALL_TILE;
		else if (str[i] == '0')
			map[x][y] = EMPTY_TILE;
		else if (str[i] == 'E')
			map[x][y] = EXIT_TILE;
		else if (str[i] == 'C')
			map[x][y] = COLLEC_TILE;
		else if (str[i] == 'P')
			map[x][y] = CHARAC_TILE;
		else if (str[i] == '\n')
		{
			x = -1;
			y++;
		}
		else
			exit_error();
		x++;
		printf("x: %i\ny: %i\n", x, y);
	}
}

void	parse_map(void)
{
	t_data	*data;
	int		i;

	data = get_data();
	




	return ;
}