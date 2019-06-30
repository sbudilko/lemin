/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   erros.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbudilko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/26 13:11:31 by sbudilko          #+#    #+#             */
/*   Updated: 2018/10/26 13:11:32 by sbudilko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void	ft_error1(t_data *data, int error)
{
	if (error == 6)
		ft_printf("ERROR: Bad roor defined\n");
	else if (error == 7)
		ft_printf("ERROR: Room will never start with the character 'L'\n");
	else if (error == 8)
		ft_printf("ERROR: Room already exists\n");
	else if (error == 9)
		ft_printf("ERROR: Bad 'coord_x'\n");
	else if (error == 10)
		ft_printf("ERROR: Bad 'coord_y'\n");
	else if (error == 51)
	{
		if (data->start == 0 && data->end != 0)
			ft_printf("ERROR: Command '##start' does not exist\n");
		else if (data->end == 0 && data->start != 0)
			ft_printf("ERROR: Command '##end' does not exist\n");
		else
			ft_printf("ERROR: Command '##start' and '##end' do not exist\n");
	}
	else if (error == 100)
		ft_printf("ERROR: No possible way!\n");
	ft_printf(RESET);
	exit(1);
}

void	ft_error(t_data *data, int error)
{
	ft_printf(RED);
	if (error == 1)
		ft_printf("ERROR: Bad ants number\n");
	else if (error == 2)
	{
		ft_valid_command(data);
		ft_printf("ERROR: No rooms\n");
	}
	else if (error == 3)
	{
		ft_valid_command(data);
		ft_printf("ERROR: No links\n");
	}
	else if (error == 4)
		ft_printf("ERROR: Command '##start' already exists\n");
	else if (error == 441)
		ft_printf("ERROR: Command '##end' already exists\n");
	else if (error == 5)
		ft_printf("ERROR: Command '##end' does not exist\n");
	else if (error == 555)
		ft_printf("ERROR: Command '##start' does not exist\n");
	ft_error1(data, error);
}

void	ft_error2(int error, char *s1, char *s2, char *line)
{
	ft_printf(RED);
	if (error == 1)
		ft_printf("ERROR: Bad link '%s'. Room '%s' does not exist\n",
		line, s1);
	else if (error == 2)
		ft_printf("ERROR: Bad link '%s'. Room '%s' does not exist\n",
		line, s2);
	else if (error == 3)
		ft_printf("ERROR: Bad link '%s'. Room '%s' and '%s' do not exist\n",
		line, s1, s2);
	ft_printf(RESET);
	exit(1);
}
