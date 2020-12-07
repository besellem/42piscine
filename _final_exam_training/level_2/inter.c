/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inter.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: besellem <besellem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/27 14:29:08 by besellem          #+#    #+#             */
/*   Updated: 2020/08/27 15:27:33 by besellem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

int		main(int ac, char **av)
{
	int i;
	int j;
	int k;

	if (ac == 3)
	{
		j = 0;
		i = -1;
		while (av[2][++i])
		{
			k = j - 1;
			while (k >= 0 && av[1][k] != av[1][j])
				--k;
			if (k != -1)
			{
				++j;
				continue ;
			}
			if (av[2][i] == av[1][j])
			{
				k = j - 1;
				while (k >= 0 && av[1][k] != av[1][j])
					--k;
				printf("i: %d, j: %d, k: %d, av[1][k]: %c, av[1][j]: %c\n", i, j, k, av[1][j], av[1][k]);
				if (k == -1)
					write(1, &av[1][j], 1);
			}
		}
	}
	write(1, "\n", 1);
	return (0);
}
