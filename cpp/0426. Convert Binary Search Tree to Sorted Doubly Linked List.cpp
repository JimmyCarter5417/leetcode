// Convert a BST to a sorted circular doubly-linked list in-place. Think of the left and right pointers as synonymous to the previous and next pointers in a doubly-linked list.

// Let's take the following BST as an example, it may help you understand the problem better:

// We want to transform this BST into a circular doubly linked list. Each node in a doubly linked list has a predecessor and successor. For a circular doubly linked list, the predecessor of the first element is the last element, and the successor of the last element is the first element.

// The figure below shows the circular doubly linked list for the BST above. The "head" symbol means the node it points to is the smallest element of the linked list.
 
// Specifically, we want to do the transformation in place. After the transformation, the left pointer of the tree node should point to its predecessor, and the right pointer should point to its successor. We should return the pointer to the first element of the linked list.

// The figure below shows the transformed BST. The solid line indicates the successor relationship, while the dashed line means the predecessor relationship.


// solution I: 中序遍历，递归
class Solution {
public:
    Node* treeToDoublyList(Node* root) {
        if (!root) 
        {
            return NULL;
        }

        Node *head = NULL, 
        Node *pre = NULL;

        inorder(root, pre, head);

        pre->right = head;
        head->left = pre;

        return head;
    }

    void inorder(Node* node, Node*& pre, Node*& head) 
    {
        if (!node) 
        {
            return;
        }

        inorder(node->left, pre, head);

        if (!head) 
        {
            head = node;
            pre = node;
        } 
        else 
        {
            pre->right = node;
            node->left = pre;
            pre = node;
        }

        inorder(node->right, pre, head);
    }
};

// solution II: 中序遍历，迭代
class Solution {
public:
    Node* treeToDoublyList(Node* root) {
        stack<Node*> stk;
        Node* p = root;
        Node* pre = NULL;
        Node* head = NULL;

        while (!stk.empty() || p)
        {
            while (p)
            {
                stk.push(p);
                p = p->left;
            }

            p = stk.top();
            stk.pop();

            // 和普通的中序迭代相比，多了pre和head的处理            
            if (!head)
            {
                head = p;
            }
            if (pre)
            {
                pre->right = p;
                p->left = pre;
            }
            pre = p;

            p = p->right;
        }

        // 还要连接头尾节点
        head->left = pre;
        pre->right = head;

        return head;
    }
}