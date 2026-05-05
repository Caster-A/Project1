/*2451454 电信 杨翰卓*/
#include <iostream>
#include <string>
using namespace std;
string result;
const char chnstr[] = "零壹贰叁肆伍陆柒捌玖";
/* 可根据需要添加相应的内容 */

/***************************************************************************
  函数名称：
  功    能：输出大写的0~9
  输入参数：
  返 回 值：
  说    明：除本函数外，不允许任何函数中输出“零”-“玖”!!!!!!
***************************************************************************/
void daxie(int num, int flag_of_zero)
{
	/* 不允许对本函数做任何修改 */
	switch (num) {
	case 0:
		if (flag_of_zero)	//此标记什么意思请自行思考
		{
			result += chnstr[0];
			result += chnstr[1];
		}
		break;
	case 1:
		result += chnstr[2];
		result += chnstr[3];
		break;
	case 2:
		result += chnstr[4];
		result += chnstr[5];
		break;
	case 3:
		result += chnstr[6];
		result += chnstr[7];
		break;
	case 4:
		result += chnstr[8];
		result += chnstr[9];
		break;
	case 5:
		result += chnstr[10];
		result += chnstr[11];
		break;
	case 6:
		result += chnstr[12];
		result += chnstr[13];
		break;
	case 7:
		result += chnstr[14];
		result += chnstr[15];
		break;
	case 8:
		result += chnstr[16];
		result += chnstr[17];
		break;
	case 9:
		result += chnstr[18];
		result += chnstr[19];
		break;
	default:
		result += "error";
		break;
	}
}

int main()
{
	double x;
	while(1)
	{
		cout << "请输入[0-100亿)之间的数字:" << endl;
		cin >> x;
		if (cin.fail()) {
			cin.clear();
			cin.ignore(1024, '\n');
			continue;
		}
		if (x < 0.00 || x>10000000000.00)
			continue;
		break;
	}
	double y = x + 0.0005;
	int b = (int)(x / 10);
	double m = y / 10 - b;
	

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

	cout << "大写结果是:" << endl;
	/* 按需完成 */
	daxie(c, c < 0);
	if (c > 0) {
		result += "拾";
	}
	daxie(d, d < 0);
	if (d > 0 || c > 0) {
		result += "亿";
	}
	daxie(e, (e + f + g + h + j + k + n != 0 && e + f + g + h != 0 && c + d != 0));
	if (e > 0) {
		result += "仟";
	}
	daxie(f, e != 0 && f + g + h != 0);
	if (f > 0) {
		result += "佰";
	}
	daxie(g, f != 0 && g + h != 0);
	if (g > 0) {
		result += "拾";
	}
	daxie(h, h < 0);
	if (e > 0 || f > 0 || g > 0 || h > 0) {
		result += "万";
	}
	daxie(i, c + d + e + f + g + h != 0 && i + j + k + n != 0);
	if (i > 0) {
		result += "仟";
	}
	daxie(j, i != 0 && j + k + n != 0);
	if (j > 0) {
		result += "佰";
	}
	daxie(k, j != 0 && k + n != 0);
	if (k > 0) {
		result += "拾";
	}
	daxie(n, c + d + e + f + g + h + i + j + k + n + o + p == 0);
	if (c + d + e + f + g + h + i + j + k + n > 0)
	{
		result += "圆";
		if (o + p == 0)
			result += "整";
	}
	else if(c + d + e + f + g + h + i + j + k + n + o + p == 0)
		result += "圆整";

	daxie(o, c + d + e + f + g + h + i + j + k + n != 0 && p != 0);
	if (o == 0) {
	}
	else {
		if (o > 0 && p == 0) {
			result += "角整";
		}
		else if (n >= 0) {
			result += "角";
		}
	}
	daxie(p, p < 0);
	if (p > 0) {
		result += "分";
	}
	cout << result << endl;
	return 0;
}