/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chughes <chughes@42quebec.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/08 14:47:22 by chughes           #+#    #+#             */
/*   Updated: 2022/08/08 14:48:21 by chughes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COLOR_H
# define COLOR_H

// Colors are 0xTTRRGGBB

#define COLOR(t, r, g, b) (t << 24 | r << 16 | g << 8 | b)
#define SCRAPE_T(color) ((color >> 24) & 0xFF)
#define SCRAPE_R(color) ((color >> 16) & 0xFF)
#define SCRAPE_G(color) ((color >> 8) & 0xFF)
#define SCRAPE_B(color) (color & 0xFF)

#endif
