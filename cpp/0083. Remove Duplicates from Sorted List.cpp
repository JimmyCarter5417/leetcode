// Given a sorted linked list, delete all duplicates such that each element appear only once.

// Example 1:

// Input: 1->1->2
// Output: 1->2
// Example 2:

// Input: 1->1->2->3->3
// Output: 1->2->3


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
    ListNode* deleteDuplicates(ListNode* head) {
        if (!head || !head->next)
        {
            return head;
        }
        
        ListNode* pre = head;
        ListNode* cur = head;
        
        while (pre)
        {
            while (cur->next && cur->val == cur->next->val)
            {
                cur = cur->next;
            }
            
            // 注意更新pre和cur即可
            pre->next = cur->next;
            pre = pre->next;
            cur = pre;
        }
        
        return head;
    }
};