/*2451454 电信 杨翰卓*/
#include <iostream>
#include <iomanip>
using namespace std;
int top[3] = { 0 };
int arr[3][10] = { 0 };
int m = 0;
void hanoi(int n, char src, char tmp, char dst)
{
        if (n == 1) {
            if (src == 'A') {
                top[0]--;
                if (dst == 'B')
                    arr[1][top[1]++] = n;
                if (dst == 'C')
                    arr[2][top[2]++] = n;
            }
            if (src == 'C') {
                top[2]--;
                if (dst == 'B')
                    arr[1][top[1]++] = n;
                if (dst == 'A')
                    arr[0][top[0]++] = n;
            }
            if (src == 'B') {
                top[1]--;
                if (dst == 'A')
                    arr[0][top[0]++] = n;
                if (dst == 'C')
                    arr[2][top[2]++] = n;
            }
            m++;
            cout << "第" << setw(4) << m << " 步" << setw(2) << "（" << n << ")" << ": " << src << "-->" << dst;
            cout << " A: ";
            for (int i = 0; i < top[0]; i++) {
                if (top[0] > 0) {
                    cout << arr[0][i] << ' ';
                }
            }
            for (int i = top[0]; i < 10; i++) {
                cout << "  ";
            }
            cout<<"B: ";
            for (int i = 0; i < top[1]; i++) {
                if (top[1] > 0) {
                    cout << arr[1][i] << ' ';
                }
            }
            for (int i = top[1]; i < 10; i++) {
                cout << "  ";
            }
            cout<<"C: ";
            for (int i = 0; i < top[2]; i++) {
                if (top[2] > 0) {
                    cout << arr[2][i] << ' ';
                }
            }
            for (int i = top[2]; i < 10; i++) {
                cout << "  ";
            }
            cout << endl;
            return;
        }
        hanoi(n - 1, src, dst, tmp);
        m++;
        if (src == 'A') {
            top[0]--;
            if (dst == 'B')
                arr[1][top[1]++] = n;
            if (dst == 'C')
                arr[2][top[2]++] = n;
        }
        if (src == 'C') {
            top[2]--;
            if (dst == 'B')
                arr[1][top[1]++] = n;
            if (dst == 'A')
                arr[0][top[0]++] = n;
        }
        if (src == 'B') {
            top[1]--;
            if (dst == 'A')
                arr[0][top[0]++] = n;
            if (dst == 'C')
                arr[2][top[2]++] = n;
        }
        cout << "第"<<setw(4) << m << " 步" << setw(2)<<"（" << n<< ")" << ": " << src << "-->" << dst;
        cout << " A: ";
        for (int i = 0; i < top[0]; i++) {
            if (top[0] > 0) {
                cout << arr[0][i] << ' ';
            }
        }
        for (int i = top[0]; i < 10; i++) {
            cout << "  ";
        }
        cout << "B: ";
        for (int i = 0; i < top[1]; i++) {
            if (top[1] > 0) {
                cout << arr[1][i] << ' ';
            }
        }
        for (int i = top[1]; i < 10; i++) {
            cout << "  ";
        }
        cout << "C: ";
        for (int i = 0; i < top[2]; i++) {
            if (top[2] > 0) {
                cout << arr[2][i] << ' ';
            }
        }
        for (int i = top[2]; i < 10; i++) {
            cout << "  ";
        }
        cout << endl;

        hanoi(n - 1, tmp, src, dst);
    }

int main()
{ 
    int num;
    char src, dst;
    char tmp = 0;
    while (1)
    {
        cout << "请输入汉诺塔的层数(1-16)" << endl;
        cin >> num;
        if (cin.fail()) {
            cin.clear();
            cin.ignore(1024, '\n');
            continue;
        }
        if (num < 1 || num > 16) {
            cin.clear();
            cin.ignore(1024, '\n');
            continue;
        }
        break;
    }
    while (1)
    {
        cout << "请输入起始柱(A-C)" << endl;
        cin >> src;
        if (src != 65 && src != 66 && src != 67 && src != 97 && src != 98 && src != 99) {
            cin.clear();
            cin.ignore(1024, '\n');
            continue;
        }
        break;
    }
    while (1)
    {
        cout << "请输入目标柱(A-C)" << endl;
        cin >> dst;
        if (src == 'a')
            src = 'A';
        if (src == 'b')
            src = 'B';
        if (src == 'c')
            src = 'C';
        if (dst == 'a')
            dst = 'A';
        if (dst == 'b')
            dst = 'B';
        if (dst == 'c')
            dst = 'C';
        if ((src == 'A' || src == 'a') && (dst == 'B' || dst == 'b')) {
            tmp = 'C';
        }
        if ((src == 'A' || src == 'a') && (dst == 'C' || dst == 'c')) {
            tmp = 'B';
        }
        if ((src == 'b' || src == 'B') && (dst == 'C' || dst == 'c')) {
            tmp = 'A';
        }
        if ((src == 'b' || src == 'B') && (dst == 'A' || dst == 'a')) {
            tmp = 'C';
        }
        if ((src == 'C' || src == 'c') && (dst == 'A' || dst == 'a')) {
            tmp = 'B';
        }
        if ((src == 'C' || src == 'c') && (dst == 'B' || dst == 'b')) {
            tmp = 'A';
        }
        if (dst == src) {
            cout << "目标柱(" << src << ")不能与起始柱(" << src << ")相同" << endl;
            cin.clear();
            cin.ignore(1024, '\n');
            continue;
        }
        else if (dst != 65 && dst != 66 && dst != 67 && dst != 97 && dst != 98 && dst != 99) {
            cin.clear();
            cin.ignore(1024, '\n');
            continue;
        }
        break;
    }
    if (src == 'a')
        src = 'A';
    if (src == 'b')
        src = 'B';
    if (src == 'c')
        src = 'C';
    if (dst == 'a')
        dst = 'A';
    if (dst == 'b')
        dst = 'B';
    if (dst == 'c')
        dst = 'C';
    if ((src == 'A' || src == 'a') && (dst == 'B' || dst == 'b')) {
        tmp = 'C';
    }
    if ((src == 'A' || src == 'a') && (dst == 'C' || dst == 'c')) {
        tmp = 'B';
    }
    if ((src == 'b' || src == 'B') && (dst == 'C' || dst == 'c')) {
        tmp = 'A';
    }
    if ((src == 'b' || src == 'B') && (dst == 'A' || dst == 'a')) {
        tmp = 'C';
    }
    if ((src == 'C' || src == 'c') && (dst == 'A' || dst == 'a')) {
        tmp = 'B';
    }
    if ((src == 'C' || src == 'c') && (dst == 'B' || dst == 'b')) {
        tmp = 'A';
    }
    for (int i = num; i > 0; i--) {
        if (src == 65 || src == 97) {
            arr[0][top[0]++] = i;
        }
        if (src == 66 || src == 98) {
            arr[1][top[1]++] = i;
        }
        if (src == 67 || src == 98) {
            arr[2][top[2]++] = i;
        }
    }
    cout << "初始:\t\t     ";
    cout << "A: ";
    for (int i = 0; i < top[0]; i++) {
        if (top[0] > 0) {
            cout << arr[0][i] << ' ';
        }
    }
    for (int i = top[0]; i < 10; i++) {
        cout << "  ";
    }
   cout<<"B: ";
    for (int i = 0; i < top[1]; i++) {
        if (top[1] > 0) {
            cout << arr[1][i] << ' ';
        }
    }
    for (int i = top[1]; i < 10; i++) {
        cout << "  ";
    }
   cout<<"C: ";
    for (int i = 0; i < top[2]; i++) {
        if (top[2] > 0) {
            cout << arr[2][i] << ' ';
        }
    }
    for (int i = top[2]; i < 10; i++) {
        cout << "  ";
    }
    cout << endl;
    hanoi(num, src, tmp, dst);
    return 0;

}