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

//TODO Check includes
# include <math.h>
# include <OpenGL/gl3.h>
# include <mlx.h>
# include <stdio.h>
# include <fcntl.h>
# include "../lft/include/libft.h"

// Struct with sprite and tile img pointers
typedef struct	s_img {
	void	*wall;
	void	*empty;
	void	*exit;
	void	*collec;
	void	*charac;
}			t_img;

// Data struct with window data
typedef struct	s_data { //TODO Check if any are unused
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
	int		collec;
	t_img	*img;
}			t_data;

// Data setup and teardown functions
t_data	*get_data(void);
void	init_data(int argc, char *argv[]);
void	del_data(void);

// Map parsing checks
void	check_input(int argc, char *argv[]);
void	parse_map(void);
void	exit_error(void);
void	check_map(void);
void	check_tile(void);

// MLX interop functions
void	close_window(t_data **data);
int		render_frame(void);

// Movement functions
void	move_up(t_data **data);
void	move_dn(t_data **data);
void	move_lf(t_data **data);
void	move_rg(t_data **data);

#endif
