/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   osgc_malloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tblochet <tblochet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 15:26:16 by tblochet          #+#    #+#             */
/*   Updated: 2024/11/19 08:34:35 by tblochet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "osgc.h"

void	*osgc_malloc(size_t sz)
{
	t_gcblock	*new;
	void		*mem;

	mem = malloc(sz);
	if (!mem)
		return (0);
	new = osgc_newblock(mem);
	if (!new)
		return (0);
	if (!osgc_addblock_back(new))
		return (0);
	return (mem);
}
