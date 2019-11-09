/*

You need to find the largest value in each row of a binary tree.

Example:
Input: 

          1
         / \
        3   2
       / \   \  
      5   3   9 

Output: [1, 3, 9]




WrittenBy : Himanshu Srivastava
Problem : Find Largest Value in Each Tree Row
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
    
    void largetValue(TreeNode* root, int level){
        if(root == NULL){ 
             return;
        }
        
        if( result.size() < level)
            result.push_back(root->val);
            
        result[level-1] =  std::max( result[level-1],root->val);
        
        largetValue(root->left,level+1);
        largetValue(root->right,level+1);
  
        
    }
    
public:
    vector<int> largestValues(TreeNode* root) {

        largetValue(root,1);
        return result;
    }
};