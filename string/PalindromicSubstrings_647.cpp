/*

Given a string, your task is to count how many palindromic substrings in this string.

The substrings with different start indexes or end indexes are counted as different substrings even
 they consist of same characters.

Example 1:

Input: "abc"
Output: 3
Explanation: Three palindromic strings: "a", "b", "c".
 

Example 2:

Input: "aaa"
Output: 6
Explanation: Six palindromic strings: "a", "a", "a", "aa", "aa", "aaa".

WrittenBy : Himanshu Srivastava
Problem : Palindromic Substrings
TimeComplexity : O(n)

*/

class Solution {
public:
     int count=1;
    
    void fun(string s, int left, int right)
    {
        cout<<left<<" "<<right<<" "<<count<<endl;
        if(left>right)
            return;
        cout<<"--"<<endl;
        while(left>=0 && right<s.size() && s[left]==s[right])
        {
            count++;
            left--;
            right++;
        }
    }
    
    int countSubstrings(string s) {
        for(int i=0;i<s.size()-1;i++)
        {
            fun(s,i,i);
            fun(s,i,i+1);
        }
        
        return count;
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

    displayInt(sol.countSubstrings(input));

    return 0;
}