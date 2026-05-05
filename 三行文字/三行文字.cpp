/*2451454 电信 杨翰卓*/
#include <iostream>
using namespace std;
int main()
{
	int countmax = 0, countmin = 0, num = 0, space = 0, other = 0;
	char str[3][128] = { '\0' };
	cout << "请输入第1行" << endl;
	cin.getline(str[0], 128);
	cout << "请输入第2行" << endl;
	cin.getline(str[1], 128);
	cout << "请输入第3行" << endl;
	cin.getline(str[2], 128);
	for (int i = 0; i < 3; i++) {
		for (int j = 0; str[i][j] != '\0'; j++) {
			if (str[i][j] >= 'A' && str[i][j] <= 'Z') {
				countmax++;
			}
			else if (str[i][j] >= 'a' && str[i][j] <= 'z') {
				countmin++;
			}
			else if (str[i][j] == 32) {
				space++;
			}
			else if (str[i][j] >= '0' && str[i][j] <= '9') {
				num++;
			}
			else
				other++;
		}
	}
	cout << "大写 : " << countmax << endl;
	cout << "小写 : " << countmin << endl;
	cout << "数字 : " << num << endl;
	cout << "空格 : " << space << endl;
	cout << "其他 : " << other << endl;
	return 0;
}