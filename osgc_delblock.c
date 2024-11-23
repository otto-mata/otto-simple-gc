/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   osgc_delblock.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tblochet <tblochet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 14:39:01 by tblochet          #+#    #+#             */
/*   Updated: 2024/11/23 16:49:46 by tblochet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "osgc.h"

void	*osgc_delblock(t_gcblock *block)
{
	t_otto_gc	*gc;

	gc = osgc_instance();
	if (block)
	{
		free(block->mem);
		block->mem = 0;
	}
	// free(block);
	return (0);
}
