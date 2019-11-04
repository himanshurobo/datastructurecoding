/*

Given an array A of strings made only from lowercase letters, return a list of all characters
 that show up in all strings within the list (including duplicates).  
 For example, if a character occurs 3 times in all strings but not 4 times, you need to include that 
 character three times in the final answer.

You may return the answer in any order.

 

Example 1:

Input: ["bella","label","roller"]
Output: ["e","l","l"]
Example 2:

Input: ["cool","lock","cook"]
Output: ["c","o"]
 

Note:

1 <= A.length <= 100
1 <= A[i].length <= 100
A[i][j] is a lowercase letter


WrittenBy : Himanshu Srivastava
Problem : Find Common Characters
TimeComplexity : O(n)

*/


class Solution {
public:
    

// Complexity Analysis
// Runtime: O(n), where n is the total number of characters.
// Memory: O(1) (we use two fixed-size vectors).


    vector<string> commonChars(vector<string>& A) {
        
    vector<int> cnt(26, INT_MAX);
    vector<string> res;
    for (auto s : A) {
        vector<int> cnt1(26, 0);
        for (auto c : s) ++cnt1[c - 'a'];
        cout<<"*"<<endl;
        for( auto i = 0 ; i < 26;i++)
            cout<<cnt1[i];
        for (auto i = 0; i < 26; ++i) cnt[i] = min(cnt[i], cnt1[i]);
        cout<<"$"<<endl;
        for( auto i = 0 ; i < 26;i++)
            cout<<cnt[i];
    }
    for (auto i = 0; i < 26; ++i)
        for (auto j = 0; j < cnt[i]; ++j) res.push_back(string(1, i + 'a'));
        
        
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

    cout<<(sol.commonChars(input));

    return 0;
}