// Given a sorted linked list, delete all nodes that have duplicate numbers, leaving only distinct numbers from the original list.

// Example 1:

// Input: 1->2->3->3->4->4->5
// Output: 1->2->5
// Example 2:

// Input: 1->1->1->2->3
// Output: 2->3


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
        
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        
        ListNode* pre = dummy;
        ListNode* cur = pre->next;
        while (cur)
        {
            while (cur && cur->next && cur->next->val == cur->val)
            {
                cur = cur->next;
            }
            
            // 注意更新此处的两处pre即可
            if (cur == pre->next)
            {
                pre = cur;                
            }
            else
            {
                pre->next = cur->next;                
            }
            
            cur = cur->next;
        }
        
        return dummy->next;
    }
};