/*
Given a non-empty array of digits representing a non-negative integer, plus one to the integer.

The digits are stored such that the most significant digit is at the head of the list, and each element
 in the array contain a single digit.

You may assume the integer does not contain any leading zero, except the number 0 itself.

Example 1:

Input: [1,2,3]
Output: [1,2,4]
Explanation: The array represents the integer 123.
Example 2:

Input: [4,3,2,1]
Output: [4,3,2,2]
Explanation: The array represents the integer 4321.

WrittenBy : Himanshu Srivastava
Problem : Plus One
TimeComplexity : O(m)


*/


#include<iostream>
#include <vector>
#include<bits/stdc++.h>

using namespace std;



class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {

        int plusOne = 1 ;
        int num = digits.size();
        for( int i = num - 1 ; i >= 0 ; i--){

               digits[i] +=  plusOne ;

            if( digits[i] < 10){
                plusOne = 0 ;
            }else{
                digits[i] = 0;
                plusOne = 1;    
            }



        }
        if( plusOne == 1 )
			digits.insert( digits.begin(), 1 );

        return digits;

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

    vector<int> input{2, 7, 11, 15};

    displayInt(s)ol.plusOne(input));

    return 0;
}
