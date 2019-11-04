/*

Given two strings A and B of lowercase letters, return true if and only if we can swap two letters in A 
so that the result equals B.

 

Example 1:

Input: A = "ab", B = "ba"
Output: true
Example 2:

Input: A = "ab", B = "ab"
Output: false
Example 3:

Input: A = "aa", B = "aa"
Output: true
Example 4:

Input: A = "aaaaaaabc", B = "aaaaaaacb"
Output: true
Example 5:

Input: A = "", B = "aa"
Output: false

WrittenBy : Himanshu Srivastava
Problem : Buddy Strings
TimeComplexity : O(n)

*/

class Solution {
public:
    bool buddyStrings(string A, string B) {
        
        
//         If A.length() != B.length(): no possible swap

// If A == B, we need swap two same characters. Check is duplicated char in A.

// In other cases, we find index for A[i] != B[i]. There should be only 2 diffs and it's our one swap.


        if (A.length() != B.length()) return false;
        if (A == B && set<char>(A.begin(), A.end()).size() < A.size()) return true;
        vector<int> dif;
        for (int i = 0; i < A.length(); ++i) if (A[i] != B[i]) dif.push_back(i);
        return dif.size() == 2 && A[dif[0]] == B[dif[1]] && A[dif[1]] == B[dif[0]];
        
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

    displayInt(sol.buddyStrings(input));

    return 0;
}