/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbudilko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/29 19:39:05 by sbudilko          #+#    #+#             */
/*   Updated: 2018/10/29 19:39:07 by sbudilko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

char	*get_end(t_data *data)
{
	t_ant	*tmp;

	tmp = data->best_way;
	while (tmp->next != NULL)
		tmp = tmp->next;
	return (tmp->name);
}

int		ft_solve2(int i, struct s_ants *ants)
{
	if (ants[i].ant->next != NULL)
	{
		if (ants[i].ant->next->i != 1)
		{
			ft_printf("%s", ants[i].color);
			ft_printf("L%i-%s ", ants[i].i, ants[i].ant->next->name);
			ft_printf("%s", ants[i].reset);
			ants[i].ant->i = 0;
			ants[i].ant->next->i = 1;
			ants[i].ant = ants[i].ant->next;
		}
		else
		{
			i = -1;
			ft_putendl("");
		}
	}
	else
		ants[i].ant->i = 0;
	return (i);
}

void	get_color(struct s_ants *ant, t_data *data, int index)
{
	if (data->flag->clr == 0)
	{
		ant[index].color = EMPTY;
		ant[index].reset = EMPTY;
	}
	else
	{
		ant[index].reset = RESET;
		if (index % 6 == 0)
			ant[index].color = RED;
		else if (index % 6 == 1)
			ant[index].color = GREEN;
		else if (index % 6 == 2)
			ant[index].color = YELLOW;
		else if (index % 6 == 3)
			ant[index].color = BLUE;
		else if (index % 6 == 4)
			ant[index].color = MAGENTA;
		else if (index % 6 == 5)
			ant[index].color = CYAN;
	}
}
