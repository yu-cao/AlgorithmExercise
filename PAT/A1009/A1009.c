#include <stdio.h>
#include <stdlib.h>
struct Node{
    int exp;
    double coff;
};

int main(void)
{
    int M, N;

    scanf("%d", &M);
    struct Node Ma[1000];
    for (int i = 0; i < M; i++) scanf("%d %lf", &Ma[i].exp, &Ma[i].coff);
    scanf("%d", &N);
    struct Node Na[1000];
    for (int i = 0; i < N; i++) scanf("%d %lf", &Na[i].exp, &Na[i].coff);

    struct Node Oa[2001];//output
    for(int i=0;i<2001;i++){
        Oa[i].coff=0;
        Oa[i].exp=i;
    }

    for (int i = 0; i < M; i++){
        for (int j = 0; j < N; j++){
            int temp = Ma[i].exp + Na[j].exp;
            Oa[temp].coff += Ma[i].coff * Na[j].coff;
        }
    }

    int K = 0;
    for(int i=2000;i>=0;i--) if(Oa[i].coff!=0) K++;

    struct Node* fin = (struct Node*)malloc(sizeof(struct Node)*K);
    int count = K;
    for(int i=2000;i>=0;i--){
        if(Oa[i].coff!=0){
            count--;
            fin[count].coff = Oa[i].coff;
            fin[count].exp = Oa[i].exp;
        }
    }
    printf("%d",K);
    for(int i=(K-1);i>=0;i--) printf(" %d %.1lf",fin[i].exp,fin[i].coff);
}