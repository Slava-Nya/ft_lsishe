/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlorrine <hlorrine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/07 15:25:05 by hlorrine          #+#    #+#             */
/*   Updated: 2020/07/07 15:25:08 by hlorrine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "print.h"
#include "str_lib.h"
#include <string.h>
#include <errno.h>

static void	print_error_str(void)
{
	int		cnt;

	cnt = 0;
	while (cnt < N_ERRORS && errno != g_errors[cnt].code)
		cnt++;
	if (cnt == N_ERRORS)
		ft_putstr_fd("unknown error", 2);
	ft_putstr_fd(g_errors[cnt].str, 2);
}

void		print_error(char *path)
{
	ft_putstr_fd("ls: ", 2);
	print_error_str();
	ft_putstr_fd(" '", 2);
	ft_putstr_fd(path, 2);
	ft_putstr_fd("': ", 2);
	ft_putendl_fd(strerror(errno), 2);
}
