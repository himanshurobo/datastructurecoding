/*

Write a function that takes a string as input and reverse only the vowels of a string.

Example 1:

Input: "hello"
Output: "holle"
Example 2:

Input: "leetcode"
Output: "leotcede"

WrittenBy : Himanshu Srivastava
Problem : Reverse Vowels of a String
TimeComplexity : O(n)

*/

class Solution {
public:
    string reverseVowels(string s) {
       set<char> vowels = {'a','e','i','o','u','A','E','I','O','U'};
    int i= 0, j = s.size()-1;
    while(i<j){
        while( ( i < s.size() ) && ( vowels.find(s[i])==vowels.end())) i++;
        while(( j > 0 ) && ( vowels.find(s[j])==vowels.end())) j--;
        if(i>=j) break;
        swap(s[i],s[j]);
        i++;
        j--;
    }
    return s;
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

    displayInt(sol.reverseVowels(input));

    return 0;
}