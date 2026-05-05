/*2451454 电信 杨翰卓*/
#include <iostream>
#include <Windows.h>
#include <conio.h>
#include "hanoi.h"
#include <cmath>
#include <iomanip>
using namespace std;


/* ----------------------------------------------------------------------------------

	 本文件功能：
	1、存放被 hanoi_main.cpp 中根据菜单返回值调用的各菜单项对应的执行函数

	 本文件要求：
	1、不允许定义外部全局变量（const及#define不在限制范围内）
	2、允许定义静态全局变量（具体需要的数量不要超过文档显示，全局变量的使用准则是：少用、慎用、能不用尽量不用）
	3、静态局部变量的数量不限制，但使用准则也是：少用、慎用、能不用尽量不用
	4、按需加入系统头文件、自定义头文件、命名空间等

   ----------------------------------------------------------------------------------- */


/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/

int m = 0;
int a[10] = { 0 };
int b[10] = { 0 };
int c[10] = { 0 };
int topA = 0;
int topB = 0;
int topC = 0;

void reset() 
{
	cct_cls();
	m = 0;
	for (int i = 0; i < 10; i++) {
		a[i] = 0;
		b[i] = 0;
		c[i] = 0;
	}
	topA = 0;
	topB = 0;
	topC = 0;
}
void hanoi(int n, char src, char tmp, char dst, int type,int speed)
{

	if (n == 1) {
		/*输出*/
		output(n, src, tmp, dst, type, speed);
		return;
	}
	hanoi(n-1, src, dst, tmp,type, speed);
   /*输出*/
	output(n, src, tmp, dst, type, speed);
	hanoi(n - 1, tmp, src, dst, type, speed);
}
char capital(char c) {
	if (c >= 'a' && c <= 'z')
		return c - ('a' - 'A');  // 或 ch - 32
	return c;
}
void column(int num,  char src, char dst,int type)
{
	int x=0, y=0;
	int dx = Underpan_Distance;
	if(type==4)
	{
		x = MenuItem4_Start_X;
		y = MenuItem4_Start_Y;
	}
	if (type == 8) {
		x = MenuItem8_Start_X;
		y = MenuItem8_Start_Y;
	}
	if (type == 9) {
		x = MenuItem9_Start_X;
		y = MenuItem9_Start_Y;
	}
	if (src == 'A')
	{
		int Ya = y + Underpan_A_Y_OFFSET - 11;
		/*cct_gotoxy(MenuItem4_Start_X + Underpan_A_X_OFFSET, MenuItem4_Start_Y + Underpan_A_Y_OFFSET);*/
		for (int i = 9; i >= 0; i--)
		{
			cct_gotoxy(x + Underpan_A_X_OFFSET-1, Ya);
			if (i >= topA) {
				cout << setw(2) << ' ' << endl;
				Ya++;
				continue;
			}
			cout << setw(2) << a[i] << endl;
			Ya++;
		}

		if (dst == 'B') {
			int Ya = y + Underpan_A_Y_OFFSET - 11;

			for (int i = 9; i >= 0; i--)
			{
				cct_gotoxy(x + Underpan_A_X_OFFSET+ dx - 1, Ya);
				if (i >= topB) {
					cout << setw(2) << ' ' << endl;
					Ya++;
					continue;
				}
				cout << setw(2) << b[i] << endl;

				Ya++;
			}
		}
		else {
			int Ya = y + Underpan_A_Y_OFFSET - 11;
			for (int i = 9; i >= 0; i--)
			{
				cct_gotoxy(x + Underpan_A_X_OFFSET+ 2*dx - 1, Ya);
				if (i >= topC) {
					cout << setw(2) << ' ' << endl;
					Ya++;
					continue;
				}
				cout << setw(2) << c[i] << endl;

				Ya++;
			}
		}
	}
	if (src == 'B')
	{
		int Ya = y + Underpan_A_Y_OFFSET - 11;

		for (int i = 9; i >= 0; i--)
		{
			cct_gotoxy(x + Underpan_A_X_OFFSET+ dx - 1, Ya);
			if (i >= topB) {
				cout << setw(2) << ' ' << endl;
				Ya++;
				continue;
			}
			cout << setw(2) << b[i] << endl;

			Ya++;
		}

		if (dst == 'A') {
			int Ya = y + Underpan_A_Y_OFFSET - 11;

			for (int i = 9; i >= 0; i--)
			{
				cct_gotoxy(x + Underpan_A_X_OFFSET - 1, Ya);
				if (i >= topA) {
					cout << setw(2) << ' ' << endl;
					Ya++;
					continue;
				}
				cout << setw(2) << a[i] << endl;

				Ya++;
			}
		}
		else {
			int Ya = y + Underpan_A_Y_OFFSET - 11;
			for (int i = 9; i >= 0; i--)
			{
				cct_gotoxy(x + Underpan_A_X_OFFSET+ 2*dx - 1, Ya);
				if (i >= topC) {
					cout << setw(2) << ' ' << endl;
					Ya++;
					continue;
				}
				cout << setw(2) << c[i] << endl;

				Ya++;
			}
		}
	}
	if (src == 'C')
	{
		int Ya = y + Underpan_A_Y_OFFSET - 11;

		for (int i = 9; i >= 0; i--)
		{
			cct_gotoxy(x + Underpan_A_X_OFFSET + 2* dx - 1, Ya);
			if (i >= topC) {
				cout << setw(2) << ' ' << endl;
				Ya++;
				continue;
			}
			cout << setw(2) << c[i] << endl;

			Ya++;
		}
		if (dst == 'A') {
			int Ya = y + Underpan_A_Y_OFFSET - 11;

			for (int i = 9; i >= 0; i--)
			{
				cct_gotoxy(x + Underpan_A_X_OFFSET - 1, Ya);
				if (i >= topA) {
					cout << setw(2) << ' ' << endl;
					Ya++;
					continue;
				}
				cout << setw(2) << a[i] << endl;

				Ya++;
			}
		}
		else {
			int Ya = y + Underpan_A_Y_OFFSET - 11;
			for (int i = 9; i >= 0; i--)
			{
				cct_gotoxy(x + Underpan_A_X_OFFSET + dx - 1, Ya);
				if (i >= topB) {
					cout << setw(2) << ' ' << endl;
					Ya++;
					continue;
				}
				cout << setw(2) << b[i] << endl;

				Ya++;
			}
		}
	}
}
void input(char data[],int type)
{
	while (1)
	{
		int n;
		cout << "请输入汉诺塔的层数(1-10)" << endl;
		cin >> n;
		if (cin.fail()) {
			cin.clear();
			cin.ignore(1024, '\n');
			continue;
		}
		if (n < 1 || n > 10) {
			cin.clear();
			cin.ignore(1024, '\n');
			continue;
		}
		data[0] = n+'0';
		break;
	}
	//起始柱
	while (1)
	{
		cout << "请输入起始柱(A-C)" << endl;
		cin >> data[1];
		if (data[1] != 65 && data[1] != 66 && data[1] != 67 && data[1] != 97 && data[1] != 98 && data[1] != 99) {
			cin.clear();
			cin.ignore(1024, '\n');
			continue;
		}
		break;
	}//层数
	//目标柱
	while (1)
	{
		cout << "请输入目标柱(A-C)" << endl;
		cin >> data[3];
		data[1] = capital(data[1]);
		data[3] = capital(data[3]);
		if ((data[1] == 'A') && (data[3] == 'B')) {
			data[2] = 'C';
		}
		if ((data[1] == 'A') && (data[3] == 'C')) {
			data[2] = 'B';
		}
		if ((data[1] == 'B') && (data[3] == 'C')) {
			data[2] = 'A';
		}
		if ((data[1] == 'B') && (data[3] == 'A')) {
			data[2] = 'C';
		}
		if ((data[1] == 'C') && (data[3] == 'A')) {
			data[2] = 'B';
		}
		if ((data[1] == 'C') && (data[3] == 'B')) {
			data[2] = 'A';
		}
		if (data[3] == data[1]) {
			cout << "目标柱(" << data[1] << ")不能与起始柱(" << data[1] << ")相同" << endl;
			cin.clear();
			cin.ignore(1024, '\n');
			continue;
		}
		else if (data[3] != 65 && data[3] != 66 && data[3] != 67 && data[3] != 97 && data[3] != 98 && data[3] != 99) {
			cin.clear();
			cin.ignore(1024, '\n');
			continue;
		}
		break;
	}
	//移动速度
	for (int i = data[0]-'0'; i > 0; i--) {
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
	if(type==4)
	{
		while (1)
		{
			int n;
			cout << "请输入移动速度(0-200：0-按回车单步演示 1-200:延时1-200ms) ";
			cin >> n;
			if (cin.fail()) {
				cin.clear();
				cin.ignore(1024, '\n');
				continue;
			}
			if (n > 200 || n < 0) {
				cin.clear();
				cin.ignore(1024, '\n');
				continue;
			}
			data[4] = n + '0';
			break;
		}
	}
	if (type == 7||type==8||type==9)
	{
		while (1)
		{
			int n;
			cout << "请输入移动速度(0-20：0-按回车单步演示 1-20:延时1-20ms) ";
			cin >> n;
			if (cin.fail()) {
				cin.clear();
				cin.ignore(1024, '\n');
				continue;
			}
			if (n > 20 || n < 0) {
				cin.clear();
				cin.ignore(1024, '\n');
				continue;
			}
			data[4] = n + '0';
			break;
		}
	}

}
void output(int n, char src, char tmp, char dst, int type,int speed)
{
	/*data0 层数 data1 src data2 tmp data3 dst data4 speed*/
	m++;
	if (type == 1) {
		cout << setw(2) << n << "# " << src << "---->" << dst << endl;
	}
	else if (type == 2) {
		cout << "第" << setw(4) << m << " 步(" << setw(2) << n << "#:" << src << "-->" << dst << endl;
	}
	else if (type == 3) {
		if (src == 'A') topA--;
		if (src == 'B') topB--;
		if (src == 'C') topC--;
		if (dst == 'A') a[topA++] = n;
		if (dst == 'B') b[topB++] = n;
		if (dst == 'C') c[topC++] = n;
		cout << "第" << setw(4) << m << " 步" << "(" <<setw(2)<< n << "#: " << src << "-->" << dst << ") ";
		cout << " A: ";
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
	}
	else if (type == 4) {
	
		cct_gotoxy(MenuItem4_Start_X, MenuItem4_Start_Y);
		/*初始*/
		if (src == 'A') topA--;
		if (src == 'B') topB--;
		if (src == 'C') topC--;
		if (dst == 'A') a[topA++] = n;
		if (dst == 'B') b[topB++] = n;
		if (dst == 'C') c[topC++] = n;
		column(n, src, dst,type);
		cct_gotoxy(MenuItem4_Start_X + Underpan_A_X_OFFSET - 2, MenuItem4_Start_Y + Underpan_A_Y_OFFSET - 1);
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
		cct_gotoxy(MenuItem4_Start_X, MenuItem4_Start_Y);
		cout << "第" << setw(4) << m << " 步" << "(" << setw(2) << m << "#: " << src << "-->" << dst << ") ";
		cout << " A: ";
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
		if (speed == 0) {
			while (_getch() != 13);
		}
		else
			Sleep(speed);
		
	}
	else if (type == 7) {
		if (src == 'A') topA--;
		if (src == 'B') topB--;
		if (src == 'C') topC--;
		if (dst == 'A') a[topA++] = n;
		if (dst == 'B') b[topB++] = n;
		if (dst == 'C') c[topC++] = n;
		movetrue(src, dst, speed, n);
	}
	else if (type == 8) {
		
		int x = MenuItem8_Start_X;
		int y = MenuItem8_Start_Y;
		
		cct_gotoxy(x, y);
		if (src == 'A') topA--;
		if (src == 'B') topB--;
		if (src == 'C') topC--;
		if (dst == 'A') a[topA++] = n;
		if (dst == 'B') b[topB++] = n;
		if (dst == 'C') c[topC++] = n;
		column(n, src, dst,type);
		cct_gotoxy(x + Underpan_A_X_OFFSET - 2, y + Underpan_A_Y_OFFSET - 1);
		for (int i = 0; i < 2*Underpan_Distance + 5; i++)
		{
			cout << "=";
		}
		cout << endl;
		cct_gotoxy(x + Underpan_A_X_OFFSET, y + Underpan_A_Y_OFFSET);
		cout << "A";
		cct_gotoxy(x + Underpan_A_X_OFFSET + Underpan_Distance, y + Underpan_A_Y_OFFSET);
		cout << "B";
		cct_gotoxy(x + Underpan_A_X_OFFSET + 2 * Underpan_Distance, y + Underpan_A_Y_OFFSET);
		cout << "C";
		cct_gotoxy(x, y);
		cout << "第" << setw(4) << m << " 步" << "(" << setw(2) << m << "#: " << src << "-->" << dst << ") ";
		cout << " A: ";
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
		movetrue(src, dst, speed, n);
		
		if (speed == 0) {
			while (_getch() != 13);
		}
		else
			Sleep(speed);
	}
	else if (type == 9) {

		int x = MenuItem9_Start_X;
		int y = MenuItem9_Start_Y;

		cct_gotoxy(x, y);
		if (src == 'A') n = a[--topA];
		if (src == 'B') n = b[--topB];
		if (src == 'C') n = c[--topC];

		if (dst == 'A') a[topA++] = n;
		if (dst == 'B') b[topB++] = n;
		if (dst == 'C') c[topC++] = n;
		column(n, src, dst, type);
		cct_gotoxy(x + Underpan_A_X_OFFSET - 2, y + Underpan_A_Y_OFFSET - 1);
		for(int i=0;i< 2*Underpan_Distance+5;i++)
		{
			cout << "=";
		}
		cout << endl;
		cct_gotoxy(x + Underpan_A_X_OFFSET, y + Underpan_A_Y_OFFSET);
		cout << "A";
		cct_gotoxy(x + Underpan_A_X_OFFSET+ Underpan_Distance, y + Underpan_A_Y_OFFSET);
		cout << "B";
		cct_gotoxy(x + Underpan_A_X_OFFSET + 2*Underpan_Distance, y + Underpan_A_Y_OFFSET);
		cout << "C";
		cct_gotoxy(x, y);
		cout << "第" << setw(4) << m << " 步" << "(" << setw(2) << m << "#: " << src << "-->" << dst << ") ";
		cout << " A: ";
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
		movetrue(src, dst, speed, n);

		if (speed == 0) {
			while (_getch() != 13);
		}
		else
			Sleep(speed);
			}
}
void pillar() 
{	
	hdc_init(HDC_COLOR[0], 0, 1400, 900);
	hdc_rectangle(HDC_Start_X, HDC_Start_Y, 23*HDC_Base_Width, HDC_Base_High, HDC_COLOR[11]);
	Sleep(HDC_Init_Delay);
	hdc_rectangle(HDC_Start_X+ 23 * HDC_Base_Width+ HDC_Underpan_Distance, HDC_Start_Y, 23 * HDC_Base_Width, HDC_Base_High, HDC_COLOR[11]);
	Sleep(HDC_Init_Delay);
	hdc_rectangle(HDC_Start_X+ 46 * HDC_Base_Width+ 2* HDC_Underpan_Distance, HDC_Start_Y, 23 * HDC_Base_Width, HDC_Base_High, HDC_COLOR[11]);
	Sleep(HDC_Init_Delay);
	/*柱子*/
	hdc_rectangle((HDC_Start_X + 22 * HDC_Base_Width + HDC_Start_X) / 2 , HDC_Start_Y-12*HDC_Base_High,HDC_Base_Width, 12*HDC_Base_High, HDC_COLOR[11]);
	Sleep(HDC_Init_Delay);
	hdc_rectangle((2* HDC_Start_X+2* HDC_Underpan_Distance+68*HDC_Base_Width)/2, HDC_Start_Y - 12 * HDC_Base_High, HDC_Base_Width, 12 * HDC_Base_High, HDC_COLOR[11]);
	Sleep(HDC_Init_Delay);
	hdc_rectangle((2* HDC_Start_X+4* HDC_Underpan_Distance+114* HDC_Base_Width) / 2 , HDC_Start_Y - 12 * HDC_Base_High, HDC_Base_Width, 12 * HDC_Base_High, HDC_COLOR[11]);
	Sleep(HDC_Init_Delay);
}
void plate() 
{
	int h = HDC_Base_High;
	int w = HDC_Base_Width;
	int countA = 0, countB = 0, countC = 0;
	
	for (int i = 0; i < 10; i++) {
		if (a[i] > 0) {
			hdc_rectangle(HDC_Start_X + (10 - a[i]+1) * HDC_Base_Width, HDC_Start_Y - (countA + 1) * h, (2 * a[i]+1) * HDC_Base_Width, HDC_Base_High, HDC_COLOR[a[i]]);
			countA++;
			Sleep(HDC_Init_Delay);
		}
		if (b[i] > 0) {
			hdc_rectangle(HDC_Start_X+23*w+ HDC_Underpan_Distance + (10 - b[i] + 1) * HDC_Base_Width, HDC_Start_Y - (countB + 1) * h, (2 * b[i] + 1) * HDC_Base_Width, HDC_Base_High, HDC_COLOR[b[i]]);
			countB++;
			Sleep(HDC_Init_Delay);
		}
		if (c[i] > 0) {
			hdc_rectangle(HDC_Start_X + 23 * w + HDC_Underpan_Distance + 23 * w + HDC_Underpan_Distance + (10 - c[i] + 1) * HDC_Base_Width, HDC_Start_Y - (countC + 1) * h, (2 * c[i] + 1) * HDC_Base_Width, HDC_Base_High, HDC_COLOR[c[i]]);
			countC++;
			Sleep(HDC_Init_Delay);
		}
	}
}
int get_base_x(int pillar) {
	if (pillar == 0) return HDC_Start_X;
	if (pillar == 1) return HDC_Start_X + 23 * HDC_Base_Width + HDC_Underpan_Distance;
	if (pillar == 2) return HDC_Start_X + 2 * (23 * HDC_Base_Width + HDC_Underpan_Distance);
	return 0;
}
void movetrue(char src, char dst, int speed,int num)
{
	
	int pillar[3][10]; // 只初始化一次
	int top[3];

		if (src == 'A') topA++;
		if (src == 'B') topB++;
		if (src == 'C') topC++;
		if (dst == 'A') a[topA--] = 0;
		if (dst == 'B') b[topB--] = 0;
		if (dst == 'C') c[topC--] = 0;

		top[0] = topA;
		top[1] = topB;
		top[2] = topC;

		for (int i = 0; i < topA; i++) {
			pillar[0][i] = a[i];
		}
		for (int i = 0; i < topB; i++) {
			pillar[1][i] = b[i];
		}
		for (int i = 0; i < topC; i++) {
			pillar[2][i] = c[i];
		}


	//if(m==1)
	//{
	//	top[0] = topA;
	//	top[1] = topB;
	//	top[2] = topC;
	//	/*for (int i = num; i > 0; i--) {
	//		if (src == 65 || src == 97) {
	//			pillar[0][top[0]++] = i;
	//		}
	//		if (src == 66 || dst == 98) {
	//			pillar[1][top[1]++] = i;
	//		}
	//		if (src == 67 || dst == 98) {
	//			pillar[2][top[2]++] = i;
	//		}
	//	}*/
	//	for (int i = 0; i < topA; i++) {
	//		pillar[0][i] = a[i];
	//	}
	//	for (int i = 0; i < topB; i++) {
	//		pillar[1][i] = b[i];
	//	}
	//	for (int i = 0; i < topC; i++) {
	//		pillar[2][i] = c[i];
	//	}
	//}
	int start = src - 'A';/*0-A 1-B 2-C*/
	int end = dst - 'A';
	int h = HDC_Base_High;
	int w = HDC_Base_Width;
	int count[3] = { 0 };
	int basex = get_base_x(start);
	int endx = get_base_x(end);

	for (int i = 0; i < 10; i++) {
		if (pillar[0][i] > 0) {
			count[0]++;
		}
		if (pillar[1][i] > 0) {
			count[1]++;
		}
		if (pillar[2][i] > 0) {
			count[2]++;
		}
	}

	int n = 1;
	int m1 = 0;
	int down = 0;
	int deltax = 23 * HDC_Base_Width + HDC_Start_X;
	while (HDC_Start_Y - (count[start])*h - n * HDC_Step_Y >= HDC_Top_Y)/*升起*/
	{
		if ((top[start] - 1) < 0)
			return;
		hdc_rectangle(basex + (11 - pillar[start][top[start] - 1]) * HDC_Base_Width/**/, HDC_Start_Y - count[start] *h - n * HDC_Step_Y/**/, (2 * pillar[start][top[start] - 1] + 1) * HDC_Base_Width/**/, HDC_Step_Y, HDC_COLOR[pillar[start][top[start] - 1]]);/*上移一个像素*/
		hdc_rectangle(basex + (11 - pillar[start][top[start] - 1]) * HDC_Base_Width/**/, HDC_Start_Y + HDC_Base_High - count[start] *h - n * HDC_Step_Y, (2 * pillar[start][top[start] - 1] + 1) * HDC_Base_Width, HDC_Step_Y, HDC_COLOR[0]);/*补背景色*/
		if (HDC_Start_Y + HDC_Base_High - count[start] *h - n * HDC_Step_Y > HDC_Start_Y - 12 * HDC_Base_High)
			hdc_rectangle(basex + 11 * HDC_Base_Width /*柱x坐标*/, HDC_Start_Y + HDC_Base_High - count[start] *h - n * HDC_Step_Y/*柱y坐标*/, HDC_Base_Width, HDC_Step_Y, HDC_COLOR[11]);/*补柱子色*/
		if (speed == 0) {
			while (_getch() != 13);
		}
		else
			Sleep(speed);
		n++;
	}

	int direction = (dst > src) ? 1 : 0;         // 向右 or 向左
	int step = abs(dst - src);
	if (direction) {
		if(step==1)
		{
			while (m1 < deltax) {
				hdc_rectangle(basex + (11 - pillar[start][top[start] - 1]) * HDC_Base_Width + (2 * pillar[start][top[start] - 1] + 1) * HDC_Base_Width + m1/*X0*/, HDC_Top_Y, HDC_Step_X, HDC_Base_High, HDC_COLOR[pillar[start][top[start] - 1]]);/*右移*/
				hdc_rectangle(basex + (11 - pillar[start][top[start] - 1]) * HDC_Base_Width + m1/*X0*/, HDC_Top_Y, HDC_Step_X, HDC_Base_High, HDC_COLOR[0]);
				if (speed == 0) {
					while (_getch() != 13);
				}
				else
					Sleep(speed);
				m1++;
			}
		}
		else 
			while (m1 < 2*deltax) {
				hdc_rectangle(basex + (11 - pillar[start][top[start] - 1]) * HDC_Base_Width + (2 * pillar[start][top[start] - 1] + 1) * HDC_Base_Width + m1/*X0*/, HDC_Top_Y, HDC_Step_X, HDC_Base_High, HDC_COLOR[pillar[start][top[start] - 1]]);/*右移*/
				hdc_rectangle(basex + (11 - pillar[start][top[start] - 1]) * HDC_Base_Width + m1/*X0*/, HDC_Top_Y, HDC_Step_X, HDC_Base_High, HDC_COLOR[0]);
				if (speed == 0) {
					while (_getch() != 13);
				}
				else
					Sleep(speed);
				m1++;
			}
	}
	else {
		if (step == 1)
		{
			while (m1 < deltax) {
				hdc_rectangle(basex + (11 - pillar[start][top[start] - 1]) * HDC_Base_Width - m1 /*X0*/, HDC_Top_Y, HDC_Step_X, HDC_Base_High, HDC_COLOR[pillar[start][top[start] - 1]]);
				hdc_rectangle(basex + (11 - pillar[start][top[start] - 1]) * HDC_Base_Width + (2 * pillar[start][top[start] - 1] + 1) * HDC_Base_Width - m1 -1/*X0*/, HDC_Top_Y, HDC_Step_X, HDC_Base_High, HDC_COLOR[0]);/*右移*/
				if (speed == 0) {
					while (_getch() != 13);
				}
				else
					Sleep(speed);
				m1++;
			}
		}
		else
			while (m1 < 2*deltax) {
				hdc_rectangle(basex + (11 - pillar[start][top[start] - 1]) * HDC_Base_Width - m1 /*X0*/, HDC_Top_Y, HDC_Step_X, HDC_Base_High, HDC_COLOR[pillar[start][top[start] - 1]]);
				hdc_rectangle(basex + (11 - pillar[start][top[start] - 1]) * HDC_Base_Width + (2 * pillar[start][top[start] - 1] + 1) * HDC_Base_Width - m1 -1/*X0*/, HDC_Top_Y, HDC_Step_X, HDC_Base_High, HDC_COLOR[0]);/*右移*/
				if (speed == 0) {
					while (_getch() != 13);
				}
				else
					Sleep(speed);
				m1++;
			}
	}
	/*下降*/
	while (HDC_Top_Y + down < HDC_Start_Y - (count[end] + 1) * h) {
		hdc_rectangle(endx + (11 - pillar[start][top[start] - 1]) * HDC_Base_Width /*X0*/, HDC_Top_Y + down + HDC_Base_High, (2 * pillar[start][top[start] - 1]+1) * HDC_Base_Width, HDC_Step_Y, HDC_COLOR[pillar[start][top[start] - 1]]);
		hdc_rectangle(endx + (11 - pillar[start][top[start] - 1]) * HDC_Base_Width /*X0*/, HDC_Top_Y + down, (2 * pillar[start][top[start] - 1]+1) * HDC_Base_Width, HDC_Step_Y, HDC_COLOR[0]);
		if (HDC_Top_Y + down - 1 >= HDC_Start_Y - 12 * HDC_Base_High)
			hdc_rectangle(endx + 11 * HDC_Base_Width/*X0*/, HDC_Top_Y + down, HDC_Base_Width, HDC_Step_Y, HDC_COLOR[11]);
		if (speed == 0) {
			while (_getch() != 13);
		}
		else
			Sleep(speed);
		down++;

	}
	/*if (src == 'A') count[start]--;
	if (src == 'B') count[start]--;
	if (src == 'C') count[start]--;
	if (dst == 'A') pillar[end][top[end]++] = num;
	if (dst == 'B') pillar[end][top[end]++] = num;
	if (dst == 'C') pillar[end][top[end]++] = num;*/
	if (src == 'A') topA--;
	if (src == 'B') topB--;
	if (src == 'C') topC--;
	
	if (dst == 'A') {
		if (topA >= 0 && topA < 10) 
			a[topA++] = num;
	}
	if (dst == 'B') {
		if (topB >= 0 && topB < 10) 
			b[topB++] = num;
	}
	if (dst == 'C') {
		if (topC >= 0 && topC < 10) 
			c[topC++] = num;
	}
	
}
bool check(char src, char dst, int num) {
	int pillar[3][10]; // 只初始化一次
	int top[3];

	top[0] = topA;
	top[1] = topB;
	top[2] = topC;

	for (int i = 0; i < topA; i++) {
		pillar[0][i] = a[i];
	}
	for (int i = 0; i < topB; i++) {
		pillar[1][i] = b[i];
	}
	for (int i = 0; i < topC; i++) {
		pillar[2][i] = c[i];
	}

	int start = src - 'A';/*0-A 1-B 2-C*/
	int end = dst - 'A';
	int h = HDC_Base_High;
	int w = HDC_Base_Width;
	int count[3] = { 0 };
	int moving1=0;
	int Top1=0;
	if(top[start] - 1>=0&& pillar[end][top[end] - 1]>=0)
	{
		moving1 = pillar[start][top[start] - 1];
		Top1 = (top[end] == 0) ? INT_MAX : pillar[end][top[end] - 1];
	}

	if (moving1 > Top1) {
		cout << "大盘压小盘，非法移动！" << endl;
		Sleep(HDC_Init_Delay);
		return 0;
	}
	if (top[start] == 0) {
		cout << "源柱为空！" << endl;
		Sleep(HDC_Init_Delay);
		return 0;
	}
	return 1;
}
bool complete(char dst, int n)
{
	if (dst == 'A') {
		if (topA != n) 
			return false;
		for (int i = 0; i < n; i++) {
			if (a[i] != n - i) 
				return false;
		}
	}
	else if (dst == 'B') {
		if (topB != n) 
			return false;
		for (int i = 0; i < n; i++) {
			if (b[i] != n - i)
			    return false;
		}
	}
	else if (dst == 'C') {
		if (topC != n) 
			return false;
		for (int i = 0; i < n; i++) {
			if (c[i] != n - i) 
				return false;
		}
	}
	else {
		return false;
	}

	return true;
}