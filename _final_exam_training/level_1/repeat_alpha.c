/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   repeat_alpha.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: besellem <besellem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/27 11:13:04 by besellem          #+#    #+#             */
/*   Updated: 2020/08/27 11:21:24 by besellem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		main(int ac, char **av)
{
	int i;
	int r;

	if (ac == 2)
	{
		i = -1;
		while (av[1][++i])
		{
			r = 0;
			if (av[1][i] >= 'a' && av[1][i] <= 'z')
				r = av[1][i] - 'a' + 1;
			else if (av[1][i] >= 'A' && av[1][i] <= 'Z')
				r = av[1][i] - 'A' + 1;
			if (r)
			{
				while (--r >= 0)
					write(1, &av[1][i], 1);
				continue ;
			}
			write(1, &av[1][i], 1);
		}
	}
	write(1, "\n", 1);
	return (0);
}
