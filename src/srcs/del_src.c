/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   del_src.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlorrine <hlorrine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/07 15:24:06 by hlorrine          #+#    #+#             */
/*   Updated: 2020/07/07 15:24:11 by hlorrine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "srcs.h"

void	del_src(t_src **src)
{
	free(*src);
	*src = NULL;
}
