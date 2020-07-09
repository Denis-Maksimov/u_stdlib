
#include "u_test.h"


//====================================================
//==            Тесты для u_chain                   ==
//====================================================

static void u_print_chain(struct chain* ch)
{

    struct chain* first; 
    struct chain* nxt = u_find_first(ch);
    int n=0;
    while (nxt)
    {
        n++;
        first=nxt;
        nxt=first->next_chain;
        printf("%d. %s %dbytes\n",n,(char*)first->array.data , first->array.n);
        
    }
    
}

static void u_print_selected(struct chain* ch)
{


    printf("\t%s %dbytes\n",(char*)ch->array.data , ch->array.n);
        
    
}

#define GO_NEXT(a) (((a)->next_chain)?(a=(a)->next_chain):(a))
#define GO_PREW(a) (((a)->prew_chain)?(a=(a)->prew_chain):(a))


#include <unistd.h>
//Тест на утечку памяти
void u_memory_leak_chain_test()
{
    struct chain* pointer;
    struct chain* parent;
    sleep(4);
    puts("start");
    for (int i=0;i<9000000;i++){
        pointer=u_new_chain("Hello, World!", 14);
        parent=pointer;
        pointer=u_insert_after(pointer,"da",3);


        pointer=u_insert_after(pointer,"dat",4);


        pointer=u_insert_after(pointer,"date",5);

        // print_chain(parent);
        // puts("----");
        struct chain* b=u_cut(pointer);
        // print_chain(parent);
        // puts("----");
        // print_chain(pointer);
        // puts("----");

        pointer=u_insert_after_ch(b->prew_chain, pointer);
        // u_print_chain(pointer);
        u_free_chain(parent);
    }
    puts("stop");
    sleep(3);
}

//====================================================
//==            Тесты для u_mallocat                ==
//====================================================


typedef struct tag_u_chain
{
  struct tag_u_chain* prew_chain;
  struct tag_u_chain* next_chain;
  size_t n;
  u8* data;

}u_chain;
extern void* u_get_start_chain(void);

static void print_uchain(void)
{

    u_chain* first;
    u_chain* _start_chain=u_get_start_chain();
    u_chain* nxt = _start_chain->next_chain;
    // int n=0;
    while (nxt)
    {
        // n++;
        first=nxt;
        nxt=first->next_chain;
        printf("0x%X:\n", first);
        printf("  prew:0x%X\n", first->prew_chain);
        printf("  next:0x%X\n", first->next_chain);
        printf("%s :%d bytes\n", (u8*)(&first->data), first->n);
        
        // printf("0x%X. %s %d/%d bytes\n",&first->data ,(u8*)(&(first->data)) , first->n, (&first->data[first->n])-(&first->data[0]));
        // sleep(1);
    }
    puts("_________________");
    
}



/**
 * @brief Тест на добавление и удаление 
 * @note   
 * @retval None
*/

void test_u_malloc_add_delete(void)
{
    puts("==\\--test1--/==");
    char data[] = "Hello, my allocated world!";//28
    char data2[] = "Bye, my allocated world!";//26

    puts("адрес начала виртуальной кучи:");
    printf("0x%X\n",u_get_start_chain());

    char* new=u_malloc(sizeof(data));
    u_memcpy(new,data,sizeof(data));
    puts("first+");
    print_uchain();

    char* new1=u_malloc(sizeof(data2));   
    u_memcpy(new1,data2,sizeof(data2));
    puts("second+");
    print_uchain();
    

    puts("удаляем первый добавленный элемент");
    u_free(new);
    // print_chain();

    puts("----------------------------\n");

    puts("снова добавляем и смотрим выделенный адрес:");
    new=u_malloc(sizeof(data));
    u_memcpy(new,data,sizeof(data));
    print_uchain();

    puts("===========================\n\n");

}

/**
 * @brief  Тест на переполнение
 * @note   
 * @param  bytes: сколько байтов выделять зараз (до 16 сохранится в дампе)
 * @retval None
 */
void test_u_malloc_overflow(u32 bytes)
{
    puts("==\\--test2--/==");
    int n=0;
    printf("Проверяем, сколько байтов %d-байтовой фигни залезет в %d байт кучи\n",bytes, MY_HEAP_SIZE);
    void* mem=(void*)1;
    while(mem)
    {   
        mem=u_malloc(bytes);
        if(mem)  u_memcpy(mem,"123456789abcdef",bytes);
        putc('.',stdout);
        n++;
    }
    puts("\nдамп кучковой цепочки:");
    print_uchain();

    printf("\nТест завершён с результатом %d\n",n);
    puts("===========================\n\n");

}


void u_dump_heap(char* file)
{
    FILE* fd= fopen(file,"wb");
    fwrite(u_get_start_chain(),MY_HEAP_SIZE,1,fd);
}


