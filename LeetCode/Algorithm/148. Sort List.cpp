//类似快排的一个写法
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode *sortList(ListNode *head) {
		if (head == nullptr)
			return nullptr;
		else if (head->next == nullptr)
			return head;

		ListNode *temp = head;

		ListNode *lowdummy = new ListNode(-1000);
		ListNode *lowtemp = lowdummy;

		ListNode *highdummy = new ListNode(-1000);
		ListNode *hightemp = highdummy;

		for (head = head->next; head != nullptr; head = head->next)
		{
			if (temp->val > head->val)
			{
				lowtemp->next = head;
				lowtemp = head;
			}
			else if (temp->val <= head->val)
			{
				hightemp->next = head;
				hightemp = head;
			}
		}
		lowtemp->next = hightemp->next = nullptr;

		lowdummy->next = sortList(lowdummy->next);
		highdummy->next = sortList(highdummy->next);

		for (lowtemp = lowdummy; lowtemp->next != nullptr; lowtemp = lowtemp->next);
		lowtemp->next = temp;
		temp->next = highdummy->next;

		return lowdummy->next;
	}
};