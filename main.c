#include "u_stdlib.h"
#include "u_test.h"

int main(int argc, char const *argv[])
{
    u_memory_leak_chain_test();
    test_u_malloc_add_delete();
    test_u_malloc_overflow(8);
    u_dump_heap("./log");
    return 0;
}
