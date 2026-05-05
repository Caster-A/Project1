/*2451454 电信 杨翰卓*/
#include <stdio.h>

#define     N   20

void move_data(int *a, const int n, const int m)
{
    int t, *p, *q;

    int shift = m % n; // 实际移动的步数
    if (shift == 0) return;

    // 先将后 shift 个元素整体“临时交换”到前面
    p = a + n - shift;
    while (p < a + n) {
        t = *p;
        q = p;
        while (q > a) {
            *q = *(q - 1);
            --q;
        }
        *a = t;
        ++p;
        ++a;
    }
}

void input(int *a, const int n)
{
    int *p = a;
    while (p < a + n) {
        scanf("%d", p);
        ++p;
    }
}

void output(int *a, const int n)
{
    int *p = a;
    while (p < a + n) {
        printf("%d ", *p);
        ++p;
    }
    printf("\n");
}

int main()
{
    int a[N], m, n;

    printf("请输入整数的数量n[%d-%d]\n", N / 2, N);
    scanf("%d", &n);

    printf("请输入%d个整数\n", n);
    input(a, n);

    printf("输入的整数序列为\n");
    output(a, n);

    printf("请输入向后移动的位置m[1..2^31-1]\n");
    scanf("%d", &m);

    move_data(a, n, m);

    printf("移动后的整数序列为\n");
    output(a, n);

    return 0;
}
