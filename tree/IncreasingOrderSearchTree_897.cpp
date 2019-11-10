/*
Given a binary search tree, rearrange the tree in in-order so that the leftmost node in the tree is now 
the root of the tree, and every node has no left child and only 1 right child.

Example 1:
Input: [5,3,6,2,4,null,8,1,null,null,null,7,9]

       5
      / \
    3    6
   / \    \
  2   4    8
 /        / \ 
1        7   9

Output: [1,null,2,null,3,null,4,null,5,null,6,null,7,null,8,null,9]

 1
  \
   2
    \
     3
      \
       4
        \
         5
          \
           6
            \
             7
              \
               8
                \
                 9  
Note:

The number of nodes in the given tree will be between 1 and 100.
Each node will have a unique integer value from 0 to 1000.


WrittenBy : Himanshu Srivastava
Problem : Increasing Order Search Tree
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
    TreeNode* increasingBST(TreeNode* root, TreeNode* pre=NULL) {
        
        // # if this null node was a left child, tail is its parent
        // # if this null node was a right child, tail is its parent's parent
        if(root == NULL){
            return pre;
        }
        
        // # recursive call, traversing left while passing in the current node as tail
       TreeNode* res = increasingBST(root->left,root);
        
         // # we don't want the current node to have a left child, only a single right child
       root->left = NULL;
        
        //         # we set the current node's right child to be tail
        // # what is tail? this part is important
        // # if the current node is a left child, tail will be its parent
        // # else if the current node is a right child, tail will be its parent's parent
       root->right = increasingBST(root->right,pre);
        
        
        // # throughout the whole algorithm, res is the leaf of the leftmost path in the original tree
        // # its the smallest node and thus will be the root of the modified tree
       return res;
        
    }
};