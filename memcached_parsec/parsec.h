#ifndef PARSEC_HEADER_H
#define PARSEC_HEADER_H

#include <ps_smr.h>
#include <ps_plat.h>

extern __thread int thd_local_id;
extern struct parsec ps;
extern unsigned long long set_periods[PS_NUMCORES];
extern unsigned long long quiesce_periods[PS_NUMCORES];

void parsec_mem_init(void);
void *parsec_mem_alloc(size_t size);
void parsec_mem_free(void *node);
void parsec_quiesce(void);
void parsec_init_thd(unsigned long long p);
void parsec_mem_state(void);

#endif
