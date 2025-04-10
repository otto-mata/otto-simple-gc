/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   ottogc.h                                             ┌─┐┌┬┐┌┬┐┌─┐        */
/*                                                        │ │ │  │ │ │        */
/*   By: tblochet <tblochet@student.42.fr>                └─┘ ┴  ┴ └─┘        */
/*                                                        ┌┬┐┌─┐┌┬┐┌─┐        */
/*   Created: 2025/04/10 06:24:49 by tblochet             │││├─┤ │ ├─┤        */
/*   Updated: 2025/04/10 06:27:13 by tblochet             ┴ ┴┴ ┴ ┴ ┴ ┴        */
/*                                                                            */
/* ************************************************************************** */

#ifndef OTTOGC_H
# define OTTOGC_H

typedef unsigned long	t_u64;

void					m_teardown(void);
void					m_delete(void *p);
void					*m_resize(void *p, t_u64 sz);
void					*m_reserve(t_u64 sz);

#endif
