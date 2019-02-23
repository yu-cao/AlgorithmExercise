//一定要提供一个dummy node，可以明显减少代码量
//多个链表的合并可以分治成多个两个链表合并（LeetCode 23 Hard)
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
