/*

Given a binary tree, return the postorder traversal of its nodes' values.

Example:

Input: [1,null,2,3]
   1
    \
     2
    /
   3

Output: [3,2,1]
Follow up: Recursive solution is trivial, could you do it iteratively?



WrittenBy : Himanshu Srivastava
Problem : Binary Tree Postorder Traversal
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
    
    void postOrderTraversal( TreeNode* root){
        
        if( root == NULL){
            return ;
        }
        
        postOrderTraversal( root->left );
        postOrderTraversal( root->right);
        
        result.push_back(root->val);
        
    }
public:
    vector<int> postorderTraversal(TreeNode* root) {
        postOrderTraversal(root);
        return result;
    }
};