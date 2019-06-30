/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbudilko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/29 13:44:31 by sbudilko          #+#    #+#             */
/*   Updated: 2018/10/29 13:44:39 by sbudilko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void	no_way(t_data *data)
{
	int		i;
	int		num;
	t_room	*tmp;

	i = 0;
	tmp = data->room;
	num = ft_num_room(data);
	while (i < num)
	{
		if (tmp->start == 1)
			data->start = i;
		if (tmp->end == 1)
		{
			if (data->d[i] == MAX_INT)
				ft_error(data, 100);
			data->end = i;
		}
		tmp = tmp->next;
		i++;
	}
}

char	*get_name(t_data *data, int index)
{
	int		i;
	t_room	*tmp;

	i = 0;
	tmp = data->room;
	while (i != index)
	{
		i++;
		tmp = tmp->next;
	}
	return (tmp->name);
}

void	ft_best_way(t_data *data)
{
	int		i;
	t_ant	*tmp;

	i = data->p[data->end];
	while (i != -1)
	{
		if (data->d[i] < 0)
			ft_error(data, 100);
		tmp = ft_newant();
		tmp->name = ft_strdup(get_name(data, i));
		tmp->next = data->best_way;
		data->best_way = tmp;
		i = data->p[i];
	}
	if (data->flag->logs == 1)
	{
		ft_printbestway(data);
		ft_printf("-------------------------------------------------");
		ft_printf("-------------------------------------------------");
		ft_putendl("");
	}
}

void	ft_init_str(struct s_ants *ant, t_data *data)
{
	int		i;

	ft_printfile(data);
	i = 0;
	while (i < data->ants)
	{
		ant[i].i = i + 1;
		ant[i].ant = data->best_way;
		get_color(ant, data, i);
		i++;
	}
}

void	ft_solve(t_data *data)
{
	struct s_ants	*ants;
	int				i;

	i = 0;
	no_way(data);
	data->best_way = ft_newant();
	data->best_way->name = ft_strdup(get_name(data, data->end));
	ft_best_way(data);
	ants = (struct s_ants*)malloc(sizeof(*ants) * data->ants);
	ft_init_str(ants, data);
	ft_putendl("");
	while (1)
	{
		if (i == data->ants && ants[i - 1].ant->next == NULL)
			break ;
		else if (i == data->ants && ants[i - 1].ant->next != NULL)
		{
			i = 0;
			ft_putendl("");
		}
		i = ft_solve2(i, ants);
		i++;
	}
	ft_putendl("");
}
