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

// Called to exit program and display error
void	exit_error(void)
{
	t_data	*data;

	data = get_data();
	del_data();
	perror("Error\n");
	exit(1);
}
