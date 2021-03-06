/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_srcs.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azomega <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/18 13:07:29 by azomega           #+#    #+#             */
/*   Updated: 2020/07/18 13:11:45 by dbutterw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "srcs.h"
#include "str_lib.h"

static size_t	get_path(char path[MAX_PATHLEN], char *argv)
{
	size_t	len;

	len = ft_strlen(argv);
	ft_strcpy(path, argv);
	if (path[len - 1] != '/')
		path[len++] = '/';
	return (len);
}

t_avl			*get_srcs(DIR *dir, char *argv, t_flags *flags)
{
	struct dirent	*dir_read;
	char			path[MAX_PATHLEN];
	size_t			len;
	t_avl			*srcs;
	struct stat		info;

	srcs = NULL;
	len = get_path(path, argv);
	while ((dir_read = readdir(dir)))
	{
		if ((flags->all[15]) || \
			(flags->all[1] && ft_strcmp(dir_read->d_name, ".") && \
				ft_strcmp(dir_read->d_name, "..")) || \
			dir_read->d_name[0] != '.')
		{
			path[len] = '\0';
			ft_strcat(path, dir_read->d_name);
			lstat(path, &info);
			srcs = ft_insert_avl(srcs, \
			ft_new_node(init_src(dir_read->d_name, info)), flags, \
			(int (*)(const void *, const void *, void *)) &cmp_srcs);
		}
	}
	return (srcs);
}
