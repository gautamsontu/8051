#ifndef _global_h_
#define _global_h_

#define Set_Bit(reg,bpos)  reg = reg | (1<<bpos)
#define Clr_Bit(reg,bpos)  reg = reg & (~(1<<bpos))

#define Is_Bit_Set(reg,bpos)      reg&(1<<bpos)
#define Is_Bit_Clr(reg,bpos)    !(reg&(1<<bpos))

#define BIT0 0 
#define BIT1 1
#define BIT2 2 
#define BIT3 3 
#define BIT4 4 
#define BIT5 5 
#define BIT6 6 
#define BIT7 7 
 
#endif