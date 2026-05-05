#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
char result[256];
const char chnstr[] = "零壹贰叁肆伍陆柒捌玖";
/* 可根据需要添加相应的内容 */

/***************************************************************************
  函数名称：
  功    能：输出大写的0~9
  输入参数：
  返 回 值：
  说    明：除本函数外，不允许任何函数中输出“零”-“玖”!!!!!!
***************************************************************************/
int daxie(int num, int flag_of_zero,int z)
{
	switch (num) {
	case 0:
		if (flag_of_zero) {
			result[z++] = chnstr[0];
			result[z++] = chnstr[1];
		}
		break;
	case 1:
		result[z++] = chnstr[2];
		result[z++] = chnstr[3];
		break;
	case 2:
		result[z++] = chnstr[4];
		result[z++] = chnstr[5];
		break;
	case 3:
		result[z++] = chnstr[6];
		result[z++] = chnstr[7];
		break;
	case 4:
		result[z++] = chnstr[8];
		result[z++] = chnstr[9];
		break;
	case 5:
		result[z++] = chnstr[10];
		result[z++] = chnstr[11];
		break;
	case 6:
		result[z++] = chnstr[12];
		result[z++] = chnstr[13];
		break;
	case 7:
		result[z++] = chnstr[14];
		result[z++] = chnstr[15];
		break;
	case 8:
		result[z++] = chnstr[16];
		result[z++] = chnstr[17];
		break;
	case 9:
		result[z++] = chnstr[18];
		result[z++] = chnstr[19];
		break;
	}
	return z;
}

int main()
{
	double x;
	int ret;
	while (1)
	{
		printf("请输入[0-100亿)之间的数字:\n");
		ret = scanf("%lf", &x);
		if (ret == 0) {
			int c;
			while ((c = getchar()) != '\n' && c != EOF);
			continue;
		}
		if (x < 0.00 || x>10000000000.00)
			continue;
		break;
	}
	double y = x + 0.0005;
	int b = (int)(x / 10);
	double m = y / 10 - b;
	char name[] = "拾亿仟佰万圆整角分";

	int c = b / 100000000;/*十亿*/
	int d = b / 10000000 - c * 10;
	int e = b / 1000000 - 10 * d - 100 * c;/*千万*/
	int f = b / 100000 - 1000 * c - 100 * d - 10 * e;
	int g = b / 10000 - 10000 * c - 1000 * d - 100 * e - 10 * f;
	int h = b / 1000 - 100000 * c - 10000 * d - 1000 * e - 100 * f - 10 * g;/*万*/
	int i = b / 100 - 1000000 * c - 100000 * d - 10000 * e - 1000 * f - 100 * g - 10 * h;
	int j = b / 10 - 10000000 * c - 1000000 * d - 100000 * e - 10000 * f - 1000 * g - 100 * h - 10 * i;
	int k = b / 1 - 100000000 * c - 10000000 * d - 1000000 * e - 100000 * f - 10000 * g - 1000 * h - 100 * i - 10 * j;

	int n = (int)(10 * m);/*个位*/
	int o = (int)(100 * m - 10 * n);
	int p = (int)(1000 * m - 100 * n - 10 * o);

	printf("大写结果是:\n");
	/* 按需完成 */
	int z = 0;
	z=daxie(c, c < 0,z);
	if (c > 0) {
		result[z++] = name[0];
		result[z++] = name[1];
	}
	z=daxie(d, d < 0,z);
	if (d > 0 || c > 0) {
		result[z++] = name[2];
		result[z++] = name[3];
	}
	z = daxie(e, (e + f + g + h + j + k + n != 0 && e + f + g + h != 0 && c + d != 0),z);
	if (e > 0) {
		result[z++] = name[4];
		result[z++] = name[5];
	}
	z = daxie(f, e != 0 && f + g + h != 0,z);
	if (f > 0) {
		result[z++] = name[6];
		result[z++] = name[7];
	}
	z = daxie(g, f != 0 && g + h != 0,z);
	if (g > 0) {
		result[z++] = name[0];
		result[z++] = name[1];
	}
	z = daxie(h, h < 0,z);
	if (e > 0 || f > 0 || g > 0 || h > 0) {
		result[z++] = name[8];
		result[z++] = name[9];
	}
	z = daxie(i, c + d + e + f + g + h != 0 && i + j + k + n != 0,z);
	if (i > 0) {
		result[z++] = name[4];
		result[z++] = name[5];
	}
	z = daxie(j, i != 0 && j + k + n != 0,z);
	if (j > 0) {
		result[z++] = name[6];
		result[z++] = name[7];
	}
	z = daxie(k, j != 0 && k + n != 0,z);
	if (k > 0) {
		result[z++] = name[0];
		result[z++] = name[1];
	}
	z = daxie(n, c + d + e + f + g + h + i + j + k + n + o + p == 0,z);
	if (c + d + e + f + g + h + i + j + k + n > 0)
	{
		result[z++] = name[10];
		result[z++] = name[11];
		if (o + p == 0)
		{
			result[z++] =name[12];
			result[z++] =name[13];
		}
	}
	else if (c + d + e + f + g + h + i + j + k + n + o + p == 0)
	{
		result[z++] = name[10];
		result[z++] = name[11];
		result[z++] = name[12];
		result[z++] = name[13];
	}

	z = daxie(o, c + d + e + f + g + h + i + j + k + n != 0 && p != 0,z);
	if (o == 0) {
	}
	else {
		if (o > 0 && p == 0) {
			result[z++] = name[14];
			result[z++] = name[15];
			result[z++] = name[12];
			result[z++] = name[13];
		}
		else if (n >= 0) {
			result[z++] =name[14];
			result[z++] =name[15];
		}
	}
	z = daxie(p, p < 0,z);
	if (p > 0) {
		result[z++] = name[16];
		result[z++] = name[17];
	}
	printf("%s\n", result);
	return 0;
}