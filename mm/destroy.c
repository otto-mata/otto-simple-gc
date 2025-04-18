/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   destroy.c                                            ┌─┐┌┬┐┌┬┐┌─┐        */
/*                                                        │ │ │  │ │ │        */
/*   By: tblochet <tblochet@student.42.fr>                └─┘ ┴  ┴ └─┘        */
/*                                                        ┌┬┐┌─┐┌┬┐┌─┐        */
/*   Created: 2025/03/09 01:23:28 by ottomata             │││├─┤ │ ├─┤        */
/*   Updated: 2025/04/10 06:25:48 by tblochet             ┴ ┴┴ ┴ ┴ ┴ ┴        */
/*                                                                            */
/* ************************************************************************** */

#include "mem_manager.h"

void	m_teardown(void)
{
	t_mpn	*node;
	t_mpn	*next;
	size_t	idx;

	node = m()->pnodes;
	while (node)
	{
		idx = 0;
		while (idx < node->len)
		{
			if (node->pages[idx].mem)
			{
				free(node->pages[idx].mem);
				node->pages[idx].sz = 0;
				node->pages[idx].mem = 0;
			}
			idx++;
		}
		next = node->fwd;
		free(node);
		node = next;
	}
}
