/*

Implement function ToLowerCase() that has a string parameter str, and returns the same string in lowercase.

 

Example 1:

Input: "Hello"
Output: "hello"
Example 2:

Input: "here"
Output: "here"
Example 3:

Input: "LOVELY"
Output: "lovely"


WrittenBy : Himanshu Srivastava
Problem : To Lower Case
TimeComplexity : O(n)


*/


class Solution {
public:
    string toLowerCase(string str) {
        for(char& c: str)
            if('A'<=c && c<='Z') c = c-'A'+'a';
        return str;
    
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

    displayInt(sol.toLowerCase(input));

    return 0;
}