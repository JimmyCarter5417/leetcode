// You are given a doubly linked list which in addition to the next and previous pointers, it could have a child pointer, which may or may not point to a separate doubly linked list. These child lists may have one or more children of their own, and so on, to produce a multilevel data structure, as shown in the example below.

// Flatten the list so that all the nodes appear in a single-level, doubly linked list. You are given the head of the first level of the list.

// Example:

// Input:
//  1---2---3---4---5---6--NULL
//          |
//          7---8---9---10--NULL
//              |
//              11--12--NULL

// Output:
// 1-2-3-7-8-11-12-9-10-4-5-6-NULL
 
// Explanation for the above example:

// Given the following multilevel doubly linked list: 

// We should return the following flattened doubly linked list:


/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;

    Node() {}

    Node(int _val, Node* _prev, Node* _next, Node* _child) {
        val = _val;
        prev = _prev;
        next = _next;
        child = _child;
    }
};
*/
class Solution {
public:
    Node* flatten(Node* head) {        
        stack<Node*> stk;
        Node* cur = head;
        
        while(cur)
        {
            if(cur->child) // 先处理child
            {
                if(cur->next) 
                {
                    stk.push(cur->next); // 将分叉节点的next入栈，注意：next非空
                }
                
                // 重置分叉节点的next，删除child
                cur->next = cur->child;
                cur->next->prev = cur;
                cur->child = NULL;
            }
            else 
            {
                if (!cur->next && !stk.empty()) // 一旦到达child链结尾，即可与栈中保存的next节点相连
                {
                    cur->next = stk.top();
                    stk.pop();
                    cur->next->prev = cur;
                }
            }
            
            cur = cur->next; // cur后移
        }
        
        return head;
    }
};