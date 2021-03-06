/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush01.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: besellem <besellem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/09 14:36:41 by besellem          #+#    #+#             */
/*   Updated: 2020/08/09 14:36:53 by besellem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	ft_print(int x, int y, int line, int col)
{
	if (line == 0 && col == 0)
		ft_putchar('/');
	else if (line == y - 1 && col == 0)
		ft_putchar('\\');
	else if ((col == 0 || col == x - 1) && line != 0 && line != y - 1)
		ft_putchar('*');
	else if (col != 0 && col != x - 1 && (line == 0 || line == y - 1))
		ft_putchar('*');
	else if (col == x - 1 && line == 0)
		ft_putchar('\\');
	else if (line == y - 1 && col == x - 1)
		ft_putchar('/');
	else
		ft_putchar(' ');
}

void	rush(int x, int y)
{
	int line;
	int col;

	if (x < 1 || y < 1)
		return ;
	line = 0;
	while (line < y)
	{
		col = 0;
		while (col < x)
		{
			ft_print(x, y, line, col);
			++col;
		}
		ft_putchar('\n');
		++line;
	}
}
