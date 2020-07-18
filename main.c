#include "u_stdlib.h"
#include "u_test.h"
char* s;
int main(int argc, char const *argv[])
{
    u_memory_leak_chain_test();
    test_u_malloc_add_delete();

    s = u_malloc(9);
    u_intToHex(0xcafebabe, s);
    puts(s);
    u_free(s);

    test_u_malloc_overflow(8);
    // u_dump_heap("./log");
    return 0;
}
