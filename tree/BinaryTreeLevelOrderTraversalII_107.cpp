/*

Given a binary tree, return the bottom-up level order traversal of its nodes' values. (ie, from left to right, level by level from leaf to root).

For example:
Given binary tree [3,9,20,null,null,15,7],
    3
   / \
  9  20
    /  \
   15   7
return its bottom-up level order traversal as:
[
  [15,7],
  [9,20],
  [3]
]



WrittenBy : Himanshu Srivastava
Problem : Binary Tree Level Order Traversal II
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
    
    void levelOrder( TreeNode* root,vector<vector<int>> &result,int level){
        
        if(root == NULL)
            return ;
        
        if(result.empty() || result.size() -1  < level){
            result.push_back(vector<int> ());
        }
        
        result[level].push_back(root->val);
        
        levelOrder(root->left,result,level+1);
        levelOrder(root->right,result,level+1);
                
    }
    
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        
        vector<vector<int>> result;

        levelOrder(root,result,0);
        
        reverse(result.rbegin(),result.rend());
        
        return result;
    }
};