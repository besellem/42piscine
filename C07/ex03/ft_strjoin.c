/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: besellem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/12 13:58:36 by besellem          #+#    #+#             */
/*   Updated: 2020/08/12 13:58:38 by besellem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i])
		++i;
	return (i);
}

char	*ft_strcat(char *dest, char *src)
{
	int i;
	int len;

	len = 0;
	while (dest[len])
		++len;
	i = -1;
	while (src[++i])
		dest[len + i] = src[i];
	dest[len + i] = '\0';
	return (dest);
}

int		ft_len(int size, char **strs, char *sep)
{
	int i;
	int len;

	i = -1;
	len = 0;
	while (++i < size)
	{
		len += ft_strlen(strs[i]);
		if (i + 1 < size)
			len += ft_strlen(sep);
	}
	return (len);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*s;
	int		i;

	if (!(s = (char *)malloc(sizeof(char) * (ft_len(size, strs, sep) + 1))))
		return (NULL);
	*s = '\0';
	if (size <= 0)
		return (s);
	i = -1;
	while (++i < size)
	{
		ft_strcat(s, strs[i]);
		if (i + 1 < size)
			ft_strcat(s, sep);
	}
	return (s);
}
