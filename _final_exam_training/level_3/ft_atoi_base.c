/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: besellem <besellem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/27 19:36:20 by besellem          #+#    #+#             */
/*   Updated: 2020/08/27 19:57:42 by besellem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	is_in_base(char c, int len)
{
	char	*base_maj;
	char	*base_min;
	int		i;

	if (len < 1 || len > 16)
		return (-1);
	base_min = "0123456789abcdef";
	base_maj = "0123456789ABCDEF";
	i = -1;
	while (base_min[++i] && i < len)
		if (c == base_min[i] || c == base_maj[i])
			return (i);
	return (-1);
}

int	ft_atoi_base(const char *str, int str_base)
{
	int		n;
	int		min;

	min = 1;
	while (*str == '-')
	{
		min *= -1;
		++str;
	}
	n = 0;
	while (is_in_base(*str, str_base) != -1)
		n = n * str_base + is_in_base(*str++, str_base);
	return (n * min);
}
