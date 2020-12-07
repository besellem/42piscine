/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: besellem <besellem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/06 15:21:17 by besellem          #+#    #+#             */
/*   Updated: 2020/08/06 15:21:25 by besellem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
