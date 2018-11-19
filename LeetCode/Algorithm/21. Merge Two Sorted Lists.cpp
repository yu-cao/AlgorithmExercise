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
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2)
    {
        ListNode *p;
        if (l1 == nullptr) return l2;
        if (l2 == nullptr) return l1;

        if (l2->val <= l1->val)
        {
            p = l2;
            for (;;)
            {
                if (l1 == nullptr) break;
                if (l2->next != nullptr && l1->val <= l2->next->val)
                {
                    ListNode *temp1 = l2->next;
                    ListNode *temp2 = l1;
                    l2->next = temp2;
                    l1 = l1->next;
                    temp2->next = temp1;
                    l2 = l2->next;
                }
                else if (l2->next == nullptr)
                {
                    l2->next = l1;
                    break;
                }
                else l2 = l2->next;
            }
        }
        else
        {
            p = l1;
            for (;;)
            {
                if (l2 == nullptr) break;
                if (l1->next != nullptr && l2->val <= l1->next->val)
                {
                    ListNode *temp1 = l1->next;
                    ListNode *temp2 = l2;
                    l1->next = temp2;
                    l2 = l2->next;
                    temp2->next = temp1;
                    l1 = l1->next;
                }
                else if (l1->next == nullptr)
                {
                    l1->next = l2;
                    break;
                }
                else l1 = l1->next;
            }
        }
        return p;
    }
};
