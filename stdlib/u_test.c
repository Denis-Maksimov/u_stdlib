
#include "u_test.h"
#include "hex.h"

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


//Тест на утечку памяти
void u_memory_leak_chain_test()
{
    struct chain* pointer;
    struct chain* parent;
    puts("start");
    for (int i=0;i<9000000;i++){
        pointer=u_new_chain("Hello, World!", 14);
        parent=pointer;
        pointer=u_insert_after(pointer,"da",3);


        pointer=u_insert_after(pointer,"dat",4);


        pointer=u_insert_after(pointer,"date",5);

        // u_print_chain(parent);
        // puts("----");
        struct chain* b=u_cut(pointer);
        // u_print_chain(parent);
        // puts("----");
        // u_print_chain(pointer);
        // puts("----");

        pointer=u_insert_after_ch(b->prew_chain, pointer);
        // u_print_chain(pointer);
        u_free_chain(parent);
    }
    puts("stop");
}

//====================================================
//==            Тесты для u_mallocat                ==
//====================================================





/**
 * @brief Тест на добавление и удаление 
 * @note   
 * @retval None
*/

void test_u_malloc_add_delete(void)
{
    puts("==\\--test_u_malloc_add_delete--/==");
    char data[] = "Hello, my allocated world!";//28
    char data2[] = "Bye, my allocated world!";//26

    puts("адрес начала виртуальной кучи:");
    printf("0x%X\n",u_get_heap());

    char* new=u_malloc(sizeof(data));
    u_memcpy(new,data,sizeof(data));
    puts("first+");
    // print_uchain();

    char* new1=u_malloc(sizeof(data2));   
    u_memcpy(new1,data2,sizeof(data2));
    puts("second+");
    // print_uchain();
    hexdump(u_get_heap(),27+25+4);

    puts("удаляем первый добавленный элемент");
    u_free(new);
    // print_chain();
    hexdump(u_get_heap(),27+25+4);

    puts("----------------------------\n");

    puts("снова добавляем и смотрим выделенный адрес:");
    new=u_malloc(sizeof(data2));
    u_memcpy(new,data2,sizeof(data2));
    // print_uchain();
    hexdump(u_get_heap(),27+25+4);
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
    puts("==\\--test_u_malloc_overflow--/==");
    int n=0;
    void* hd=0;
    void* mem_=0;
    printf("Проверяем, сколько байтов %d-байтовой фигни залезет в %d байт кучи\n",bytes, uHEAP_SIZE);
    void* mem=(void*)1;
    while(mem)
    {   
        mem=u_malloc(bytes);
        if(!hd)hd=mem;
        if(!mem_)mem_=mem;
        if(mem)  u_memcpy(mem,"123456789abcdef",bytes);
        // putc('.',stdout);
        n++;
    }
    puts("\nдамп кучи:");
    hexdump(hd, n);

    printf("\nТест завершён с результатом %d\n",n);
    puts("===========================\n\n");

}

void test_u_malloc_realloc()
{
    puts("==\\--test u_realoc--/==");
    int n=0;
    u8* mem=0;

    
    mem=u_malloc(sizeof("Hello, world")-1);
    memcpy(mem,"Hello, world",sizeof("Hello, world")-1);
    for (size_t i = 0; i < 25; i++)
    {
        mem=u_realloc(mem,(sizeof("Hello, world")-1)*(i+1));
        memcpy(mem+(sizeof("Hello, world")-1)*i,"Hello, world",sizeof("Hello, world")-1);
    }
    
    puts("25 :");
    printf(mem);
    printf("\nТест завершён\n");
    puts("===========================\n\n");

}
// void u_dump_heap(char* file)
// {
//     FILE* fd= fopen(file,"wb");
//     fwrite(u_get_start_chain(),MY_HEAP_SIZE,1,fd);
// }

#include "u_vector.h"

void test_u_vector()
{
    puts("==\\--test vector--/==");
    u_vector vec;
    
    struct test_t
    {
        char a[15];
    }el={0};
    
    
    
    u_vector_init(&vec,sizeof(el));
    
    u_memcpy(el.a,"Hello, world",13);
    u_vector_push_back(&vec, &el);

    u_memcpy(el.a,"bye, world",11);
    u_vector_push_back(&vec, &el);

    #define AT(i) ((struct test_t*)u_vector_at(&vec,i))

    printf("%s\n", AT(0)->a);
    printf("%s\n", AT(1)->a);
    printf("%d\n",u_vector_cmp(&vec,0,&el));
    printf("%d\n",u_vector_cmp(&vec,1,&el));
    printf("\nТест завершён\n");
    puts("===========================\n\n");
}

#include "u_graph.h"
void test_u_graph()
{
    puts("==\\--test graph--/==");
    u_graph a;
    u_graph_init(&a);

    
    u_graph_add_v(&a,"q");
    
    u_graph_add_v(&a,"w");
    u_graph_add_v(&a,"e");
    u_graph_add_v(&a,"r");
    u_graph_add_v(&a,"t");
    u_graph_add_v(&a,"y");
        u_graph_add_v(&a,"a");
        u_graph_add_v(&a,"s");
        u_graph_add_v(&a,"d");
        u_graph_add_v(&a,"f");
        u_graph_add_v(&a,"g");
        u_graph_add_v(&a,"h");
            u_graph_add_v(&a,"z");
            u_graph_add_v(&a,"x");
            u_graph_add_v(&a,"c");
            u_graph_add_v(&a,"v");
            u_graph_add_v(&a,"b");
            u_graph_add_v(&a,"n");

    
    u_graph_bind_vertex(&a,"qw","q","w",10);
    u_graph_bind_vertex(&a,"qa","q","a",10);
    
    u_graph_bind_vertex(&a,"ws","w","s",10);
    u_graph_bind_vertex(&a,"we","w","e",10);
    u_graph_bind_vertex(&a,"ed","e","d",10);
    u_graph_bind_vertex(&a,"er","e","r",10);
    u_graph_bind_vertex(&a,"rf","r","f",10);
    u_graph_bind_vertex(&a,"rt","r","t",10);
    u_graph_bind_vertex(&a,"tg","t","g",10);
    u_graph_bind_vertex(&a,"ty","t","y",10);
    u_graph_bind_vertex(&a,"yh","y","h",10);

    u_graph_bind_vertex(&a,"as","a","s",10);
    u_graph_bind_vertex(&a,"az","a","z",10);

    u_graph_bind_vertex(&a,"sx","s","x",10);
    u_graph_bind_vertex(&a,"sd","s","d",10);
    u_graph_bind_vertex(&a,"dc","d","c",10);
    u_graph_bind_vertex(&a,"df","d","f",10);
    u_graph_bind_vertex(&a,"fv","f","v",10);
    u_graph_bind_vertex(&a,"fg","f","g",10);
    
    u_graph_bind_vertex(&a,"gb","g","b",10);
    u_graph_bind_vertex(&a,"gh","g","h",10);
    u_graph_bind_vertex(&a,"hn","h","n",10);
//-----наискось-----
    u_graph_bind_vertex(&a,"rg","r","g",14);
    u_graph_bind_vertex(&a,"rd","r","d",14);
    u_graph_bind_vertex(&a,"ef","e","f",14);
    u_graph_bind_vertex(&a,"es","e","s",14);
    u_graph_bind_vertex(&a,"wd","w","d",14);
    u_graph_bind_vertex(&a,"tf","t","f",14);
    u_graph_bind_vertex(&a,"th","t","h",14);
    u_graph_bind_vertex(&a,"yg","y","g",14);
    u_graph_bind_vertex(&a,"qs","q","s",14);
    u_graph_bind_vertex(&a,"wa","w","a",14);
    u_graph_bind_vertex(&a,"hb","h","b",14);
    u_graph_bind_vertex(&a,"gn","g","n",14);
    u_graph_bind_vertex(&a,"gv","g","v",14);
    u_graph_bind_vertex(&a,"fb","f","b",14);
    u_graph_bind_vertex(&a,"fc","f","c",14);
    u_graph_bind_vertex(&a,"dv","d","v",14);
    u_graph_bind_vertex(&a,"dx","d","x",14);
    u_graph_bind_vertex(&a,"sc","s","c",14);
    u_graph_bind_vertex(&a,"ax","a","x",14);
    u_graph_bind_vertex(&a,"sz","s","z",14);

    u_graph_print_short_way(&a,"q","n");
    printf("\nТест завершён\n");
    puts("===========================\n\n");

}






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

