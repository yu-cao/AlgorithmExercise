#include<stdio.h>
#include<stdlib.h>

struct Node {
	int number;
	int level;
	int flag;
	struct Node* ancestor_node;
};

int main(void)
{
	//N:�ܽڵ��� M: ��Ҷ(non-leaf)�ڵ���
	int N;
	scanf("%d", &N);

	int M;
	scanf("%d", &M);

	struct Node *a[N + 1];

	//������1��ʼ
	int i;
	for (i = 1; i <= N; i++) {
		//����������Ϊα���Ļ���
		a[i] = (struct Node*)malloc(sizeof(struct Node));
		a[i]->number = i;
		a[i]->level = -1;
		a[i]->flag = 0;//0����Ҷ�ڵ�  1���Ƿ�Ҷ�ڵ�
		a[i]->ancestor_node = NULL;//�ýڵ�����Ƚڵ�
	}
	a[1]->level = 0;

	int node_front;
	int number_node_next;
	int temp,j;
	for (j = 0; j < M; j++) {
		scanf("%d", &node_front);//ǰ�ڵ�λ��
		a[node_front]->flag = 1;//��ȻΪ��Ҷ�ڵ�
		scanf("%d", &number_node_next);
		for (int q = 0; q < number_node_next; q++) {
			scanf("%d", &temp);
			a[temp]->level = a[node_front]->level + 1;
			a[temp]->ancestor_node = a[node_front];
		}
	}
	
	//����
	int k;
	if (N != 1) {
		for (k = 2; k <= N; k++) {
			a[k]->level = a[k]->ancestor_node->level + 1;
		}
	}
	
	//ͳ��
	int count[N];
	for (int j = 0; j < N; j++) {
		count[j] = 0;
	}

	for (k = 0; k <= N; k++) {
		for (i = 1; i <= N; i++) {
			if (a[i]->level == k) {
				if (a[i]->flag==0) {
					count[k]++;
				}
			}
		}
	}

	//���
	int sum = count[0];
	printf("%d", count[0]);
	if (sum == (N - M)) {
		return 0;
	}

	for (k = 1; k < N; k++) {
		printf(" %d", count[k]);
		sum += count[k];
		if (sum == (N - M)) {
			break;
		}
	}

}