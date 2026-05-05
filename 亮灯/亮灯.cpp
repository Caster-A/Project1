/*2451454 µçĞÅ Ñîº²×¿*/
#include <iostream>
using namespace std;
int main()
{
	int arr[100] = {0};
	for (int person = 1; person <= 100; person++) {
		for (int a = person; a <= 100; a += person) {
			arr[a - 1] = 1 - arr[a - 1];
		}
	}
	cout << arr[0];
	for (int i = 3; i < 100; i++) {
		if (arr[i] == 1) {
			cout <<' '<< i + 1;
		}
	}
	cout << endl;
	return 0;
}