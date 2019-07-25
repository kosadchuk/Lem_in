/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kosadchu <kosadchu@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/04 18:56:31 by kosadchu          #+#    #+#             */
/*   Updated: 2019/05/16 16:04:08 by kosadchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lemin.h"

void	check_command(char *str)
{
	if (str[0] == '#' && str[1] == '#')
	{
		if (!ft_strcmp(str, "##start") && g_start == NULL)
		{
			g_start = save_start_end();
			push_array(g_rooms, g_start);
		}
		else if (!ft_strcmp(str, "##end") && g_end == NULL)
			g_end = save_start_end();
		else
			ft_error("\033[01;31mError in command!\n");
	}
}

void	valid_string(char *str)
{
	if (!str || str == NULL || str[0] == '\0')
		ft_error("\033[01;31mError! An empty line!\n");
	if (str[0] == 'L')
		ft_error("\033[01;31mError! Invalid room name!\n");
	if (str[0] == ' ' || str[0] == '\t')
		ft_error("\033[01;31mError! Whitespaces before room name!\n");
	if (str[0] == '#' && str[1] == '#')
		check_command(str);
}

int		valid_room(char *str)
{
	int		i;
	int		space;
	int		defis;

	i = 0;
	space = 0;
	defis = 0;
	while (str[i++] != '\0')
	{
		(str[i] == ' ' || str[i] == '\t') ? space++ : 0;
		(str[i] == '-') ? defis++ : 0;
	}
	if (space > 2)
		ft_error("\033[01;31mError! So many spaces in room name/link!\n\e[0m");
	if (space == 2 && defis == 0)
		return (0);
	if (space == 0 && defis == 1)
		return (1);
	return (2);
}

void	compare_room(char **arr)
{
	int		i;

	i = 0;
	while (i < g_rooms->len)
	{
		if (!ft_strcmp(g_rooms->item[i]->name, arr[0]))
			ft_error("\033[01;31mError! Duplicated room name!\n\e[0m");
		if (g_rooms->item[i]->y == ft_atoi(arr[1])
			&& g_rooms->item[i]->x == ft_atoi(arr[2]))
			ft_error("\033[01;31mError! Duplicated room coordinates!\n\e[0m");
		i++;
	}
}

void	check_room_name(char **arr)
{
	int		i;
	int		j;

	j = 0;
	while (++j < 3)
	{
		i = -1;
		while (arr[j][++i] != '\0')
			if (ft_isdigit(arr[j][i]) == 1)
				ft_error("\033[01;31mError! Wrong coordinate!\n\e[0m");
	}
}
