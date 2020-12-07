/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_and_replace.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: besellem <besellem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/27 11:36:06 by besellem          #+#    #+#             */
/*   Updated: 2020/08/27 11:44:58 by besellem         ###   ########.fr       */
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

	if (ac == 4)
	{
		if (ft_strlen(av[2]) != 1 || ft_strlen(av[2]) != 1)
		{
			write(1, "\n", 1);
			return (0);
		}
		i = -1;
		while (av[1][++i])
		{
			if (av[1][i] == av[2][0])
				write(1, &av[3][0], 1);
			else
				write(1, &av[1][i], 1);
		}
	}
	write(1, "\n", 1);
	return (0);
}
