/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   osgc_clear.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tblochet <tblochet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 14:40:55 by tblochet          #+#    #+#             */
/*   Updated: 2024/11/19 08:36:30 by tblochet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "osgc.h"

void	*osgc_clear(void)
{
	t_gcblock	*iter;
	t_gcblock	*tmp;
	t_otto_gc	*gc;

	gc = osgc_instance();
	if (!gc)
		return (0);
	iter = (gc)->blocks;
	while (iter)
	{
		free(iter->mem);
		tmp = iter->next;
		free(iter);
		iter = tmp;
	}
	free(gc);
	return (0);
}
