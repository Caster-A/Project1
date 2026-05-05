/*2451454 电信 杨翰卓*/
#include <iostream>
using namespace std;

int cal(char *arr)
{
	int sum = 0;
	char* p;
	p = arr;
	for (; *p != '\0'; p++) {
		if (*p == '1') {
			sum = sum * 2 + 1;
		}
		else if (*p == '0')
			sum = sum * 2;
	}
	return sum;
}
int main()
{
	char arr[32];
	cout << "请输入一个0/1组成的字符串，长度不超过32" << endl;
	cin.getline(arr, 32);
	cout << cal(arr) << endl;
}