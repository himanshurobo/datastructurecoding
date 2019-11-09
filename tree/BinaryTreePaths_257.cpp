/*
Given a binary tree, return all root-to-leaf paths.

Note: A leaf is a node with no children.

Example:

Input:

   1
 /   \
2     3
 \
  5

Output: ["1->2->5", "1->3"]

Explanation: All root-to-leaf paths are: 1->2->5, 1->3



WrittenBy : Himanshu Srivastava
Problem : Binary Tree Paths
TimeComplexity : O(n)

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
class Solution {
    
    vector<string> result;
    
    void binaryTreePath(TreeNode* root,string s){
        
        if(root == NULL)
            return ;
        
        if(root->left == NULL && root->right == NULL){
            result.push_back(s);
            return ;
        }
        
        if(root->left)
            binaryTreePath(root->left,s + "->" + to_string(root->left->val));
        if(root->right)
            binaryTreePath(root->right,s + "->" + to_string(root->right->val));
        
       
    }
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        if(root == NULL)
            return result;
        binaryTreePath(root,to_string(root->val));
        return result;
    }
};