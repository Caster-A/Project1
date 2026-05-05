/*2451454 电信 杨翰卓*/
#include <iostream>
using namespace std;
int main()
{
	int arr[1000];
	int frequency[1000] = { 0 };
	int count = 0;
	int num;
	cout << "请输入成绩（最多1000个），负数结束输入" << endl;
	while (count < 1000) {
		cin >> num;
		if (num < 0) {
			break;
		}
		arr[count] = num;
		count++;
	}
	cout << "输入的数组为:" << endl;
	for (int i = 0; i < count; i++) {
		cout << arr[i]<<' ';
		if ((i + 1) % 10 == 0) {
			cout << endl;
		}
		if (i == count - 1) {
			cout << endl;
		}
	}
	cout << "分数与名次的对应关系为:" << endl;;
	for (int i = 0; i < count; i++) {
		frequency[arr[i]]++;
	}
	int m = 1;
	for (int i = 100; i >= 0; i--) {
		if (frequency[i] > 0) {
			for (int n = 1; n <= frequency[i]; n++) {
				cout << i << ' ' << m << endl;
			}
			m += frequency[i];
		}
	}
	return 0;
}