#include "parsec.h"

#define ITEM_SIZE 102

__thread int thd_local_id;
struct parsec ps;
PS_PARSLAB_CREATE(item, ITEM_SIZE, PS_PAGE_SIZE * 512)

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

void
parsec_init_thd(unsigned long long p)
{
	ps_init_period(&ps, p);
}

void
parsec_mem_state(void)
{
	struct ps_mem *m = &__ps_mem_item;
	int i, m_tot = 0, c_tot = 0, m_max=0;

	for (i = 0 ; i < PS_NUMCORES ; i++) {
		/* printf("core %d quis max %d curr %d\n", i, m->percore[i].smr_info.qmemmax, m->percore[i].smr_info.qmemcnt); */
		m_tot += m->percore[i].smr_info.qmemmax;
		c_tot += m->percore[i].smr_info.qmemcnt;
		printf("core %d cur %d tot %d\n", i, m->percore[i].smr_info.qmemcnt, m->percore[i].smr_info.qmemmax);
		if (m->percore[i].smr_info.qmemmax > m_max) m_max = m->percore[i].smr_info.qmemmax;
	}
	printf("max %d tot_max %d cur %d\n", m_max, m_tot, c_tot);
	for (i = 0 ; i < PS_NUMCORES ; i++) {
		m->percore[i].smr_info.qmemmax = 0;
	}
}
