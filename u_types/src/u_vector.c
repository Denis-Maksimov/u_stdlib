#include "u_vector.h"




void u_vector_init(u_vector* vec)
{
    if(!vec)return;
    vec->mem=0;
    vec->n_elem=0;
}


void u_vector_deinit(u_vector* vec,void(*free_func)(void*))
{
    if(!vec)return;
    if(free_func){
        for (size_t i = 0; i < vec->n_elem; i++)
        {
            free_func((vec->mem[i]));
        }   
    }
    free(vec->mem);
    vec->mem=0;
    vec->n_elem=0;
}


void u_vector_push_back(u_vector* vec, void* el)
{
    if(!vec)return;
    vec->n_elem++;
    vec->mem=realloc(vec->mem, (sizeof(size_t))*vec->n_elem);
    vec->mem[vec->n_elem-1]=el;

}

void* u_vector_pop_back(u_vector* vec)
{
    if(!vec)return 0;
    if(!vec->n_elem)return 0;

    vec->n_elem--;
    void* rv = vec->mem[vec->n_elem];
    vec->mem=realloc(vec->mem, vec->n_elem);
    return rv;
}


void* u_vector_at(u_vector* vec,size_t at)
{
    if(!vec)return 0;
    return vec->mem[at];
}

#define IS_EQUAL    0
#define NO_EQUAL    1

int u_vector_cmp(u_vector* vec,size_t ind,void* el)
{
    if(!vec)return -1;
    if(u_vector_at(vec, ind)==el)
        return IS_EQUAL;
    return NO_EQUAL;
}

int u_vector_is_exist(u_vector* vec,void* el)
{
    if(!vec)return -1;
    for (size_t i = 0; i < vec->n_elem; i++)
    {
        if(!u_vector_cmp(vec,i,el))return 1;
    }
    return 0;
}

int u_vector_get_indx(u_vector* vec,void* el)
{
    if(!vec)return -1;
    for (size_t i = 0; i < vec->n_elem; i++)
    {
        if(!u_vector_cmp(vec,i,el))return i;
    }
    return 0;
}


int u_vector_find_indx(u_vector* vec,int(*cmp)(void* el, void* comparation),void* comparation )
{
    if(!vec)return -1;
    for (size_t i = 0; i < vec->n_elem; i++)
    {
        if(!cmp(vec->mem[i], comparation))
            return i;
    }
    return 0;
}


void* u_vector_find(u_vector* vec,int(*cmp)(void* el, void* comparation),void* comparation )
{
    if(!vec)return 0;
    for (size_t i = 0; i < vec->n_elem; i++)
    {
        if(!cmp(vec->mem[i], comparation))
            return vec->mem[i];
    }
    return 0;
}
