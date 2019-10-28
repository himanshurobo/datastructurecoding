/*

Given a string S, return the "reversed" string where all characters that are not a letter stay in the same place, and all letters reverse their positions.

 

Example 1:

Input: "ab-cd"
Output: "dc-ba"
Example 2:

Input: "a-bC-dEf-ghIj"
Output: "j-Ih-gfE-dCba"
Example 3:

Input: "Test1ng-Leet=code-Q!"
Output: "Qedo1ct-eeLg=ntse-T!"


WrittenBy : Himanshu Srivastava
Problem : Reverse Only Letters
TimeComplexity : O(n)


*/


class Solution {
public:
    string reverseOnlyLetters(string S) {
        int left = 0 ;
        int right = S.size()-1;
        
        while( left < right ){
            
            if( !isalpha(S[left]) ){
                left++;
                continue;
            }
            if(!isalpha(S[right]) ){
                right--;
                continue;
            }
            
            char temp = S[left];
            S[left] = S[right];
            S[right] = temp;
            left++;
            right--;
        }
        
        return S;
        
        
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

        displayInt(sol.reverseOnlyLetters(input));

        return 0;
    }