/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getdata.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbudilko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/26 14:02:27 by sbudilko          #+#    #+#             */
/*   Updated: 2018/10/26 14:02:30 by sbudilko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void	ft_getfile(t_data *data, char *line)
{
	t_file	*file;

	file = data->file;
	while (file->next != NULL)
		file = file->next;
	if (file->line != NULL)
	{
		file->next = ft_newfile();
		file = file->next;
	}
	file->line = ft_strdup(line);
}

void	ft_getroom(t_data *data, char *line)
{
	t_room	*tmp;
	char	**buff;

	tmp = data->room;
	while (tmp->next != NULL)
		tmp = tmp->next;
	if (tmp->name != NULL)
	{
		tmp->next = ft_newroom();
		tmp = tmp->next;
	}
	buff = ft_strsplit(line, ' ');
	tmp->name = ft_strdup(buff[0]);
	tmp->coord_x = ft_atoi(buff[1]);
	tmp->coord_y = ft_atoi(buff[2]);
	del_buff(buff);
	free(buff);
}

void	ft_getlink(t_data *data, char *line)
{
	char	**buff;
	t_link	*tmp;

	tmp = data->link;
	while (tmp->next != NULL)
		tmp = tmp->next;
	if (tmp->from != NULL && tmp->to != NULL)
	{
		tmp->next = ft_newlink();
		tmp = tmp->next;
	}
	buff = ft_strsplit(line, '-');
	tmp->from = ft_strdup(buff[0]);
	tmp->to = ft_strdup(buff[1]);
	del_buff(buff);
	free(buff);
}

void	ft_getcommand(t_data *data, t_room *room, char *line)
{
	if (ft_strcmp(line, "##start") == 0 && data->start == 0)
	{
		data->start = 1;
		room->start = 1;
	}
	else if (ft_strcmp(line, "##end") == 0 && data->end == 0)
	{
		data->end = 1;
		room->end = 1;
	}
	else if ((ft_strcmp(line, "##start") == 0 && data->start == 1))
		ft_error(data, 4);
	else if ((ft_strcmp(line, "##end") == 0 && data->end == 1))
		ft_error(data, 441);
	ft_getfile(data, line);
}
