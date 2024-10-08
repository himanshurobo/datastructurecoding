/*
Given a complete binary tree, count the number of nodes.

Note:

Definition of a complete binary tree from Wikipedia:
In a complete binary tree every level, except possibly the last, is completely filled, and all nodes in the
 last level are as far left as possible. It can have between 1 and 2h nodes inclusive at the last level h.

Example:

Input: 
    1
   / \
  2   3
 / \  /
4  5 6

Output: 6


WrittenBy : Himanshu Srivastava
Problem : Count Complete Tree Nodes
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
    int count = 0 ;
    void countNode(TreeNode* root){
        
        if(root == NULL )
            return ;
        
        if( root->left == NULL && root->right == NULL){
            count++;
            return ;
        }
        
        if(root->left != NULL || root->right != NULL)
            count++;
        
        countNode(root->left);
        countNode(root->right);
    }
public:
    int countNodes(TreeNode* root) {
        countNode(root);
        return count;
    }
};