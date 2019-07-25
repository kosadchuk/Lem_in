/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ants_run.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kosadchu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/22 17:04:31 by kosadchu          #+#    #+#             */
/*   Updated: 2019/05/22 17:04:34 by kosadchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lemin.h"

void	ants_start_array(int *ants)
{
	int		i;
	int		len;

	i = -1;
	len = 0;
	while (++i < g_ways->len)
	{
		if (g_ways->ways[i]->len * i - len < (*ants))
		{
			push_array(g_rooms_for_ants, g_ways->ways[i]->item[0]);
			(*ants)--;
		}
		len = len + g_ways->ways[i]->len;
	}
}

int		move_ant(t_rooms *way)
{
	int		len;

	len = way->len - 2;
	while (len > -1)
	{
		if (way->item[len]->ant > 0)
		{
			ft_printf("L%d-%s ", way->item[len]->ant, \
			way->item[len]->re_r->name);
			way->item[len]->re_r->ant = way->item[len]->ant;
			way->item[len]->ant = 0;
			if (!ft_strcmp(way->item[len]->re_r->name, g_end->name))
				g_ants_num--;
		}
		if (g_ants_num < 1)
			return (1);
		len--;
	}
	return (0);
}

int		check_ways(void)
{
	int		i;

	i = 0;
	while (i < g_ways->len)
	{
		if (move_ant(g_ways->ways[i]) == 1)
			return (1);
		i++;
	}
	return (0);
}

void	go_go_ants(int *lines)
{
	int		ant;
	int		flag;
	int		ant_num;
	int		j;

	ant = 1;
	flag = 0;
	ant_num = g_ants_num;
	while (flag == 0)
	{
		j = -1;
		while (++j < g_ways->len && g_ways->ways[j] && ant <= ant_num)
		{
			if (g_rooms_for_ants->item[ant - 1]->ant == 0)
			{
				g_rooms_for_ants->item[ant - 1]->ant = ant;
				ft_printf("L%d-%s ", ant, \
				g_rooms_for_ants->item[ant - 1]->name);
				ant++;
			}
		}
		ft_printf("\n");
		(*lines)++;
		flag = check_ways();
	}
}

void	running_ants(void)
{
	int		ants;
	int		count;
	int		lines;

	ants = g_ants_num;
	count = g_ants_num;
	lines = 1;
	if (g_finish != 2)
	{
		g_rooms_for_ants = new_array(g_ants_num);
		while (ants > 0)
			ants_start_array(&ants);
		go_go_ants(&lines);
	}
	if (g_finish == 2)
	{
		ants = 1;
		while (ants <= count)
		{
			ft_printf("L%d-%s L%d-%s\n", ants, g_start->name,\
				ants, g_end->name);
			ants++;
		}
	}
	ft_printf("\n\033[01;31mFinal number of lines : %d\n\e[0m", lines);
}
