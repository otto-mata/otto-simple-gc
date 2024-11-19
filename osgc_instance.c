/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   osgc_instance.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tblochet <tblochet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 14:54:00 by tblochet          #+#    #+#             */
/*   Updated: 2024/11/19 08:34:35 by tblochet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "osgc.h"

t_otto_gc	*osgc_instance(void)
{
	static t_otto_gc	*inst;

	if (!inst)
	{
		inst = malloc(sizeof(t_otto_gc));
		if (!inst)
			return (0);
	}
	return (inst);
}
