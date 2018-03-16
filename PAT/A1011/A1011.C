#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    double a[3][3];
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            scanf("%lf", &a[i][j]);

    double answer = 1;
    for (int i = 0; i < 3; i++)
    {
        if (a[i][0] > a[i][1] && a[i][0] > a[i][2])
        {
            printf("W ");
            answer *= a[i][0];
        }
        else if (a[i][2] > a[i][1] && a[i][2] > a[i][0])
        {
            printf("L ");
            answer *= a[i][2];
        }
        else if (a[i][1] > a[i][0] && a[i][1] > a[i][2])
        {
            printf("T ");
            answer *= a[i][1];
        }
    }
    double fin = (answer * 0.65 - 1) * 2 + 0.00000001;
    printf("%.2f", fin);
}