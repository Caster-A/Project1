/*2451454 电信 杨翰卓*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int m = 0;
int elk[10] = { 0 };
int xun[10] = { 0 };
int knight[10] = { 0 };

int topA = 0;
int topB = 0;
int topC = 0;

void hanoi(int n, char src, char tmp, char dst)
{
    
    
    if (n == 1) {
        if (src == 'A') {
            topA--;
            if (dst == 'B')
                xun[topB++] = n;
            if (dst == 'C')
                knight[topC++] = n;
        }
        if (src == 'C') {
            topC--;
            if (dst == 'B')
                xun[topB++] = n;
            if (dst == 'A')
                elk[topA++] = n;
        }
        if (src == 'B') {
            topB--;
            if (dst == 'A')
                elk[topA++] = n;
            if (dst == 'C')
                knight[topC++] = n;
        }
        m++;
        printf("第%4d 步(%2d): %c-->%c ", m, n, src, dst);
        printf("A: ");
        for (int i = 0; i < topA; i++) {
            if (topA > 0) {
                printf("%d ", elk[i]);
            }
        }
        for (int i = topA; i < 10; i++) {
            printf("  ");
        }
        printf("B: ");
        for (int i = 0; i < topB; i++) {
            if (topB > 0) {
                printf("%d ", xun[i]);
            }
        }
        for (int i = topB; i < 10; i++) {
            printf("  ");
        }
        printf("C: ");
        for (int i = 0; i < topC; i++) {
            if (topC > 0) {
                printf("%d ", knight[i]);
            }
        }
        for (int i = topC; i < 10; i++) {
            printf("  ");
        }
        printf("\n");
        
        return;
    }
    hanoi(n - 1, src, dst, tmp);
    m++;
    if (src == 'A') {
        topA--;
        if (dst == 'B')
            xun[topB++] = n;
        if (dst == 'C')
            knight[topC++] = n;
    }
    if (src == 'C') {
        topC--;
        if (dst == 'B')
            xun[topB++] = n;
        if (dst == 'A')
            elk[topA++] = n;
    }
    if (src == 'B') {
        topB--;
        if (dst == 'A')
            elk[topA++] = n;
        if (dst == 'C')
            knight[topC++] = n;
    }
    printf("第%4d 步(%2d): %c-->%c ", m, n, src, dst);
    printf("A: ");
    for (int i = 0; i < topA; i++) {
        if (topA > 0) {
            printf("%d ", elk[i]);
        }
    }
    for (int i = topA; i < 10; i++) {
        printf("  ");
    }
    printf("B: ");
    for (int i = 0; i < topB; i++) {
        if (topB > 0) {
            printf("%d ", xun[i]);
        }
    }
    for (int i = topB; i < 10; i++) {
        printf("  ");
    }
    printf("C: ");
    for (int i = 0; i < topC; i++) {
        if (topC > 0) {
            printf("%d ", knight[i]);
        }
    }
    for (int i = topC; i < 10; i++) {
        printf("  ");
    }
    printf("\n");
    hanoi(n - 1, tmp, src, dst);
}

int main()
{
    int num, ret;
    char src, dst;
    char tmp = 0;
    while (1)
    {
        printf("请输入汉诺塔的层数(1-10)\n");
        ret = scanf("%d", &num);
        if (ret == 0) {
            int c;
            while ((c = getchar()) != '\n' && c != EOF) {
            }
            continue;
        }
        if (num < 1 || num > 16) {
            int c;
            while ((c = getchar()) != '\n' && c != EOF) {
            }
            continue;
        }
        break;
    }
    while (1)
    {
        printf("请输入起始柱(A-C)\n");
        scanf(" %c", &src);
        if (src != 65 && src != 66 && src != 67 && src != 97 && src != 98 && src != 99) {
            int c;
            while ((c = getchar()) != '\n' && c != EOF) {
            }
            continue;
        }
        break;
    }
    while (1)
    {
        printf("请输入目标柱(A-C)\n");
        scanf(" %c", &dst);
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
            printf("目标柱(%c)不能与起始柱(%c)相同\n", src, dst);
            int c;
            while ((c = getchar()) != '\n' && c != EOF) {
            }
            continue;
        }
        else if (dst != 65 && dst != 66 && dst != 67 && dst != 97 && dst != 98 && dst != 99) {
            int c;
            while ((c = getchar()) != '\n' && c != EOF) {
            }
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
            elk[topA++] = i;
        }
        if (src == 66 || src == 98) {
            xun[topB++] = i;
        }
        if (src == 67 || src == 98) {
            knight[topC++] = i;
        }
    }
    printf("初始:\t\t     ");
    printf("A: ");
    for (int i = 0; i < topA; i++) {
        if(topA > 0){
            printf("%d ", elk[i]);
        }
    }
    for (int i = topA; i < 10; i++) {
        printf("  ");
    }
    printf("B: ");
    for (int i = 0; i < topB; i++) {
        if(topB > 0){
            printf("%d ", xun[i]);
        }
    }
    for (int i = topB; i < 10; i++) {
        printf("  ");
    }
    printf("C: ");
    for (int i = 0; i < topC; i++) {
        if(topC > 0){
            printf("%d ", knight[i]);
        }
    }
    for (int i = topC; i < 10; i++) {
        printf("  ");
    }
    printf("\n");
    hanoi(num, src, tmp, dst);
    return 0;
}