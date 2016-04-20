#ifndef PARSEC_HEADER_H
#define PARSEC_HEADER_H

#include <ps_smr.h>
#include <ps_plat.h>

extern __thread int thd_local_id;
extern struct parsec ps;

void parsec_mem_init(void);
void *parsec_mem_alloc(size_t size);
void parsec_mem_free(void *node);
void parsec_quiesce(void);

#endif
