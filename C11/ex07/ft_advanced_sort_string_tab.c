/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_advanced_sort_string_tab.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: besellem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/18 11:21:54 by besellem          #+#    #+#             */
/*   Updated: 2020/08/18 11:21:56 by besellem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_advanced_sort_string_tab(char **tab, int (*cmp)(char *, char *))
{
	char	*tmp;
	int		i;

	i = -1;
	while (tab[++i])
	{
		if (*(tab + i + 1) && cmp(*(tab + i), *(tab + i + 1)) > 0)
		{
			tmp = *(tab + i);
			*(tab + i) = *(tab + i + 1);
			*(tab + i + 1) = tmp;
			i = -1;
		}
	}
}
