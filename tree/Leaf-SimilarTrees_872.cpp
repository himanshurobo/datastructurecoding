/*

Consider all the leaves of a binary tree.  From left to right order, the values of those leaves form a leaf
 value sequence.



For example, in the given tree above, the leaf value sequence is (6, 7, 4, 9, 8).

Two binary trees are considered leaf-similar if their leaf value sequence is the same.

Return true if and only if the two given trees with head nodes root1 and root2 are leaf-similar.

 

Note:

Both of the given trees will have between 1 and 100 nodes.

WrittenBy : Himanshu Srivastava
Problem : Leaf-Similar Trees
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
    
    int dfs1(stack<TreeNode*>& s ){
        
        while(true){
            TreeNode* t = s.top();
            s.pop();
            
            if(t->right)
                s.push(t->right);
            
            if(t->left)
                s.push(t->left);
            
            if(!t->left && !t->right)
                return t->val;
            
        }
        
    }
    
public:
    bool leafSimilar1(TreeNode* root1, TreeNode* root2) {
        
        stack<TreeNode*> s1, s2;
        
        s1.push(root1);
        s2.push(root2);
        
        while(!s1.empty() && !s2.empty()){
            if(dfs1(s1) != dfs1(s2)){
                return false;
            }
        }
        
        return true;
        
    }

vector<int> leaves(TreeNode* root) {
        vector<int> result;
        stack<TreeNode*> s;
        s.push(root);
        while (!s.empty()) {
            auto* node = s.top();
            s.pop();
            if (node->right == nullptr && node->left == nullptr) {
                result.push_back(node->val);
            }

            if (node->right) {
                s.push(node->right);
            }
            if (node->left) {
                s.push(node->left);
            }
        }

        return result;
    }

    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        return leaves(root1) == leaves(root2);
    }
};
