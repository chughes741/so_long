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

static char**listtoarray(t_list **head)
{
	int		count;
	char	**rtn;
	t_list	*node;
	t_list	*temp;
	int		i;

	count = ft_lstsize(*head);
	rtn = ft_calloc(count, sizeof(char *));
	node = *head;
	i = -1;
	while (++i < count)
	{
		rtn[i] = ft_strdup((*head)->content);
		free(node->content);
		temp = node;
		node = node->next;
		free(temp);
	}
	return (rtn);
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
		ft_lstadd_back(&head, ft_lstnew(temp));
	}
	data->map = listtoarray(&head);
	return ;
}
