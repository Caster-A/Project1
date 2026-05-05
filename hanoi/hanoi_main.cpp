/*2451454 电信 杨翰卓*/
#include <iostream>
#include <Windows.h>
#include <conio.h>
#include <iomanip>
#include <cmath>
#include "hanoi_const_value.h"
#include "hanoi.h"
#include "cmd_hdc_tools.h"
#include "cmd_console_tools.h"
using namespace std;
/* ----------------------------------------------------------------------------------

     本文件功能：
	1、放main函数
	2、初始化屏幕
	3、调用菜单函数（hanoi_menu.cpp中）并返回选项
	4、根据选项调用菜单各项对应的执行函数（hanoi_multiple_solutions.cpp中）

     本文件要求：
	1、不允许定义全局变量（含外部全局和静态全局，const及#define不在限制范围内）
	2、静态局部变量的数量不限制，但使用准则也是：少用、慎用、能不用尽量不用
	3、按需加入系统头文件、自定义头文件、命名空间等

   ----------------------------------------------------------------------------------- */

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
int main()
{
	cout << "请确认当前cmd窗口的大小为40行*120列以上，字体为新宋体/16，按C继续，Q退出" << endl;
	while (1) {
		char ch = _getch();
		if (ch == 'C' || ch == 'c')
			break;
		if (ch == 'Q' || ch == 'q')
			return 0;
	}
	int type;
	char data[7] = {'\0'};/*data0 层数 data1 src data2 tmp data3 dst data4 speed data5 m*/
	while (1) 
	{
		type = menu() - '0';
		cout << endl;
		cout << endl;
		if (type > 0 && type < 4) {
			input(data, type);
			hanoi(data[0]-'0', data[1], data[2], data[3], type,data[4]-'0');
		}
		if (type == 4) {
			input(data, type);
			cct_cls();
			cct_gotoxy(Status_Line_X, Status_Line_Y);
			cout << "从" << data[1] << "移动到" << data[3] << "，共" << ' ' << data[0] - '0' << " 层，延时设置为 " << data[4] - '0'<<"ms" << endl;
			cct_gotoxy(MenuItem4_Start_X, MenuItem4_Start_Y);
			/*初始*/
			int a[10] = { 0 };
			int b[10] = { 0 };
			int c[10] = { 0 };
			int topA = 0;
			int topB = 0;
			int topC = 0;
			for (int i = data[0] - '0'; i > 0; i--) {
				if (data[1] == 65 || data[1] == 97) {
					a[topA++] = i;
				}
				if (data[1] == 66 || data[1] == 98) {
					b[topB++] = i;
				}
				if (data[1] == 67 || data[1] == 98) {
					c[topC++] = i;
				}
			}
			cout << "初始:  ";
			cout << "A: ";
			for (int i = 0; i < topA; i++) {
				if (topA > 0) {
					cout << a[i] << ' ';
				}
			}
			for (int i = topA; i < 10; i++) {
				cout << "  ";
			}
			cout << "B: ";
			for (int i = 0; i < topB; i++) {
				if (topB > 0) {
					cout << b[i] << ' ';
				}
			}
			for (int i = topB; i < 10; i++) {
				cout << "  ";
			}
			cout << "C: ";
			for (int i = 0; i < topC; i++) {
				if (topC > 0) {
					cout << c[i] << ' ';
				}
			}
			for (int i = topC; i < 10; i++) {
				cout << "  ";
			}
			cout << endl;
			column(data[0] - '0', data[1], data[3],type);
			cct_gotoxy(MenuItem4_Start_X+ Underpan_A_X_OFFSET-2, MenuItem4_Start_Y+ Underpan_A_Y_OFFSET-1);
			for (int i = 0; i < 2*Underpan_Distance + 5; i++)
			{
				cout << "=";
			}cout << endl;
			cct_gotoxy(MenuItem4_Start_X + Underpan_A_X_OFFSET, MenuItem4_Start_Y + Underpan_A_Y_OFFSET);
			cout << "A";
			cct_gotoxy(MenuItem4_Start_X + Underpan_A_X_OFFSET + Underpan_Distance, MenuItem4_Start_Y + Underpan_A_Y_OFFSET);
			cout << "B";
			cct_gotoxy(MenuItem4_Start_X + Underpan_A_X_OFFSET + 2 * Underpan_Distance, MenuItem4_Start_Y + Underpan_A_Y_OFFSET);
			cout << "C";
			if (data[4] - '0' == 0) {
				while (_getch() != 13);
			}
			else
				Sleep(data[4] - '0');
			hanoi(data[0] - '0', data[1], data[2], data[3], type, data[4] - '0');
		}
		if (type == 5) {
			
			cct_cls();
			cct_gotoxy(Status_Line_X, Status_Line_Y);
			hdc_cls();
			pillar();
			

		}
		if (type == 6) {
			input(data, type);
			cct_cls();
			cct_gotoxy(Status_Line_X, Status_Line_Y);
			cout << "从 " << data[1] << " 移动到 " << data[3] << "，共 " << data[0] - '0' << " 层" << endl;
			hdc_cls();
			pillar();
			plate();
			
		}
		if (type == 7) {
			input(data, type);
			cct_cls();
			cct_gotoxy(Status_Line_X, Status_Line_Y);
			cout << "从 " << data[1] << " 移动到 " << data[3] << "，共 " << data[0] - '0' << " 层" << endl;
			hdc_cls();
			pillar();
			plate();
			output(data[0] - '0', data[1], data[2], data[3], type, data[4]-'0');
		}
		if (type == 8) {
			input(data, type);
			cct_cls();
			cct_gotoxy(Status_Line_X, Status_Line_Y);
			double result = pow(2, data[0] - '0')-1;
			cout << "从" << data[1] << "移动到" << data[3] << "，共" << ' ' << data[0] - '0' << " 层，延时设置为 " << data[4] - '0' << "ms（前" << (int)result << "步，后面自动变为0ms）" << endl;
			cct_gotoxy(MenuItem8_Start_X, MenuItem8_Start_Y);
			/*初始*/
			int a[10] = { 0 };
			int b[10] = { 0 };
			int c[10] = { 0 };
			int topA = 0;
			int topB = 0;
			int topC = 0;
			for (int i = data[0] - '0'; i > 0; i--) {
				if (data[1] == 65 || data[1] == 97) {
					a[topA++] = i;
				}
				if (data[1] == 66 || data[1] == 98) {
					b[topB++] = i;
				}
				if (data[1] == 67 || data[1] == 98) {
					c[topC++] = i;
				}
			}
			cout << "初始:  ";
			cout << "A: ";
			for (int i = 0; i < topA; i++) {
				if (topA > 0) {
					cout << a[i] << ' ';
				}
			}
			for (int i = topA; i < 10; i++) {
				cout << "  ";
			}
			cout << "B: ";
			for (int i = 0; i < topB; i++) {
				if (topB > 0) {
					cout << b[i] << ' ';
				}
			}
			for (int i = topB; i < 10; i++) {
				cout << "  ";
			}
			cout << "C: ";
			for (int i = 0; i < topC; i++) {
				if (topC > 0) {
					cout << c[i] << ' ';
				}
			}
			for (int i = topC; i < 10; i++) {
				cout << "  ";
			}
			cout << endl;
			column(data[0] - '0', data[1], data[3],type);
			cct_gotoxy(MenuItem8_Start_X + Underpan_A_X_OFFSET - 2, MenuItem8_Start_Y + Underpan_A_Y_OFFSET - 1);
			for (int i = 0; i < 2*Underpan_Distance + 5; i++)
			{
				cout << "=";
			}cout << endl;
			cct_gotoxy(MenuItem8_Start_X + Underpan_A_X_OFFSET, MenuItem8_Start_Y + Underpan_A_Y_OFFSET);
			cout << "A";
			cct_gotoxy(MenuItem8_Start_X + Underpan_A_X_OFFSET + Underpan_Distance, MenuItem8_Start_Y + Underpan_A_Y_OFFSET);
			cout << "B";
			cct_gotoxy(MenuItem8_Start_X + Underpan_A_X_OFFSET + 2 * Underpan_Distance, MenuItem8_Start_Y + Underpan_A_Y_OFFSET);
			cout << "C";
			hdc_cls();
			pillar();
			plate();
			if (data[4] - '0' == 0) {
				while (_getch() != 13);
			}
			else
				Sleep(data[4] - '0');
			hanoi(data[0] - '0', data[1], data[2], data[3], type, data[4] - '0');
		}
		if (type == 9) {
			input(data, type);
			cct_cls();
			cct_gotoxy(Status_Line_X, Status_Line_Y);
			cout << "从 " << data[1] << " 移动到 " << data[3] << "，共 " << data[0] - '0' << " 层" << endl;
			cct_gotoxy(MenuItem9_Start_X, MenuItem9_Start_Y);
			/*初始*/
			int a[10] = { 0 };
			int b[10] = { 0 };
			int c[10] = { 0 };
			int topA = 0;
			int topB = 0;
			int topC = 0;
			for (int i = data[0] - '0'; i > 0; i--) {
				if (data[1] == 65 || data[1] == 97) {
					a[topA++] = i;
				}
				if (data[1] == 66 || data[1] == 98) {
					b[topB++] = i;
				}
				if (data[1] == 67 || data[1] == 98) {
					c[topC++] = i;
				}
			}
			cout << "初始:  ";
			cout << "A: ";
			for (int i = 0; i < topA; i++) {
				if (topA > 0) {
					cout << a[i] << ' ';
				}
			}
			for (int i = topA; i < 10; i++) {
				cout << "  ";
			}
			cout << "B: ";
			for (int i = 0; i < topB; i++) {
				if (topB > 0) {
					cout << b[i] << ' ';
				}
			}
			for (int i = topB; i < 10; i++) {
				cout << "  ";
			}
			cout << "C: ";
			for (int i = 0; i < topC; i++) {
				if (topC > 0) {
					cout << c[i] << ' ';
				}
			}
			for (int i = topC; i < 10; i++) {
				cout << "  ";
			}
			cout << endl;
			column(data[0] - '0', data[1], data[3], type);
			cct_gotoxy(MenuItem9_Start_X + Underpan_A_X_OFFSET - 2, MenuItem9_Start_Y + Underpan_A_Y_OFFSET - 1);
			for (int i = 0; i < 2*Underpan_Distance + 5; i++)
			{
				cout << "=";
			}cout << endl;
			cct_gotoxy(MenuItem9_Start_X + Underpan_A_X_OFFSET, MenuItem9_Start_Y + Underpan_A_Y_OFFSET);
			cout << "A";
			cct_gotoxy(MenuItem9_Start_X + Underpan_A_X_OFFSET + Underpan_Distance, MenuItem9_Start_Y + Underpan_A_Y_OFFSET);
			cout << "B";
			cct_gotoxy(MenuItem9_Start_X + Underpan_A_X_OFFSET + 2 * Underpan_Distance, MenuItem9_Start_Y + Underpan_A_Y_OFFSET);
			cout << "C";
			hdc_cls();
			pillar();
			plate();
			
			while (1) {
				cct_gotoxy(Status_Line_X, Status_Line_Y);
				cout << "从 " << data[1] << " 移动到 " << data[3] << "，共 " << data[0] - '0' << " 层" << endl;
				cct_gotoxy(MenuItem9_Start_X, MenuItem9_Start_Y - Underpan_A_Y_OFFSET);
				if (data[4]-'0' == 0) {
					while (_getch() != 13);
				}
				else
					Sleep(data[4] - '0');
				cout << "                                                                                                     ";
				cct_gotoxy(MenuItem9_Start_X, MenuItem9_Start_Y - Underpan_A_Y_OFFSET);
				cout << "请输入移动的柱号(命令形式：AC=A顶端的盘子移动到C，Q=退出) ：";
				char put[3];
				cin >>put;
				if ((put[0] == 'q' || put[0] == 'Q') && put[1] == '\0') {
					cout << "游戏中止!!!!!" << endl;
					break;
				}
				put[0] = capital(put[0]);
				put[1] = capital(put[1]);
				if ((put[0] != 'A' && put[0] != 'B' && put[0] != 'C')|| (put[1] != 'A' && put[1] != 'B' && put[1] != 'C')|| put[0]== put[1])
					continue;
				data[5] = put[0];
				data[6] = put[1];
				if(!check(data[5], data[6], data[0] - '0')) {
					continue;
				}
				output(data[0] - '0', data[5], data[2], data[6], type, data[4] - '0');	
				if (complete(data[3], data[0] - '0')) {
					cout << "游戏结束!!!!!" << endl;
					break;
				}
			}
		}
		if (type == 0) {
			break;
		}
		
		cout << endl;
		cout << "按回车键继续";
		while (_getch() != 13);
		reset();
	}
	return 0;
}