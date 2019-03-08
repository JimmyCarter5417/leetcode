//Remove all elements from a linked list of integers that have value val.
//
//Example:
//
//Input:  1->2->6->3->4->5->6, val = 6
//Output: 1->2->3->4->5
//


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 /* solution I: 迭代 */
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {        
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* pre = dummy;
        ListNode* cur = dummy->next;
        
        while (cur)
        {
            while (cur && cur->val == val)
            {
                cur = cur->next;
            }
            
            pre->next = cur;
            pre = pre->next;
            if (cur)
            {
                cur = cur->next;
            }
        }
        
        return dummy->next;
    }
};

/* solution II: 递归 */
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {        
        if (!head)
        {
            return NULL;
        }
        
        if (head->val == val)
        {
            return removeElements(head->next, val);
        }
        else
        {
            head->next = removeElements(head->next, val);
            return head;
        }
    }
};

