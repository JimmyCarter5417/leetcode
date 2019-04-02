// Given a non-negative number represented as a singly linked list of digits, plus one to the number.

// The digits are stored such that the most significant digit is at the head of the list.

// Example:

// Input:
// 1->2->3

// Output:
// 1->2->4


// solution I: 翻转处理
class Solution {
public:
    ListNode* plusOne(ListNode* head) {
        if (!head) 
            return head;

        ListNode *rev_head = reverse(head); // 翻转
        ListNode *cur = rev_head;
        ListNode *pre = cur;
        int carry = 1; // 把要加的1当成进位处理

        while (cur) 
        {
            pre = cur;

            int t = cur->val + carry;
            carry = t / 10;

            cur->val = t % 10;
            
            if (carry == 0) 
                break;

            cur = cur->next;
        }

        if (carry) 
            pre->next = new ListNode(1);

        return reverse(rev_head); // 翻转回来
    }

    ListNode* reverse(ListNode *head) 
    {
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

        // 递归翻转
        /*if (!head || !head->next)
        {
            return head;
        }

        ListNode* t = reverse(head->next);
        head->next->next = head;
        head->next = NULL;
        
        return t;*/
    }
};

// solution II: 递归
class Solution {
public:
    ListNode* plusOne(ListNode* head) 
    {
        if (!head) 
            return head;

        if (helper(head)) 
        {
            ListNode *res = new ListNode(1);
            res->next = head;

            return res;
        }
        else
        {
            return head;
        }
    }

    int helper(ListNode *node) 
    {
        if (!node) 
            return 1;

        int sum = node->val + helper(node->next);
        node->val = sum % 10;

        return sum / 10;
    }
};

// solution III: 迭代
class Solution {
public:
    ListNode* plusOne(ListNode* head) {
        stack<ListNode*> s;
        ListNode *cur = head;

        while (cur) // 先把链表全部从前往后入栈，才能从后往前处理
        {
            s.push(cur);
            cur = cur->next;
        }

        int carry = 1;
        while (!s.empty() && carry) 
        {
            ListNode *t = s.top(); 
            s.pop();

            int sum = t->val + carry;

            t->val = sum % 10;
            carry = sum / 10;
        }

        if (carry) 
        {
            ListNode *new_head = new ListNode(1);
            new_head->next = head;
            head = new_head;
        }

        return head;
    }
};