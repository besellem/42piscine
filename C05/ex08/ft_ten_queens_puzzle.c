/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ten_queens_puzzle.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: besellem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/13 17:16:55 by besellem          #+#    #+#             */
/*   Updated: 2020/08/13 17:16:57 by besellem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

#define N 10

void	ft_print_board(int c[N])
{
	int i;
	int tmp;

	i = -1;
	while (++i < N)
	{
		tmp = c[i] + 48;
		write(1, &tmp, 1);
	}
	write(1, "\n", 1);
}

int		ft_check(int c[N], int row, int col)
{
	int i;

	i = -1;
	while (++i < N)
	{
		if (i != col && c[i] == row)
			return (0);
		if (i != col && (row - c[i] < 0 ? c[i] - row : row - c[i]) == col - i)
			return (0);
	}
	return (1);
}

int		ft_backtrack(int c[N], int col, int *size)
{
	int i;

	if (col == N)
	{
		ft_print_board(c);
		*size += 1;
	}
	i = -1;
	while (++i < N)
	{
		if (ft_check(c, i, col))
		{
			c[col] = i;
			if (ft_backtrack(c, col + 1, size))
				return (0);
			c[col] = -1;
		}
	}
	return (0);
}

int		ft_ten_queens_puzzle(void)
{
	int c[N];
	int i;
	int size;

	i = -1;
	while (++i < N)
		c[i] = -1;
	size = 0;
	ft_backtrack(c, 0, &size);
	return (size);
}
