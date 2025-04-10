NAME=libgc.a
AR=ar rc
LIB=ranlib
CC=clang
CFLAGS=-Wall -Wextra -Werror -g3

LL_SRC=osgc_clear.c \
	osgc_addblock_front.c \
	osgc_delblock.c \
	osgc_malloc.c \
	osgc_addblock_back.c \
	osgc_newblock.c \
	otto_bzero.c \
	osgc_blocksz.c \
	osgc_calloc.c \
	osgc_lastblock.c \
	osgc_instance.c \
	osgc_realloc.c \
	otto_memcpy.c \
	otto_min.c \
	osgc_find_by_address.c \
	osgc_find_prev_by_address.c \
	osgc_free.c

MM_SRC=allocations.c \
	block.c \
	destroy.c \
	free.c \
	init.c \
	page.c \
	utilities.c


LL_PATH=$(addprefix ./ll/, $(LL_SRC))
MM_PATH=$(addprefix ./mm/, $(MM_SRC))
LL_OBJS=$(LL_PATH:.c=.o)
MM_OBJS=$(MM_PATH:.c=.o)

all: $(NAME)

$(NAME): $(LL_OBJS) $(MM_OBJS)
	$(AR) $@ $^
	$(LIB) $@

clean:		 
	rm -f $(LL_OBJS) $(MM_OBJS)

fclean: clean					
	rm -f $(NAME)

re: fclean  all

default: all
