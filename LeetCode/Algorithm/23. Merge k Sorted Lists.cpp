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
	ListNode *mergeKLists(vector<ListNode *> &lists)
	{
		if (lists.empty()) return NULL;
		return split(lists, 0, lists.size());
	}

	ListNode *split(vector<ListNode *> &list, int index, int size)
	{
		if (size <= 1) return list[index];
		ListNode *l = split(list, index, size / 2);
		ListNode *r = split(list, index + size / 2, size - size / 2);
		return merge2List(l, r);
	}

	ListNode *merge2List(ListNode *a, ListNode *b)
	{
		ListNode *dummy = new ListNode(-1), *curr = dummy;
		while (a && b)
		{
			if (a->val < b->val)
			{
				curr->next = a;
				a = a->next;
			}
			else
			{
				curr->next = b;
				b = b->next;
			}
			curr = curr->next;
		}
		if (a == NULL) curr->next = b;
		if (b == NULL) curr->next = a;
		return dummy->next;
	}
};