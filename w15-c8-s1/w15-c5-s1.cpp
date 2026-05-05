/*2451454 电信 杨翰卓*/
#include <iostream>
using namespace std;

#define     N       2000
#define     END_NUM     -1

void input(int* array, const int n)
{
    int* p = array;
    while (cin >> *p) {
        if (*p == END_NUM || p - array >= n)
            break;
        ++p;
    }
    *p = END_NUM; // 保证最后有 -1 结束
}

void output(int* array, const int n)
{
    int* p = array;
    int cnt = 0;
    while (*p != END_NUM) {
        cout << *p << " ";
        ++cnt;
        if (cnt % n == 0)
            cout << endl;
        ++p;
    }
    if (cnt % n != 0)
        cout << endl;
}

void adjust(int* array)
{
    int t, *p1, *p2;

    p1 = array;
    while (*p1 != END_NUM) {
        // 找奇数和偶数
        if (*p1 % 2 == 0) { // 如果是偶数，向后找一个奇数
            p2 = p1 + 1;
            while (*p2 != END_NUM && *p2 % 2 == 0)
                ++p2;

            if (*p2 == END_NUM)
                break;

            t = *p1;
            *p1 = *p2;
            *p2 = t;
        }
        ++p1;
    }
}

int main(int argc, char **argv)
{
    int a[N + 1];

    cout << "请输入数组各元素(正整数),以" << END_NUM << "结束(不含" << END_NUM << "最多" << N << "个数)" << endl;
    input(a, N);

    cout << "数组的内容为" << endl;
    output(a, 15);

    adjust(a);
    cout << "调整后数组的内容为" << endl;
    output(a, 10);

    return 0;
}
