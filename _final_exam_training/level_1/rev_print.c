/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_print.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: besellem <besellem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/27 11:21:37 by besellem          #+#    #+#             */
/*   Updated: 2020/08/27 11:25:50 by besellem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i])
		++i;
	return (i);
}

int	main(int ac, char **av)
{
	int i;
	int len;

	if (ac == 2)
	{
		len = ft_strlen(av[1]);
		while (--len >= 0)
			write(1, &av[1][len], 1);
	}
	write(1, "\n", 1);
	return (0);
}
