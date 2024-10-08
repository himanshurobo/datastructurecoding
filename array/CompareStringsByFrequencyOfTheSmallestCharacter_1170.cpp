/*

Let's define a function f(s) over a non-empty string s, which calculates the frequency of the 
smallest character in s. For example, if s = "dcce" then f(s) = 2 because the smallest character 
is "c" and its frequency is 2.

Now, given string arrays queries and words, return an integer array answer, 
where each answer[i] is the number of words such that f(queries[i]) < f(W), where W is a word in words.



Example 1:

Input: queries = ["cbd"], words = ["zaaaz"]
Output: [1]
Explanation: On the first query we have f("cbd") = 1, f("zaaaz") = 3 so f("cbd") < f("zaaaz").
Example 2:

Input: queries = ["bbb","cc"], words = ["a","aa","aaa","aaaa"]
Output: [1,2]
Explanation: On the first query only f("bbb") < f("aaaa"). On the second query both f("aaa") and f("aaaa") 
are both > f("cc").
 

Constraints:

1 <= queries.length <= 2000
1 <= words.length <= 2000
1 <= queries[i].length, words[i].length <= 10
queries[i][j], words[i][j] are English lowercase letters.

WrittenBy : Himanshu Srivastava
Problem : Compare Strings by Frequency of the Smallest Character
TimeComplexity : O(n)


*/



class Solution {
public:
    vector<int> numSmallerByFrequency(vector<string>& queries, vector<string>& words) {
        
         vector<int> fr(12, 0);
        int f;
        vector<int> q;
        for(int i = 0; i < words.size(); i++){
            f = getF(words[i]);
            fr[f]++;
        }
        
        for( int i = 0 ; i < fr.size();i++){
            cout<<fr[i]<<" ";
        }
        cout<<"***"<<endl;
		//Find cumulative frequency i.e. ith item will have sum of i..end.
        for(int i = 9; i >= 0; i--){
            fr[i] = fr[i] + fr[i+1];
        }
        for( int i = 0 ; i < fr.size();i++){
            cout<<fr[i]<<" ";
        }
        cout<<endl;
        
        for(int i = 0; i < queries.size(); i++){
            f = getF(queries[i]);
            q.push_back(fr[f+1]);
        }
        return q;
    }
    /*Helper function to calculate frequency of smallest element*/
    int getF(string &s){
        int a[26] = {0,};
        for(int i = 0; i < s.size(); i++){
            a[s[i]-'a']++;
        }
        
        for(int i = 0; i < 26; i++){
            if(a[i] != 0) return a[i];
        }
        return 0;
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

    cout<<(sol.numSmallerByFrequency(input));

    return 0;
}