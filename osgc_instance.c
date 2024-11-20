/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   osgc_instance.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tblochet <tblochet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 14:54:00 by tblochet          #+#    #+#             */
/*   Updated: 2024/11/20 16:49:55 by tblochet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "osgc.h"

t_otto_gc	*osgc_instance(void)
{
	static t_otto_gc	*inst = 0;

	if (!inst)
	{
		inst = malloc(sizeof(t_otto_gc));
		if (!inst)
			return (0);
		inst->blocks = 0;
	}
	return (inst);
}
