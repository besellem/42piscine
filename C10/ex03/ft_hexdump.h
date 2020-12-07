/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexdump.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: besellem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/24 15:13:15 by besellem          #+#    #+#             */
/*   Updated: 2020/08/24 15:13:17 by besellem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_HEXDUMP_H
# define FT_HEXDUMP_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <fcntl.h>
# include <sys/errno.h>
# include <libgen.h>

# define BUFFER 4096

/*
** MAIN.C
*/
int		ft_check_args(int ac, char **av);

/*
** FT_LIBFT.C
*/
int		ft_strncmp(char *s1, char *s2, unsigned int n);

#endif
