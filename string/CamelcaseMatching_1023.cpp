/*

A query word matches a given pattern if we can insert lowercase letters to the pattern word so that it equals the query. (We may insert each character at any position, and may insert 0 characters.)

Given a list of queries, and a pattern, return an answer list of booleans, where answer[i] is true if and only if queries[i] matches the pattern.

 

Example 1:

Input: queries = ["FooBar","FooBarTest","FootBall","FrameBuffer","ForceFeedBack"], pattern = "FB"
Output: [true,false,true,true,false]
Explanation: 
"FooBar" can be generated like this "F" + "oo" + "B" + "ar".
"FootBall" can be generated like this "F" + "oot" + "B" + "all".
"FrameBuffer" can be generated like this "F" + "rame" + "B" + "uffer".
Example 2:

Input: queries = ["FooBar","FooBarTest","FootBall","FrameBuffer","ForceFeedBack"], pattern = "FoBa"
Output: [true,false,true,false,false]
Explanation: 
"FooBar" can be generated like this "Fo" + "o" + "Ba" + "r".
"FootBall" can be generated like this "Fo" + "ot" + "Ba" + "ll".
Example 3:

Input: queries = ["FooBar","FooBarTest","FootBall","FrameBuffer","ForceFeedBack"], pattern = "FoBaT"
Output: [false,true,false,false,false]
Explanation: 
"FooBarTest" can be generated like this "Fo" + "o" + "Ba" + "r" + "T" + "est".

WrittenBy : Himanshu Srivastava
Problem : Camelcase Matching
TimeComplexity : O(n)

*/

class Solution {
public:
    // Runtime: O(n), where n is all letters in all queries. We process each letter only once.
// Memory: O(m), where m is the number of queries (to store the resul
    vector<bool> camelMatch(vector<string>& queries, string pattern) {
     
        vector<bool> res;
    for (auto i = 0, j = 0, p = 0; i < queries.size(); ++i) {
    for (j = 0, p = 0; j < queries[i].size(); ++j) {
      if (p < pattern.size() && queries[i][j] == pattern[p]) ++p;
      else if (!islower(queries[i][j])) break;
    }
    res.push_back(j == queries[i].size() && p == pattern.size());
  }
  return res;
        
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

    displayInt(sol.camelMatch(input));

    return 0;
}