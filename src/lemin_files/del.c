/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   del.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbudilko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/26 16:58:39 by sbudilko          #+#    #+#             */
/*   Updated: 2018/10/26 16:58:40 by sbudilko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

int		num_buff(char **str)
{
	int		i;

	i = 0;
	while (*str != '\0')
	{
		i++;
		str++;
	}
	return (i);
}

void	del_buff(char **str)
{
	while (*str != '\0')
	{
		free(*str);
		*str = NULL;
		str++;
	}
}

void	ft_printflag(t_data *data)
{
	if (data->flag->logs == 1)
		return ;
	if (data->flag->room == 1 || data->flag->link == 1 ||
		data->flag->map == 1 || data->flag->way == 1)
		ft_putendl("");
	if (data->flag->room == 1)
		ft_printroom(data);
	if (data->flag->link == 1)
		ft_printlink(data);
	if (data->flag->map == 1)
		ft_printmapinfo(data);
	if (data->flag->way == 1)
		ft_printbestway(data);
}

void	ft_log(t_data *data)
{
	if (data->flag->logs == 1)
	{
		ft_printroom(data);
		ft_printlink(data);
		ft_printmapinfo(data);
	}
}

void	ft_printmapinfo2(t_data *data, t_room *tmp, int i)
{
	int		j;
	int		num;

	j = 0;
	if (tmp->name != NULL)
	{
		num = ft_num_room(data);
		ft_printf("   [%.4s] -> ", tmp->name);
		while (j < num)
		{
			if (data->adj_matrix[i][j] == 1)
				ft_printf(" [%.4s] |", get_22(data, j));
			j++;
		}
	}
	ft_putendl("");
}
