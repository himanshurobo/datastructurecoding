/*
Given a root node reference of a BST and a key, delete the node with the given key in the BST.
 Return the root node reference (possibly updated) of the BST.

Basically, the deletion can be divided into two stages:

Search for a node to remove.
If the node is found, delete the node.
Note: Time complexity should be O(height of tree).

Example:

root = [5,3,6,2,4,null,7]
key = 3

    5
   / \
  3   6
 / \   \
2   4   7

Given key to delete is 3. So we find the node with value 3 and delete it.

One valid answer is [5,4,6,2,null,null,7], shown in the following BST.

    5
   / \
  4   6
 /     \
2       7

Another valid answer is [5,2,6,null,4,null,7].

    5
   / \
  2   6
   \   \
    4   7

Delete Node in a BST
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
    
    TreeNode* findMinNode(TreeNode* root){
        if(root->left)
            return findMinNode(root->left);
        
        return root;
    }
    
    
    
    
public:

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
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (root == nullptr) {
            return root; // If the tree is empty or the node is not found
        }

        // Traverse the tree to find the node to delete
        if (key < root->val) {
            root->left = deleteNode(root->left, key); // Go left
        } else if (key > root->val) {
            root->right = deleteNode(root->right, key); // Go right
        } else {
            // Node to be deleted found
            // Case 1: Node has no children (leaf node) or one child
            if (root->left == nullptr) {
                TreeNode* temp = root->right;
                delete root;
                return temp;
            } else if (root->right == nullptr) {
                TreeNode* temp = root->left;
                delete root;
                return temp;
            }

            // Case 2: Node has two children
            // Find the inorder successor (smallest in the right subtree)
            TreeNode* successor = findMinNode(root->right);
            root->val = successor->val; // Replace the node's value with successor's value
            // Delete the successor
            root->right = deleteNode(root->right, successor->val);
        }

        return root; // Return the updated root
    }

private:
    // Helper function to find the minimum value node in a tree
    TreeNode* findMin(TreeNode* node) {
        while (node->left != nullptr) {
            node = node->left; // Keep going left
        }
        return node;
    }
};

    TreeNode*   (TreeNode* root, int key) {
        
        if(root == NULL){
            return NULL;
        }
        
        
        if(root->val > key){
            root->left = deleteNode(root->left,key);
        }else if( root->val < key){
            root->right = deleteNode(root->right,key);
        }else{
            if(!root->right){
                TreeNode* left = root->left;
                delete root;
                return left;
            }else{
                
                TreeNode* successor = findMinNode(root->right);
                root->val = successor->val;
                root->right = deleteNode(root->right, successor->val);
            }
        }
        return root;       
    }
};
