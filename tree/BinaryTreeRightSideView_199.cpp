/*

Given a binary tree, imagine yourself standing on the right side of it, return the values of the nodes you 
can see ordered from top to bottom.

Example:

Input: [1,2,3,null,5,null,4]
Output: [1, 3, 4]
Explanation:

   1            <---
 /   \
2     3         <---
 \     \
  5     4       <---



WrittenBy : Himanshu Srivastava
Problem : Binary Tree Right Side View
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
    void rightSide( TreeNode* root,int level){
        if(root == NULL)
            return ;
         if(result.size() < level)
             result.push_back(root->val);
        
        rightSide(root->right,level+1);
        rightSide(root->left,level+1);
        
    }

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> result;
        if (root == nullptr) {
            return result; // Return empty if tree is empty
        }

        queue<TreeNode*> q; // Queue for level-order traversal
        q.push(root);

        while (!q.empty()) {
            int levelSize = q.size(); // Number of nodes at the current level
            TreeNode* lastNode = nullptr;

            for (int i = 0; i < levelSize; ++i) {
                TreeNode* currentNode = q.front();
                q.pop();

                // Keep track of the last node in the current level
                lastNode = currentNode;

                // Add left and right children to the queue for the next level
                if (currentNode->left) {
                    q.push(currentNode->left);
                }
                if (currentNode->right) {
                    q.push(currentNode->right);
                }
            }

            // Add the last node's value from the current level to the result
            if (lastNode) {
                result.push_back(lastNode->val);
            }
        }

        return result;
    }
};

public:
    vector<int> rightSideView(TreeNode* root) {
        rightSide(root,1);
        return result;
    }
};
