/*

Given a binary tree, determine if it is a valid binary search tree (BST).

Assume a BST is defined as follows:

The left subtree of a node contains only nodes with keys less than the node's key.
The right subtree of a node contains only nodes with keys greater than the node's key.
Both the left and right subtrees must also be binary search trees.
 

Example 1:

    2
   / \
  1   3

Input: [2,1,3]
Output: true
Example 2:

    5
   / \
  1   4
     / \
    3   6

Input: [5,1,4,null,null,3,6]
Output: false
Explanation: The root node's value is 5 but its right child's value is 4.





WrittenBy : Himanshu Srivastava
Problem : Validate Binary Search Tree
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
    
    bool isValidBST( TreeNode* root, TreeNode* minNode, TreeNode* maxNode){
        if(root == NULL)
            return true;
        
        if(minNode && minNode->val >= root->val || maxNode && maxNode->val <= root->val)
            return false;
            
        return isValidBST(root->left,minNode,root) && isValidBST(root->right,root,maxNode);
    }
public:
    bool isValidBST(TreeNode* root) {
       
               
        return isValidBST(root,NULL,NULL);
        
    }
};