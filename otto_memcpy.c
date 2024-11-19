/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   otto_memcpy.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tblochet <tblochet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 11:01:51 by tblochet          #+#    #+#             */
/*   Updated: 2024/11/19 21:10:48 by tblochet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "osgc.h"

void	*otto_memcpy(void *d, void const *s, size_t sz)
{
	char const	*src;
	char		*dest;

	src = s;
	if (!d && !s)
		return (d);
	dest = d;
	while (sz--)
		*dest++ = *src++;
	return (d);
}
