/*

Given an array of non-negative integers, you are initially positioned at the first index of the array.

Each element in the array represents your maximum jump length at that position.

Your goal is to reach the last index in the minimum number of jumps.

Example:

Input: [2,3,1,1,4]
Output: 2
Explanation: The minimum number of jumps to reach the last index is 2.
    Jump 1 step from index 0 to 1, then 3 steps to the last index.



WrittenBy : Himanshu Srivastava
Problem : Jump Game II
TimeComplexity : O(n)


*/


#include<iostream>
#include <vector>
#include<bits/stdc++.h>

using namespace std;



class Solution {
public:
    int jump(vector<int>& nums) {

        int n = nums.size();

        if( n <= 1){
            return 0;
        }


        //Keep Track of ladder
        int ladder = nums[0];

        //Keep track of stairs
        int stairs = nums[0];

        int jump = 1;

        for ( int level = 1 ; level < n-1 ;level++ ){

            // if( level == n-1){
            //     return jump;
            // }

            // build ladders
            if( level + nums[level] > ladder){
                ladder = level + nums[level];
            }

            //Used one stair
            stairs--;
            if( stairs==0){
                //No stairs left so jump
                jump++;

                //update stairs
                stairs = ladder - level;
            }
        }

        return jump;
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

    vector<int> input{2,3,1,1,4};
    vector<vector<int>> res;
    int jump = sol.trap(input);
    cout<<jump<<endl;

    return 0;
}
