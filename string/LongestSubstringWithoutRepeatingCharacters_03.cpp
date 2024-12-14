/*

Given a string, find the length of the longest substring without repeating characters.

Example 1:

Input: "abcabcbb"
Output: 3 
Explanation: The answer is "abc", with the length of 3. 
Example 2:

Input: "bbbbb"
Output: 1
Explanation: The answer is "b", with the length of 1.
Example 3:

Input: "pwwkew"
Output: 3
Explanation: The answer is "wke", with the length of 3. 
             Note that the answer must be a substring, "pwke" is a subsequence and not a substring.


WrittenBy : Himanshu Srivastava
Problem : Longest Substring Without Repeating Characters
TimeComplexity : O(n)

*/

#include"../header.hpp"

class Solution {
public:

// Function to find the length of the longest substring without repeating characters
    int lengthOfLongestSubstring(string s) {

        // 'n' is the length of the string
        int n = s.size();

        // 'start' and 'end' represent the window of characters we are currently considering
        int start = 0;
        int end = 0;
        
        // 'maxlen' holds the length of the longest valid substring found
        int maxlen = 0;

        // 'hash' is a set to store characters that are currently in the window
        set<char> hash;

        // Iterate over the string until the 'end' pointer reaches the end of the string
        while( end < n){

            // If the current character is not in the set, it's valid for the current window
            if(hash.find(s[end]) == hash.end()){
                // Update maxlen if the current window is longer than the previously found ones
                maxlen = max(maxlen, end - start + 1);
                // Add the current character to the set
                hash.insert(s[end]);
                // Move the 'end' pointer to expand the window
                end++;
            }else{
                // If the current character is already in the set, move the 'start' pointer
                // to shrink the window and remove characters from the set until the duplicate is removed
                hash.erase(s[start]);
                start++;
            }

        }

        // Return the length of the longest valid substring found
        return maxlen;
    }


    int lengthOfLongestSubstring(string ch) {
      int max = 0;
      int start = 0 ;
      map<char,int> hash;
      int lenght = ch.size();
      
      for( int i = 0 ; i < lenght; i++){
        
        if(hash.find(ch[i]) != hash.end() && hash.at(ch[i]) >= start){
          start = hash.at(ch[i])+1;
          
        }
          
          hash[ch[i]] = i;
        // }
        
        
        
        max = std::max(max,i-start +1);
        
        
      }
  
  
  map<char,int>::iterator it = hash.begin();
  
  for( it = hash.begin(); it != hash.end(); it++){
    cout<<"first : "<<(*it).first<<" Second : "<<(*it).second<<endl;
  }

  
  return max;
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

    string input = "abcabcbb";

    cout<<sol.lengthOfLongestSubstring(input);

    return 0;
}
