/*


Given a non-empty string s, you may delete at most one character. Judge whether you can make it a palindrome.

Example 1:
Input: "aba"
Output: True
Example 2:
Input: "abca"
Output: True
Explanation: You could delete the character 'c'.


WrittenBy : Himanshu Srivastava
Problem : Valid Palindrome II
TimeComplexity : O(n)

*/

#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    // Main function to check if a string can be a palindrome by removing at most one character
    bool validPalindrome(string s) {
        int left = 0, right = s.size() - 1;

        // Two-pointer approach to validate the palindrome
        while (left < right) {
            if (s[left] != s[right]) {
                // Skip one character and check if the remaining string is a palindrome
                return isPalindrome(s, left + 1, right) || isPalindrome(s, left, right - 1);
            }
            left++;
            right--;
        }

        return true; // If the loop completes, the string is already a palindrome
    }

private:
    // Helper function to check if a substring is a palindrome
    bool isPalindrome(const string& s, int left, int right) {
        while (left < right) {
            if (s[left] != s[right]) return false;
            left++;
            right--;
        }
        return true;
    }
};

int main() {
    Solution solution;
    string s = "abca";
    cout << (solution.validPalindrome(s) ? "True" : "False") << endl;

    return 0;
}


// class Solution {
// public:
//     bool validPalindrome(string s) {
        
//         for (int i = 0, j = s.size() - 1; i < j; i++, j--){
//             if (s[i] != s[j]) {
//                 int i1 = i, j1 = j - 1, i2 = i + 1, j2 = j;
//                 while (i1 < j1 && s[i1] == s[j1]) {i1++; j1--;};
//                 while (i2 < j2 && s[i2] == s[j2]) {i2++; j2--;};
//                 return i1 >= j1 || i2 >= j2;
//             }
//         }
        
//         return true;
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

//     displayInt(sol.validPalindrome(input));

//     return 0;
// }
