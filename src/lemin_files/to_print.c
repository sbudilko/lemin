/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   to_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbudilko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/26 19:32:44 by sbudilko          #+#    #+#             */
/*   Updated: 2018/10/26 19:32:46 by sbudilko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void	ft_printmapinfo(t_data *data)
{
	int		i;
	int		j;
	int		num;
	t_room	*tmp;

	i = 0;
	num = ft_num_room(data);
	tmp = data->room;
	ft_printf("->Map info\n");
	while (tmp->next != NULL)
	{
		j = 0;
		ft_printf("   [%.4s] -> ", tmp->name);
		while (j < num)
		{
			if (data->adj_matrix[i][j] == 1)
				ft_printf(" [%.4s] |", get_22(data, j));
			j++;
		}
		i++;
		ft_putendl("");
		tmp = tmp->next;
	}
	ft_printmapinfo2(data, tmp, i);
}

void	ft_printroom(t_data *data)
{
	t_room	*tmp;

	tmp = data->room;
	ft_printf("->Rooms info\n");
	while (tmp->next != NULL)
	{
		ft_printf("   name: %.4s | x: %-3i | y: %-3i | start: %i | end: %i\n",
		tmp->name, tmp->coord_x, tmp->coord_y, tmp->start, tmp->end);
		tmp = tmp->next;
	}
	if (tmp->name != NULL)
		ft_printf("   name: %.4s | x: %-3i | y: %-3i | start: %i | end: %i\n",
			tmp->name, tmp->coord_x, tmp->coord_y, tmp->start, tmp->end);
}

void	ft_printbestway(t_data *data)
{
	t_ant	*tmp;

	tmp = data->best_way;
	ft_printf("->Best(min) way\n   ");
	while (tmp->next != NULL)
	{
		ft_printf("[%s] -> ", tmp->name);
		tmp = tmp->next;
	}
	ft_printf("[%s]\n", tmp->name);
}

void	ft_printlink(t_data *data)
{
	t_link	*tmp;

	tmp = data->link;
	ft_printf("->Links info:\n");
	while (tmp->next != NULL)
	{
		ft_printf("   from: [%s] | to: [%s]\n", tmp->from, tmp->to);
		ft_printf("   from: [%s] | to: [%s]\n", tmp->to, tmp->from);
		tmp = tmp->next;
	}
	ft_printf("   from: [%s] | to: [%s]\n", tmp->from, tmp->to);
	ft_printf("   from: [%s] | to: [%s]\n", tmp->to, tmp->from);
}

void	for_deijkstra(t_data *data, int num)
{
	int		i;
	int		j;
	t_room	*tmp;

	i = 0;
	tmp = data->room;
	ft_printf("   | Node's Name: |       Adjacency matrix:       |     Dist");
	ft_printf("ance from start:     |  Mark nodes:  |\n");
	while (tmp != NULL)
	{
		j = -1;
		if (tmp->name == NULL)
			break ;
		if (tmp->name != NULL)
			ft_printf("   [%i] - %s     |     ", i, tmp->name);
		while (++j < num)
			ft_printf("%i  ", data->adj_matrix[i][j]);
		ft_printf("     |     d[%i]: %-15i    |    u[%i] : %i   |\n",
		i, data->d[i], i, data->u[i]);
		i++;
		tmp = tmp->next;
	}
	i = -1;
	while (++i < num)
		ft_printf("     -> p[%i] : %i\n", i, data->p[i]);
}
