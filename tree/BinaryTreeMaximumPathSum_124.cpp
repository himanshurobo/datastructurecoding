/*
Given a non-empty binary tree, find the maximum path sum.

For this problem, a path is defined as any sequence of nodes from some starting node to any node in the tree 
along the parent-child connections. The path must contain at least one node and does not need to go through
 the root.

Example 1:

Input: [1,2,3]

       1
      / \
     2   3

Output: 6
Example 2:

Input: [-10,9,20,null,null,15,7]

   -10
   / \
  9  20
    /  \
   15   7

Output: 42



WrittenBy : Himanshu Srivastava
Problem : Binary Tree Maximum Path Sum
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
    
    int maxValue ;
    
    int maxSum(TreeNode* root){
        
        if(root == NULL){
            return 0;
        }
        
        int left = max(0,maxSum(root->left));
        int right = max(0,maxSum(root->right));
        
        maxValue = max( maxValue, left + right + root->val);
        
        return max(left,right) + root->val;
        
    }
    
public:
    int maxPathSum(TreeNode* root) {
        maxValue = INT_MIN;
         maxSum(root);
        return maxValue;
    }
};