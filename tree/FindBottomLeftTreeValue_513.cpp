/*
Given a binary tree, find the leftmost value in the last row of the tree.

Example 1:
Input:

    2
   / \
  1   3

Output:
1
Example 2:
Input:

        1
       / \
      2   3
     /   / \
    4   5   6
       /
      7

Output:
7



WrittenBy : Himanshu Srivastava
Problem : Find Bottom Left Tree Value
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
    int depth = 0;
    int leftMost = 0;
    
    void findBottomLeftVlue(TreeNode* root, int level){
        
        if(depth < level){            
            leftMost = root->val;
            depth = level;
        }
        
        if(root->left != NULL){
            findBottomLeftVlue(root->left,level+1);
        }
        
         if(root->right != NULL){
            findBottomLeftVlue(root->right,level+1);
        }
            
    }
    
public:
    int findBottomLeftValue(TreeNode* root) {
        findBottomLeftVlue(root,1);
        return leftMost;
    }
};