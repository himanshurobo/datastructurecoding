/*

For strings S and T, we say "T divides S" if and only if S = T + ... + T  (T concatenated with itself 1 or more times)

Return the largest string X such that X divides str1 and X divides str2.

 

Example 1:

Input: str1 = "ABCABC", str2 = "ABC"
Output: "ABC"
Example 2:

Input: str1 = "ABABAB", str2 = "ABAB"
Output: "AB"
Example 3:

Input: str1 = "LEET", str2 = "CODE"
Output: ""

WrittenBy : Himanshu Srivastava
Problem : Greatest Common Divisor of Strings
TimeComplexity : O(n)

*/

#include"../header.hpp"

class Solution {
public:
    string gcdOfStrings1(string str1, string str2) {
        if (str1.size() < str2.size()) return gcdOfStrings(str2, str1);
        if (str2.empty()) return str1;
        if (str1.substr(0, str2.size()) != str2) return "";
        cout<<str1.substr(str2.size())<<endl;
        return gcdOfStrings(str1.substr(str2.size()), str2);
        
    }
string gcdOfStrings(string str1, string str2) {

        int n1 = str1.size();
        int n2 = str2.size();

        if( n1 < n2 ){
            return gcdOfStrings(str2,str1);
        }

        for ( int i = n1; i > 0 ; i--){

            if ( n1 % i == 0 && n2 % i == 0){

                int j = 0;
                string s1 = "";
                string s2 = "";

                while( j < n1 ){
                    s1 += str1.substr(0,i);
                    if ( j < n2 ){
                        s2 += str2.substr(0,i);
                    }
                    j += i;
                }
                // cout<<i<<"-->"<<s1<<":"<<str1<<"|"<<s2<<":"<<str2<<endl;
                if( s1 == str1 && s2 == str2 && str1.substr(0,i) == str2.substr(0,i)){
                    return str1.substr(0,i);
                }
                
            }
        }
        
        return "";
    }
    string gcdOfStrings2(string str1, string str2) {

        return (str1 + str2 == str2 + str1)? 
        str1.substr(0, gcd(size(str1),size(str2))): "";
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

    string str1 = "ababab";
    string str2 = "abab";

    cout<<sol.gcdOfStrings(str1,str2);

    return 0;
}
