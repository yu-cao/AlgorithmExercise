#include<iostream>
//Definition for singly-linked list.
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution
{
  public:
    ListNode *rotateRight(ListNode *head, int k)
    {
        if (k == 0 || head == NULL || head->next == NULL)
            return head; //整个链表只有一个值
        ListNode *check = head;
        int i;
        for (i = 1; check->next != NULL; i++, check = check->next);
        k = k % i;
        for (; k != 0; k--)
        {
            ListNode *fin = head;
            ListNode *fin2 = head;
            for (; fin->next != NULL; fin = fin->next);
            for (; fin2->next->next != NULL; fin2 = fin2->next);
            fin->next = head;
            fin2->next = NULL;
            head = fin;
        }
        return head;
    }
};