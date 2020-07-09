#ifndef U_CHAIN_H
#define U_CHAIN_H
#include "u_stddef.h"
#include "u_mallocat.h"
//-------------
struct Array{
    void* data;
    size_t n;
};
//-------------

struct chain
{
  struct chain* prew_chain;
  struct chain* next_chain;
  struct Array array;

};





#endif // !U_CHAIN_H
