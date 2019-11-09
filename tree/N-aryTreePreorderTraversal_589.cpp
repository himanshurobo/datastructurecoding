/*

Given an n-ary tree, return the preorder traversal of its nodes' values.

For example, given a 3-ary tree:

 



 

Return its preorder traversal as: [1,3,5,6,2,4].

 

Note:

Recursive solution is trivial, could you do it iteratively?


WrittenBy : Himanshu Srivastava
Problem : N-ary Tree Preorder Traversal
TimeComplexity : O(n)


*/

/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/
class Solution {
    
    
    void preorder( Node* root, vector<int>& res){
        
        if( root == NULL)
            return;
        
        res.push_back(root->val);
        
        for( Node* r : root->children){
            preorder(r, res);
        }
        
    }
    
public:
    vector<int> preorder(Node* root) {
        vector<int> res;
        preorder(root,res);
        return res;
    }
};