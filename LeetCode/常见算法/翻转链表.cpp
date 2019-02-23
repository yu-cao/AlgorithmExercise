//翻转链表就是把未进行的nodey进行一次重新排序，其策略有二
//1. 不断放到dummy node和头结点之间（链表题基本要自己弄个dummy node）
//2. 不断放到尾节点之前（仅适用于给出尾节点node的情况）

struct ListNode
{
    int val;
    ListNode *next;
    
    ListNode(int x) : val(x), next(NULL)
    {}
};

//翻转从head节点到tail节点的链表（包括head，不包括tail），返回头结点
//想法：不断把node放到后面去，也就是说在tail前不断向前插入
ListNode* reverse(ListNode* head, ListNode* tail) {
    ListNode *pre = tail;
    while (head != tail) {
        ListNode *t = head->next;
        head->next = pre;
        pre = head;
        head = t;
    }
    return pre;
}
//这个想法是不断把node提到前面来，在dummy之后进行插入
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

//简单版：翻转整个单链表
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode *dummy = new ListNode(-1);
        ListNode *cur = head;
        dummy->next = head;
        
        //cur不用变化，因为它始终保持是最后一个
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

//困难版 LeetCode 25 Hard 
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

    //使用上面的翻转方法
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