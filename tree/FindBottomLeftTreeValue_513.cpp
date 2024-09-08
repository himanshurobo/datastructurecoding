/*
Given a binary tree, find the leftmost value in the last row of the tree.

Example 1:
Input:

    2
   / \
  1   3

Output:
1
Example 2:
Input:

        1
       / \
      2   3
     /   / \
    4   5   6
       /
      7

Output:
7



WrittenBy : Himanshu Srivastava
Problem : Find Bottom Left Tree Value
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
    int depth = 0;
    int leftMost = 0;
    
    void findBottomLeftVlue1(TreeNode* root, int level){
        
        if(depth < level){            
            leftMost = root->val;
            depth = level;
        }
        
        if(root->left != NULL){
            findBottomLeftVlue1(root->left,level+1);
        }
        
         if(root->right != NULL){
            findBottomLeftVlue1(root->right,level+1);
        }
            
    }
    
public:
    int findBottomLeftValue1(TreeNode* root) {
        findBottomLeftVlue1(root,1);
        return leftMost;
    }

int findBottomLeftValue(TreeNode* root) {
        if (root == NULL) {
            return -1; // Return a default value if the tree is empty
        }
        
        queue<TreeNode*> q;
        q.push(root);
        
        int bottomLeftValue = root->val; // Initialize with the root value
        
        while (!q.empty()) {
            int levelSize = q.size();
            
            // Traverse the current level
            for (int i = 0; i < levelSize; ++i) {
                TreeNode* node = q.front();
                q.pop();
                
                // The first node in the current level is the leftmost node
                if (i == 0) {
                    bottomLeftValue = node->val;
                }
                
                if (node->left != NULL) {
                    q.push(node->left);
                }
                if (node->right != NULL) {
                    q.push(node->right);
                }
            }
        }
        
        return bottomLeftValue;
    }


};
