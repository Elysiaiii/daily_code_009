

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* partition(struct ListNode* head, int x) {
    struct ListNode* Small = (struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode* Large = (struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode* Small_Head = Small;
    struct ListNode* Large_Head = Large;
    while (head)
    {
        if (head->val < x)
        {
            Small->next = head;
            Small = Small->next;
        }
        else
        {
            Large->next = head;
            Large = Large->next;
        }
        head = head->next;
    }
    Large->next = NULL;//注意要将链表尾置空
    Small->next = Large_Head->next;
    return Small_Head->next;
}