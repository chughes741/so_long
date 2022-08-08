/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chughes <chughes@42quebec.com>             +#+  +:+       +#+        */
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
# include "../libft/include/libft.h"
# include "./color.h"
# include "./events.h"

// Generates offset for pixel addr
# define OFFSET(y, len, x, bpp) (y * len + x * (bpp / 8))

// Data struct with window data
typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}			t_data;

// Function prototypes
void	pixel_put(t_data *data, int x, int y, int color);
t_data	*get_data(void);

#endif
