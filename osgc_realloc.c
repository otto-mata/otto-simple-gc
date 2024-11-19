/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   osgc_realloc.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tblochet <tblochet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 15:31:43 by tblochet          #+#    #+#             */
/*   Updated: 2024/11/19 21:11:30 by tblochet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "osgc.h"

void	*osgc_realloc(void *mem, size_t old_sz, size_t new_sz)
{
	t_otto_gc	*gc;
	t_gcblock	*block;
	void		*nmem;

	gc = osgc_instance();
	if (!gc)
		return (0);
	if (!gc->blocks)
		return (0);
	block = gc->blocks;
	while (block)
	{
		if ((unsigned long)block->mem == (unsigned long)mem)
			break ;
		block = block->next;
	}
	if (!block)
		return (0);
	nmem = malloc(new_sz);
	otto_memcpy(nmem, mem, old_sz);
	free(mem);
	block->mem = nmem;
	return (nmem);
}
