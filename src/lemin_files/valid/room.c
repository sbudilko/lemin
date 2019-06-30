/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   room.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbudilko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/26 14:56:42 by sbudilko          #+#    #+#             */
/*   Updated: 2018/10/26 14:56:43 by sbudilko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

int		ft_isroom(t_data *data, char *line)
{
	int		i;
	char	**buff;

	i = 0;
	if (line == NULL && ft_num_room(data) == 0)
		ft_error(data, 2);
	if (line == NULL && ft_num_room(data) != 0)
		ft_error(data, 3);
	while (line[i] != '\0')
	{
		if (line[i] == '-')
			return (0);
		i++;
	}
	if (line[0] != '#')
	{
		buff = ft_strsplit(line, ' ');
		i = num_buff(buff);
		del_buff(buff);
		free(buff);
		if (i != 3)
			return (10);
	}
	return (1);
}

int		ft_roomexist(t_data *data, char *line)
{
	t_room	*tmp;

	tmp = data->room;
	while (tmp->next != NULL)
	{
		if (ft_strcmp(tmp->name, line) == 0)
			return (1);
		tmp = tmp->next;
	}
	if (ft_strcmp(tmp->name, line) == 0)
		return (1);
	return (0);
}

void	ft_validroom2(t_data *data, char *line)
{
	char	**buff;
	int		i;

	i = 0;
	buff = ft_strsplit(line, ' ');
	if (num_buff(buff) != 3)
		ft_error(data, 6);
	if (buff[0][0] == 'L')
		ft_error(data, 7);
	if (ft_roomexist(data, buff[0]))
		ft_error(data, 8);
	while (++i && buff[1][i - 1] != '\0')
		if (!ft_isdigit(buff[1][i - 1]))
			ft_error(data, 9);
	i = 0;
	while (++i && buff[2][i - 1] != '\0')
		if (!ft_isdigit(buff[2][i - 1]))
			ft_error(data, 10);
	del_buff(buff);
	free(buff);
}

void	ft_validroom(t_data *data, char *line)
{
	t_room	*tmp;

	tmp = data->room;
	while (tmp->next != NULL)
		tmp = tmp->next;
	if (tmp->name != NULL)
	{
		tmp->next = ft_newroom();
		tmp = tmp->next;
	}
	if (line[0] == '#' && line[1] != '#')
	{
		ft_getfile(data, line);
		return ;
	}
	if (line[0] == '#' && line[1] == '#')
	{
		ft_getcommand(data, tmp, line);
		return ;
	}
	ft_validroom2(data, line);
	ft_getroom(data, line);
	ft_getfile(data, line);
}
