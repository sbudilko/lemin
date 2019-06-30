/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbudilko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/29 16:43:22 by sbudilko          #+#    #+#             */
/*   Updated: 2018/10/29 16:43:23 by sbudilko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void	ft_init(t_data *data)
{
	data->flag = (t_flag*)malloc(sizeof(t_flag));
	data->flag->logs = 0;
	data->flag->way = 0;
	data->flag->clr = 0;
	data->flag->link = 0;
	data->flag->map = 0;
	data->flag->room = 0;
}

void	ft_error3(int i, char a)
{
	if (i == 1)
	{
		ft_printf(RED"lem-in: illegal optin -- %c\n"RESET, a);
	}
	ft_printf(GREEN"usage: lem-in [-LWcelmr]\n"RESET);
	ft_printf("   L	-	Figure out logs.\n");
	ft_printf("   W	-	Figure out min way.\n");
	ft_printf("   c	-	Color output.\n");
	ft_printf("   l	-	Figure out links info.\n");
	ft_printf("   m	-	Figure  out map info.\n");
	ft_printf("   r	-	Figure out rooms info.\n");
	exit(0);
}

int		a_in_b(char a, t_data *data)
{
	int		i;

	i = -1;
	while (FLAGS[++i] != '\0')
		if (a == FLAGS[i])
		{
			if (a == 'L')
				data->flag->logs = 1;
			if (a == 'W')
				data->flag->way = 1;
			if (a == 'c')
				data->flag->clr = 1;
			if (a == 'l')
				data->flag->link = 1;
			if (a == 'm')
				data->flag->map = 1;
			if (a == 'r')
				data->flag->room = 1;
			return (1);
		}
	return (0);
}

void	ft_flag(t_data *data, int argc, char **argv)
{
	int		i;
	int		j;

	i = 1;
	ft_init(data);
	if (argc == 1)
		return ;
	while (i < argc)
	{
		if (ft_strlen(argv[i]) == 1)
			ft_error3(0, ' ');
		j = 0;
		while (argv[i][j] != '\0')
		{
			if (argv[i][0] != '-')
				ft_error3(0, ' ');
			if (!a_in_b(argv[i][j], data))
				ft_error3(1, argv[i][j]);
			j++;
		}
		i++;
	}
}
