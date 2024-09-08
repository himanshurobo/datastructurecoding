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
    
    void largetValue1(TreeNode* root, int level){
        if(root == NULL){ 
             return;
        }
        
        if( result.size() < level)
            result.push_back(root->val);
            
        result[level-1] =  std::max( result[level-1],root->val);
        
        largetValue1(root->left,level+1);
        largetValue1(root->right,level+1);
  
        
    }
    
public:
    vector<int> largestValues1(TreeNode* root) {

        largetValue1(root,1);
        return result;
    }

 vector<int> largestValues(TreeNode* root) {
        vector<int> result;
        if (root == nullptr) {
            return result; // Return empty if the tree is empty
        }
        
        queue<TreeNode*> q;
        q.push(root);
        
        while (!q.empty()) {
            int levelSize = q.size();  // Number of nodes at the current level
            int maxVal = INT_MIN;     // Initialize to the smallest possible integer
            
            for (int i = 0; i < levelSize; ++i) {
                TreeNode* node = q.front();
                q.pop();
                
                maxVal = max(maxVal, node->val);  // Update maxVal
                
                if (node->left != nullptr) {
                    q.push(node->left);
                }
                if (node->right != nullptr) {
                    q.push(node->right);
                }
            }
            
            result.push_back(maxVal);  // Add the largest value of the current level to the result
        }
        
        return result;
    }
};
