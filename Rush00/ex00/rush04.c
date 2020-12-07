/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush04.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sle-four <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/08 18:58:11 by sle-four          #+#    #+#             */
/*   Updated: 2020/08/08 18:58:12 by sle-four         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	ft_print(int x, int y, int line, int col)
{
	if (line == 0 && col == 0)
		ft_putchar('A');
	else if (line == y - 1 && col == 0)
		ft_putchar('C');
	else if ((col == 0 || col == x - 1) && line != 0 && line != y - 1)
		ft_putchar('B');
	else if (col != 0 && col != x - 1 && (line == 0 || line == y - 1))
		ft_putchar('B');
	else if (col == x - 1 && line == 0)
		ft_putchar('C');
	else if (line == y - 1 && col == x - 1)
		ft_putchar('A');
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
