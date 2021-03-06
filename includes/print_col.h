/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_col.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azomega <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/18 12:27:24 by azomega           #+#    #+#             */
/*   Updated: 2020/07/18 12:34:16 by azomega          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINT_COL_H
# define PRINT_COL_H
# include "srcs.h"
# define N_COL_PAD 2
# define COL_PAD " "

typedef struct	s_srcs_params
{
	int			max_name;
	int			sum_name;
}				t_srcs_params;

typedef struct	s_print_col{
	int			n;
	int			id;
	int			*widths;
}				t_print_col;

void			init_col_attr(t_avl *srcs, t_print_col *attr);
void			print_srcs_col(t_avl *srcs, char *path);
void			walk_srcs_col(t_avl *srcs, char *path, t_print_col *attr);
void			walk_srcs_row(t_avl *srcs, t_print_col *attr);
void			print_src(t_src *src, char *path, t_print_col *attr);
#endif
