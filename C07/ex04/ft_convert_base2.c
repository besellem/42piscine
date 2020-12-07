/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: besellem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/12 16:24:16 by besellem          #+#    #+#             */
/*   Updated: 2020/08/14 15:05:59 by besellem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_check_base(char *base);
int		ft_atoi_base(char *str, char *base);

int		ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i])
		++i;
	return (i);
}

char	*ft_strcpy(char *dest, char *src)
{
	int i;

	i = -1;
	while (src[++i])
		dest[i] = src[i];
	dest[i] = '\0';
	return (dest);
}

char	*ft_convert_back(char *nbr, char *base_from, char *base_to)
{
	char	*res;
	long	nb;
	long	div;
	int		tmp;
	int		i;

	if (!(ft_check_base(base_from)) || !(res = malloc(50)))
		return (NULL);
	nb = ft_atoi_base(nbr, base_from);
	i = -1;
	if (nb < 0 && (nb = -nb) && ++i == 0)
		res[i] = '-';
	div = 1;
	tmp = ft_check_base(base_to);
	while (nb / div >= tmp)
		div *= tmp;
	while (div > 0)
	{
		res[++i] = base_to[nb / div % tmp];
		div /= tmp;
	}
	res[i + 1] = '\0';
	return (res);
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	char *res;
	char *tmp;

	if (!ft_check_base(base_from) || !ft_check_base(base_to))
		return (NULL);
	tmp = ft_convert_back(nbr, base_from, base_to);
	if (!(res = (char *)malloc(sizeof(char) * (ft_strlen(tmp) + 1))))
		return (NULL);
	ft_strcpy(res, tmp);
	free(tmp);
	return (res);
}
