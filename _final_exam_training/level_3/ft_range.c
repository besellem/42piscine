/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: besellem <besellem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/27 20:10:43 by besellem          #+#    #+#             */
/*   Updated: 2020/08/27 21:37:09 by besellem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int start, int end)
{
	int *tab;
	int size;
	int i;

	size = start > end ? start - end + 1 : end - start + 1;
	if (!(tab = (int *)malloc(sizeof(int) * (size))))
		return (NULL);
	i = -1;
	while (start <= end && ++i < size)
		tab[i] = start++;
	while (start >= end && ++i < size)
		tab[i] = start--;
	return (tab);
}
