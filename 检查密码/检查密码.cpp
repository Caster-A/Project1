/*2451454 电信 杨翰卓*/
#include <iostream>
using namespace std;

static const char other[] = "!@#$%^&*-_=+,.?";

bool checkother(char ch)
{
	for (int i = 0; i < 15; i++) {
		if (ch == other[i])
			return true;
	}
	return false;
}
int main()
{
	char title[128];
	char arr[12][128];
	cin.getline(title,128);/*首行*/
	int length, letter1, letter2, num, other1;
	cin >> length >> letter1 >> letter2 >> num >> other1;
	cin.ignore();

	char password[10][128];
	for (int i = 0; i < 10; i++) {
		cin.getline(password[i], 128);
	}
	int count1 = 0, count2 = 0, count3 = 0, count4 = 0;
	bool check = true;
	for (int i = 0; i < 10; i++) {
		if (strlen(password[i]) != length)
		{
			check = false;
			break;
		}
	}
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < length; j++) {
			if (password[i][j] >= 'A' && password[i][j] <= 'Z')
				count1++;
			else if (password[i][j] >= 'a' && password[i][j] <= 'z')
				count2++;
			else if (password[i][j] >= '0' && password[i][j] <= '9')
				count3++;
			else if (checkother(password[i][j]))
				count4++;
		}
		if (count1 < letter1 || count2 < letter2 || count3 < num || count4 < other1)
		{
			check = false;
			break;
		}
	}
	
	if (check)
		cout << "正确" << endl;
	else
		cout << "错误" << endl;
	return 0;
}