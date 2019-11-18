/*

You are given an array of strings words and a string chars.

A string is good if it can be formed by characters from chars (each character can only be used once).

Return the sum of lengths of all good strings in words.

 

Example 1:

Input: words = ["cat","bt","hat","tree"], chars = "atach"
Output: 6
Explanation: 
The strings that can be formed are "cat" and "hat" so the answer is 3 + 3 = 6.
Example 2:

Input: words = ["hello","world","leetcode"], chars = "welldonehoneyr"
Output: 10
Explanation: 
The strings that can be formed are "hello" and "world" so the answer is 5 + 5 = 10.
 

Note:

1 <= words.length <= 1000
1 <= words[i].length, chars.length <= 100
All strings contain lowercase English letters only.

WrittenBy : Himanshu Srivastava
Problem : Find Words That Can Be Formed by Characters
TimeComplexity : O(n)

*/


class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        
        vector<int> c(26,0);
        int res = 0;
        
        for( char ch : chars){            
            c[ch-'a']++;
        }
        
        for( string word : words){
            
            vector<int> cTemp = c;
            bool isMatch = true;
            for( char ch : word ){
                
                if( --cTemp[ch-'a'] < 0 ){
                    isMatch = false;
                    break;
                }
            }
            
            if( isMatch)
                res += word.size();
        }
        
        
        return res;
        
        
        
    }
};

void displayInt(vector<int>input){
    cout<<"Displaying size "<<input.size()<<endl;
    for (std::vector<int>::size_type i = 0; i < input.size(); i++) {
        std::cout << input.at(i) << ' ';
    }
}

int main(){

    Solution sol;

    vector<int>input{7,1,5,3,6,4}

    cout<<(sol.countCharacters(input));

    return 0;
}