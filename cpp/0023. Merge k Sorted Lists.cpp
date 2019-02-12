// Merge k sorted linked lists and return it as one sorted list. Analyze and describe its complexity.

// Example:

// Input:
// [
  // 1->4->5,
  // 1->3->4,
  // 2->6
// ]
// Output: 1->1->2->3->4->4->5->6


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
    struct cmp
    {
        bool operator()(ListNode* n1, ListNode* n2)
        {
            return n1->val > n2->val;
        }
    };
    
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* res = new ListNode(0);
        ListNode* cur = res;
        // 最小堆
        priority_queue<ListNode*, vector<ListNode*>, cmp> pq;
        
        for (ListNode* list: lists)
        {
            if (list) // 空链表不要入堆
            {
                pq.push(list);
            }
        }
        
        while (!pq.empty())
        {
            ListNode* tmp = pq.top();
            pq.pop();
            if (tmp->next)
            {
                pq.push(tmp->next);
            }
            
            cur->next = tmp;
            cur = cur->next;
        }
        
        return res->next;
    }
};