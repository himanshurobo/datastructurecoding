/*
Given a binary tree, return the preorder traversal of its nodes' values.

Example:

Input: [1,null,2,3]
   1
    \
     2
    /
   3

Output: [1,2,3]
Follow up: Recursive solution is trivial, could you do it iteratively?



WrittenBy : Himanshu Srivastava
Problem : Binary Tree Preorder Traversal
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
    vector<int> result;
    
    void preorderTraversl(TreeNode* root){
        
        if(root ==  NULL)
            return;
        
        result.push_back(root->val);
        preorderTraversal(root->left);
        preorderTraversal(root->right);
    }
    
public:
    vector<int> preorderTraversal(TreeNode* root) {
        
        preorderTraversl(root);
        return result;
        
    }
};