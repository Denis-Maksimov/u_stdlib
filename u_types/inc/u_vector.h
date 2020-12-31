#ifndef U_VECTOR_H
#define U_VECTOR_H

#include "u_mallocat.h"
#define STDLIB_API extern

typedef struct 
{
    size_t typesize;    //размер элемента данных
    size_t n_elem;      //число элементов
    void* mem;          //участок памяти, в котором находятся данные
}u_vector;


STDLIB_API void u_vector_init(u_vector* vec,size_t typesize);
STDLIB_API void u_vector_deinit(u_vector* vec);
STDLIB_API void u_vector_push_back(u_vector* vec, void* el);
STDLIB_API void u_vector_pop_back(u_vector* vec, void* el);
STDLIB_API void* u_vector_at(u_vector* vec,size_t at);
STDLIB_API int u_vector_cmp(u_vector* vec,size_t ind,void* el);
STDLIB_API int u_vector_find(u_vector* vec,void* el);

#undef STDLIB_API
#endif //!U_VECTOR_H
