/*
Give a string s, count the number of non-empty (contiguous) substrings that have the same number of 0's and 1's, and all the 0's and all the 1's in these substrings are grouped consecutively.

Substrings that occur multiple times are counted the number of times they occur.

Example 1:
Input: "00110011"
Output: 6
Explanation: There are 6 substrings that have equal number of consecutive 1's and 0's: "0011", "01", "1100", "10", "0011", and "01".

Notice that some of these substrings repeat and are counted the number of times they occur.

Also, "00110011" is not a valid substring because all the 0's (and 1's) are not grouped together.
Example 2:
Input: "10101"
Output: 4
Explanation: There are 4 substrings: "10", "01", "10", "01" that have equal number of consecutive 1's and 0's.

WrittenBy : Himanshu Srivastava
Problem : Count Binary Substrings
TimeComplexity : O(n)


*/


class Solution {
public:
    int countBinarySubstrings(string s) {
        vector<int> rec;
        int count = 1;
        for(int i=1, n=s.size(); i<=n; ++i){
            if(s[i] == s[i-1]){
                ++count;
            }else{
                cout<<i<<" "<<count<<endl;
                rec.push_back(count);
                count = 1;
            }
        }
        int res = 0;
        for(int i=1, n=rec.size(); i<n; ++i){
            res += min(rec[i-1], rec[i]);
        }
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

    displayInt(sol.countBinarySubstrings(input));

    return 0;
}