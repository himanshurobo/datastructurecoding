/*

Given a binary search tree with non-negative values, find the minimum absolute difference between values of any two nodes.

Example:

Input:

   1
    \
     3
    /
   2

Output:
1

Explanation:
The minimum absolute difference is 1, which is the difference between 2 and 1 (or between 2 and 3).
 

Note: There are at least two nodes in this BST.



WrittenBy : Himanshu Srivastava
Problem : Minimum Absolute Difference in BST
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
    
    int val = -1;
    int minVal = INT_MAX;
    
public:
    int getMinimumDifference(TreeNode* root) {
                
        if( root->left != NULL)  getMinimumDifference(root->left);
        
        
        if( val >= 0 ) minVal = min(minVal, root->val-val);            
        val = root->val;
        
        if(root->right != NULL)  getMinimumDifference(root->right);
        
        return minVal;
    }
    
    
};