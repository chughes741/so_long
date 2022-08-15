/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chughes <chughes@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 14:47:22 by chughes           #+#    #+#             */
/*   Updated: 2022/07/07 14:48:21 by chughes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <math.h>
# include <OpenGL/gl3.h>
# include <mlx.h>
# include <stdio.h>
# include <fcntl.h>
# include "../libft/include/libft.h"
# include "./color.h"
# include "./events.h"

// Generates offset for pixel addr
# define OFFSET(y, len, x, bpp) (y * len + x * (bpp / 8))

// Macros for tiles and sprites
# define WALL_TILE 100
# define EMPTY_TILE 200
# define EXIT_TILE 300
# define COLLEC_TILE 400
# define CHARAC_TILE 500

// Struct with sprite and tile img pointers
typedef struct	s_img {
	void	*wall;
	void	*empty;
	void	*exit;
	void	*collec;
	void	*charac;
}			t_img;

// Data struct with window data
typedef struct	s_data {
	void	*mlx;
	void	*win;
	char	*addr;
	int		**map;
	int		map_fd;
	int		height;
	int		width;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	t_img	*img;
}			t_data;

// Function prototypes
void	pixel_put(t_data *data, int x, int y, int color);
t_data	*get_data(void);
void	check_input(int argc, char *argv[]);
void	init_data(int argc, char *argv[]);
void	del_data(void);
void	parse_map(void);
void	exit_error(void);

#endif
