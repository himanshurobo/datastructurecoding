/*

Given a binary tree, check whether it is a mirror of itself (ie, symmetric around its center).

For example, this binary tree [1,2,2,3,4,4,3] is symmetric:

    1
   / \
  2   2
 / \ / \
3  4 4  3
 

But the following [1,2,2,null,3,null,3] is not:

    1
   / \
  2   2
   \   \
   3    3
 

Note:
Bonus points if you could solve it both recursively and iteratively.



WrittenBy : Himanshu Srivastava
Problem : Symmetric Tree
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
    bool isSymmetric(TreeNode* left, TreeNode* right){
        if(left == NULL && right == NULL)
            return true;
        
        if( ( left == NULL && right != NULL ) || (left != NULL && right == NULL))
            return false;
        if(left->val != right->val)
            return false;
        
        return ( isSymmetric(left->left,right->right) && isSymmetric(left->right,right->left));
    }
public:
    bool isSymmetric(TreeNode* root) {
        if(root == NULL)
            return true;
        return isSymmetric(root->left,root->right);
    }
};