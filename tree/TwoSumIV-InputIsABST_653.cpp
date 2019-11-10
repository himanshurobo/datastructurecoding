/*
Given a Binary Search Tree and a target number, return true if there exist two elements in the BST
 such that their sum is equal to the given target.

Example 1:

Input: 
    5
   / \
  3   6
 / \   \
2   4   7

Target = 9

Output: True
 

Example 2:

Input: 
    5
   / \
  3   6
 / \   \
2   4   7

Target = 28

Output: False


WrittenBy : Himanshu Srivastava
Problem : Two Sum IV - Input is a BST
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
    
    unordered_map<int,bool> hash;
public:
    bool findTarget(TreeNode* root, int k) {
        
        if(root == NULL){
            return false;
        }
        
        if(hash.find(root->val) != hash.end()){
            return true;
        }
        
        hash[k-root->val] = true;
        
        
        return findTarget(root->left,k) || findTarget(root->right,k);
        
        
    }
};