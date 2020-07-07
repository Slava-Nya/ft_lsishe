/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_dir_node.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlorrine <hlorrine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/07 15:29:00 by hlorrine          #+#    #+#             */
/*   Updated: 2020/07/07 15:29:03 by hlorrine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "nodes.h"
#include "str_lib.h"
#include "mem_lib.h"

t_node	*get_dir_node(char *argv, struct stat info)
{
	t_node *new_node;

	new_node = (t_node*)ft_xmalloc(sizeof(t_node));
	new_node->info = info;
	ft_strcpy(new_node->path, argv);
	new_node->srcs = NULL;
	return (new_node);
}
