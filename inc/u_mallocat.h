#ifndef U_MALLOC_H
#define U_MALLOC_H

#include "../u_stdlib.h"


#define STDLIB_API extern
/** **************************************************************
 * @autor: dn.maksimow@gmail.com
 * 
 * При использовании данного кода помните, что тут может 
 * храниться много жучков-паучков.
 * Пожалуйста, не используйте в серьёзных проектах
 * -----------------------------------------------------------
 *  Велосипед из стандартных функций.
 * Работает по следующему принципу: 
 * 1) дефайнингом uHEAP_SIZE предопределяется размер памяти в
 * которой будут храниться динамически выделенные через u_malloc
 * данные.
 * 2) в пределах этой памяти работают двусвязные контейнеры, состоящие
 * из предыдущего адреса, следующего адреса размера данных и самих
 * данных. при вызове u_malloc создаётся такой контейнер. При
 * вызове u_free уничтожается.
 * 3) при 64-битной архитектуре размер памяти съедаемой при u_malloc(n):
 *  (N+1)*24 паразитные данные
 *  + полезные данные 
 * 
 * макроопределение DEBUG для тестирования, если отсутствует main
 * ************************************************************** */
#define uHEAP_SIZE 6048
// #define DEBUG

STDLIB_API void* u_memset(void *__s, unsigned char __c, size_t __n);

STDLIB_API void* u_memcpy(void *__dest, const void *__src, size_t __n);

STDLIB_API void* u_malloc(size_t n_bytes);

STDLIB_API void u_free(void* ptr);

STDLIB_API u8* u_get_heap(void);

STDLIB_API void* u_realloc (void *__ptr, size_t __size);


#undef STDLIB_API
#endif // !U_MALLOC_H
