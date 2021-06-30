/*
Given an array of non-negative integers, you are initially positioned at the first index of the array.

Each element in the array represents your maximum jump length at that position.

Determine if you are able to reach the last index.

Example 1:

Input: [2,3,1,1,4]
Output: true
Explanation: Jump 1 step from index 0 to 1, then 3 steps to the last index.
Example 2:

Input: [3,2,1,0,4]
Output: false
Explanation: You will always arrive at index 3 no matter what. Its maximum
             jump length is 0, which makes it impossible to reach the last index.



WrittenBy : Himanshu Srivastava
Problem : Jump Game
TimeComplexity : O(n)


*/



#include<iostream>
#include <vector>
#include<bits/stdc++.h>

using namespace std;


class Solution {
public:
    bool canJump(vector<int>& nums) {

        int n = nums.size();
        int i = 0;
        for (int reach = 0; i < n && i <= reach; ++i){

            reach = max(i + nums[i], reach);
            cout<<reach<<" ";
        }
        return i == n;

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
    int jump = sol.canJump(input);
    cout<<jump<<endl;

    return 0;
}
