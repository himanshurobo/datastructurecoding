/*

Given a binary tree, you need to compute the length of the diameter of the tree. The diameter of a binary tree is the length of the longest path between any two nodes in a tree. This path may or may not pass through the root.

Example:
Given a binary tree
          1
         / \
        2   3
       / \     
      4   5    
Return 3, which is the length of the path [4,2,1,3] or [5,2,1,3].

Note: The length of path between two nodes is represented by the number of edges between them.



WrittenBy : Himanshu Srivastava
Problem : Diameter of Binary Tree
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
    int diameter = 0;
    int maxDepth(TreeNode* root){
        
        if(root == NULL)
            return 0;
        
        int left =  maxDepth(root->left);
        int right = maxDepth(root->right);
        
        diameter = std::max(diameter, left+right);
        
        return std::max(left,right) +1;
        
        
    }
public:
    int diameterOfBinaryTree(TreeNode* root) {
        
        maxDepth(root);
        return diameter;
        
    }
};