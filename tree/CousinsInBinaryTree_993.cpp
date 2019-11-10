/*

In a binary tree, the root node is at depth 0, and children of each depth k node are at depth k+1.

Two nodes of a binary tree are cousins if they have the same depth, but have different parents.

We are given the root of a binary tree with unique values, and the values x and y of two different nodes in 
the tree.

Return true if and only if the nodes corresponding to the values x and y are cousins.

 

Example 1:


Input: root = [1,2,3,4], x = 4, y = 3
Output: false
Example 2:


Input: root = [1,2,3,null,4,null,5], x = 5, y = 4
Output: true
Example 3:



Input: root = [1,2,3,null,4], x = 2, y = 3
Output: false
 

Note:

The number of nodes in the tree will be between 2 and 100.
Each node has a unique integer value from 1 to 100.

WrittenBy : Himanshu Srivastava
Problem : Cousins in Binary Tree
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
    bool isCousins(TreeNode* root, int x, int y) {
        
        if( root == NULL){
            return false;
        }
        
        queue<TreeNode*> q;
        q.push(root);
               
        while(!q.empty()){
            
            bool isX = false;
            bool isY = false;
            
            int n = q.size();
        
            
            for( int i = 0 ; i < n ;i++){
                
                TreeNode* r =  q.front();
                q.pop();
            
                if(r->val == x) isX = true;
                if(r->val == y) isY = true;
                                
                if(r->left != NULL && r->right != NULL ){
                    if(r->left->val == x && r->right->val == y)
                       return false;
                
                    if(r->right->val == x && r->left->val == y)
                        return false;
                }
                
                
                if( r->left != NULL){
                    q.push(r->left);
                }
                
                if(r->right != NULL){
                    q.push(r->right);
                }
                                                                
                
                
            }
            
            if(isX && isY )
                return true;                        
        }
                
        return false;
        
        
    }
};