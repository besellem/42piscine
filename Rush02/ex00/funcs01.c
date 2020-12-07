/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   funcs01.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: besellem <besellem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/23 10:16:33 by besellem          #+#    #+#             */
/*   Updated: 2020/08/26 11:54:06 by besellem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

t_data	*ft_create_elem(char *key, char *value)
{
	t_data *new;

	if (!(new = (t_data *)malloc(sizeof(t_data))))
		return (NULL);
	new->key = ft_strdup(key);
	new->value = ft_strdup(value);
	new->next = NULL;
	return (new);
}

void	ft_list_push(t_data **head, t_data *new)
{
	t_data **tracer;

	tracer = head;
	while ((*tracer) && ft_strcmp((*tracer)->key, new->key) <= 0 &&
			ft_strlen((*tracer)->key) > ft_strlen(new->key))
	{
		tracer = &(*tracer)->next;
	}
	new->next = *tracer;
	*tracer = new;
}

void	ft_print_list(t_data *head)
{
	t_data *tracer;

	tracer = head;
	while (tracer)
	{
		ft_putstr(tracer->value);
		tracer = tracer->next;
	}
}
