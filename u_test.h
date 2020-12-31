#ifndef U_TEST_H
#define U_TEST_H

#include "u_stdlib.h"
#include <stdio.h>
#include <unistd.h>
//====================================================
//==            Тесты для u_chain                   ==
//====================================================
extern void u_memory_leak_chain_test(void);

//====================================================
//==            Тесты для u_mallocat                ==
//====================================================
extern void test_u_malloc_add_delete(void);
void test_u_malloc_realloc();
extern void test_u_malloc_overflow(u32 bytes);
// extern void u_dump_heap(char* file);

//====================================================
//==            Тесты для u_string                  ==
//====================================================
//TODO
//====================================================
//==            Тесты для u_vector                  ==
//====================================================
void test_u_vector();

void test_u_graph();

#endif // !U_TEST_H
