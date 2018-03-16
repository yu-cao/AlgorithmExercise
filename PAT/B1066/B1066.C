#include<stdio.h>
int main(void)
{
	int hang, lie;
	scanf("%d", &hang);
	scanf("%d", &lie);

	int low, high;
	scanf("%d", &low);
	scanf("%d", &high);

	int to_be;
	scanf("%d", &to_be);

	int a[hang][lie];
	int i, j;
	for (i = 0; i<hang; i++) {
		for (j = 0; j<lie; j++) {
			scanf("%d", &a[i][j]);
			if (a[i][j] >= low&&a[i][j] <= high) {
				a[i][j] = to_be;
			}
		}
	}
	for (i = 0; i<hang; i++) {
		for (j = 0; j<lie; j++) {
			printf("%.3d", a[i][j]);
			if (j == lie - 1) {
				break;
			}
			printf(" ");
		}
		printf("\n");
	}
}