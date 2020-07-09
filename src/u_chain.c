#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "u_chain.h"



#define c_new(type) (type*)u_malloc(sizeof(type))




//=============================================================

struct chain* init_chain()
{
    struct chain* ret_ch = c_new(struct chain);
    u_memset(ret_ch, 0, sizeof(struct chain));
    return ret_ch;   
}

struct chain* new_chain(void* _data, size_t n)
{
    struct chain* ch=init_chain();
    if(_data)
    {
        ch->array.n=n;
        ch->array.data=u_malloc(n);
        u_memcpy(ch->array.data, _data, n);
    }
    return ch;
}

struct chain* find_last(struct chain* ch)
{

    //----------------------------
     //0-1-2-3-4
	struct chain* ch1=ch; //4
    struct chain* ch2=ch1;

	// if(!ch1->prew_chain) {return ch;}

    while(ch1->next_chain)
	{   
        ch2=ch1;
		ch1=ch2->next_chain;
	
	}
	return ch1;
}

struct chain* find_first(struct chain* ch)
{
    //0-1-2-3-4
	struct chain* ch1=ch; //4
    struct chain* ch2=ch1;

    while(ch1->prew_chain)
	{   
        ch2=ch1;
		ch1=ch2->prew_chain;
	
	}
	return ch1;
}

int attach(struct chain* first, struct chain* second)
{
    //Закольцовка
    if(  (find_last(first)==find_last(second)) || (find_first(first)==find_first(second))    ) 
    {
        // perror("Ring detected!");
        return 1;
    }

    struct chain* last_second;
    struct chain* tmp2 = first->next_chain;
    first->next_chain=find_first(second);
    last_second = find_last(second);
    last_second->next_chain=tmp2;
    return 0;
}

    static void _attach2_chains(struct chain* first, struct chain* sec)
    {
        if(first)
            first->next_chain=sec;
        if(sec)    
            sec->prew_chain=first;
    }

    // static void _fill_array(struct chain* ch,void* data, size_t n)
    // {
    //     if(data){
    //         ch->array.n=n;
    //         ch->array.data=malloc(n);
    //         memcpy(ch->array.data, data, n);
    //     }
    // }


struct chain* insert_after(struct chain* dest, void* data, size_t n)
{
    // 01-02_-03
    struct chain* last_first = dest->next_chain; //03
    _attach2_chains(dest,new_chain(data, n));

    if(last_first)//03
    {
        _attach2_chains(dest->next_chain,last_first);

    }
    // _fill_array(dest->next_chain, data, n);
    return dest->next_chain;
}

struct chain* insert_after_ch(struct chain* dest, struct chain* ch)
{
    // 01-02_-03
    struct chain* last_first = dest->next_chain; //03
    _attach2_chains(dest,ch);

    if(last_first)//03
    {
        _attach2_chains(dest->next_chain,last_first);

    }
    // _fill_array(dest->next_chain, data, n);
    return dest->next_chain;
}
//-------------------------------------------------------------------
struct chain* insert_before(struct chain* dest, void* data, size_t n)
{
    struct chain* prew_first = dest->prew_chain;
    _attach2_chains(new_chain(data, n),dest);
    
    if(prew_first)
    {
        _attach2_chains(prew_first,dest->prew_chain);

    }
    // _fill_array(dest->prew_chain, data, n);
    return dest;
}
struct chain* insert_before_ch(struct chain* dest, struct chain* ch)
{
    struct chain* prew_first = dest->prew_chain;
    _attach2_chains(ch,dest);
    
    if(prew_first)
    {
        _attach2_chains(prew_first,dest->prew_chain);

    }
    // _fill_array(dest->prew_chain, data, n);
    return dest;
}


void free_chain(struct chain* ch)
{

    struct chain* first;
    struct chain* nxt=find_first(ch);
    while (nxt)
    {
        first=nxt;
        nxt=first->next_chain;
        if(first->array.data){
            u_free(first->array.data);
        }
        u_free(first);
        
    }


}

//!WARNING! не забудьте головное значение
struct chain* cut(struct chain* ch)
{
    struct chain* rv=ch->prew_chain;
    _attach2_chains(ch->prew_chain,ch->next_chain);
    ch->next_chain=0;
    ch->prew_chain=0;
    return rv;
}

struct chain* copy(struct chain* ch)
{
    return new_chain(ch->array.data, ch->array.n);
}

//----------------------------------------------------
void rewrite_chain(struct chain* ch,void* data, size_t n)
{
    if(ch->array.data){
        u_free(ch->array.data);
    }
    if(ch->array.data=u_malloc(n))
    {
        u_memcpy(ch->array.data, data, n);
        ch->array.n=n;
    }else{
        ch->array.n=0;
    }
    
}

// void append_in_sellected_chain(struct chain* ch,void* data, size_t n)
// {
//     if(!ch->array.data){
//         rewrite_chain(ch,data, n);
//         return;
//     }
//     real
//     if(ch->array.data=malloc(n))
//     {
//         memcpy(ch->array.data, data, n);
//         ch->array.n=n;
//     }else{
//         ch->array.n=0;
//     }
    
// }
//----------------------------------------------------
void print_chain(struct chain* ch)
{

    struct chain* first; 
    struct chain* nxt = find_first(ch);
    int n=0;
    while (nxt)
    {
        n++;
        first=nxt;
        nxt=first->next_chain;
        printf("%d. %s %dbytes\n",n,(char*)first->array.data , first->array.n);
        
    }
    
}

void print_selected(struct chain* ch)
{


    printf("\t%s %dbytes\n",(char*)ch->array.data , ch->array.n);
        
    
}

#define GO_NEXT(a) (((a)->next_chain)?(a=(a)->next_chain):(a))
#define GO_PREW(a) (((a)->prew_chain)?(a=(a)->prew_chain):(a))


#include <unistd.h>
//Тест на утечку памяти (смотреть в диспетчер задач)
void _test1_()
{
    struct chain* pointer;
    struct chain* parent;
    sleep(10);
    puts("start");
    for (int i=0;i<9000000;i++){
        pointer=new_chain("Hello, World!", 14);
        parent=pointer;
        pointer=insert_after(pointer,"da",3);


        pointer=insert_after(pointer,"dat",4);


        pointer=insert_after(pointer,"date",5);

        // print_chain(parent);
        // puts("----");
        struct chain* b=cut(pointer);
        // print_chain(parent);
        // puts("----");
        // print_chain(pointer);
        // puts("----");

        pointer=insert_after_ch(b->prew_chain, pointer);
        // print_chain(pointer);
        free_chain(parent);
    }
    puts("stop");
    sleep(10);
}





//-------------
int main(){

    _test1_();
    // free_chain(pointer);
    return 0;
}
//-------------

