#ifndef __S5_TIMERS_H__
#define __S5_TIMERS_H__

#ifndef U_STDDEF_H
#include <stdint.h>
typedef uint32_t u32;
typedef uint16_t u16;
typedef uint8_t u8;

typedef int32_t s32;
typedef int16_t s16;
typedef int8_t s8;
#endif
#ifdef __MY_BARE_ARM__
extern uint32_t SysTick_VAL;
#else
uint32_t SysTick_VAL;
#endif // !1


typedef struct{
    u32 stv;
    // u32 value;
    u8 state:1;
    u8 state_pext:1;
}u_timer;

/*************************************************
* Формирователь импульса
* 
* ___|▔▔▔▔▔|____________      set 1
*
* ___|▔▔▔▔▔|____________      return 1
* 
* ___|▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔|__      set 2
*
* ___|▔▔▔▔▔▔▔▔▔▔▔|______      return 2
*
* ___|▔▔▔▔▔▔▔▔▔▔▔|______      tv
*
**************************************************/
u32 s_pulse(u_timer* Tx, u32 tv, u16 set, u16 rst);




/*************************************************
* Формирователь продлённого импульса
* 
* ___|▔▔▔▔▔|____________      set
*
* ___|▔▔▔▔▔▔▔▔▔▔▔|______      return
*
* ___|▔▔▔▔▔▔▔▔▔▔▔|______      tv
*
**************************************************/
u32 s_pext(u_timer* Tx, u32 tv, u16 set, u16 rst);


/*************************************************
* Формирователь задержки включения
*  
* ___|▔▔▔▔▔▔▔|__________      set
*
* ______|▔▔▔▔|__________      return 
*
* ___|▔▔|_______________      tv
*
**************************************************/
u32 s_odt(u_timer* Tx, u32 tv, u16 set, u16 rst);


/*************************************************
* Формирователь задержки включения с запоминанием
*  
* ___|▔▔▔|____________      set
*
* _____________|▔▔▔▔▔▔      return
*
* ___|▔▔▔▔▔▔▔▔|_______      tv
*
**************************************************/
u32 s_odts(u_timer* Tx, u32 tv, u16 set, u16 rst);


/*************************************************
*  Формирователь задержки выключения
*  
* ___|▔▔▔▔▔|_____________   set
*
* 
* ___|▔▔▔▔▔▔▔▔▔▔▔▔|______   return
*
* _________|▔▔▔▔▔▔|______   tv
*
**************************************************/
u32 s_offdt(u_timer* Tx, u32 tv, u16 set, u16 rst);
//------------------------------------------------------------
struct pid
{
    float Kp;
    float Ki;
    float Kd;

    float prev_delta;
    // u32 prev_time;//TODO

    float integral;
};

float proc_pid(struct pid* Pid,float x,float setting);

s32 clamp(s32 x, s32 low, s32 high);
float fclamp(float x, float low, float high);




#endif // __S5_TIMERS_H__
