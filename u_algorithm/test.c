#include <u_sort.h>
#include <math.h>
#include <stdio.h>


int nosort0[]={13,9,11,10,7,6,24,32,8,3,5,4,1,12,14};
int nosort1[]={13,9,11,10,7,6,24,32,8,3,5,4,1,12,14};
int nosort2[]={13,9,11,10,7,6,24,32,8,3,5,4,1,12,14};
int nosort3[]={13,9,11,10,7,6,24,32,8,3,5,4,1,12,14};
int nosort4[]={13,9,11,10,7,6,24,32,8,3,5,4,1,12,14};

int main(int argc, char const *argv[])
{

    insert_sort(nosort0,15);
    choise_sort(nosort1,15);
    bubble_sort(nosort2, 15);
    Gnome_sort( nosort3,15);
    quick_sort( nosort4,15);

    printf("|――――|―――――――――――|―――――――――――|―――――――――――|――――――――――|――――――――――|\n");
    printf("|  № |insert_sort|choise_sort|bubble_sort|Gnome_sort|quick_sort|\n");
    printf("|――――|―――――――――――|―――――――――――|―――――――――――|――――――――――|――――――――――|\n");
    for(int i=0;i<15;i++){
        printf("|%3d)|%11d|%11d|%11d|%10d|%10d|\n",
                 i,nosort0[i],nosort1[i],nosort2[i],nosort3[i],nosort4[i]);
    }
    printf("|――――|―――――――――――|―――――――――――|―――――――――――|――――――――――|――――――――――|\n");
    return 0;
}

#define SIZE 20
#include <stdio.h>

int test2()
{
  int a[SIZE];
  // Заполнение массива случайными числами
  for (int i = 0; i<SIZE; i++)
    a[i] = rand() % 201 - 100;
  // Вывод элементов массива до сортировки
  for (int i = 0; i<SIZE; i++)
    printf("%4d ", a[i]);
  printf("\n");
  quickSort(a, 0, SIZE-1); // вызов функции сортировки
            // Вывод элементов массива после сортировки
  for (int i = 0; i<SIZE; i++)
    printf("%4d ", a[i]);
  printf("\n");
  return 0;
}
