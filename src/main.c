/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kosadchu <kosadchu@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/01 19:06:18 by kosadchu          #+#    #+#             */
/*   Updated: 2019/05/17 13:14:26 by kosadchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lemin.h"

void	print_ways(void)
{
	int		i;
	int		j;

	i = 0;
	ft_printf("\n\033[01;32mFinal quantity of ways : %d\n\n\e[0m", \
	g_ways->len);
	while (i < g_ways->len)
	{
		j = -1;
		ft_printf("\033[01;35mWAY #%d\n\e[0m", i + 1);
		ft_printf("\033[01;33m[%s] \e[0m", g_start->name);
		while (++j < g_ways->ways[i]->len)
			ft_printf("\033[01;33m[%s] \e[0m", g_ways->ways[i]->item[j]->name);
		ft_printf("\n\n");
		i++;
	}
}

void	print_input(void)
{
	int		i;

	i = -1;
	while (++i < g_save->len)
	{
		if (ft_strstr((char *)g_save->item[i], "#Here is"))
			ft_printf("\033[01;33m%s\n\e[0m", (char *)g_save->item[i]);
		else
			ft_printf("%s\n", (char *)g_save->item[i]);
	}
	ft_printf("\n");
}

int		main(void)
{
	g_rooms = new_array(50);
	g_queue = new_array(100);
	g_ways = new_array(50);
	pars_farm();
	bfs();
	print_input();
	running_ants();
	print_ways();
	return (0);
}
