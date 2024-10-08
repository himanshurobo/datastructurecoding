/*
Given the root node of a binary search tree, return the sum of values of all nodes with value between
 L and R (inclusive).

The binary search tree is guaranteed to have unique values.

 

Example 1:

Input: root = [10,5,15,3,7,null,18], L = 7, R = 15
Output: 32
Example 2:

Input: root = [10,5,15,3,7,13,18,1,null,6], L = 6, R = 10
Output: 23
 

Note:

The number of nodes in the tree is at most 10000.
The final answer is guaranteed to be less than 2^31.

WrittenBy : Himanshu Srivastava
Problem : Range Sum of BST
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
    int sum_ = 0;
     
public:
    int rangeSumBST1(TreeNode* root, int L, int R) {
        
        if( root == NULL ){
            return 0;
        }
        int sum = 0;
        if( root->val >= L && root->val <= R){
            sum += root->val;
        }
        
        if( root->val > L ){
            sum += rangeSumBST(root->left, L,R) ;
        }
        
         if( root->val < R ){
            sum += rangeSumBST(root->right, L,R) ;
        }        
        
        return sum;
    }

      int rangeSumBST(TreeNode* root, int L, int R) {
        
        if( root == NULL ){
            return 0;
        }

        if( root->val >= L && root->val <= R){
            sum_ += root->val;
        }
        
        rangeSumBST(root->left, L,R) ;
        
        
        rangeSumBST(root->right, L,R) ;
                
        
        return sum;
    
    }
};