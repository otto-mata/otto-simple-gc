/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   mem_manager.h                                        ┌─┐┌┬┐┌┬┐┌─┐        */
/*                                                        │ │ │  │ │ │        */
/*   By: tblochet <tblochet@student.42.fr>                └─┘ ┴  ┴ └─┘        */
/*                                                        ┌┬┐┌─┐┌┬┐┌─┐        */
/*   Created: 2025/03/08 23:57:40 by ottomata             │││├─┤ │ ├─┤        */
/*   Updated: 2025/04/10 06:26:12 by tblochet             ┴ ┴┴ ┴ ┴ ┴ ┴        */
/*                                                                            */
/* ************************************************************************** */

#ifndef MEM_MANAGER_H
# define MEM_MANAGER_H
# define PAGES_PER_NODE 64
# define PAGE_ALIGN 3
# define PAGE_POW_2 12
# include <errno.h>
# include <limits.h>
# include <stdint.h>
# include <stdlib.h>

typedef struct s_mem_manager	t_mem_manager;
typedef t_mem_manager			t_mm;

typedef struct s_page			t_page;
typedef t_page					t_mp;

typedef struct s_block			t_block;
typedef t_block					t_mpn;

typedef struct s_chunk			t_chunk;
typedef t_chunk					t_mpc;

typedef void					*(*t_fn_malloc)(size_t sz);
typedef void					*(*t_fn_realloc)(void *p, size_t sz);
typedef void					(*t_fn_free)(void *p);

struct							s_chunk
{
	char						x;
	size_t						sz;
};

struct							s_page
{
	size_t						sz;
	void						*mem;
};

struct							s_block
{
	size_t						len;
	t_mp						pages[PAGES_PER_NODE];
	t_mpn						*fwd;
};

struct							s_mem_manager
{
	t_fn_free					delete;
	t_fn_malloc					reserve;
	t_fn_realloc				resize;
	t_mpn						*pnodes;
};

t_mm							*m(void);
void							m_teardown(void);
void							m_delete(void *p);
void							*m_resize(void *p, size_t sz);
void							*m_reserve(size_t sz);
size_t							align_to(size_t n, size_t exponent);
void							ft_bzero(void *mem, size_t sz);
void							*ft_memcpy(void *d, void const *s, size_t sz);
void							*ft_memmove(void *d, void const *s, size_t sz);
t_mpc							*find_chunk_of_size(t_mm *mm, size_t sz);
t_mpc							*fragment_block(t_mpc *chunk, size_t sz);
t_mpc							*get_next_block_in_page(t_mpc *chunk,
									int find_zero);
t_mpc							*get_first_block_in_page(t_mp *mem_page);
int								new_memory_page(t_mm *alloc, size_t page_size);
#endif
