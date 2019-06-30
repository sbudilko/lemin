/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbudilko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/21 16:29:43 by sbudilko          #+#    #+#             */
/*   Updated: 2018/10/21 16:29:45 by sbudilko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

int		ft_num_room(t_data *data)
{
	t_room	*tmp;
	int		res;

	res = 0;
	tmp = data->room;
	while (tmp != NULL)
	{
		if (tmp->name != NULL)
			res++;
		tmp = tmp->next;
	}
	return (res);
}

void	ft_printfile(t_data *data)
{
	t_file	*tmp;

	tmp = data->file;
	while (tmp->next != NULL)
	{
		ft_printf("%s\n", tmp->line);
		tmp = tmp->next;
	}
	ft_printf("%s\n", tmp->line);
}

void	ft_inicialization(t_data *data)
{
	data->start = 0;
	data->end = 0;
	data->d = NULL;
	data->u = NULL;
	data->p = NULL;
	data->adj_matrix = NULL;
	data->room = ft_newroom();
	data->link = ft_newlink();
	data->file = ft_newfile();
}

int		main(int argc, char **argv)
{
	t_data	data;

	ft_flag(&data, argc, argv);
	ft_inicialization(&data);
	ft_readmap(&data);
	ft_valid_command(&data);
	dijkstra_algo(&data);
	ft_solve(&data);
	ft_printflag(&data);
	return (0);
}
