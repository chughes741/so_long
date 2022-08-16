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

static **listtoarray(t_list **head)
{
	int		count;
	char	**rtn;

	count = ft_lstsize(*head);
	rtn = ft_calloc(count, sizeof(char *));

}

void	parse_map(void)
{
	t_data	*data;
	t_list	*head;
	char	*temp;
	int		i;

	data = get_data();
	temp = get_next_line(data->map_fd);
	head = ft_lstnew(temp);
	while (temp)
	{
		free(temp);
		temp = get_next_line(data->map_fd);
		ft_lstadd_back(&head, temp);
	}
	free(temp);
	data->map = listtoarray(&head);
	return ;
}
