/*
Given a binary tree and a sum, find all root-to-leaf paths where each path's sum equals the given sum.

Note: A leaf is a node with no children.

Example:

Given the below binary tree and sum = 22,

      5
     / \
    4   8
   /   / \
  11  13  4
 /  \    / \
7    2  5   1
Return:

[
   [5,4,11,2],
   [5,8,4,5]
]



WrittenBy : Himanshu Srivastava
Problem : Path Sum II
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
    
  void findPathSum( TreeNode* root, int sum, vector<int>& path, vector<vector<int>>& paths){
      
      if(!root) return ;
      
      path.push_back(root->val);
                
      if(root->val == sum && !root->left && !root->right  )
          paths.push_back(path);
      
      findPathSum(root->left, sum-root->val,path,paths);
      findPathSum(root->right, sum-root->val,path,paths);
      path.pop_back();
      
  } 
    
public:
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        
        vector<vector<int>> paths;
        vector<int> path;
        findPathSum(root,sum,path,paths);
        
        return paths;
        
    }
    
    
};