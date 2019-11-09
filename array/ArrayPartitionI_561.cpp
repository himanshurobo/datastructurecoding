
/*

Given an array of 2n integers, your task is to group these integers into n pairs of integer, 
say (a1, b1), (a2, b2), ..., (an, bn) which makes sum of min(ai, bi) for all i from 1 to n as large as possible.

Example 1:
Input: [1,4,3,2]

Output: 4
Explanation: n is 2, and the maximum sum of pairs is 4 = min(1, 2) + min(3, 4).


WrittenBy : Himanshu Srivastava
Problem : Array Partition I
TimeComplexity : O(n)

*/

#include"../header.hpp"

class Solution {
public:
    int arrayPairSum(vector<int>& nums) {
        int res =0 ;
        
        sort(nums.begin(),nums.end());
        
        for( int i =0 ; i < nums.size();i+=2){
            
            res +=nums[i];
        }
        
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

    cout<<(sol.arrayPairSum(input));

    return 0;
}