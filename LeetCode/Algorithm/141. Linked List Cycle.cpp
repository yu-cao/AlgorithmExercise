/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(head == nullptr) return false;
        ListNode* fast = head->next;
        ListNode* slow = head;
        int flag = 0;
        while(1)
        {
            if(fast == nullptr || fast->next == nullptr)
            {
                break;
            }
            if(fast == slow)
            {
                flag = 1;
                break;
            }
            fast = fast->next->next;
            slow = slow->next;
        }
        if(flag == 1) return true;
        else return false;
    }
};