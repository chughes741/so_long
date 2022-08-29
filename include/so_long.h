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
# include "../lft/include/libft.h"
# include "./events.h"

// Generates offset for pixel addr //! Unused atm
# define OFFSET(y, len, x, bpp) (y * len + x * (bpp / 8))

// Macros for tiles and sprites //! Unused atm
# define WALL_TILE 49
# define EMPTY_TILE 48
# define EXIT_TILE 69
# define COLLEC_TILE 67
# define CHARAC_TILE 80

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
	char	**map;
	int		map_fd;
	int		height;
	int		width;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		moves;
	int		x_P;
	int		y_P;
	t_img	*img;
}			t_data;

// Function prototypes
t_data	*get_data(void);
void	check_input(int argc, char *argv[]);
void	init_data(int argc, char *argv[]);
void	del_data(void);
void	parse_map(void);
void	exit_error(void);
void	check_map(void);

// Moves
void	move_up(void);
void	move_dn(void);
void	move_rg(void);
void	move_lf(void);

#endif
