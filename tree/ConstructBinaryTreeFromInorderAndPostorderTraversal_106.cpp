/*

Given inorder and postorder traversal of a tree, construct the binary tree.

Note:
You may assume that duplicates do not exist in the tree.

For example, given

inorder = [9,3,15,20,7]
postorder = [9,15,7,20,3]
Return the following binary tree:

    3
   / \
  9  20
    /  \
   15   7


WrittenBy : Himanshu Srivastava
Problem : Construct Binary Tree from Inorder and Postorder Traversal
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
    
    TreeNode* createTree( vector<int>& inorder,int is,int ie, vector<int>& postorder, int ps, int pe){
        
        if(ps > pe)
            return NULL;
        
        TreeNode* node = new TreeNode(postorder[pe]);
        int index;
        for(int i = is ; i <=ie;i++){
            if(postorder[pe] == inorder[i]){
                index = i;
                break;
            }
        }
        
        node->left = createTree( inorder,is,index-1, postorder,ps, ps + ( index - is ) -1 );
        node->right = createTree( inorder,index+1,ie, postorder, pe - ( ie - index), pe-1);
        return node;
        
        
    }
    
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        return createTree( inorder,0,inorder.size()-1,postorder,0,postorder.size()-1);
    }
};
