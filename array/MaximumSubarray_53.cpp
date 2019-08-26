/*
Given an integer array nums, find the contiguous subarray (containing at least one number) which has the largest sum and return its sum.

Example:

Input: [-2,1,-3,4,-1,2,1,-5,4],
Output: 6
Explanation: [4,-1,2,1] has the largest sum = 6.



WrittenBy : Himanshu Srivastava
Problem : Maximum Sub Araay
TimeComplexity : O(n)

*/



#include<iostream>
#include <vector>
#include<bits/stdc++.h>

using namespace std;


class Solution {
public:
    int maxSubArray(vector<int>& nums) {

        int maxSum = INT_MIN;
        int sum = 0;
        for( int i :nums){

            sum += i;

            maxSum = std::max(maxSum,sum);

            sum = std::max(sum,0);

        }

        return maxSum;

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

    vector<int> input{-2,1,-3,4,-1,2,1,-5,4};
    int maxSum = sol.maxSubArray(input);
    cout<<maxSum<<endl;

    return 0;
}
