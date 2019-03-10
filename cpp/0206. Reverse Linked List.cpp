//Reverse a singly linked list.
//
//Example:
//
//Input: 1->2->3->4->5->NULL
//Output: 5->4->3->2->1->NULL
//Follow up:
//
//A linked list can be reversed either iteratively or recursively. Could you implement both?
//


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 /* solution II: 迭代 */
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = NULL;
        ListNode* next = NULL;
        
        while (head)
        {
            next = head->next;
            head->next = prev;
            prev = head;
            head = next;
        }
        
        return prev;
    }
};

/* solution II: 递归 */
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if (!head || !head->next)
        {
            return head;
        }
        
        ListNode* p = reverseList(head->next);
        
        head->next->next = head;
        head->next = NULL;
        
        return p;
    }
};

