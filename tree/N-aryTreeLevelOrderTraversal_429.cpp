/*
Given an n-ary tree, return the level order traversal of its nodes' values. (ie, from left to right,
 level by level).

For example, given a 3-ary tree:

 



 

We should return its level order traversal:

[
     [1],
     [3,2,4],
     [5,6]
]
 

Note:

The depth of the tree is at most 1000.
The total number of nodes is at most 5000.



WrittenBy : Himanshu Srivastava
Problem : N-ary Tree Level Order Traversal
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
public:
    vector<vector<int>> levelOrder(Node* root) {
        
        vector<vector<int>> res;
        
        if(root == NULL){
            return res;
        }
        
        queue<Node*> q;
        
        q.push(root);
        
        while(!q.empty()){
            
            
            int n = q.size();
            vector<int>path;
            
            for( int i = 0 ; i < n ;i++){
            
                Node* r = q.front();
                q.pop();

                path.push_back(r->val);

                for( Node* t : r->children){
                    q.push(t);
                }
                
            }
            res.push_back(path);
            
        }
        return res;
    }
};