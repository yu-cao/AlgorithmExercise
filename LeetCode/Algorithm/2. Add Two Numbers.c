/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
#include<stdio.h>
struct ListNode{
    int val;
    struct ListNode *next;
};

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    int temp,count=0;
    struct ListNode* p = (struct ListNode*)malloc(sizeof(struct ListNode)),*q;
    q=p;
    for(;;){
        struct ListNode* a = (struct ListNode*)malloc(sizeof(struct ListNode));
        p->next=a;
        a->next=NULL;
        temp=l1->val+l2->val;
        a->val=temp+count;
        p=a;
        if(a->val>=10){
            count=1;
            a->val-=10;
        }else count=0;
        
        if(l1->next==NULL){
            if(l2->next==NULL) {
                if(count==1){
                    struct ListNode* a = (struct ListNode*)malloc(sizeof(struct ListNode));
                    p->next=a;
                    a->next=NULL;
                    a->val=1;
                    return (q->next);
                }
                return (q->next);
            }
            else{
                struct ListNode* b = (struct ListNode*)malloc(sizeof(struct ListNode));
                l1->next=b;
                b->next=NULL;
                b->val=0;
                l1=b;
                l2=l2->next;
            }
        }else{
            if(l2->next==NULL){
                struct ListNode* b = (struct ListNode*)malloc(sizeof(struct ListNode));
                l2->next=b;
                b->next=NULL;
                b->val=0;
                l2=b;
                l1=l1->next;
            } 
            else{
                l1=l1->next;
                l2=l2->next;
            }
        }
    }
}