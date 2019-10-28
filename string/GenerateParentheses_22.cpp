/*


Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

For example, given n = 3, a solution set is:

[
  "((()))",
  "(()())",
  "(())()",
  "()(())",
  "()()()"
]


WrittenBy : Himanshu Srivastava
Problem : Generate Parentheses
TimeComplexity : O(n)

*/



class Solution {
public:
    
    void dfs(vector<string>& result, string& solution, int left, int right) {
        if (left == 0 &&  right == 0) {
            result.push_back(solution);
            return;
        }
        if (left > 0) {
            solution += "(";
            dfs(result, solution, left - 1, right);
            solution.pop_back();
        }
        if (right > left) {
            solution += ")";
            dfs(result, solution, left, right - 1);
            solution.pop_back();
        }
    }
        
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        string solution;
        dfs(result, solution, n, n);
        return result;
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

    displayInt(sol.generateParenthesis(input));

    return 0;
}