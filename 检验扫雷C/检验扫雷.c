/*2451454 µçÐÅ Ñîº²×¿*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main()
{
	int dx[] = { -1, -1, -1, 0, 1, 1, 1, 0 };
	int dy[] = { -1, 0, 1, 1, 1, 0, -1, -1 };
	char mines[10][26];

	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 26; j++) {
			char a;
			scanf(" %c", &a);
			mines[i][j] = a;
		}
	}
	int check = 1;
	int sum = 0;
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 26; j++) {
			if (mines[i][j] == '*')
			{
				sum++;
				continue;
			}
			int edge = mines[i][j] - '0';
			int count = 0;

			for (int k = 0; k < 8; k++) {
				int ni = i + dx[k], nj = j + dy[k];
				if (ni >= 0 && ni < 10 && nj >= 0 && nj < 26) {
					if (mines[ni][nj] == '*')
						count++;

				}
			}
			if (count != edge) {
				check = 0;
			}
		}
	}
	if (sum != 50) {
		printf("´íÎó1\n");
	}
	else if (check == 1)
		printf("ÕýÈ·\n");
	else if (check == 0)
		printf("´íÎó2\n");

	return 0;
}