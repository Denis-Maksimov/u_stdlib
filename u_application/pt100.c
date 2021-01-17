// #include "u_math.h"

//+-0.4 градуса возвращает 100*температура
int R_to_Temp(int Rt){
    return (2605*Rt-26080999)/1000;
}

#include <stdio.h>
int main(int argc, char const *argv[])
{
    printf("%d\n",R_to_Temp(10700));
    return 0;
}
