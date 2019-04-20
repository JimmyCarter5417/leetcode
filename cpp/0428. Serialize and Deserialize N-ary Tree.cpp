// Serialization is the process of converting a data structure or object into a sequence of bits so that it can be stored in a file or memory buffer, or transmitted across a network connection link to be reconstructed later in the same or another computer environment.

// Design an algorithm to serialize and deserialize an N-ary tree. An N-ary tree is a rooted tree in which each node has no more than N children. There is no restriction on how your serialization/deserialization algorithm should work. You just need to ensure that an N-ary tree can be serialized to a string and this string can be deserialized to the original tree structure.

// For example, you may serialize the following 3-ary tree
 
// as [1 [3[5 6] 2 4]]. You do not necessarily need to follow this format, so please be creative and come up with different approaches yourself.

// Note:
// N is in the range of [1, 1000]
// Do not use class member/global/static variables to store states. Your serialize and deserialize algorithms should be stateless.


// 与c0297. Serialize and Deserialize Binary Tree相同
class Codec {
public:
    // Encodes a tree to a single string.
    string serialize(Node* root) {
        string res;
        serializeHelper(root, res);
        return res;
    }
    
    void serializeHelper(Node* node, string& res) 
    {
        if (!node) 
        {
            res += "# "; // 用空格分隔
        }
        else
        {
            res += to_string(node->val) + " " + to_string(node->children.size()) + " "; // 需要记录子节点个数

            for (auto child : node->children) 
            {
                serializeHelper(child, res);
            }
        }
    }

    // Decodes your encoded data to tree.
    Node* deserialize(string data) {
        istringstream iss(data);
        return deserializeHelper(iss);
    }
    
    Node* deserializeHelper(istringstream& iss) {
        string val = "";
        string size = "";

        iss >> val;
        if (val == "#") // 空节点
        {
            return NULL;
        }

        Node *node = new Node(stoi(val), {}); // 创建节点

        iss >> size; // 处理叶子节点
        for (int i = 0; i < stoi(size); ++i) 
        {
            node->children.push_back(deserializeHelper(iss));
        }

        return node;
    }
};