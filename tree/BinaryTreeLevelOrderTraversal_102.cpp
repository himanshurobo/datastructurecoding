/*
Given a binary tree, return the level order traversal of its nodes' values. (ie, from left to right, level by level).

For example:
Given binary tree [3,9,20,null,null,15,7],
    3
   / \
  9  20
    /  \
   15   7
return its level order traversal as:
[
  [3],
  [9,20],
  [15,7]
]



WrittenBy : Himanshu Srivastava
Problem : Binary Tree Level Order Traversal
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
    vector<vector<int>> result;
    
    void levelOrder(TreeNode* root,int level){
        if(root == NULL)
            return ;
        if(result.size() <= level)
            result.push_back(vector<int>());
            
        result[level++].push_back(root->val);
        
        levelOrder(root->left,level);
        levelOrder(root->right,level);
        
    }
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        levelOrder(root,0);
        return result;
    }
};