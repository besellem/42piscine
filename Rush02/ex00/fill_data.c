/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: besellem <besellem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/23 16:46:10 by besellem          #+#    #+#             */
/*   Updated: 2020/08/26 11:47:56 by besellem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

char	*get_key(char *line, int *len)
{
	char	*key;
	int		i;

	i = 0;
	while (line[i] >= '0' && line[i] <= '9')
		++i;
	if (!(key = (char *)malloc(sizeof(char) * (i + 1))))
		return (NULL);
	ft_strlcpy(key, line, i + 1);
	while (line[i] == ' ' || line[i] == ':')
		++i;
	*len += i;
	return (key);
}

char	*get_value(char *line)
{
	char	*value;
	int		len;
	int		i;

	i = 0;
	while (line[i] == ' ')
		++i;
	len = ft_strlen(line);
	while (line[len] == ' ')
		--len;
	if (!(value = (char *)malloc(sizeof(char) * (len - i + 1))))
		return (NULL);
	ft_strlcpy(value, line + i, len - i + 1);
	return (value);
}

char	**ft_epur_str(char *line)
{
	char	**split;
	int		len;

	len = 0;
	if (!(split = (char **)malloc(sizeof(char *) * 3)))
		return (NULL);
	if ((split[0] = get_key(line, &len)) == NULL)
		return (NULL);
	if ((split[1] = get_value(line + len)) == NULL)
		return (NULL);
	split[2] = NULL;
	return (split);
}

t_data	*ft_fill_list(char *buffer)
{
	t_data	*data;
	char	**split;
	char	*tmp;
	int		len;
	int		i;

	if (!(tmp = (char *)malloc(sizeof(char) * (ft_strlen(buffer) + 1))))
		return (NULL);
	i = 0;
	while (buffer[i])
	{
		len = 0;
		while (buffer[len + i] && buffer[len + i] != '\n')
			++len;
		ft_strlcpy(tmp, buffer + i, len + 1);
		split = ft_epur_str(tmp);
		ft_list_push(&data, ft_create_elem(split[0], split[1]));
		i += len + 1;
	}
	i = -1;
	while (split[++i])
		free(split[i]);
	free(tmp);
	free(split);
	return (data);
}
