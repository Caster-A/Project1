/*2451454 电信 杨翰卓*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main()
{
	int arr[1000];
	int frequency[1000] = { 0 };
	int count = 0;
	int num;
	printf("请输入成绩（最多1000个），负数结束输入\n");
	while (count < 1000) {
		scanf("%d", &num);
		if (num < 0) {
			break;
		}
		arr[count] = num;
		count++;
	}
	printf("输入的数组为:\n");
	for (int i = 0; i < count; i++) {
		printf("%d ", arr[i]);
		if ((i + 1) % 10 == 0) {
			printf("\n");
		}
		if (i == count - 1) {
			printf("\n");
		}
	}
	printf("分数与人数的对应关系为:\n");
	for (int i = 0; i < count; i++) {
		frequency[arr[i]]++;
	}

	for (int i = 100; i >= 0; i--) {
		if (frequency[i]>0) {
			printf("%d %d\n", i, frequency[i]);
		}
	}

	return 0;
}