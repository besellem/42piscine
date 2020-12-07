/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: besellem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/18 11:21:23 by besellem          #+#    #+#             */
/*   Updated: 2020/08/18 11:21:24 by besellem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_is_sort_c(int *tab, int length, int (*f)(int, int))
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (i < length - 1)
	{
		j = i + 1;
		if ((f)(tab[i], tab[j]) > 0)
			return (0);
		i++;
	}
	return (1);
}

int		ft_is_sort_d(int *tab, int length, int (*f)(int, int))
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (i < length - 1)
	{
		j = i + 1;
		if ((f)(tab[i], tab[j]) < 0)
			return (0);
		i++;
	}
	return (1);
}

int		ft_is_sort(int *tab, int length, int (*f)(int, int))
{
	if (ft_is_sort_c(tab, length, &(*f)) == 0 &&
			ft_is_sort_d(tab, length, &(*f)) == 0)
		return (0);
	return (1);
}
