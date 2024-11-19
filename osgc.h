/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   osgc.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tblochet <tblochet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 15:01:07 by tblochet          #+#    #+#             */
/*   Updated: 2024/11/19 21:12:37 by tblochet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OSGC_H
# define OSGC_H
# include <stdint.h>
# include <stdlib.h>

typedef struct s_gcblock
{
	void				*mem;
	struct s_gcblock	*next;
}						t_gcblock;

typedef struct s_otto_gc
{
	t_gcblock			*blocks;
}						t_otto_gc;

t_otto_gc				*osgc_instance(void);
t_gcblock				*osgc_addblock_back(t_gcblock *new);
t_gcblock				*osgc_addblock_front(t_gcblock *new);
t_gcblock				*osgc_newblock(void *mem);
t_gcblock				*osgc_lastblock(void);
void					*osgc_delblock(t_gcblock *block);
int						osgc_blocksz(void);
void					*osgc_clear(void);
void					*osgc_malloc(size_t sz);
void					*osgc_realloc(void *mem, size_t old_sz, size_t new_sz);
void					otto_bzero(void *mem, size_t sz);
void					*otto_memcpy(void *d, void const *s, size_t sz);
#endif
