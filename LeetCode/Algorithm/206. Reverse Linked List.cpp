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
    ListNode* reverseList(ListNode* head) {
        ListNode *dummy = new ListNode(-1);
        ListNode *cur = head;
        dummy->next = head;
        
        while(cur && cur->next)
        {
            ListNode* temp = cur->next;
            cur->next = temp->next;
            temp->next = dummy->next;
            dummy->next = temp;
        }
        return dummy->next;
    }
};