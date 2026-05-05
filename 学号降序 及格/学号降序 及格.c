/*2451454 电信 杨翰卓*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
void input(char id[][8],char name[][9],int score[])
{
	for(int i=0;i<10;i++)
	{
		printf("请输入第%d个人的学号、姓名、成绩\n", i+1);
		scanf("%s", id[i]);
		scanf("%s", name[i]);
		scanf("%d", &score[i]);
	}
}
void rank(char id[][8], char name[][9], int score[])
{
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9 - i; j++) {
			if (strcmp(id[j], id[j + 1]) < 0) {
				char tmpid[8];
				strcpy(tmpid, id[j]);
				strcpy(id[j], id[j + 1]);
				strcpy(id[j + 1], tmpid);

				char tmpname[9];
				strcpy(tmpname, name[j]);
				strcpy(name[j], name[j + 1]);
				strcpy(name[j + 1], tmpname);

				int tmpscore[10];
				tmpscore[j] = score[j];
				score[j] = score[j + 1];
				score[j + 1] = tmpscore[j];
			}
		}
	}
}
void output(char id[][8], char name[][9], int score[])
{
	printf("及格名单(学号降序):\n");
	for (int i = 0; i < 10; i++) {
		if (score[i] >= 60) {
			printf("%s %s %d\n", name[i], id[i], score[i]);
		}
	}
}
int main() 
{
	char id[10][8], name[10][9];
	int score[10];
	input(id, name, score);
	rank(id, name, score);
	printf("\n");
	output(id, name, score);
	return 0;
}