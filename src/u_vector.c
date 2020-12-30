#include "u_vector.h"




void u_vector_init(u_vector* vec,size_t typesize)
{
    vec->mem=0;
    vec->n_elem=0;
    vec->typesize=typesize;
}


void u_vector_deinit(u_vector* vec)
{
    u_free(vec->mem);
    vec->mem=0;
    vec->n_elem=0;
}


void u_vector_push_back(u_vector* vec, void* el)
{
    
    vec->n_elem++;
    vec->mem=u_realloc(vec->mem, vec->typesize*vec->n_elem);

    u_memcpy((u8*)vec->mem+(vec->typesize*(vec->n_elem-1)), 
                el, 
                vec->typesize);

}

void u_vector_pop_back(u_vector* vec, void* el)
{
    
    if(!vec->n_elem)return;

    if(el){
        u_memcpy(   
                    el, 
                    (u8*)vec->mem+(vec->typesize*(vec->n_elem-1)), 
                    vec->typesize
                );
    }

    vec->n_elem--;
    vec->mem=u_realloc(vec->mem, vec->n_elem);

}


void* u_vector_at(u_vector* vec,size_t at)
{
    return &((u8*)vec->mem)[at*vec->typesize];
}

#define IS_EQUAL    0
#define NO_EQUAL    1

int u_vector_cmp(u_vector* vec,size_t ind,void* el)
{
    u8* el_in_v=(u8*)u_vector_at(vec, ind);

    for(size_t i=0; i < vec->typesize; i++)
	{
		if( el_in_v[i] != ((u8*)el)[i])
		{
			return NO_EQUAL;
		}

	}
    return IS_EQUAL;

}

int u_vector_find(u_vector* vec,void* el)
{
    for (size_t i = 0; i < vec->n_elem; i++)
    {
        if(!u_vector_cmp(vec,i,el))return 1;
    }
    return 0;
}
