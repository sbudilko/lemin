/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   room.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbudilko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/25 13:35:28 by sbudilko          #+#    #+#             */
/*   Updated: 2018/10/25 13:35:30 by sbudilko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

t_room	*ft_newroom(void)
{
	t_room	*new;

	new = (t_room*)malloc(sizeof(t_room));
	new->next = NULL;
	new->coord_x = -1;
	new->coord_y = -1;
	new->start = 0;
	new->end = 0;
	new->name = NULL;
	return (new);
}

t_ant	*ft_newant(void)
{
	t_ant	*new;

	new = (t_ant*)malloc(sizeof(t_ant));
	new->next = NULL;
	new->i = 0;
	new->name = NULL;
	return (new);
}

t_link	*ft_newlink(void)
{
	t_link	*new;

	new = (t_link*)malloc(sizeof(t_link));
	new->from = NULL;
	new->to = NULL;
	new->next = NULL;
	return (new);
}

t_file	*ft_newfile(void)
{
	t_file	*new;

	new = (t_file*)malloc(sizeof(t_file));
	new->line = NULL;
	new->next = NULL;
	return (new);
}
