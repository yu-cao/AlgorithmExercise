#include<stdio.h>
#include<string.h>
struct people
{
  char ID[100];
  char in[10];
  char out[10];
};

int main(void)
{
  int N;
  scanf("%d", &N);

  struct people a[N];//finally return to N
  struct people *ptr_in = &a[0];
  struct people *ptr_out = &a[0];
  for(int i=0;i<N;i++)
  {
    scanf("%s %s %s", a[i].ID, a[i].in, a[i].out);
    if(strcmp(a[i].in,ptr_in->in)<0)
    {
      ptr_in = &a[i];
    }
    if(strcmp(a[i].out,ptr_out->out)>0)
    {
      ptr_out = &a[i];
    }
  }
  printf("%s %s", ptr_in->ID, ptr_out->ID);
}