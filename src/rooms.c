/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rooms.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kosadchu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/23 19:59:10 by kosadchu          #+#    #+#             */
/*   Updated: 2019/05/23 19:59:13 by kosadchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lemin.h"

void	pars_room(char *str, t_room *room)
{
	char	**arr;

	arr = ft_strsplit(str, ' ');
	if (!arr[0] || !arr[1] || !arr[2])
		ft_error("\033[01;31mError! Wrong room coordinates!\n");
	check_room_name(arr);
	compare_room(arr);
	room->name = ft_strdup(arr[0]);
	room->y = ft_atoi(arr[1]);
	room->x = ft_atoi(arr[2]);
	room->v = 0;
	room->ant = 0;
	room->links = new_array(6);
	ft_free_array(arr);
}

t_room	*save_start_end(void)
{
	char	*s;
	t_room	*room;
	int		check;

	room = (t_room*)ft_memalloc(sizeof(t_room));
	get_next_line(0, &s);
	valid_string(s);
	check = valid_room(s);
	while (s[0] == '#' && s[1] != '#')
	{
		push_array(g_save, (t_room*)s);
		get_next_line(0, &s);
		check = valid_room(s);
	}
	if (check == 2)
		ft_error("\033[01;31mWrong room/link or command!\n\e[0m");
	if (check == 0)
	{
		pars_room(s, room);
		push_array(g_save, (t_room *)s);
	}
	return (room);
}

void	save_rooms(char *str)
{
	t_room	*room;
	char	**arr;
	int		check;

	check = valid_room(str);
	room = ft_memalloc(sizeof(t_room));
	if (check == 2)
		ft_error("\033[01;31mError! Wrong room/link name!\n\e[0m");
	if (check == 1)
	{
		arr = ft_strsplit(str, '-');
		save_links(arr);
		ft_free_array(arr);
	}
	if (check == 0)
		pars_room(str, room);
	push_array(g_rooms, room);
}

t_room	*find_room(char *name)
{
	int		i;

	i = -1;
	while (++i < g_rooms->len)
	{
		if (g_end != NULL && !ft_strcmp(g_end->name, name))
			return (g_end);
		if (g_rooms->item[i]->name != NULL
		&& !ft_strcmp(g_rooms->item[i]->name, name))
			return (g_rooms->item[i]);
	}
	ft_error("\033[01;31mError! The link room doesn't exist!\n");
	return (0);
}
