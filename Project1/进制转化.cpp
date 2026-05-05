#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void decimalToBinary(int n) {
    vector<int> binary;

    // 十进制转二进制
    while (n > 0) {
        binary.push_back(n % 2);
        n = n / 2;
    }

    // 输出二进制
    reverse(binary.begin(), binary.end());
    for (int i = 0; i < binary.size(); i++) {
        cout << binary[i];
    }
    cout << endl;
}

int main() {
    int number;
    cout << "Enter a decimal number: ";
    cin >> number;

    cout << "Binary representation: ";
    decimalToBinary(number);

    return 0;
}