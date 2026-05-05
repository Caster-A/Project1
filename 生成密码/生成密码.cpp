/*2451454 电信 杨翰卓*/
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

static const char upper[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
static const char lower[] = "abcdefghijklmnopqrstuvwxyz";
static const char num1[] = "0123456789";
static const char other[] = "!@#$%^&*-_=+,.?";

//string getrandom(const char set[], int n)
//{
//	string res;
//	int len = strlen(set);
//	for (int i = 0; i < n; i++) {
//		res += set[rand() % len];
//	}
//	return res;
//}
//
//string getpassword(int length, int letter1, int letter2, int num, int other1) 
//{
//	string password;
//	password += getrandom(upper, letter1);
//	password += getrandom(lower, letter2);
//	password += getrandom(num1, num);
//	password += getrandom(other, other1);
//
//	int last = length - password.size();
//	for (int i = 0; i < last; i++) {
//		password += (char)(rand() % 94 + 33);
//	}
//	string sum;
//	sum += password[rand() % 12];
//	return password;
//}
int main()
{
	srand(time(0));
	int length, letter1, letter2, num, other1;
	cout << "请输入密码长度(12-16)， 大写字母个数(≥2)， 小写字母个数(≥2)， 数字个数(≥2)， 其它符号个数(≥2)" << endl;
	cin >> length >> letter1 >> letter2 >> num >> other1;
	if (cin.fail()) {
		cin.clear();
		cin.ignore(1024, '\n');
	}
	if (length < 12 || length>16)
	{
		cout << "密码长度[" << length << "]不正确" << endl;
		return 0;
	}
	else if (letter1 < 2 || letter1>length)
	{
		cout << "大写字母个数[" << letter1 << "]不正确" << endl;
		return 0;
	}
	else if (letter2 < 2 || letter2>length)
	{
		cout << "小写字母个数[" << letter2 << "]不正确" << endl;
		return 0;
	}
	else if (num < 2 || num>length)
	{
		cout << "数字个数[" << num << "]不正确" << endl;
		return 0;
	}
	else if (other1 < 2 || other1>length)
	{
		cout << "其它符号个数[" << other1 << "]不正确" << endl;
		return 0;
	}
	else if (length < letter1 + letter2 + other1 + num)
	{
		cout << "所有字符类型之和[" << letter1 << '+' << letter2 << '+' << num << '+' << other1 << "]大于总密码长度[" << length << ']' << endl;
		return 0;
	}

	cout << length << " " << letter1 << " " << letter2 << " " << num << " " << other1 << endl;

	int count = 0;
	int sum = 10;
	while(sum >= 1)
	{
		char password[17];
		int count1 = 0, count2 = 0, count3 = 0, count4 = 0;
		count = 0;
		while (count < length) {
			
			int kind = rand() % 4;
			char ch=0;
			if (kind == 0) {
				count1++;
				ch = (rand() % 26 + 'A');
			}
			if (kind == 1) {
				count2++;
				ch = (rand() % 26 + 'a');
			}
			if (kind == 2) {
				count3++;
				ch = (rand() % 10 + '0');
			}
			if (kind == 3) {
				count4++;
				ch = (other[rand() % 15]);
			}
			password[count++] = ch;
		}
		if (count1 < letter1 || count2 < letter2 || count3 < num || count4 < other1)
			continue;
		password[length] = '\0';
		cout << password << endl;
		sum--;
	}
	/*for(int i=0;i<10;i++)
	{
		string password = getpassword(length, letter1, letter2, num, other1);
		cout << password << endl;
		
	}*/

	return 0;
}