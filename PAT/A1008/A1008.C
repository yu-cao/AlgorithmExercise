#include <stdio.h>

int main(void)
{
    int N;
    scanf("%d", &N);

    int a[100];//also correct: int a[N];  //c99 support the dymamic array
    for (int i = 0; i < N; i++) scanf("%d", &a[i]);

    int time = a[0] * 6 + 5;
    for (int i = 1; i < N; i++){
        if (a[i - 1] > a[i]) time += (a[i - 1] - a[i]) * 4 + 5;
        else time += (a[i] - a[i - 1]) * 6 + 5;
    }
    printf("%d", time);
}