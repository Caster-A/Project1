#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	double m;
	int w,n;
	printf("请输入double型数据及显示总宽度、小数点后位数\n");
	scanf("%lf %d %d", &m, &w, &n);
	printf("01234567890123456789\n");
	char fmt[20];
	sprintf(fmt, "%%%d.%dlf*\n", w, n);
	printf(fmt, m);
	return 0;
}








