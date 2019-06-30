/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alg.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbudilko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/28 15:47:52 by sbudilko          #+#    #+#             */
/*   Updated: 2018/10/28 15:47:53 by sbudilko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void	get_data(t_data *data)
{
	int		num;
	int		i;
	t_room	*tmp;

	i = 0;
	tmp = data->room;
	num = ft_num_room(data);
	data->d = (int*)malloc(sizeof(int) * num);
	data->u = (int*)malloc(sizeof(int) * num);
	data->p = (int*)malloc(sizeof(int) * num);
	while (i < num)
	{
		data->d[i] = MAX_INT;
		data->u[i] = 0;
		data->p[i] = -1;
		if (tmp->start == 1)
			data->d[i] = 0;
		i++;
		tmp = tmp->next;
	}
}

int		get_minvertex(t_data *data)
{
	int		res;
	int		j;
	int		num;

	j = 0;
	res = 0;
	num = ft_num_room(data);
	while (j < num)
	{
		if (data->u[j] != 1)
		{
			res = j;
			break ;
		}
		j++;
	}
	j = 0;
	while (j < num)
	{
		if (data->d[j] < data->d[res] && data->u[j] != 1)
			res = j;
		j++;
	}
	return (res);
}

void	ft_ft(t_data *data, int j, int min)
{
	if (data->d[min] + 1 <= data->d[j])
	{
		data->d[j] = data->d[min] + 1;
		data->p[j] = min;
	}
}

char	*get_22(t_data *data, int i)
{
	t_room	*tmp;
	int		j;

	j = 0;
	tmp = data->room;
	while (j != i)
	{
		j++;
		tmp = tmp->next;
	}
	return (tmp->name);
}

void	dijkstra_algo(t_data *data)
{
	int		num;
	int		min;
	int		i;
	int		j;

	i = -1;
	num = ft_num_room(data);
	data->adj_matrix = get_adj_matrix(data);
	get_data(data);
	ft_log(data);
	while (++i < num)
	{
		j = -1;
		min = get_minvertex(data);
		while (++j < num)
			if (data->adj_matrix[min][j] == 1)
				ft_ft(data, j, min);
		data->u[min] = 1;
		if (data->flag->logs)
		{
			ft_printf("->Deijkstra's Algo for node: %s\n", get_22(data, min));
			for_deijkstra(data, num);
		}
	}
}
