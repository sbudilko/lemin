/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbudilko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/26 12:48:40 by sbudilko          #+#    #+#             */
/*   Updated: 2018/10/26 12:48:43 by sbudilko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void	ft_valid_command(t_data *data)
{
	t_room	*tmp;

	tmp = data->room;
	while (tmp->next != NULL)
	{
		if (tmp->end == 1 && tmp->name == NULL)
			ft_error(data, 5);
		if (tmp->start == 1 && tmp->name == NULL)
			ft_error(data, 555);
		tmp = tmp->next;
	}
	if ((tmp->end == 1 || tmp->start == 1) &&
			tmp->name == NULL)
		ft_error(data, 5);
	if (data->start == 0 || data->end == 0)
		ft_error(data, 51);
}

void	ft_readmap(t_data *data)
{
	int		i;

	ft_readants(data);
	i = ft_readrooms(data);
	if (i == 10)
	{
		ft_printf(YELLOW);
		ft_printf("WARNING: Bad line. Stop the ant farm’s reading\n");
		ft_printf(RESET);
		return ;
	}
	ft_valid_command(data);
}

void	ft_readants(t_data *data)
{
	char	*line;
	int		i;

	i = 0;
	get_next_line(0, &line);
	while (line != NULL)
	{
		if (line[0] == '#' && line[1] != '#')
			ft_getfile(data, line);
		else
		{
			while (++i && line[i - 1] != '\0')
				if (!ft_isdigit(line[i - 1]))
					ft_error(data, 1);
			data->ants = ft_atoi(line);
			ft_getfile(data, line);
			if (data->ants <= 0 || ft_strlen(line) > 10)
				ft_error(data, 1);
			ft_strdel(&line);
			break ;
		}
		ft_strdel(&line);
		get_next_line(0, &line);
	}
}

int		ft_readrooms(t_data *data)
{
	char	*line;
	int		i;

	get_next_line(0, &line);
	i = ft_isroom(data, line);
	while (line != NULL && (i == 1 || i == 10))
	{
		if (i == 10)
		{
			ft_strdel(&line);
			return (10);
		}
		ft_validroom(data, line);
		ft_strdel(&line);
		get_next_line(0, &line);
		i = ft_isroom(data, line);
	}
	ft_valid_command(data);
	i = ft_readlinks(data, line);
	if (i == 10)
		return (10);
	ft_strdel(&line);
	return (1);
}

int		ft_readlinks(t_data *data, char *s1)
{
	char	*line;
	int		i;

	line = ft_strdup(s1);
	i = ft_islink(line);
	while (line != NULL && (i == 1 || i == 10))
	{
		if (i == 10)
		{
			ft_strdel(&line);
			return (10);
		}
		ft_validlink(data, line);
		ft_strdel(&line);
		get_next_line(0, &line);
		if (line == NULL)
			return (1);
		i = ft_islink(line);
	}
	ft_strdel(&line);
	return (1);
}
