/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbudilko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/21 16:29:05 by sbudilko          #+#    #+#             */
/*   Updated: 2018/10/21 16:29:08 by sbudilko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEMIN_H
# define LEMIN_H
# define MAX_INT 	214748364
# define FLAGS 		"-LWclmr"
# define RED		"\x1b[31m"
# define GREEN		"\x1b[32m"
# define YELLOW		"\x1b[33m"
# define BLUE		"\x1b[34m"
# define MAGENTA	"\x1b[35m"
# define CYAN		"\x1b[36m"
# define RESET		"\x1b[0m"
# define EMPTY		""

# include "ft_printf.h"

typedef struct		s_room
{
	int				coord_x;
	int				coord_y;
	int				start;
	int				end;
	char			*name;
	struct s_room	*next;
}					t_room;

typedef struct		s_link
{
	char			*from;
	char			*to;
	struct s_link	*next;
}					t_link;

typedef struct		s_flag
{
	int				logs;
	int				way;
	int				clr;
	int				link;
	int				map;
	int				room;
}					t_flag;

typedef struct		s_file
{
	char			*line;
	struct s_file	*next;
}					t_file;

typedef struct		s_ant
{
	char			*name;
	int				i;
	struct s_ant	*next;
}					t_ant;

struct				s_ants
{
	t_ant			*ant;
	char			*color;
	char			*reset;
	int				i;
};

typedef struct		s_data
{
	int				*d;
	int				*u;
	int				*p;
	long int		**adj_matrix;
	int				start;
	int				end;
	int				ants;
	t_room			*room;
	t_ant			*best_way;
	t_link			*link;
	t_file			*file;
	t_flag			*flag;
}					t_data;

void				ft_solve(t_data *data);
void				ft_flag(t_data *data, int argc, char **argv);
t_room				*ft_newroom(void);
t_link				*ft_newlink(void);
t_file				*ft_newfile(void);
t_ant				*ft_newant(void);
int					ft_num_room(t_data *data);
void				ft_readmap(t_data *data);

void				ft_readants(t_data *data);
int					ft_readrooms(t_data *data);
int					ft_readlinks(t_data *data, char *line);
void				ft_error(t_data *data, int error);
void				ft_error2(int error, char *s1, char *s2, char *line);

void				ft_getfile(t_data *data, char *line);
void				ft_getroom(t_data *data, char *line);
void				ft_getlink(t_data *data, char *line);
int					ft_isroom(t_data *data, char *line);
void				ft_validroom(t_data *data, char *line);
void				ft_validlink(t_data *data, char *line);
void				del_buff(char **str);
int					num_buff(char **str);
char				*get_end(t_data *data);

int					ft_roomexist(t_data *data, char *line);
int					ft_islink(char *line);
void				ft_getcommand(t_data *data, t_room *room, char *line);

void				ft_valid_command(t_data *data);

void				ft_printroom(t_data *data);
void				ft_printlink(t_data *data);
void				ft_printmapinfo(t_data *data);
void				ft_printmapinfo2(t_data *data, t_room *tmp, int i);
void				for_deijkstra(t_data *data, int num);
void				ft_printbestway(t_data *data);
void				ft_printfile(t_data *data);

void				dijkstra_algo(t_data *data);
long int			**get_adj_matrix(t_data *data);
int					ft_get_index(t_data *data, char *str);
void				ft_printflag(t_data *data);
int					ft_solve2(int i, struct s_ants *ants);

void				ft_log(t_data *data);
char				*get_22(t_data *data, int i);
void				get_color(struct s_ants *ant, t_data *data, int index);

#endif
