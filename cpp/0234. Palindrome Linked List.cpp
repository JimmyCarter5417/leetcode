// Given a singly linked list, determine if it is a palindrome.

// Example 1:

// Input: 1->2
// Output: false
// Example 2:

// Input: 1->2->2->1
// Output: true
// Follow up:
// Could you do it in O(n) time and O(1) space?


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
    bool isPalindrome(ListNode* head) {
        if (NULL == head || NULL == head->next)
            return true;
            
        ListNode* slow = head;
        ListNode* fast = head;
        // 找到中点
        while (fast->next && fast->next->next)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        // 断开并翻转下半部分
        ListNode* last = slow->next;
        while (last->next)
        {
            ListNode* tmp = last->next;
            last->next = tmp->next;
            tmp->next = slow->next;
            slow->next = tmp;
        }
        
        slow = slow->next;
        while (slow)
        {
            if (head->val != slow->val)
                return false;
            
            slow = slow->next;
            head = head->next;
        }
        
        return true;
    }
};
