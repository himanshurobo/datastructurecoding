/*
Given a string s, find the longest palindromic substring in s. You may assume that the maximum length of s 
is 1000.

Example 1:

Input: "babad"
Output: "bab"
Note: "aba" is also a valid answer.
Example 2:

Input: "cbbd"
Output: "bb"

WrittenBy : Himanshu Srivastava
Problem : Longest Palindromic Substring
TimeComplexity : O(n)

*/

#include"../header.hpp"

class Solution {
public:
    
    
    
    string longestPalindrome(string s) {
        
        int newLength = 2*s.size() + 1;
        
        char a[newLength+1];
        int index = 0;
        a[index++] = '^';
        for( int i = 0; i < s.size(); i++){
            a[index++] = s[i];
            a[index++] = '^';
        }
        
        a[index] = 0;
        
        int res[newLength];
        memset(res,0,sizeof(res));
        
        int aLeft = 0;
        int aRight = 0;
        
        int aRightBoundary = 0;
        int aCenter = 0;
        
        int aResultLength = 0;
        int aResultCenter = 0;
        
        for( int i = 1 ; i < newLength - 1  ; i++){
            
            //Symmetric accross the center
            if( i < aRightBoundary){
                
                int mirror = 2*aCenter - i ;
                res[i] = min( res[mirror],aRightBoundary-i);
                                
            }
            
            aLeft = i - 1 - res[i];
            aRight = i + 1 + res[i];
            
            //Expansion of accross the center
            while( aLeft >= 0 && aRight < newLength && a[aLeft] == a[aRight]){
                res[i]++;
                aLeft--;
                aRight++;
            }
            
            //Shift Boundary and center since i cross the rightBoundary
            if(i + res[i] > aRightBoundary){
                aRightBoundary = i + res[i];
                aCenter = i;
            }
            
            
            if(res[i] > aResultLength){
                aResultLength = res[i];
                aResultCenter = i;
            }
            
            
            
        }
        
        
         cout<<aResultLength<<" "<<aResultCenter<<endl;   
        
        return s.substr((aResultCenter - aResultLength) / 2, aResultLength);
    }



    string longestPalindrome1(string s) {
        int n = s.size();
        int newN = 2*n+1;
        char T[newN];
        int index = 0;
        for( int i = 0 ; i < newN;i++){
            T[i++] = '#';
            T[i] =  s[index++];
        }

        vector<int> p(newN,0);

        int c = 0 , r = 0;

        for( int i = 1 ; i < newN;i++){
            int mirror = 2*c -i;

            if( i < r){
                p[i] = min(r-i,p[mirror]);
            }

            while(T[i + ( 1 + p[i])] == T[i - ( 1 + p[i])]){
                p[i]++;
            }

            if( i + p[i] > r){
                c = i;
                r = i +p[i];
            }

        }


        int maxValue = 0;
        for( int i = 0 ; i < p.size();i++){
            maxValue = max(maxValue,p[i]);
        }

        cout<<maxValue;
        return "ABC";

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

    string input = "abababaa";

    sol.longestPalindrome(input);

    return 0;
}