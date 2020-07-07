/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   del_flags.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlorrine <hlorrine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/07 15:29:50 by hlorrine          #+#    #+#             */
/*   Updated: 2020/07/07 15:29:53 by hlorrine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "flags.h"

void	del_flags(t_flags **flags)
{
	free(*flags);
	*flags = NULL;
}
