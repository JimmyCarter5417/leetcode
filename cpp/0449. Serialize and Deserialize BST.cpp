// Serialization is the process of converting a data structure or object into a sequence of bits so that it can be stored in a file or memory buffer, or transmitted across a network connection link to be reconstructed later in the same or another computer environment.

// Design an algorithm to serialize and deserialize a binary search tree. There is no restriction on how your serialization/deserialization algorithm should work. You just need to ensure that a binary search tree can be serialized to a string and this string can be deserialized to the original tree structure.

// The encoded string should be as compact as possible.

// Note: Do not use class member/global/static variables to store states. Your serialize and deserialize algorithms should be stateless.


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        ostringstream oss;       
        serializeHelper(root, oss);        
        return oss.str();
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        istringstream iss(data);
        return deserializeHelper(iss);
    }
    
    void serializeHelper(TreeNode* root, ostringstream& oss)
    {
        if (!root)
        {
            oss << "# ";
            return;
        }
        
        oss << to_string(root->val) << " ";
        
        serializeHelper(root->left, oss);
        serializeHelper(root->right, oss);
    }
    
    TreeNode* deserializeHelper(istringstream& iss)
    {
        string str;
        iss>>str;
        
        if (str == "#")
        {
            return NULL;
        }
        
        TreeNode* root = new TreeNode(stoi(str));
        root->left = deserializeHelper(iss);
        root->right = deserializeHelper(iss);
        
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));