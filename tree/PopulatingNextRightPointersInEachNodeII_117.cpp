/*
Given a binary tree

struct Node {
  int val;
  Node *left;
  Node *right;
  Node *next;
}
Populate each next pointer to point to its next right node. If there is no next right node, the next pointer should be set to NULL.

Initially, all next pointers are set to NULL.

 

Example:



Input: {"$id":"1","left":{"$id":"2","left":{"$id":"3","left":null,"next":null,"right":null,"val":4},"next":null,"right":{"$id":"4","left":null,"next":null,"right":null,"val":5},"val":2},"next":null,"right":{"$id":"5","left":null,"next":null,"right":{"$id":"6","left":null,"next":null,"right":null,"val":7},"val":3},"val":1}

Output: {"$id":"1","left":{"$id":"2","left":{"$id":"3","left":null,"next":{"$id":"4","left":null,"next":{"$id":"5","left":null,"next":null,"right":null,"val":7},"right":null,"val":5},"right":null,"val":4},"next":{"$id":"6","left":null,"next":null,"right":{"$ref":"5"},"val":3},"right":{"$ref":"4"},"val":2},"next":null,"right":{"$ref":"6"},"val":1}

Explanation: Given the above binary tree (Figure A), your function should populate each next pointer to point to its next right node, just like in Figure B.
 

Note:

You may only use constant extra space.
Recursive approach is fine, implicit stack space does not count as extra space for this problem.



WrittenBy : Himanshu Srivastava
Problem : Populating Next Right Pointers in Each Node II
TimeComplexity : O(n)


*/


/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:
    void connect(TreeLinkNode *root) {
        
        TreeLinkNode* child=NULL;
        TreeLinkNode* childStart = NULL;
        
        
        while(root != NULL){
            
            while(root != NULL){
                
                if(root->left){
                    
                    if(childStart){
                        child->next = root->left;
                        child = child->next;
                    }else{
                        childStart = root->left;
                        child = root->left;
                    }                   
                    
                }
                
                if(root->right){
                    if(childStart){
                        child->next = root->right;
                        child = child->next;
                    }else{
                        childStart = root->right;
                        child = root->right;
                    }
                    
                }
                
                root = root->next;
            }
            
            root = childStart;
            childStart = NULL;
            child = NULL;
               
        }
        
    }
};