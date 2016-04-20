#include "parsec.h"

#define ITEM_SIZE 100

__thread int thd_local_id;

struct parsec ps;
PS_PARSLAB_CREATE(item, ITEM_SIZE, PS_PAGE_SIZE * 128)

void
parsec_mem_init(void)
{
	ps_mem_init_item(&ps);
}

void *
parsec_mem_alloc(size_t size)
{
	assert(size == ITEM_SIZE);
	return ps_mem_alloc_item();
}

void
parsec_mem_free(void *node)
{
	ps_mem_free_item(node);
}

void
parsec_quiesce(void)
{
	ps_quiesce_item();
}

