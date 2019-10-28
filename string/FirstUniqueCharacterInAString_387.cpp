/*

Given a string, find the first non-repeating character in it and return it's index. If it doesn't exist, return -1.

Examples:

s = "leetcode"
return 0.

s = "loveleetcode",
return 2.


WrittenBy : Himanshu Srivastava
Problem : First Unique Character in a String
TimeComplexity : O(n)


*/

class Solution {
public:
    int firstUniqChar(string s) {
        int n = s.size();
        
        if( n == 0 ){
            return -1;
        }
        if( n == 1){
            return 0;
        }
        int slow = 0 ;
        int fast = 1;
        vector<int> count(256,0);
        count[s[slow]]++;
        
        while(fast < n ){
            count[s[fast]]++;
            while(slow < n && count[s[slow]] > 1 )
                slow++;
            // cout<<slow<<fast<<endl;
            if( slow >= n )
                return -1;
            
            if( count[s[slow]] == 0){
                count[s[slow]]++;
                fast = slow;
            }
            fast++;
            
        }
        return slow;
        
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

    displayInt(sol.firstUniqChar(input));

    return 0;
}