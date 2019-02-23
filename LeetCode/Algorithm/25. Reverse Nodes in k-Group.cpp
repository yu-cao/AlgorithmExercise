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
	ListNode *reverseKGroup(ListNode *head, int k)
	{
		if (!head || k == 1) return head;
		ListNode *tail = head;
		for(int i = 0;i<k;i++)
		{
			if(tail == NULL) return head;
			tail = tail->next;
		}
		//循环不变量：让head通过翻转变成末尾，翻转结束后的头部new_head变成新的头部，两者递归组合起来
		ListNode *new_head = reverse(head,tail);
		head->next = reverseKGroup(tail,k);
		return new_head;
	}

    //使用标准的链表翻转方法
	ListNode* reverse(ListNode* head, ListNode* tail) {
		ListNode *dummy = new ListNode(-1);
		dummy->next = head;
		ListNode *curr = head;

		while(curr->next != tail)
		{
			ListNode* temp = curr->next;
			curr->next = temp->next;
			temp->next = dummy->next;
			dummy->next = temp;
		}
		return dummy->next;
	}
};