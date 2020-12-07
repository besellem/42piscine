/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   max.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: besellem <besellem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/27 15:49:04 by besellem          #+#    #+#             */
/*   Updated: 2020/08/27 15:54:04 by besellem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		max(int *tab, unsigned int len)
{
	int				max;
	unsigned int	i;

	max = 0;
	i = 0;
	while (i < len)
	{
		if (tab[i] > max)
			max = tab[i];
		++i;
	}
	return (max);
}
