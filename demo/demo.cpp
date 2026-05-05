#include <iostream>
using namespace std;

int main() {
    int arr[3] = { 10, 20, 30 };
    int* p = arr;

    int val1 = *(p + 3); 
    int val2 = *(p - 1);

    return 0;  
}
