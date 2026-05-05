/*2451454 电信 杨翰卓*/
#include <iostream>
using namespace std;
int min(int a = 2147483647, int b = 2147483647, int c = 2147483647, int d = 2147483647)
{
	a = (a < b ? a : b);
	a = (a < c ? a : c);
	a = (a < d ? a : d);
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
			int m = min(a, b);
			cout << "min=" << m << endl;
			break;
		}
		if (num == 3) {
			cin >> a >> b >> c;
			if (cin.fail()) {
				cin.clear();
				cin.ignore(1024, '\n');
				continue;
			}
			int m = min(a, b, c);
			cout << "min=" << m << endl;
			break;
		}
		if (num == 4) {
			cin >> a >> b >> c >> d;
			if (cin.fail()) {
				cin.clear();
				cin.ignore(1024, '\n');
				continue;
			}
			int m = min(a, b, c, d);
			cout << "min=" << m << endl;
			break;
		}
		if (num > 4 || num < 2) {
			cout << "个数输入错误" << endl;
			break;
		}
	}
	return 0;
}