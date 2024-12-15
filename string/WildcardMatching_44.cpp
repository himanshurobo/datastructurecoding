/*

Given an input string (s) and a pattern (p), implement wildcard pattern matching with support for '?' and '*'.

'?' Matches any single character.
'*' Matches any sequence of characters (including the empty sequence).
The matching should cover the entire input string (not partial).

Note:

s could be empty and contains only lowercase letters a-z.
p could be empty and contains only lowercase letters a-z, and characters like ? or *.
Example 1:

Input:
s = "aa"
p = "a"
Output: false
Explanation: "a" does not match the entire string "aa".
Example 2:

Input:
s = "aa"
p = "*"
Output: true
Explanation: '*' matches any sequence.
Example 3:

Input:
s = "cb"
p = "?a"
Output: false
Explanation: '?' matches 'c', but the second letter is 'a', which does not match 'b'.
Example 4:

Input:
s = "adceb"
p = "*a*b"
Output: true
Explanation: The first '*' matches the empty sequence, while the second '*' matches the substring "dce".
Example 5:

Input:
s = "acdcb"
p = "a*c?b"
Output: false

WrittenBy : Himanshu Srivastava
Problem : Wildcard Matching
TimeComplexity : O(n)
*/

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    bool isMatch(string s, string p) {
        int m = s.size(), n = p.size();
        
        // DP table where dp[i][j] means if s[0..i-1] matches p[0..j-1]
        vector<vector<bool>> dp(m + 1, vector<bool>(n + 1, false));
        
        // Base cases
        dp[0][0] = true;  // Empty string matches empty pattern
        
        // Handle patterns like "*", "**", etc., that match an empty string
        for (int j = 1; j <= n; j++) {
            if (p[j - 1] == '*')
                dp[0][j] = dp[0][j - 1];
        }
        
        // Fill the DP table
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (p[j - 1] == s[i - 1] || p[j - 1] == '?') {
                    dp[i][j] = dp[i - 1][j - 1];
                } else if (p[j - 1] == '*') {
                    dp[i][j] = dp[i - 1][j] || dp[i][j - 1];
                }
            }
        }
        
        return dp[m][n];
    }
};

int main() {
    Solution solution;
    string s = "adceb";
    string p = "*a*b";
    cout << (solution.isMatch(s, p) ? "True" : "False") << endl;

    return 0;
}

------------------------------------------------------------------------------------------------------------------------------



// class Solution {
// public:
//     bool isMatch(string s, string p) {
//         int m = s.length(), n = p.length();
//         int i = 0, j = 0, asterisk = -1, match;
//         while (i < m) {
//             if (j < n && p[j] == '*') {
//                 match = i; 
//                 asterisk = j++;
//             }
//             else if (j < n && (s[i] == p[j] || p[j] == '?')) {
//                 i++; 
//                 j++;
//             }
//             else if (asterisk >= 0) {
//                 i = ++match;
//                 j = asterisk + 1;
//             }
//             else return false;
//         }
//         while (j < n && p[j] == '*') j++;
//         return j == n;
//     }
// };


// void displayInt(vector<string>input){
//     cout<<"Displaying size "<<input.size()<<endl;
//     for (std::vector<string>::size_type i = 0; i < input.size(); i++) {
//         std::cout << input.at(i) << ' ';
//     }
// }

// int main(){

//     Solution sol;

//     vector<string>input{"abcabcbb"}

//     displayInt(sol.isMatch(input));

//     return 0;
// }
