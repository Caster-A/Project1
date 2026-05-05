/*2451454 电信 杨翰卓*/
#include <iostream>
using namespace std;

bool check(char* arr)
{
	char* p;
	p = arr;
	int length = 0;
	for (; *p != '\0'; p++) {
		if (*p == '\n') {
			*p = '\0';
			length -= 1;
		}
		length++;
	}
	char* p1;
	char* p2;
	p1 = arr;
	p2 = arr + length-1;
	while (p1 < p2) {
		if (*p1 != *p2)
			return false;
		p1++;
		p2--;
	}
	return true;
}
int main()
{
	char arr[80];
	cout << "请输入一个长度小于80的字符串（回文串）" << endl;
	fgets(arr, 80, stdin);
	if (check(arr))
		cout << "yes" << endl;
	else
		cout << "no" << endl;
	return 0;
}