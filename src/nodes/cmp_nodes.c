/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmp_nodes.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azomega <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/18 13:02:15 by azomega           #+#    #+#             */
/*   Updated: 2020/07/18 18:55:14 by dbutterw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "nodes.h"
#include "str_lib.h"

int		cmp_nodes(t_node *node1, t_node *node2, t_flags *flags)
{
	long	ret;

	if (flags->sort == f_unset)
		return (1);
	ret = 0;
	if (!ft_strlen(node1->path))
		return (-1);
	else if (!ft_strlen(node2->path))
		return (1);
	if (flags->sort == f_mtime)
		ret = node2->info.st_mtimespec.tv_sec - node1->info.st_mtimespec.tv_sec;
	else if (flags->sort == f_ctime)
		ret = node2->info.st_ctimespec.tv_sec - node1->info.st_ctimespec.tv_sec;
	else if (flags->sort == f_atime)
		ret = node2->info.st_atimespec.tv_sec - node1->info.st_atimespec.tv_sec;
	else if (flags->sort == f_size)
		ret = node2->info.st_size - node1->info.st_size;
	if (ret == 0)
		ret = ft_strcmp(node1->path, node2->path);
	if (flags->all[31])
		ret *= -1;
	return ((int)ret);
}
