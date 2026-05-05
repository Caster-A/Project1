/*2451454 电信 杨翰卓*/
#include <iostream>
using namespace std;
bool result(int size[9][9])
{
	for (int i = 0; i < 9; i++) {
		bool row[10] = { false };
		bool column[10] = { false };
		for (int j = 0; j < 9; j++)
		{
			if (row[size[i][j]])
				return false;
			row[size[i][j]] = true;
			if (column[size[j][i]])
				return false;
			column[size[j][i]] = true;
		}
	}
	for (int blockrow = 0; blockrow < 9; blockrow += 3) {
		for (int blockcol = 0; blockcol < 9; blockcol += 3) {
			bool check[10] = { false };
			for (int i = 0; i < 3; i++) {
				for (int j = 0; j < 3; j++) {
					int num = size[blockrow + i][blockcol + j];
					if (check[num])
						return false;
					check[num] = true;
				}
			}
		}
	}
	return true;
}
int main()
{
	int arr[9][9];
	int a;
	cout << "请输入9*9的矩阵，值为1-9之间" << endl;
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			cin >> a;
			arr[i][j] = a;
			if (cin.fail()) {
				cin.clear();
				cin.ignore(1024, '\n');
				cout << "请重新输入第" << i + 1 << "行" << j + 1 << "列(行列均从1开始计数)的值" << endl;
				j -= 1;
			}
			else if (a > 9 || a < 1) {
				cout << "请重新输入第" << i + 1 << "行" << j + 1 << "列(行列均从1开始计数)的值" << endl;
				j -= 1;
			}
			
		}
	}
	bool check = result(arr);
	if (check)
		cout << "是数独的解" << endl;
	else
		cout<< "不是数独的解" << endl;
	return 0;
}