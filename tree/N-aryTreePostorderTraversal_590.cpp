/*
Given an n-ary tree, return the postorder traversal of its nodes' values.

For example, given a 3-ary tree:

 



 

Return its postorder traversal as: [5,6,3,2,4,1].

 
Note:

Recursive solution is trivial, could you do it iteratively?



WrittenBy : Himanshu Srivastava
Problem :N-ary Tree Postorder Traversal
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
    
    void postorder(Node* root, vector<int>& res){
        
        if( root == NULL){
            return;
        }
        
        for( Node* r : root->children){
            postorder(r,res);
        }
        
        res.push_back(root->val);
        
    }
    
public:
    vector<int> postorder(Node* root) {
        vector<int> res;
        postorder(root,res);
        return res;
    }
};