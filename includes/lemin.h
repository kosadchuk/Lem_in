/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kosadchu <kosadchu@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/01 19:07:27 by kosadchu          #+#    #+#             */
/*   Updated: 2019/05/17 13:06:08 by kosadchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEMIN_H
# define LEMIN_H

# include "../libft/ft_printf/ft_printf.h"
# include <sys/types.h>
# include <stdio.h>
# include <limits.h>
# include <fcntl.h>

typedef struct s_room	t_room;
typedef struct s_rooms	t_rooms;
typedef	struct s_ways	t_ways;

struct				s_room
{
	char			*name;
	int				y;
	int				x;
	int				v;
	int				ant;
	t_room			*re_r;
	t_rooms			*links;
};

struct				s_rooms
{
	t_room			**item;
	ssize_t			len;
	ssize_t			full;
};

struct				s_ways
{
	t_rooms			**ways;
	ssize_t			len;
	ssize_t			full;
};

int					g_ants_num;
int					g_finish;
t_room				*g_start;
t_room				*g_end;
t_rooms				*g_rooms;
t_rooms				*g_way;
t_rooms				*g_save;
t_rooms				*g_queue;
t_ways				*g_ways;
t_rooms				*g_rooms_for_ants;

void				pars_farm(void);
void				valid_string(char *str);
void				check_command(char *str);
t_room				*save_start_end(void);
void				compare_room(char **arr);
void				save_ants(t_rooms *save);
void				save_rooms(char *str);
void				bfs(void);
void				running_ants(void);
void				save_links(char **arr);
t_room				*find_room(char *name);
int					valid_room(char *str);
void				check_room_name(char **arr);

#endif
