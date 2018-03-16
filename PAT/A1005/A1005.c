#include<stdio.h>

int main(void)
{
	char a[101]={0};
	scanf("%s", a);

	int count = 0;
	for(int i=0;i<101;i++)
	{
		if (a[i] != 0)	count += a[i] - '0';
		else break;
	}
	
	int b[4] = { 0 };
	int i;
	for (i = 0; i < 4; i++)
	{
		b[i] = count % 10;
		count /= 10;
		if (count == 0) break;
	}

	for(;i>=0;i--)
	{
		switch(b[i])
		{
		case 0:
			printf("zero");
			break;
		case 1:
			printf("one");
			break;
		case 2:
			printf("two");
			break;
		case 3:
			printf("three");
			break;
		case 4:
			printf("four");
			break;
		case 5:
			printf("five");
			break;
		case 6:
			printf("six");
			break;
		case 7:
			printf("seven");
			break;
		case 8:
			printf("eight");
			break;
		case 9:
			printf("nine");
			break;
		}
		if(i!=0)
		{
			printf(" ");
		}
	}
}