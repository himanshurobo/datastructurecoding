/*

Given an array where elements are sorted in ascending order, convert it to a height balanced BST.

For this problem, a height-balanced binary tree is defined as a binary tree in which the depth of the two subtrees of every node never differ by more than 1.

Example:

Given the sorted array: [-10,-3,0,5,9],

One possible answer is: [0,-3,9,-10,null,5], which represents the following height balanced BST:

      0
     / \
   -3   9
   /   /
 -10  5


WrittenBy : Himanshu Srivastava
Problem : Convert Sorted Array to Binary Search Tree
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
    
    TreeNode* sortedArrayToBST( vector<int>& nums, int left, int right){
        
        if(right < left) 
            return NULL;
        
        int mid = left + (right-left)/2;
        
        TreeNode* root = new TreeNode(nums[mid]);
        cout<<root->val;
        root->left = sortedArrayToBST(nums,left,mid-1);
        root->right = sortedArrayToBST(nums,mid+1,right);
        
        return root;
        
        
    }
    
    
    
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {

        if( nums.empty())
            return NULL;
        
        if(nums.size() == 1){
            return new TreeNode(nums[0]);
        }

        return sortedArrayToBST(nums,0,nums.size()-1); 
        
        
    }
};