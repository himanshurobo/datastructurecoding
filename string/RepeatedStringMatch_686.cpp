/*

Given two strings A and B, find the minimum number of times A has to be repeated such that B is a substring 
of it. If no such solution, return -1.

For example, with A = "abcd" and B = "cdabcdab".

Return 3, because by repeating A three times (“abcdabcdabcd”), B is a substring of it; and B is not a 
substring of A repeated two times ("abcdabcd").

Note:
The length of A and B will be between 1 and 10000.


WrittenBy : Himanshu Srivastava
Problem : Repeated String Match
TimeComplexity : O(n)

*/

class Solution {
public:
    int repeatedStringMatch(string a, string b) {
        vector<int> lps(b.size()); // longest proper suffix prefix array
        for (int i = 1, j = 0; i < b.size();) {
            if(b[j] == b[i])
                lps[i++] = ++j;
            else if (j == 0)
                i++;
            else
                j = lps[j -1];
        }
        for (auto i = 0, j = 0; i < a.size(); i++, j = j ? lps[j-1] : 0) {
            while (j < b.size() && a[(i + j) % a.size()] == b[j])
                ++j;
            if (j == b.size())
                return ceil((float)(i + j) / a.size());
        }
        return -1;
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

    displayInt(sol.repeatedStringMatch(input));

    return 0;
}