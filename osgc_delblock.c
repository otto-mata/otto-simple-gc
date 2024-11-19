/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   osgc_delblock.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tblochet <tblochet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 14:39:01 by tblochet          #+#    #+#             */
/*   Updated: 2024/11/19 08:35:19 by tblochet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "osgc.h"

void	*osgc_delblock(t_gcblock *block)
{
	t_otto_gc	*gc;

	gc = osgc_instance();
	if (block)
		free(block->mem);
	free(block);
	return (0);
}
