#ifndef STD_TYPES_H_
#define STD_TYPES_H_

#define SET_BIT(VAR, BIT_NO)  VAR|(1<<BIT_NO)
#define CLR_BIT(VAR, BIT_NO) VAR&~(1<<BIT_NO)
#define TOOGLE_BIT(VAR, BIT_NO)  VAR^(1<<BIT_NO)
#define GET_BIT(VAR,BIT_NO) (VAR >> BIT_NO) & 1‏
typedef signed char s8;
typedef signed short int s16;
typedef signed long int s32;
typedef unsigned char u8;
typedef unsigned short int u16;
typedef unsigned long int u32;
typedef float f32;
typedef double f64;
typedef long double f128;
typedef unsigned long long int u128;
typedef signed long long int s128;

#define NULL 0

#endif
