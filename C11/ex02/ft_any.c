/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_any.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: besellem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/18 11:20:59 by besellem          #+#    #+#             */
/*   Updated: 2020/08/18 11:21:00 by besellem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_any(char **tab, int (*f)(char*))
{
	int i;

	i = -1;
	while (tab[++i])
	{
		if (f(tab[i]) != 0)
			return (1);
	}
	return (0);
}