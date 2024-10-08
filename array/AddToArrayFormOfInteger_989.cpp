/*

For a non-negative integer X, the array-form of X is an array of its digits in left to right order. 
For example, if X = 1231, then the array form is [1,2,3,1].

Given the array-form A of a non-negative integer X, return the array-form of the integer X+K.

 

Example 1:

Input: A = [1,2,0,0], K = 34
Output: [1,2,3,4]
Explanation: 1200 + 34 = 1234
Example 2:

Input: A = [2,7,4], K = 181
Output: [4,5,5]
Explanation: 274 + 181 = 455
Example 3:

Input: A = [2,1,5], K = 806
Output: [1,0,2,1]
Explanation: 215 + 806 = 1021
Example 4:

Input: A = [9,9,9,9,9,9,9,9,9,9], K = 1
Output: [1,0,0,0,0,0,0,0,0,0,0]
Explanation: 9999999999 + 1 = 10000000000
 

Note：

1 <= A.length <= 10000
0 <= A[i] <= 9
0 <= K <= 10000
If A.length > 1, then A[0] != 0


WrittenBy : Himanshu Srivastava
Problem : Add to Array-Form of Integer
TimeComplexity : O(n)

*/

#include"../header.hpp"

class Solution {
public:
    vector<int> addToArrayForm(vector<int>& A, int K) {
        
        int len = A.size();
        
        int index = len -1 ;
        int carry = 0;
        vector<int> res;
        while( index >= 0 || K != 0 ){
            
            int rem = K%10;
            K = K/10;
            
            int firstNumber = index < 0 ? 0 : A[index];
            
            int sum = firstNumber + rem + carry;
            
            res.push_back(sum%10);
            carry = sum/10;
            index--;            
            
        }
        
        
        if( carry ){
            res.push_back(carry);
        }
        
        reverse(res.begin(), res.end());
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

    cout<<(sol.addToArrayForm(input));

    return 0;
}