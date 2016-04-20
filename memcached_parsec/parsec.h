#ifndef PARSEC_HEADER_H
#define PARSEC_HEADER_H

#include <ps_smr.h>
#include <ps_plat.h>

extern __thread int thd_local_id;
extern struct parsec ps;
extern unsigned long long set_periods[NUM_CPU];
extern unsigned long long quiesce_periods[NUM_CPU];

void parsec_mem_init(void);
void *parsec_mem_alloc(size_t size);
void parsec_mem_free(void *node);
void parsec_quiesce(void);

#endif
