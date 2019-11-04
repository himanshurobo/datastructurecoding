/*

You need to construct a string consists of parenthesis and integers from a binary tree with the preorder
 traversing way.

The null node needs to be represented by empty parenthesis pair "()". And you need to omit all the empty
 parenthesis pairs that don't affect the one-to-one mapping relationship between the string and the original 
 binary tree.

Example 1:
Input: Binary tree: [1,2,3,4]
       1
     /   \
    2     3
   /    
  4     

Output: "1(2(4))(3)"

Explanation: Originallay it needs to be "1(2(4)())(3()())", 
but you need to omit all the unnecessary empty parenthesis pairs. 
And it will be "1(2(4))(3)".
Example 2:
Input: Binary tree: [1,2,3,null,4]
       1
     /   \
    2     3
     \  
      4 

Output: "1(2()(4))(3)"

Explanation: Almost the same as the first example, 
except we can't omit the first parenthesis pair to break the one-to-one mapping relationship between the input 
and the output.

WrittenBy : Himanshu Srivastava
Problem : Construct String from Binary Tree
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
public:
    string tree2str(TreeNode* t) {
        if( t == NULL)
            return "";
        string st = to_string(t->val);
        
        if( t->left){
            st += "(" + tree2str(t->left) + ")";
            // cout<<"left : "<<st<<endl;
        }else if( t->right)
            st += "()";
        if(t->right){
             st += "(" + tree2str(t->right) + ")";
            // cout<<"right : "<<st<<endl;
        }
        
        return st;
        
        
    }
};


void displayInt(vector<string>input){
    cout<<"Displaying size "<<input.size()<<endl;
    for (std::vector<string>::size_type i = 0; i < input.size(); i++) {
        std::cout << input.at(i) << ' ';
    }
}

int main(){

    Solution sol;

    vector<string>input{"abcabcbb"}

    displayInt(sol.tree2str(input));

    return 0;
}