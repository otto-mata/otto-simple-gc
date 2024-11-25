/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   osgc_delblock.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tblochet <tblochet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 14:39:01 by tblochet          #+#    #+#             */
/*   Updated: 2024/11/25 11:53:23 by tblochet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "osgc.h"

void	*osgc_delblock(t_block *block)
{
	t_gc *const		gc = osgc_instance();
	t_block *const	prev = osgc_find_prev_by_address(block->mem);

	if (!gc || !block)
		return (0);
	if (!prev)
		gc->blocks = block->next;
	else
		prev->next = block->next;
	free(block->mem);
	block->mem = 0;
	free(block);
	return (0);
}
