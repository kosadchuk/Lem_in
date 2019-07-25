/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bfs.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kosadchu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/18 14:09:54 by kosadchu          #+#    #+#             */
/*   Updated: 2019/05/18 14:09:57 by kosadchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lemin.h"

void	save_parent(t_room *link, t_room *save)
{
	t_room	*tmp;

	link->re_r = (t_room*)ft_memalloc(sizeof(t_room));
	tmp = link->re_r;
	link->re_r = save;
	link->v = 1;
	free(tmp);
}

void	save_way(t_room *fin)
{
	g_way = new_array(100);
	while (ft_strcmp(fin->name, g_end->name))
	{
		push_array(g_way, fin);
		fin->v = 2;
		fin = fin->re_r;
	}
	push_array(g_way, fin);
	push_array(g_ways, g_way);
}

void	push_queue(t_room *srcroom)
{
	int		i;

	i = -1;
	g_end->v = 1;
	while (++i < srcroom->links->len)
	{
		if (srcroom->links->item[i]->v == 0)
		{
			save_parent(srcroom->links->item[i], srcroom);
			push_array(g_queue, srcroom->links->item[i]);
			if (!ft_strcmp(srcroom->links->item[i]->name, g_start->name))
			{
				if (!ft_strcmp(srcroom->name, g_end->name))
				{
					save_way(g_end);
					g_finish = 2;
					break ;
				}
				g_finish = 1;
				break ;
			}
		}
	}
}

void	free_visit_rooms(void)
{
	int		i;

	i = -1;
	while (++i < g_rooms->len)
	{
		if (g_rooms->item[i]->v == 1)
			g_rooms->item[i]->v = 0;
	}
}

void	bfs(void)
{
	int		i;

	i = 0;
	while (1)
	{
		g_finish = 0;
		if (i > 0)
			while (i < g_queue->len)
				i++;
		push_queue(g_end);
		while (i < g_queue->len)
		{
			if (g_finish == 1)
			{
				save_way(g_queue->item[i - 1]);
				free_visit_rooms();
				break ;
			}
			if (g_finish == 2)
				break ;
			push_queue(g_queue->item[i++]);
		}
		if (g_finish == 0 || g_finish == 2)
			break ;
	}
}
