/*
Serialization is the process of converting a data structure or object into a sequence of bits so that it can be stored in a file or memory buffer, or transmitted across a network connection link to be reconstructed later in the same or another computer environment.

Design an algorithm to serialize and deserialize a binary search tree. There is no restriction on how your serialization/deserialization algorithm should work. You just need to ensure that a binary search tree can be serialized to a string and this string can be deserialized to the original tree structure.

The encoded string should be as compact as possible.

Note: Do not use class member/global/static variables to store states. Your serialize and deserialize algorithms should be stateless.


Serialize and Deserialize BST
*/


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
    
    
    int stoint(string& data){
        
        int pos = data.find(',');
        int val = std::stoi(data.substr(0,pos));
        data = data.substr(pos+1);
        return val;
        
    }
    
    
    TreeNode* mydeserialize(string& data, int left, int right){
        if(data[0]=='#'){
            if(data.size() > 1) 
                data = data.substr(2);
            return NULL;
        }
        TreeNode* node = new TreeNode(stoint(data));

        node->left = mydeserialize(data,left,node->val);
        node->right = mydeserialize(data,node->val,right);
        
        return node;
                
    }
    
    
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(root == NULL)
            return "#";
        
        return to_string(root->val) + "," + serialize(root->left) + "," + serialize(root->right);
        
    }
    
    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        // cout<<data;
        // return NULL;
       return mydeserialize(data, INT_MIN, INT_MAX);
        
        
        
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));