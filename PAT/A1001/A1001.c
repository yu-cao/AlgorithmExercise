#include<stdio.h>

void Print_4_Front(int temp);

int main(void)
{
	int a, b, sum;
	scanf("%d %d", &a, &b);
	sum = a + b;
	if (sum < 0) {
		printf("-");
		sum = -sum;
	}
	int temp1, temp2, temp3;
	temp1 = sum % 1000;
	temp2 = (sum / 1000) % 1000;
	temp3 = sum / 1000000;
	if (temp3 != 0) {
		printf("%d,", temp3);
	}

	if (temp3 != 0) {
		Print_4_Front(temp2);
		printf(",");
	}
	
	if (temp3 == 0 && temp2 != 0) {
		printf("%d,", temp2);
	}

	if (temp3 != 0 || temp2 != 0) {
		Print_4_Front(temp1);
	}
	else {
		printf("%d", temp1);
	}
	return 0;
}

void Print_4_Front(int temp)
{
	if (temp == 0) {
		printf("000");
	}
	else {
		if (temp / 10 == 0) {
			printf("00");
			printf("%d", temp);
		}
		else if (temp / 100 == 0) {
			printf("0");
			printf("%d", temp);
		}
		else if (temp / 1000 == 0) {
			printf("%d", temp);
		}
	}
}
