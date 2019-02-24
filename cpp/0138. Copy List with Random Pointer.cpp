//A linked list is given such that each node contains an additional random pointer which could point to any node in the list or null.
//
//Return a deep copy of the list.
//
//Example 1:
//
//Input:
//{"$id":"1","next":{"$id":"2","next":null,"random":{"$ref":"2"},"val":2},"random":{"$ref":"2"},"val":1}
//
//Explanation:
//Node 1's value is 1, both of its next and random pointer points to Node 2.
//Node 2's value is 2, its next pointer points to null and its random pointer points to itself.
//


/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node() {}

    Node(int _val, Node* _next, Node* _random) {
        val = _val;
        next = _next;
        random = _random;
    }
};
*/
class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node* dummy = new Node(0);
        Node* curOld = head;
        Node* curNew = dummy;
        unordered_map<Node*, Node*> m; // 记录新旧链表节点映射关系
        
        while (curOld)
        {
            Node* tmp = new Node(curOld->val, NULL, NULL);
            curNew->next = tmp;
            m[curOld] = tmp;
            
            curNew = curNew->next;
            curOld = curOld->next;            
        }
        
        curOld = head;
        curNew = dummy->next;
        while (curOld)
        {
            curNew->random = m[curOld->random]; // 单独为random赋值
            
            curNew = curNew->next;
            curOld = curOld->next;            
        }
        
        return dummy->next;
    }
};

