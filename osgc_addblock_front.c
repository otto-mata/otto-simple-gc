/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   osgc_addblock_front.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tblochet <tblochet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 14:30:42 by tblochet          #+#    #+#             */
/*   Updated: 2024/11/19 08:36:18 by tblochet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "osgc.h"

t_gcblock	*osgc_addblock_front(t_gcblock *new)
{
	t_otto_gc	*gc;

	gc = osgc_instance();
	if (!gc || !new)
		return (0);
	new->next = gc->blocks;
	gc->blocks = new;
	return (new);
}
