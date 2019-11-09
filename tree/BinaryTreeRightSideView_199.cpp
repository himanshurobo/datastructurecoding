/*

Given a binary tree, imagine yourself standing on the right side of it, return the values of the nodes you can see ordered from top to bottom.

Example:

Input: [1,2,3,null,5,null,4]
Output: [1, 3, 4]
Explanation:

   1            <---
 /   \
2     3         <---
 \     \
  5     4       <---



WrittenBy : Himanshu Srivastava
Problem : Binary Tree Right Side View
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
    vector<int> result;
    void rightSide( TreeNode* root,int level){
        if(root == NULL)
            return ;
         if(result.size() < level)
             result.push_back(root->val);
        
        rightSide(root->right,level+1);
        rightSide(root->left,level+1);
        
    }
public:
    vector<int> rightSideView(TreeNode* root) {
        rightSide(root,1);
        return result;
    }
};