#include "u_stdlib.h"
#include "u_test.h"
#include "hex.h"
// #include "crc16.h"

char* s;
unsigned long t[2UL<<20]={0};

// #include <stdlib.h>
unsigned int collisions=0;

int main(int argc, char const *argv[])
{
    // // u_memory_leak_chain_test();
    // test_u_malloc_add_delete();
    // // crc_init();
    // s = u_malloc(9);
    // u_intToHex(0xcafebabe, s);
    // puts(s);
    // hexdump(u_get_heap(),uHEAP_SIZE);
    // u_free(s);

    // test_u_malloc_realloc();
    // test_u_vector();
    test_u_graph();
    test_u_malloc_overflow(1);

    return 0;
}

