/*


Two elements of a binary search tree (BST) are swapped by mistake.

Recover the tree without changing its structure.

Example 1:

Input: [1,3,null,null,2]

   1
  /
 3
  \
   2

Output: [3,1,null,null,2]

   3
  /
 1
  \
   2
Example 2:

Input: [3,1,4,null,null,2]

  3
 / \
1   4
   /
  2

Output: [2,1,4,null,null,3]

  2
 / \
1   4
   /
  3
Follow up:

A solution using O(n) space is pretty straight forward.
Could you devise a constant space solution?



WrittenBy : Himanshu Srivastava
Problem : Recover Binary Search Tree
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
    
    TreeNode* first = NULL;
    TreeNode* second = NULL;
    TreeNode* pre = new TreeNode(INT_MIN);
    
    void recover( TreeNode* root){
        
        if(root){
        
            recover(root->left);
            
            if(first == NULL && root->val <= pre->val){
                first = pre;
            }
            
            if(first != NULL && pre->val >= root->val){
                second = root;
            }
            
            pre = root;
            
            recover(root->right);
                    
        }
        
        
    }
    
public:
    void recoverTree(TreeNode* root) {
        
        recover(root);
        
        int temp = first->val;
        first->val = second->val;
        second->val = temp;
        
    }
};