/*

Given a string s consists of upper/lower-case alphabets and empty space characters ' ', return the length of last
 word in the string.

If the last word does not exist, return 0.

Note: A word is defined as a character sequence consists of non-space characters only.

Example:

Input: "Hello World"
Output: 5

WrittenBy : Himanshu Srivastava
Problem : Length of Last Word
TimeComplexity : O(n)
_
*/


class Solution {
public:
    int lengthOfLastWord(string s) {
        
        int len = 0, tail = s.size()-1;        
        while( tail >= 0 && s[tail] == ' ') tail--;
        while( tail >= 0 && s[tail] != ' ') {
            len++;
            tail--;
        }
        
        return len;
        
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

    displayInt(sol.lengthOfLastWord(input));

    return 0;
}