/*
Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

An input string is valid if:

Open brackets must be closed by the same type of brackets.
Open brackets must be closed in the correct order.
Note that an empty string is also considered valid.

Example 1:

Input: "()"
Output: true
Example 2:

Input: "()[]{}"
Output: true
Example 3:

Input: "(]"
Output: false
Example 4:

Input: "([)]"
Output: false
Example 5:

Input: "{[]}"
Output: true



WrittenBy : Himanshu Srivastava
Problem : Valid Parentheses
TimeComplexity : O(n)

*/

class Solution {
public:
    bool isValid(string s) {
        stack<char> t;
        for(char& ch : s){
            switch(ch)
            {
                case '(' :
                case '{' :
                case '[' : t.push(ch);break;
                case ')' : if(t.empty() || t.top() != '(' ) return false; else t.pop(); break; 
                case '}' : if(t.empty() || t.top() != '{' ) return false; else t.pop(); break; 
                case ']' : if(t.empty() || t.top() != '[' ) return false; else t.pop(); break; 
                default: ;
            }
                    
        }
        return t.empty() ;
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

    displayInt(sol.isValid(input));

    return 0;
}