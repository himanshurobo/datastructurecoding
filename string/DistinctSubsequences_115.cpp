/*

Given a string S and a string T, count the number of distinct subsequences of S which equals T.

A subsequence of a string is a new string which is formed from the original string by deleting some
 (can be none) of the characters without disturbing the relative positions of the remaining characters. 
 (ie, "ACE" is a subsequence of "ABCDE" while "AEC" is not).

Example 1:

Input: S = "rabbbit", T = "rabbit"
Output: 3
Explanation:
    
As shown below, there are 3 ways you can generate "rabbit" from S.
(The caret symbol ^ means the chosen letters)

rabbbit
^^^^ ^^
rabbbit
^^ ^^^^
rabbbit
^^^ ^^^
Example 2:

Input: S = "babgbag", T = "bag"
Output: 5
Explanation:

As shown below, there are 5 ways you can generate "bag" from S.
(The caret symbol ^ means the chosen letters)

babgbag
^^ ^
babgbag
^^    ^
babgbag
^    ^^
babgbag
  ^  ^^
babgbag
    ^^^

WrittenBy : Himanshu Srivastava
Problem : Distinct Subsequences
TimeComplexity : O(n)

*/

#include"../header.hpp"

class Solution {
public:
    int numDistinct(string S, string T) {
        
    int m = T.length();
    int n = S.length();
    if (m > n) return 0;    // impossible for subsequence
    vector<vector<int>> path(m+1, vector<int>(n+1, 0));
    for (int k = 0; k <= n; k++) path[0][k] = 1;    // initialization
    
    for (int j = 1; j <= n; j++) {
        for (int i = 1; i <= m; i++) {
            path[i][j] = path[i][j-1] + (T[i-1] == S[j-1] ? path[i-1][j-1] : 0);
        }
    }

    for( int i = 0 ; i < path.size();i++){
        for( int j = 0 ; j < path[i].size();j++){
            cout<<path[i][j]<<" ";
        }
        cout<<endl;
    }
    
    return path[m][n];
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


    string S = "rabbbit", T = "rabbit";

    cout<<sol.numDistinct(S,T);

    return 0;
}