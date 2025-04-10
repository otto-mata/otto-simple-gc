/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   init.c                                               ┌─┐┌┬┐┌┬┐┌─┐        */
/*                                                        │ │ │  │ │ │        */
/*   By: tblochet <tblochet@student.42.fr>                └─┘ ┴  ┴ └─┘        */
/*                                                        ┌┬┐┌─┐┌┬┐┌─┐        */
/*   Created: 2025/03/09 00:03:16 by ottomata             │││├─┤ │ ├─┤        */
/*   Updated: 2025/04/10 06:26:12 by tblochet             ┴ ┴┴ ┴ ┴ ┴ ┴        */
/*                                                                            */
/* ************************************************************************** */

#include "mem_manager.h"

static t_mm	__initialize_memory_manager(void)
{
	t_mm	manager;

	manager.delete = &m_delete;
	manager.reserve = &m_reserve;
	manager.resize = &m_resize;
	manager.pnodes = 0;
	return (manager);
}

t_mm	*m(void)
{
	static t_mm	manager = {0};
	static int	init = 0;

	if (!init)
	{
		init = 1;
		manager = __initialize_memory_manager();
	}
	return (&manager);
}
