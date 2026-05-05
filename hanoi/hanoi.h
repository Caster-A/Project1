/*2451454 电信 杨翰卓*/
#pragma once

/* 将所有const常量定义的头文件包含进来 */
#include "hanoi_const_value.h"
#include "cmd_console_tools.h"
#include "cmd_hdc_tools.h"

/* ------------------------------------------------------------------------------------------------------

     本文件功能：
	1、为了保证 hanoi_main.cpp/hanoi_menu.cpp/hanoi_multiple_solutions.cpp 能相互访问函数的函数声明
	2、一个以上的cpp中用到的宏定义（#define）或全局只读（const）变量，个数不限
	3、可以参考 cmd_console_tools.h 的写法（认真阅读并体会）
   ------------------------------------------------------------------------------------------------------ */
int menu();
void input(char data[], int type);
void output(int n, char src, char tmp, char dst, int type, int speed);
void hanoi(int n, char src, char tmp, char dst, int type, int speed);
void reset();
void column(int num, char src, char dst,int type);
void pillar();
void plate();
void movetrue(char src, char dst, int speed,int num);
char capital(char c);
bool check(char src, char dst, int num);
bool complete(char dst, int n);