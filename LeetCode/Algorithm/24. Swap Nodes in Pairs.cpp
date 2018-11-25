/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution
{
public:
    ListNode *swapPairs(ListNode *head)
    {
        if (head == nullptr || head->next == nullptr)
            return head;

        bool flag = true;
        ListNode *p1 = head, *p2 = head->next, *monitor = nullptr;
        head = head->next;
        for (;;)
        {
            p1->next = p2->next;
            p2->next = p1;
            if (!flag)
            {
                monitor->next = p2;
                monitor = p1;
            }
            else
            {
                monitor = p1;
                flag = false;
            }

            if (p1->next != nullptr)
                p1 = p1->next;
            else
                return head;//no rest

            if (p1->next != nullptr)
                p2 = p1->next;
            else
                return head;//rest of 1
        }

    }
};