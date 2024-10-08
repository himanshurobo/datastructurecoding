/*
You are given an array A of strings.

Two strings S and T are special-equivalent if after any number of moves, S == T.

A move consists of choosing two indices i and j with i % 2 == j % 2, and swapping S[i] with S[j].

Now, a group of special-equivalent strings from A is a non-empty subset S of A such that any string not 
in S is not special-equivalent with any string in S.

Return the number of groups of special-equivalent strings from A.

 

Example 1:

Input: ["a","b","c","a","c","c"]
Output: 3
Explanation: 3 groups ["a","a"], ["b"], ["c","c","c"]
Example 2:

Input: ["aa","bb","ab","ba"]
Output: 4
Explanation: 4 groups ["aa"], ["bb"], ["ab"], ["ba"]
Example 3:

Input: ["abc","acb","bac","bca","cab","cba"]
Output: 3
Explanation: 3 groups ["abc","cba"], ["acb","bca"], ["bac","cab"]
Example 4:

Input: ["abcd","cdab","adcb","cbad"]
Output: 1
Explanation: 1 group ["abcd","cdab","adcb","cbad"]

WrittenBy : Himanshu Srivastava
Problem : Groups of Special-Equivalent Strings
TimeComplexity : O(n)


*/

#include"../header.hpp"

class Solution {
public:
    int numSpecialEquivGroups(vector<string>& A) {
        
        unordered_set<string> s;
    for (const auto& w : A) {
        string odd, even;
        for (int i = 0; i < w.size (); ++i) {
            if (i % 2) even  += w[i];
            else       odd += w[i];
        }
        sort (even.begin (), even.end());
        sort (odd.begin(), odd.end());
        cout<<even<<" "<<odd<<endl;
        s.insert(even +  odd);
    }

    return s.size (); //Time: O(n * w log w)
        
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

    vector<string>input{"a","b","c","a","c","c"};

    cout<<sol.numSpecialEquivGroups(input);

    return 0;
}
