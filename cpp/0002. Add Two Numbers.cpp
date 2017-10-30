// You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.
// 
// You may assume the two numbers do not contain any leading zero, except the number 0 itself.
// 
// Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
// Output: 7 -> 0 -> 8


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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        shared_ptr<ListNode> dummy(new ListNode(0));
        ListNode* cur = dummy.get();
        int flag = 0;
        
        while (l1 || l2)
        {
            int n1 = l1 ? l1->val : 0;
            int n2 = l2 ? l2->val : 0;
            int sum = n1 + n2 + flag;
            
            cur->next = new ListNode(sum % 10);            
            flag = sum / 10;
            
            cur = cur->next;
            if (l1)
                l1 = l1->next;
            if (l2)
                l2 = l2->next;
        }
        
        if (flag != 0)
            cur->next = new ListNode(flag);      
        
        return dummy->next;        
    }
};
