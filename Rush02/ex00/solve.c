/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: besellem <besellem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/23 19:15:19 by besellem          #+#    #+#             */
/*   Updated: 2020/08/26 11:44:19 by besellem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

char	*get_unit(int nb, int pos, t_data *data)
{
	t_data	*tracer;
	char	*res;
	int		i;

	if (!(res = (char *)malloc(sizeof(char) * 50)))
		return (NULL);
	i = 0;
	tracer = data;
	while (tracer)
	{
		if (tracer->key[0] - 48 == nb &&
			ft_strlen(tracer->key) == MAX_TAB - pos)
		{
			ft_strlcpy(res, tracer->value, ft_strlen(tracer->value) + 1);
			return (res);
		}
		++i;
		tracer = tracer->next;
	}
	return (NULL);
}

void	print_third(int nb, int pos, t_data *data)
{
	ft_putstr(get_unit(nb, pos, data));
}
