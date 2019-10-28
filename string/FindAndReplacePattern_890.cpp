/*
You have a list of words and a pattern, and you want to know which words in words matches the pattern.

A word matches the pattern if there exists a permutation of letters p so that after replacing every letter x in the pattern with p(x), we get the desired word.

(Recall that a permutation of letters is a bijection from letters to letters: every letter maps to another letter, and no two letters map to the same letter.)

Return a list of the words in words that match the given pattern. 

You may return the answer in any order.

 

Example 1:

Input: words = ["abc","deq","mee","aqq","dkd","ccc"], pattern = "abb"
Output: ["mee","aqq"]
Explanation: "mee" matches the pattern because there is a permutation {a -> m, b -> e, ...}. 
"ccc" does not match the pattern because {a -> c, b -> c, ...} is not a permutation,
since a and b map to the same letter.


WrittenBy : Himanshu Srivastava
Problem : Find and Replace Pattern
TimeComplexity : O(n)

*/

class Solution {
    string toPattern(string word) {
        map<char, char> M;
        int curr = 97;
        for(char& c: word) if(M.count(c) == 0) M[c] = (char) curr++;
        for(int i = 0; i < word.length(); i++) word[i] = M[word[i]];
        return word;
  }
public:
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        
        string p = toPattern(pattern);
        vector<string> res;
        for(string& w: words) if(toPattern(w).compare(p) == 0) res.push_back(w);
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

    displayInt(sol.findAndReplacePattern(input));

    return 0;
}