/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush01.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: besellem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/16 11:30:47 by besellem          #+#    #+#             */
/*   Updated: 2020/08/16 11:30:48 by besellem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		end_test_vertical(int map[4][4], int views_up_down[4], int dir)
{
	int max_building_height;
	int num_buildings;
	int	x;
	int	y;

	x = 0;
	while (x < 4)
	{
		max_building_height = 0;
		num_buildings = 0;
		y = (dir < 0 ? 3 : 0);
		while (y >= 0 && y < 4 && max_building_height < 4)
		{
			if (map[x][y] > max_building_height)
			{
				max_building_height = map[x][y];
				num_buildings++;
			}
			y += dir;
		}
		if (num_buildings != views_up_down[x])
			return (0);
		x++;
	}
	return (1);
}

int		end_test_horizontal(int map[4][4], int views_left_right[4], int dir)
{
	int max_building_height;
	int num_buildings;
	int x;
	int y;

	y = 0;
	while (y < 4)
	{
		max_building_height = 0;
		num_buildings = 0;
		x = (dir < 0 ? 3 : 0);
		while (x >= 0 && x < 4 && max_building_height < 4)
		{
			if (map[x][y] > max_building_height)
			{
				max_building_height = map[x][y];
				num_buildings++;
			}
			x += dir;
		}
		if (num_buildings != views_left_right[y])
			return (0);
		y++;
	}
	return (1);
}

int		check_duplicates(int map[4][4])
{
	int	arr_found[4];
	int	x;
	int	y;
	int i;

	x = 0;
	y = 0;
	while (y < 4)
	{
		i = 0;
		while (i < 4)
			arr_found[i++] = 0;
		while (x < 4)
		{
			if (arr_found[map[x][y] - 1])
				return (0);
			arr_found[map[x++][y] - 1] = 1;
		}
		x = 0;
		y++;
	}
	return (1);
}
0
void	update_map(int map[4][4], int current_columns[4],
		int possible_columns[24][4])
{
	int	x;
	int	y;

	y = 0;
	while (y < 4)
	{
		x = 0;
		while (x < 4)
		{
			map[x][y] = possible_columns[current_columns[x]][y];
			x++;
		}
		y++;
	}
}

int		plus_one(int map[4][4], int current_columns[4],
		int possible_columns[24][4])
{
	if (current_columns[3] < 23)
		current_columns[3]++;
	else
	{
		current_columns[3] = 0;
		if (current_columns[2] < 23)
			current_columns[2]++;
		else
		{
			current_columns[2] = 0;
			if (current_columns[1] < 23)
				current_columns[1]++;
			else
			{
				current_columns[1] = 0;
				if (current_columns[0] < 23)
					current_columns[0]++;
				else
					return (0);
			}
		}
	}
	update_map(map, current_columns, possible_columns);
	return (1);
}
