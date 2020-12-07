/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   union.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: besellem <besellem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/27 17:17:46 by besellem          #+#    #+#             */
/*   Updated: 2020/08/27 17:45:08 by besellem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i])
		++i;
	return (i);
}

int		main(int ac, char **av)
{
	int i;
	int j;
	int tst;

	if (ac == 3)
	{
		char buffer[ft_strlen(av[1]) + ft_strlen(av[2]) + 1];

		i = -1;
		while (av[1][++i])
			buffer[i] = av[1][i];
		j = -1;
		while (av[2][++j])
			buffer[i + j] = av[2][j];
		buffer[i + j] = '\0';
		i = -1;
		while (buffer[++i])
		{
			tst = 1;
			j = -1;
			while (++j < i)
			{
				if (buffer[j] == buffer[i])
				{
					tst = 0;
					break ;
				}
			}
			if (tst)
				write(1, &buffer[i], 1);
		}
	}
	write(1, "\n", 1);
	return (0);
}
