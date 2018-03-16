#include <stdio.h>
int main(void)
{
	int N;
	scanf("%d", &N);

	int a[N]; //finally return to N
	for (int i = 0; i < N; i++)	scanf("%d", &a[i]);

	int sum = 0;
	int max = 0;
	int left = -1;
	int right = -1;
	for (int i = 0; i < N; i++)
	{
		sum = 0;
		for (int j = i; j < N; j++)
		{
			sum += a[j];
			if (sum > max || (max == 0 && sum == 0))
			{
				left = i;
				right = j;
				max = sum;
			}
		}
	}
	if (max == 0 && left == -1) printf("%d %d %d\n", max, a[0], a[N - 1]);
	else printf("%d %d %d\n", max, a[left], a[right]);
}