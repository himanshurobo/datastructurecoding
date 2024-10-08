

/*
Given an array nums of n integers and an integer target, find three integers in nums such that the sum is 
closest to target. Return the sum of the three integers. You may assume that each input would have exactly 
one solution.

Example:

Given array nums = [-1, 2, 1, -4], and target = 1.

The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).


 WrittenBy : Himanshu Srivastava
 Problem : Three Sum closest 
 TimeComplexity : O(n*n)

 */



#include<iostream>
#include <vector>
#include<bits/stdc++.h>

using namespace std;






class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {

        sort(nums.begin(), nums.end());
        int res = nums[0] + nums[1] + nums[2];
        for(int i = 0; i < nums.size() - 2; i++){
            int j = i + 1, k = nums.size() - 1;
            while(j < k){
                int num = nums[i] + nums[j] + nums[k];
                if(abs(num - target) < abs(res - target)) res = num;
                if(num < target) j++;
                else k--;
            }
        }
        return res;

    }

    void displayInt(vector<int>input){
        cout<<"Displaying size "<<input.size()<<endl;
        for (std::vector<int>::size_type i = 0; i < input.size(); i++) {
            std::cout << input.at(i) << ' ';
        }
    }
};




int main(){

    Solution sol;

    vector<int> input{2, 7, 11, 15};
    int target = 9;

    sol.displayInt(sol.threeSumClosest(input,target));

    return 0;
}
