/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tail.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: besellem <besellem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/19 13:55:52 by besellem          #+#    #+#             */
/*   Updated: 2020/08/26 12:55:19 by besellem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_TAIL_H
# define FT_TAIL_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <fcntl.h>
# include <sys/errno.h>
# include <libgen.h>

# define BUFFER 100000

typedef	struct	s_tab
{
	char	*data;
	int		size;
}				t_tab;

/*
** MAIN.C
*/
char			*ft_strcat(char *dest, char *src);
int				ft_file_size(char *file);
void			ft_tail_stdin(int offset);
void			ft_tail(char *file, int offset, int mult_files);

/*
** FT_LIBFT.C
*/
void			ft_putstr_fd(char *str, int fd);
int				ft_strlen(char *str);
int				ft_atoi(char *str);
int				ft_strncmp(char *s1, char *s2, unsigned int n);
int				ft_str_is_numeric(char *str);

/*
** FT_ERRORS.C
*/
void			ft_print_file_name(char *file);
int				ft_is_file(char *file);
int				ft_print_error(int ac, char **av, int i);
void			ft_option_offset(int ac, char **av, int *offset);
void			ft_arg_nbr(int ac, char **av, int *i);

/*
** FT_STDIN_CASE.C
*/
char			*ft_strcat(char *dest, char *src);
char			*ft_strdup(char *str);
t_tab			*ft_file_size_stdin(int offset);
void			ft_tail_stdin(int offset);

#endif
