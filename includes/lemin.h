/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjamie <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 20:23:37 by sjamie            #+#    #+#             */
/*   Updated: 2019/11/12 20:23:38 by sjamie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEMIN_H
# define LEMIN_H

#include "../gnl/get_next_line.h"
#include <stdio.h>

typedef struct		s_main
{
	int				ants;
	int				rooms;
	int				links;
	struct s_graph	*graph;
}					t_main;

typedef struct		s_link
{
	char			is_true;
	char			directed;
	struct s_node	*node;
	struct s_link	*next;
}					t_link;

typedef struct		s_rel
{
	int				count;
	struct s_link	*link;
}					t_rel;

typedef struct		s_node
{
	int				id;
	char			*name;
	int				x;
	int				y;
	struct s_rel	*linkbox;
	struct s_node	*next;
}					t_node;

typedef struct		s_graph
{
	struct s_node	*start;
	struct s_node	*end;
	struct s_node	*node;
}					t_graph;

void				*lm_init(int res, char *line);
void				die();
void				reader(t_main *main, char **line, int ch);

void				reader_words(t_main *main, char **line, int ch);
void				reader_crtroom(t_main *main, char **items, char flag);
int					reader_is_link(t_main *main, char *line);
void				graph_init(t_main *main);

int					lm_count(char **items);
void				cleaner_2_array(char **array, int count);

#endif
