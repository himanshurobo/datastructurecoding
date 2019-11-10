/*
Given a binary tree, determine if it is height-balanced.

For this problem, a height-balanced binary tree is defined as:

a binary tree in which the left and right subtrees of every node differ in height by no more than 1.

 

Example 1:

Given the following tree [3,9,20,null,null,15,7]:

    3
   / \
  9  20
    /  \
   15   7
Return true.

Example 2:

Given the following tree [1,2,2,3,3,null,null,4,4]:

       1
      / \
     2   2
    / \
   3   3
  / \
 4   4
Return false.



WrittenBy : Himanshu Srivastava
Problem : Balanced Binary Tree
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
    
    int height( TreeNode* root){
        
        if( !root ){
            return 0;
        }
        
        int hL = height(root->left) + 1;
        int hR = height(root->right) + 1 ;
        
        if(hL > hR){
            return hL;
        }else{
            return hR;
        }
        
    }
    
    bool isBalanced(TreeNode* root) {
        
        if( !root){
            return true;
        }
        
        int hL = height(root->left);
        int hR = height(root->right);
        
        return abs(hL-hR) <= 1 && isBalanced(root->left) && isBalanced(root->right) ;
        
    }
};