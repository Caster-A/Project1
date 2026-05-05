/*2451454 电信 杨翰卓*/
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <conio.h>
#include <windows.h>
#include "5-b7.h"
using namespace std;
int m = 0;
int a[10] = { 0 };
int b[10] = { 0 };
int c[10] = { 0 };
int num, speed, detail;
int topA = 0;
int topB = 0;
int topC = 0;
void column(int detail, int num, int speed, char src, char dst);
char capital(char c) {
	if (c == 'a') return 'A';
	if (c == 'b') return 'B';
	if (c == 'c') return 'C';
	return c;
}
void hanoi(int n, char src, char tmp, char dst,int speed)
{
	if (n == 1) {
		if (src == 'A') topA--;
		if (src == 'B') topB--;
		if (src == 'C') topC--;
		if (dst == 'A') a[topA++] = n;
		if (dst == 'B') b[topB++] = n;
		if (dst == 'C') c[topC++] = n;
		m++;
		cct_gotoxy(20, 26);
		cout << "第" << setw(4) << m << "步" << "(" << n << "#: " << src << "-->" << dst << ") ";
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
		switch (speed)
		{
		case 0:
			while (1) {
				if (getchar() == '\n')
					break;
			}
			break;
		case 1:
			Sleep(1000);
			break;
		case 2:
			Sleep(500);
			break;
		case 3:
			Sleep(200);
			break;
		case 4:
			Sleep(50);
			break;
		case 5:
			Sleep(0);
			break;
		}
		column(detail, num, speed, src, dst);
		return;
	}
	hanoi(n - 1, src, dst, tmp,speed);
	m++;
	if (src == 'A') topA--;
	if (src == 'B') topB--;
	if (src == 'C') topC--;
	if (dst == 'A') a[topA++] = n;
	if (dst == 'B') b[topB++] = n;
	if (dst == 'C') c[topC++] = n;
	cct_gotoxy(20, 26);
	cout << "第" << setw(4) << m << "步" << "(" << n << "#: " << src << "-->" << dst<<") ";
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
	switch (speed)
	{
	case 0:
		while (1) {
			if (getchar() == '\n')
				break;
		}
		break;
	case 1:
		Sleep(1000);
		break;
	case 2:
		Sleep(500);
		break;
	case 3:
		Sleep(200);
		break;
	case 4:
		Sleep(50);
		break;
	case 5:
		Sleep(0);
		break;
	}
	column(detail, num, speed, src, dst);
	hanoi(n - 1, tmp, src, dst,speed);
}
void hanoisimple(int n, char src, char tmp, char dst, int speed)
{
	if (n == 1) {
		if (src == 'A') topA--;
		if (src == 'B') topB--;
		if (src == 'C') topC--;
		if (dst == 'A') a[topA++] = n;
		if (dst == 'B') b[topB++] = n;
		if (dst == 'C') c[topC++] = n;
		m++;
		cct_gotoxy(20, 26);
		cout << "第" << setw(4) << m << "步" << "(" << n << "#: " << src << "-->" << dst << ") ";
		cout << endl;
		switch (speed)
		{
		case 0:
			while (1) {
				if (getchar() == '\n')
					break;
			}
			break;
		case 1:
			Sleep(1000);
			break;
		case 2:
			Sleep(500);
			break;
		case 3:
			Sleep(200);
			break;
		case 4:
			Sleep(50);
			break;
		case 5:
			Sleep(0);
			break;
		}
		column(detail, num, speed, src, dst);
		return;
	}
	hanoisimple(n - 1, src, dst, tmp, speed);
	m++;
	if (src == 'A') topA--;
	if (src == 'B') topB--;
	if (src == 'C') topC--;
	if (dst == 'A') a[topA++] = n;
	if (dst == 'B') b[topB++] = n;
	if (dst == 'C') c[topC++] = n;
	cct_gotoxy(20, 26);
	cout << "第" << setw(4) << m << "步" << "(" << n << "#: " << src << "-->" << dst << ") ";
	cout << endl;
	switch (speed)
	{
	case 0:
		while (1) {
			if (getchar() == '\n')
				break;
		}
		break;
	case 1:
		Sleep(1000);
		break;
	case 2:
		Sleep(500);
		break;
	case 3:
		Sleep(200);
		break;
	case 4:
		Sleep(50);
		break;
	case 5:
		Sleep(0);
		break;
	}
	column(detail, num, speed, src, dst);
	hanoisimple (n - 1, tmp, src, dst, speed);
}
void column(int detail,int num,int speed, char src, char dst)
{
	if (src == 'A')
	{
		int Ya = 11;

		for (int i = 9; i >= 0; i--)
		{
			cct_gotoxy(10, Ya);
			if (i >= topA) {
				cout << setw(2) << ' ' << endl;
				Ya++;
				continue;
			}
			cout << setw(2) << a[i] << endl;
			Ya++;
		}

		if (dst == 'B') {
			int Ya = 11;

			for (int i = 9; i >= 0; i--)
			{
				cct_gotoxy(20, Ya);
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
			int Ya = 11;
			for (int i = 9; i >= 0; i--)
			{
				cct_gotoxy(30, Ya);
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
		int Ya = 11;

		for (int i = 9; i >= 0; i--)
		{
			cct_gotoxy(20, Ya);
			if (i >= topB) {
				cout << setw(2) << ' ' << endl;
				Ya++;
				continue;
			}
			cout << setw(2) << b[i] << endl;

			Ya++;
		}

		if (dst == 'A') {
			int Ya = 11;

			for (int i = 9; i >= 0; i--)
			{
				cct_gotoxy(10, Ya);
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
			int Ya = 11;
			for (int i = 9; i >= 0; i--)
			{
				cct_gotoxy(30, Ya);
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
		int Ya = 11;

		for (int i = 9; i >= 0; i--)
		{
			cct_gotoxy(30, Ya);
			if (i >= topC) {
				cout << setw(2) << ' ' << endl;
				Ya++;
				continue;
			}
			cout << setw(2) << c[i] << endl;

			Ya++;
		}
		if (dst == 'A') {
			int Ya = 11;

			for (int i = 9; i >= 0; i--)
			{
				cct_gotoxy(10, Ya);
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
			int Ya = 11;
			for (int i = 9; i >= 0; i--)
			{
				cct_gotoxy(20, Ya);
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
int main()
{
	
	char src, dst;
	char tmp = 0;
	//层数
	while (1)
	{
		cout << "请输入汉诺塔的层数(1-10)" << endl;
		cin >> num;
		if (cin.fail()) {
			cin.clear();
			cin.ignore(1024, '\n');
			continue;
		}
		if (num < 1 || num > 16) {
			cin.clear();
			cin.ignore(1024, '\n');
			continue;
		}
		break;
	}
	//起始柱
	while (1)
	{
		cout << "请输入起始柱(A-C)" << endl;
		cin >> src;
		if (src != 65 && src != 66 && src != 67 && src != 97 && src != 98 && src != 99) {
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
		cin >> dst;
		src = capital(src);
		dst = capital(dst);
		if ((src == 'A') && (dst == 'B')) {
			tmp = 'C';
		}
		if ((src == 'A') && (dst == 'C')) {
			tmp = 'B';
		}
		if ((src == 'B') && (dst == 'C')) {
			tmp = 'A';
		}
		if ((src == 'B') && (dst == 'A')) {
			tmp = 'C';
		}
		if ((src == 'C') && (dst == 'A')) {
			tmp = 'B';
		}
		if ((src == 'C') && (dst == 'B')) {
			tmp = 'A';
		}
		if (dst == src) {
			cout << "目标柱(" << src << ")不能与起始柱(" << src << ")相同" << endl;
			cin.clear();
			cin.ignore(1024, '\n');
			continue;
		}
		else if (dst != 65 && dst != 66 && dst != 67 && dst != 97 && dst != 98 && dst != 99) {
			cin.clear();
			cin.ignore(1024, '\n');
			continue;
		}
		break;
	}
	//移动速度
	while (1) 
	{
		cout << "请输入移动速度(0-5: 0-按回车单步演示 1-延时最长 5-延时最短)" << endl;
		cin >> speed;
		if (cin.fail()) {
			cin.clear();
			cin.ignore(1024, '\n');
			continue;
		}
		if (speed > 5 || speed < 0) {
			cin.clear();
			cin.ignore(1024, '\n');
			continue;
		}
		break;
	}
	while (1) 
	{
		cout << "请输入是否显示内部数组值(0-不显示 1-显示)" << endl;
		cin >> detail;
		if (cin.fail()) {
			cin.clear();
			cin.ignore(1024, '\n');
			continue;
		}
		if (detail !=0 && detail !=1) {
			cin.clear();
			cin.ignore(1024, '\n');
			continue;
		}
		break;
	}
	for (int i = num; i > 0; i--) {
		if (src == 65 || src == 97) {
			a[topA++] = i;
		}
		if (src == 66 || src == 98) {
			b[topB++] = i;
		}
		if (src == 67 || src == 98) {
			c[topC++] = i;
		}
	}
	cct_cls(); 
	if (detail == 0)
	{
		cout << "从" << src << "移动到" << dst << "，共" << ' ' << num << " 层，延时设置为 " << speed << "，不显示内部数组值" << endl;
		switch (speed)
		{
		case 0:
			while (1) {
				if (getchar() == '\n')
					break;
			}
			break;
		case 1:
			Sleep(1000);
			break;
		case 2:
			Sleep(500);
			break;
		case 3:
			Sleep(200);
			break;
		case 4:
			Sleep(50);
			break;
		case 5:
			Sleep(0);
			break;
		}
		column(detail, num, speed, src, dst);
		cout << "\t =========================" << endl;
		cout << "           A         B         C" << endl;
		switch (speed)
		{
		case 0:
			system("pause");
			break;
		case 1:
			Sleep(1000);
			break;
		case 2:
			Sleep(500);
			break;
		case 3:
			Sleep(200);
			break;
		case 4:
			Sleep(50);
			break;
		case 5:
			Sleep(0);
			break;
		}
		hanoisimple(num, src, tmp, dst, speed);
	}
	else
	{
		cout << "从" << src << "移动到" << dst << "，共" << ' ' << num << " 层，延时设置为 " << speed << "，显示内部数组值" << endl;
		cct_gotoxy(20, 26);
		cout << "初始:\t\t     ";
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
		switch (speed)
		{
		case 0:
			while (1) {
				if (getchar() == '\n')
					break;
			}
			break;
		case 1:
			Sleep(1000);
			break;
		case 2:
			Sleep(500);
			break;
		case 3:
			Sleep(200);
			break;
		case 4:
			Sleep(50);
			break;
		case 5:
			Sleep(0);
			break;
		}
		column(detail, num, speed, src, dst);
		cout << "\t =========================" << endl;
		cout << "           A         B         C" << endl;
		switch (speed)
		{
		case 0:
			while (1) {
				if (getchar() == '\n')
					break;
			}
			break;
		case 1:
			Sleep(1000);
			break;
		case 2:
			Sleep(500);
			break;
		case 3:
			Sleep(200);
			break;
		case 4:
			Sleep(50);
			break;
		case 5:
			Sleep(0);
			break;
		}
		hanoi(num, src, tmp, dst, speed);
	}
	
	system("pause");//最后用这句表示暂停（注意：只适合于特定程序，无特别声明的程序加此句则得分为0）
	return 0;
}