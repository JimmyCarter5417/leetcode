// You are given two non-empty linked lists representing two non-negative integers. The most significant digit comes first and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.

// You may assume the two numbers do not contain any leading zero, except the number 0 itself.

// Follow up:
// What if you cannot modify the input lists? In other words, reversing the lists is not allowed.

// Example:
// Input: (7 -> 2 -> 4 -> 3) + (5 -> 6 -> 4)
// Output: 7 -> 8 -> 0 -> 7


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
        // 不让翻转链表，那就只能用栈翻转了
        stack<ListNode*> s1, s2;
        
        while (l1) // l1入栈
        {
            s1.push(l1);
            l1 = l1->next;
        }
        while (l2) // l2入栈
        {
            s2.push(l2);
            l2 = l2->next;
        }
        
        ListNode* dummy = new ListNode(-1);
        ListNode* cur = dummy;
        int carry = 0;
        
        while (!s1.empty() || !s2.empty())
        {
            int n1 = 0;
            int n2 = 0;
            
            if (!s1.empty())
            {
                n1 = s1.top()->val;
                s1.pop();
            }
            if (!s2.empty())
            {
                n2 = s2.top()->val;
                s2.pop();
            }
            
            cur->next = new ListNode((n1 + n2 + carry) % 10);
            cur = cur->next;
            
            carry = (n1 + n2 + carry) / 10;
        }
        
        if (carry) // 处理进位
        {
            cur->next = new ListNode(carry % 10);
        }
            
        // 需要翻转链表    
        ListNode* prev = nullptr;
        ListNode* next = nullptr;
        ListNode* head = dummy->next;
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
