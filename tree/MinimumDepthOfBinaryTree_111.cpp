/*

Given a binary tree, find its minimum depth.

The minimum depth is the number of nodes along the shortest path from the root node down to the nearest 
leaf node.

Note: A leaf is a node with no children.

Example:

Given binary tree [3,9,20,null,null,15,7],

    3
   / \
  9  20
    /  \
   15   7
return its minimum depth = 2.



WrittenBy : Himanshu Srivastava
Problem : Minimum Depth of Binary Tree
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
public:
    int minDepth1(TreeNode* root) {
        
        if(!root){
            return 0;
        }
        
       if(!root->left) 
           return minDepth(root->right) + 1;
        
        if(!root->right)
            return minDepth(root->left) + 1;
        
           
        
        return min(minDepth(root->left),minDepth(root->right))+1;
        
    }

    int minDepth(TreeNode* root){
        
        if( root == NULL){
            return 0;
        }
        
        int left = minDepth(root->left);
        int right = minDepth( root->right);
        
        return (left==0) || ( right == 0) ? left+right+1: min(left,right)+1;
        
    }
    


};