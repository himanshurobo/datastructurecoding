/*

Given a binary tree, return the zigzag level order traversal of its nodes' values. (ie, from left to right, then right to left for the next level and alternate between).

For example:
Given binary tree [3,9,20,null,null,15,7],
    3
   / \
  9  20
    /  \
   15   7
return its zigzag level order traversal as:
[
  [3],
  [20,9],
  [15,7]
]



WrittenBy : Himanshu Srivastava
Problem : Binary Tree Zigzag Level Order Traversal
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
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
       
        if(root == NULL){
            return vector<vector<int>> ();
        }
        
        queue<TreeNode*> q;
        vector<vector<int>> result;
        
        bool leftToRight = true;
        
        q.push(root);
        
        while(!q.empty()){
            int size = q.size();
            vector<int> res(size);
           
            for( int i = 0 ; i < size ; i++){
                TreeNode* node = q.front();
                q.pop();
                
                int index = leftToRight ? i : size-1-i;
                
                res[index] = node->val;
                
                if(node->left)
                    q.push(node->left);
                if(node->right)
                    q.push(node->right);
                                
            }
            
            leftToRight = !leftToRight;
            result.push_back(res);
            
        }
        
        return result;
        
    }
};