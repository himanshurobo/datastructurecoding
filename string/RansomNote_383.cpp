/*

Given an arbitrary ransom note string and another string containing letters from all the magazines,
 write a function that will return true if the ransom note can be constructed from the magazines ;
  otherwise, it will return false.

Each letter in the magazine string can only be used once in your ransom note.

Note:
You may assume that both strings contain only lowercase letters.

canConstruct("a", "b") -> false
canConstruct("aa", "ab") -> false
canConstruct("aa", "aab") -> true



WrittenBy : Himanshu Srivastava
Problem : Ransom Note
TimeComplexity : O(n)

*/

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        vector<int> vec(26, 0);
        for (int i = 0; i < magazine.size(); ++i)
            ++vec[magazine[i] - 'a'];
        for (int j = 0; j < ransomNote.size(); ++j)
            if (--vec[ransomNote[j] - 'a'] < 0)
                return false;
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

    displayInt(sol.canConstruct(input));

    return 0;
}