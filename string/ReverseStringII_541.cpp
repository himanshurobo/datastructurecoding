/*

Given a string and an integer k, you need to reverse the first k characters for every 2k characters counting from the start of the string. If there are less than k characters left, reverse all of them. If there are less than 2k but greater than or equal to k characters, then reverse the first k characters and left the other as original.
Example:
Input: s = "abcdefg", k = 2
Output: "bacdfeg"
Restrictions:
The string consists of lower English letters only.
Length of the given string and k will in the range [1, 10000]

WrittenBy : Himanshu Srivastava
Problem : Reverse String II
TimeComplexity : O(n)


*/

class Solution {
public:
    /**
     * 0            k           2k          3k
     * |-----------|-----------|-----------|---
     * +--reverse--+           +--reverse--+
     */
    string reverseStr(string s, int k) {
        
        int n = s.size();
        
        if( n < k ){
            k = n;
        }
        
        for( int i = 0 ; i < n;i=i+2*k){
            int left = i ;
            int right = min(k-1+i,(int)s.size() - 1);

            while( left < right){            
                char c = s[left];
                s[left] = s[right];
                s[right] = c;
                left++;
                right--;
            }
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

    displayInt(sol.reverseStr(input));

    return 0;
}