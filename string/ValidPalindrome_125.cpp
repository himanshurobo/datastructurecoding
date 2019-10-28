/*

Given a string, determine if it is a palindrome, considering only alphanumeric characters and ignoring cases.

Note: For the purpose of this problem, we define empty string as valid palindrome.

Example 1:

Input: "A man, a plan, a canal: Panama"
Output: true
Example 2:

Input: "race a car"
Output: false

WrittenBy : Himanshu Srivastava
Problem : Valid Palindrome
TimeComplexity : O(n)

*/


class Solution {
public:
    bool isPalindrome(string s) {
        int left = 0 ;
        int right =  s.size()-1;
        
        while( left < right ){
            while(left < right && isalnum(s[left]) ==  false)
                left++;
            while(left < right && isalnum(s[right]) == false)
                right--;
            
            
            // cout<<left<<" "<<s[left]<<" "<<right<<" "<<s[right]<<endl;
            if( toupper(s[left]) != toupper(s[right]))
                return false;
            
            left++;
            right--;
        }
        
        return true;
        
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

    displayInt(sol.isPalindrome(input));

    return 0;
}