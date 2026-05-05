/*2451454 电信 杨翰卓*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int year(int y)
{
	if ((y % 4 == 0) && (y % 100 != 0) || (y % 4 == 0) && (y % 400 == 0)) {
		return 1;
	}
	else
		return 0;
}
int mouth_day(int y, int m, int d)
{
	int n = year(y);
	int total = 0;
	if (n == 1) {
		int mouth[12] = { 31,29,31,30,31,30,31,31,30,31,30,31 };/*是闰年*/
		if (m > 12 || m < 1) {
			printf("输入错误-月份错误\n");
			return 0;
		}
		if (d > mouth[m - 1] || d < 1) {
			printf("输入错误-日与月的关系非法\n");
			return 0;
		}
		for (int i = 0; i < m - 1; i++) {
			total += mouth[i];
		}
		total += d;
	}
	else {
		int mouth[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };/*不是闰年*/
		if (m > 12 || m < 1) {
			printf("输入错误-月份错误\n");
			return 0;
		}
		if (d > mouth[m - 1] || d < 1) {
			printf("输入错误-日与月的关系非法\n");
			return 0;
		}
		for (int i = 0; i < m - 1; i++) {
			total += mouth[i];
		}
		total += d;
	}
	return total;
}
int main()
{
	printf("请输入年，月，日\n");
	int y, m, d;
	scanf("%d %d %d", &y, &m, &d);
	int total = mouth_day(y, m, d);
	if (total == 0) {

	}
	else {
		printf("%d-%d-%d是%d年的第%d天\n",y,m,d,y,total);
	}
	return 0;
}