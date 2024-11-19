/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   osgc_newblock.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tblochet <tblochet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 14:28:13 by tblochet          #+#    #+#             */
/*   Updated: 2024/11/19 08:34:35 by tblochet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "osgc.h"

t_gcblock	*osgc_newblock(void *mem)
{
	t_gcblock	*node;

	node = malloc(sizeof(t_gcblock));
	if (!node)
		return (0);
	node->mem = mem;
	node->next = 0;
	return (node);
}
