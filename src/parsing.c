/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kosadchu <kosadchu@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/01 20:18:29 by kosadchu          #+#    #+#             */
/*   Updated: 2019/05/17 13:11:06 by kosadchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lemin.h"

void	save_ants(t_rooms *save)
{
	int		i;
	char	*str;

	str = NULL;
	while (1)
	{
		i = -1;
		get_next_line(0, &str);
		(str == NULL) ? ft_error("\033[01;31mError! Empty file!\n") : 0;
		while (str[0] == '#' && str[1] != '#')
		{
			push_array(save, (t_room*)str);
			get_next_line(0, &str);
		}
		push_array(save, (t_room*)str);
		valid_string(str);
		while (str[++i] != '\0')
			if (ft_isdigit(str[i]) == 1)
				ft_error("\033[01;31mError! Invalid ants number!\n");
		if ((g_ants_num = ft_atoi(str)) > 21474)
			ft_error("\033[01;31mError! So much ants! Ya manal ih puskat'\n");
		if (g_ants_num <= 0 || g_ants_num > INT_MAX)
			ft_error("\033[01;31mError! Wrong ants number!\n");
		break ;
	}
}

void	save_links(char **arr)
{
	t_room		*into;
	t_room		*push_room;

	if (!arr[0] || !arr[1])
		ft_error("\033[01;31mError in links! Have no room with same name!\n");
	into = find_room(arr[0]);
	push_room = find_room(arr[1]);
	if (!push_room || !into->name)
		ft_error("\033[01;31mError in links! Have no room with same name!\n");
	push_array(into->links, push_room);
	push_array(push_room->links, into);
}

void	pars_farm(void)
{
	char	*str;

	str = NULL;
	g_save = new_array(1000);
	save_ants(g_save);
	while (get_next_line(0, &str))
	{
		push_array(g_save, (t_room*)str);
		valid_string(str);
		(str[0] != '#') ? save_rooms(str) : 0;
	}
	if (g_end == NULL || g_start == NULL)
		ft_error("\033[01;31mError! Didn't find start/end room!\n");
	if (g_end->links[0].item[0] == NULL || g_start->links[0].item[0] == NULL)
		ft_error("\033[01;31mError! Didn't find any way!\n");
	push_array(g_rooms, g_end);
}
