/*
Given a word, you need to judge whether the usage of capitals in it is right or not.

We define the usage of capitals in a word to be right when one of the following cases holds:

All letters in this word are capitals, like "USA".
All letters in this word are not capitals, like "leetcode".
Only the first letter in this word is capital, like "Google".
Otherwise, we define that this word doesn't use capitals in a right way.
 

Example 1:

Input: "USA"
Output: True
 

Example 2:

Input: "FlaG"
Output: False

WrittenBy : Himanshu Srivastava
Problem : Detect Capital
TimeComplexity : O(n)


*/
class Solution {
public:
    bool detectCapitalUse1(string word) {
        for(int i = 1; i < word.size(); i++){
        if(isupper(word[1]) != isupper(word[i]) || 
           islower(word[0]) && isupper(word[i])) return false;
    }        
    return true;
        
    }

bool detectCapitalUse(const std::string& word) {
    int n = word.size();
    
    if (n == 0) {
        return true; // An empty string is considered valid
    }

    // Determine if the first letter is uppercase
    bool firstLetterUpper = (word[0] >= 'A' && word[0] <= 'Z');
    
    // Check if the entire word is uppercase or lowercase
    bool allUpper = true;
    bool allLower = true;

    // Start checking from the first character
    for (int i = 0; i < n; ++i) {
        if (word[i] < 'A' || word[i] > 'Z') {
            allUpper = false; // Not all characters are uppercase
        }
        if (word[i] < 'a' || word[i] > 'z') {
            allLower = false; // Not all characters are lowercase
        }
    }

    // If all characters are uppercase or all characters are lowercase
    if (allUpper || allLower) {
        return true;
    }

    // If only the first letter is uppercase and the rest are lowercase
    if (firstLetterUpper) {
        for (int i = 1; i < n; ++i) {
            if (word[i] < 'a' || word[i] > 'z') {
                return false; // Found a non-lowercase character after the first uppercase letter
            }
        }
        return true;
    }

    // If none of the conditions are satisfied
    return false;
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

    displayInt(sol.detectCapitalUse(input));

    return 0;
}
