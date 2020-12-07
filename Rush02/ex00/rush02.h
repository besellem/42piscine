/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush02.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: besellem <besellem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/23 08:53:30 by besellem          #+#    #+#             */
/*   Updated: 2020/08/26 11:54:31 by besellem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RUSH02_H
# define RUSH02_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <string.h>

# define BUFFER 4096
# define MAX_TAB 37

/*
** STRUCTS PROTOTYPES
*/
typedef	struct	s_args
{
	int		*values;
	char	*file;
}				t_args;

typedef	struct	s_data
{
	char			*key;
	char			*value;
	struct s_data	*next;
}				t_data;

/*
** MAIN.C
*/
void			ft_solve(int *values, t_data *data);;
int				*ft_get_values(char *arg);

/*
** FUNCS00.C
*/
void			ft_putstr(char *str);
int				ft_strlen(char *str);
int				ft_strcmp(char *s1, char *s2);
unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size);
char			*ft_strdup(char *src);

/*
** FUNCS01.C
*/
t_data			*ft_create_elem(char *key, char *value);
void			ft_list_push(t_data **head, t_data *new);
void			ft_print_list(t_data *head);

/*
** FT_SPLIT.C
*/
char			**ft_split(char *str, char *charset);

/*
** CHECKS.C
*/
int				ft_is_file(char *file);
int				ft_check_args(int ac, char **av, t_args *args);
int				ft_file_size(char *file);
t_data			*ft_fill_list(char *buffer);
t_data			*ft_parse_file(t_args *args);

/*
** CHECKS.C
*/
char			*get_key(char *line, int *len);
char			*get_value(char *line);
char			**ft_epur_str(char *line);
t_data			*ft_fill_list(char *buffer);

/*
** SOLVE.C
*/
char			*get_position(int nb, int pos, t_data *data);
char			*get_unit(int nb, int pos, t_data *data);
void			print_first(int nb, int pos, t_data *data);
void			print_second(int nb, int pos, t_data *data);
void			print_third(int nb, int pos, t_data *data);

#endif
