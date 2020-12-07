/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: besellem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/16 11:30:41 by besellem          #+#    #+#             */
/*   Updated: 2020/08/16 11:30:43 by besellem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "rush01.h"

int		parse_inputs(int views[16], char *input_str)
{
	int	i;

	i = 0;
	while (*input_str)
	{
		if (i >= 16)
			return (0);
		if (*input_str < '1' || *input_str > '4')
			return (0);
		views[i++] = *input_str - '0';
		if (i < 16 && *++input_str != ' ')
			return (0);
		++input_str;
	}
	return (i == 16);
}

void	output_map(int map[4][4])
{
	int		x;
	int		y;
	char	c;

	y = 0;
	while (y < 4)
	{
		x = 0;
		while (x < 4)
		{
			c = '0' + map[x][y];
			write(1, &c, 1);
			++x;
			if (x < 4)
				write(1, " ", 1);
		}
		write(1, "\n", 1);
		++y;
	}
}

void	tab_init(int map[4][4], int possible_columns[4][4],
		int current_columns[4])
{
	int	x;
	int	y;

	y = 0;
	while (y < 4)
	{
		x = 0;
		current_columns[y] = 0;
		while (x < 4)
		{
			map[x][y] = possible_columns[0][x];
			++x;
		}
		++y;
	}
}

void	gen_possible_columns(int possible_columns[24][4])
{
	int n;
	int	i;
	int	nbs[4];

	n = 0;
	i = 0;
	while (n < 4 * 4 * 4 * 4)
	{
		nbs[3] = n % 4;
		nbs[2] = (n / 4) % 4;
		nbs[1] = (n / (4 * 4)) % 4;
		nbs[0] = (n / (4 * 4 * 4));
		if (nbs[0] != nbs[1] && nbs[0] != nbs[2] && nbs[0] != nbs[3] &&
				nbs[1] != nbs[2] && nbs[1] != nbs[3] &&
				nbs[2] != nbs[3])
		{
			possible_columns[i][0] = 1 + nbs[0];
			possible_columns[i][1] = 1 + nbs[1];
			possible_columns[i][2] = 1 + nbs[2];
			possible_columns[i][3] = 1 + nbs[3];
			++i;
		}
		++n;
	}
}

int		main(int argc, char **argv)
{
	int	map[4][4];
	int views[16];
	int	possible_columns[25][4];
	int	current_columns[4];

	if (argc != 2 || !parse_inputs(views, argv[1]))
		write(1, "Error\n", 6);
	else
	{
		gen_possible_columns(possible_columns);
		tab_init(map, possible_columns, current_columns);
		while (!end_test_vertical(map, views, 1) ||
				!end_test_vertical(map, views + 4, -1) ||
				!end_test_horizontal(map, views + 8, 1) ||
				!end_test_horizontal(map, views + 12, -1) ||
				!check_duplicates(map))
		{
			if (plus_one(map, current_columns, possible_columns))
				continue ;
			write(1, "Error\n", 6);
			return (0);
		}
		output_map(map);
	}
	return (0);
}
