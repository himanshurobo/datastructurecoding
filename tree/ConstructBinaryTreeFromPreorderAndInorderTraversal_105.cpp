/*

Given preorder and inorder traversal of a tree, construct the binary tree.

Note:
You may assume that duplicates do not exist in the tree.

For example, given

preorder = [3,9,20,15,7]
inorder = [9,3,15,20,7]
Return the following binary tree:

    3
   / \
  9  20
    /  \
   15   7



WrittenBy : Himanshu Srivastava
Problem : Construct Binary Tree from Preorder and Inorder Traversal
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
    
    TreeNode* createTree( vector<int>& preorder, int ps, int pe, vector<int>& inorder, int is, int ie){
        if(ps > pe)
            return NULL;
        
        TreeNode* node = new TreeNode(preorder[ps]);
        int index ;
        for( int i = is ; i <= ie;i++){
            if(inorder[i] == preorder[ps]){
                index = i;
                break;
            }
                
        }

        node->left = createTree( preorder,ps+1,ps+index - is , inorder, is,index-1);
        node->right = createTree( preorder,pe - ie + index + 1,pe, inorder, index+1,ie);
        return node;
        
    }
    
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        
        return createTree(preorder,0,preorder.size()-1,inorder,0,inorder.size()-1);
        
    }
};