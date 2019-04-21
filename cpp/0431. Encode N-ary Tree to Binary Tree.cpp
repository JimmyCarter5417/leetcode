// Design an algorithm to encode an N-ary tree into a binary tree and decode the binary tree to get the original N-ary tree. An N-ary tree is a rooted tree in which each node has no more than N children. Similarly, a binary tree is a rooted tree in which each node has no more than 2 children. There is no restriction on how your encode/decode algorithm should work. You just need to ensure that an N-ary tree can be encoded to a binary tree and this binary tree can be decoded to the original N-nary tree structure.

// For example, you may encode the following 3-ary tree to a binary tree in this way:
// Note that the above is just an example which might or might not work. You do not necessarily need to follow this format, so please be creative and come up with different approaches yourself.

// Note:

// N is in the range of [1, 1000]
// Do not use class member/global/static variables to store states. Your encode and decode algorithms should be stateless.


// 与Serialize and Deserialize N-ary Tree有点关系
class Codec {
// 编码方案：将每个节点的第一个子节点，放到二叉树的左子节点，后面的子节点，依次挂到右子节点组成的链上

// N-ary Tree:
//       1
//    /  |  \
//   3   2   4
//  / \
// 5   6

// Binary Tree:
//     1
//    /
//   3
//  / \
// 5   2
//  \   \
//   6   4
public:
    // Encodes an n-ary tree to a binary tree.
    TreeNode* encode(Node* root) {
        if (!root)
        {
            return NULL;
        }

        TreeNode *res = new TreeNode(root->val);

        if (!root->children.empty()) 
        {
            res->left = encode(root->children[0]);
        }

        TreeNode *cur = res->left; // 一律挂到左边
        for (int i = 1; i < root->children.size(); ++i) 
        {
            cur->right = encode(root->children[i]);
            cur = cur->right; // 一律挂到右边
        }

        return res;
    }

    // Decodes your binary tree to an n-ary tree.
    Node* decode(TreeNode* root) {
        if (!root)
        {
            return NULL;
        }

        Node *res = new Node(root->val, {});
        TreeNode *cur = root->left; // 先从左边取第一个节点

        while (cur) 
        {
            res->children.push_back(decode(cur));
            cur = cur->right; // 一直从右边取后续节点
        }

        return res;
    }
};