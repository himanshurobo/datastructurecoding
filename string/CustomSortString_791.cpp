/*

S and T are strings composed of lowercase letters. In S, no letter occurs more than once.

S was sorted in some custom order previously. We want to permute the characters of T so that they match the order that S was sorted. More specifically, if x occurs before y in S, then x should occur before y in the returned string.

Return any permutation of T (as a string) that satisfies this property.

Example :
Input: 
S = "cba"
T = "abcd"
Output: "cbad"
Explanation: 
"a", "b", "c" appear in S, so the order of "a", "b", "c" should be "c", "b", and "a". 
Since "d" does not appear in S, it can be at any position in T. "dcba", "cdba", "cbda" are also valid outputs.

WrittenBy : Himanshu Srivastava
Problem : Custom Sort String
TimeComplexity : O(n)


*/


class Solution {
public:
    string customSortString(string S, string T) {
        
        int len1 = S.length();
        int len2 = T.length();
        unordered_map<char,int> m;
        string ans = "";
        for(int i=0; i<len2; i++){
            m[T[i]]++;
        }
        for(int i=0; i<len1; i++){
            while(m[S[i]]){
                ans = ans + S[i];
                m[S[i]]--;
            }
        }
        for(auto i: m){
            while(i.second){
                ans = ans + i.first;
                i.second--;
            }
        }
        return ans;
        
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

    displayInt(sol.customSortString(input));

    return 0;
}