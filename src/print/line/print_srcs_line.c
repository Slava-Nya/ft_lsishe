//
// Created by slavanya on 21.03.2020.
//

#include <print.h>
#include <print_line.h>
#include <grp.h>
#include <pwd.h>
#include "srcs.h"
/*
 * 1 - chmod -- st_mode
 * 2 * - количество жестких ссылок для файлов -- st_nlink
 * 3 * - владелец -- st_uid; getpwuid
 * 4 * - группа -- st_gid; getgrgid
 * 5 * - размер в байтах -- st_size;
 * 6 *для даты - дата последнего изменения -- st_mtim;
 * 7 - имя файла
 *
 * l o g n
 *
 * 1 - имена в столбик
 * o - буз группы
 * g - без владельца
 *
 *
 */

static void		get_call(t_src *src, t_flags *flags, t_max_values max)
{
	if (flags->all[37])
	{
		print_name_endl(src->name, src->info.st_mode);
		return ;
	}
	print_mode(src->name, src->info.st_mode);
	print_nlink(src->info.st_nlink, max.links);
	if (!flags->all[21])
		print_uid(getpwuid((src->info).st_uid)->pw_name, max.uid);
	if (!flags->all[28])
		print_gid(getgrgid((src->info).st_gid)->gr_name, max.uid);
	print_size(src->info, max, flags);
	print_date(src->info, flags);
	print_name_endl(src->name, src->info.st_mode);
}

static void	get_elements(t_avl *srcs, t_flags *flags, t_max_values max)
{
	static t_src *tmp;

	if (!srcs)
		return ;
	get_elements(srcs->left, flags, max);
	tmp = (t_src *) srcs->content;
	get_call(tmp, flags, max);
	get_elements(srcs->right, flags, max);
}

void	print_srcs_line(t_avl *srcs, t_flags *flags)
{
	t_max_values max;

	get_max_values(srcs, &max);
	get_elements(srcs, flags, max);
}
