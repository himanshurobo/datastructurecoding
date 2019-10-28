/*

Write a function to find the longest common prefix string amongst an array of strings.

If there is no common prefix, return an empty string "".

Example 1:

Input: ["flower","flow","flight"]
Output: "fl"
Example 2:

Input: ["dog","racecar","car"]
Output: ""
Explanation: There is no common prefix among the input strings.



WrittenBy : Himanshu Srivastava
Problem : Longest Common Prefix
TimeComplexity : O(n)

 
*/

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        
        string prefix="";
        if(strs.size()==0)  return prefix;
        
        /** check char by char, for each char, check all the string word **/
        for(int k=0; k<strs[0].size(); k++){
            int i=1;
            for(; i<strs.size() && strs[i].size()>k; i++){
                if(strs[i][k]!=strs[0][k])
                    return prefix;
            }
            if(i==strs.size()) prefix+=strs[0][k];
        }
        return prefix;
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

    displayInt(sol.longestCommonPrefix(input));

    return 0;
}