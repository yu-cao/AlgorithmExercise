
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
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        vector<ListNode *> temp;//store the address of each node
        int count = 0;

        if (head == nullptr || (head->next == nullptr && n == 1))
            return nullptr;

        for (ListNode *p = head; p != nullptr; p = p->next)
        {
            temp.push_back(p);
            count++;
        }

        if (count - n == 0)//delete the head node
        {
            ListNode *p = head;
            head = head->next;
            delete[] p;
            return head;
        }

        ListNode *target = temp[count - n];
        ListNode *p = head;
        ListNode *p1 = head->next;
        for (; p1 != target;)
        {
            p = p->next;
            p1 = p1->next;
        }
        p->next = p1->next;
        delete[] p1;
        return head;
    }
};