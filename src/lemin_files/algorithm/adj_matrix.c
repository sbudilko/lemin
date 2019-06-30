/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   adj_matrix.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbudilko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/28 16:46:09 by sbudilko          #+#    #+#             */
/*   Updated: 2018/10/28 16:46:11 by sbudilko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

int			ft_get_index(t_data *data, char *str)
{
	int		i;
	t_room	*tmp;

	i = 0;
	tmp = data->room;
	while (tmp != NULL)
	{
		if (ft_strcmp(tmp->name, str) == 0)
			return (i);
		i++;
		tmp = tmp->next;
	}
	return (-1);
}

long int	**get_matrix(t_data *data)
{
	long int	**res;
	int			num_room;
	int			i;
	int			j;

	i = 0;
	num_room = ft_num_room(data);
	res = (long int**)malloc(sizeof(*res) * num_room);
	while (i < num_room)
	{
		j = 0;
		res[i] = (long int*)malloc(sizeof(long int) * num_room);
		while (j < num_room)
		{
			res[i][j] = 0;
			j++;
		}
		i++;
	}
	return (res);
}

long int	**get_adj_matrix(t_data *data)
{
	long int	**res;
	t_link		*tmp;
	int			i;
	int			j;

	i = 0;
	j = 0;
	tmp = data->link;
	res = get_matrix(data);
	while (tmp != NULL)
	{
		i = ft_get_index(data, tmp->from);
		j = ft_get_index(data, tmp->to);
		if (i != j)
		{
			res[i][j] = 1;
			res[j][i] = 1;
		}
		tmp = tmp->next;
	}
	return (res);
}
