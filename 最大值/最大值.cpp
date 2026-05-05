/*2451454 电信 杨翰卓*/
#include <iostream>
using namespace std;
int max(int a,int b)
{
	a = (a > b ? a : b);
	return a;
}
int max(int a, int b, int c)
{
	a = (a > b ? a : b);
	a = (a > c ? a : c);
	return a;
}
int max(int a, int b, int c, int d)
{
	a = (a > b ? a : b);
	a = (a > c ? a : c);
	a = (a > d ? a : d);
	return a;
}
int main()
{
	int num, a, b, c, d, e;
	while (1) {
		cout << "请输入个数num及num个正整数：" << endl;
		cin >> num;
		if (cin.fail()) {
			cin.clear();
			cin.ignore(1024, '\n');
			continue;
		}
		if (num == 2) {
			cin >> a >> b;
			if (cin.fail()) {
				cin.clear();
				cin.ignore(1024, '\n');
				continue;
			}
			int m = max(a, b);
			cout << "max=" << m << endl;
			break;
		}
		if (num == 3) {
			cin >> a >> b >> c;
			if (cin.fail()) {
				cin.clear();
				cin.ignore(1024, '\n');
				continue;
			}
			int m = max(a, b, c);
			cout << "max=" << m << endl;
			break;
		}
		if (num == 4) {
			cin >> a >> b >> c >> d;
			if (cin.fail()) {
				cin.clear();
				cin.ignore(1024, '\n');
				continue;
			}
			int m = max(a, b, c, d);
			cout << "max=" << m << endl;
			break;
		}
		if (num > 4 || num < 2) {
			cout << "个数输入错误" << endl;
			break;
		}
	}
	return 0;
}