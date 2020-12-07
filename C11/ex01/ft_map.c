/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: besellem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/18 11:20:47 by besellem          #+#    #+#             */
/*   Updated: 2020/08/18 11:20:49 by besellem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_map(int *tab, int length, int (*f)(int))
{
	int *res;
	int i;

	if (!(res = (int *)malloc(sizeof(int) * length)))
		return (NULL);
	i = -1;
	while (++i < length)
		res[i] = f(tab[i]);
	return (res);
}
