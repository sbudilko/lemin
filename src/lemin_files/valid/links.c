/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   links.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbudilko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/26 17:32:55 by sbudilko          #+#    #+#             */
/*   Updated: 2018/10/26 17:32:56 by sbudilko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

int		ft_islink(char *line)
{
	int		i;
	int		j;
	char	**buff;

	if (line[0] != '#')
	{
		buff = ft_strsplit(line, '-');
		i = num_buff(buff);
		del_buff(buff);
		free(buff);
		if (i != 2)
			return (10);
	}
	i = 0;
	j = 0;
	while (line[i] != '\0')
	{
		if (line[i] == '-')
			j++;
		i++;
	}
	if (line[0] != '#' && j != 1)
		return (10);
	return (1);
}

void	ft_validlink2(t_data *data, char *line)
{
	char	**buff;
	int		i;
	int		j;

	buff = ft_strsplit(line, '-');
	i = ft_roomexist(data, buff[0]);
	j = ft_roomexist(data, buff[1]);
	if (i == 0 && j != 0)
		ft_error2(1, buff[0], buff[1], line);
	if (j == 0 && i != 0)
		ft_error2(2, buff[0], buff[1], line);
	if (j == 0 && i == 0)
		ft_error2(3, buff[0], buff[1], line);
	del_buff(buff);
	free(buff);
}

void	ft_validlink(t_data *data, char *line)
{
	t_link	*tmp;

	tmp = data->link;
	while (tmp->next != NULL)
		tmp = tmp->next;
	if (tmp->from != NULL && tmp->to != NULL)
	{
		tmp->next = ft_newlink();
		tmp = tmp->next;
	}
	if (line[0] == '#' && line[1] != '#')
	{
		ft_getfile(data, line);
		return ;
	}
	if (line[0] == '#' && line[1] == '#')
	{
		ft_getcommand(data, data->room, line);
		return ;
	}
	ft_validlink2(data, line);
	ft_getlink(data, line);
	ft_getfile(data, line);
}
