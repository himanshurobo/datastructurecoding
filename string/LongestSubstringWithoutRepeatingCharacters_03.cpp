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

class Solution {
public:
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
  
  
//   map<char,int>::iterator it = hash.begin();
  
//   for( it = hash.begin(); it != hash.end(); it++){
//     cout<<"first : "<<(*it).first<<" Second : "<<(*it).second<<endl;
//   }

  
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

    vector<string>input{"abcabcbb"}

    cout<<(sol.lengthOfLongestSubstring(input));

    return 0;
}