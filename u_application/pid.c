#include "s5_timers.h"

// struct pid
// {
//     float Kp;
//     float Ki;
//     float Kd;

//     float prev_delta;
//     // u32 prev_time;//TODO

//     float integral;
// };

#include <stdio.h>

float proc_pid(struct pid* Pid,float x,float setting)
{
    float delta=setting-x;
    float deriv=Pid->prev_delta-delta;// div dT
    Pid->integral+=delta;// div dT
    Pid->prev_delta=delta;
    // printf("P=%f, I=%f, D=%f\t",Pid->Kp*delta,Pid->Ki*Pid->integral,Pid->Kd*deriv);
    return  Pid->Kp*delta+
            Pid->Ki*Pid->integral-
            Pid->Kd*deriv;
}


s32 clamp(s32 x, s32 low, s32 high)
{   
    return (x > high) ? (high): 
    ((x < low) ? (low) : (x));
}

float fclamp(float x, float low, float high)
{   
    return (x > high) ? (high): 
    ((x < low) ? (low) : (x));
}


