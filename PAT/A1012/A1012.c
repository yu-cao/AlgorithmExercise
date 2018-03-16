#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct student
{
    char ID[7];
    int C;
    int M;
    int E;
    int A;
    int choose; //1:A 2:C 3:M 4:E
};
void Print(char *ch, struct student stu[], int N);
int main(void)
{
    int N, re;
    scanf("%d %d", &N, &re);

    struct student stu[2000];
    for (int i = 0; i < N; i++)
    {
        scanf("%s %d %d %d", stu[i].ID, &stu[i].C, &stu[i].M, &stu[i].E);
        stu[i].A = (stu[i].C + stu[i].M + stu[i].E) / 3;
        stu[i].choose = 0;
    }

    for (int i = 0; i < re; i++)
    {
        char ch[7];
        scanf("%s", ch);
        Print(ch, stu, N);
    }
}
//Firstly, compare to the rank,then choose the best rank and sort in subject
void Print(char *ch, struct student stu[], int N)
{
    int i;
    for (i = 0; i < N; i++)
        if (!strcmp(stu[i].ID, ch))
            break;
    if (i == N)
    {
        printf("N/A\n");
        return;
    }
    const int st = i;
    int rank1 = 1;
    int rank2 = 1;
    int rank3 = 1;
    int rank4 = 1;
    for (int j = 1; j <= 4; j++)
    {
        switch (j)
        {
        case 1:
            for (int i = 0; i < N; i++)
                if (stu[i].A > stu[st].A)
                    rank1++;
            break;

        case 2:
            for (int i = 0; i < N; i++)
                if (stu[i].C > stu[st].C)
                    rank2++;
            break;

        case 3:
            for (int i = 0; i < N; i++)
                if (stu[i].M > stu[st].M)
                    rank3++;
            break;

        case 4:
            for (int i = 0; i < N; i++)
                if (stu[i].E > stu[st].E)
                    rank4++;
            break;
        }
    }
    if (rank1 <= rank2 && rank1 <= rank3 && rank1 <= rank4)
        printf("%d A\n", rank1);
    else if (rank2 < rank1 && rank2 <= rank3 && rank2 <= rank4)
        printf("%d C\n", rank2);
    else if (rank3 < rank1 && rank3 < rank2 && rank3 <= rank4)
        printf("%d M\n", rank3);
    else if (rank4 < rank1 && rank4 < rank2 && rank4 < rank3)
        printf("%d E\n", rank4);
}