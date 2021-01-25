#ifndef U_VECTOR_H
#define U_VECTOR_H

#include <u_stdlib.h>
// #define STDLIB_API extern

typedef struct 
{

    void** mem;        //участок памяти, в котором находятся данные

    size_t n_elem;      //число элементов
    
}u_vector;


STDLIB_API void u_vector_init(u_vector* vec);
STDLIB_API void u_vector_deinit(u_vector* vec,void(*free_func)(void*));
STDLIB_API void u_vector_push_back(u_vector* vec, void* el);
STDLIB_API void* u_vector_pop_back(u_vector* vec);
STDLIB_API void* u_vector_at(u_vector* vec,size_t at);
STDLIB_API int u_vector_cmp(u_vector* vec,size_t ind,void* el);
STDLIB_API int u_vector_is_exist(u_vector* vec,void* el);
STDLIB_API int u_vector_get_indx(u_vector* vec,void* el);
STDLIB_API int u_vector_find_indx(u_vector* vec,int(*cmp)(void* el, void* comparation),void* comparation );

#endif //!U_VECTOR_H
