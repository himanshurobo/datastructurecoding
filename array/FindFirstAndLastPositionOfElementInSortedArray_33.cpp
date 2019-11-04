/*

Given an array of integers nums sorted in ascending order, find the starting and ending position of a 
given target value.

Your algorithm's runtime complexity must be in the order of O(log n).

If the target is not found in the array, return [-1, -1].

Example 1:

Input: nums = [5,7,7,8,8,10], target = 8
Output: [3,4]
Example 2:

Input: nums = [5,7,7,8,8,10], target = 6
Output: [-1,-1]

WrittenBy : Himanshu Srivastava
Problem : Find First and Last Position of Element in Sorted Array
TimeComplexity : O(logn)


*/


#include<iostream>
#include <vector>
#include<bits/stdc++.h>

using namespace std;


class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {

        vector<int> ret(2,-1);

        int start = 0, end = nums.size() -1 ,mid =0  ;
        if(end < 0)
            return ret;


        while( start < end){

            mid = start + ( end - start)/2;

            if(nums[mid] < target)
                start = mid + 1;
            else
                end = mid ;
        }

        if(nums[start] != target) return ret;
        else
            ret[0] = start;

        end = nums.size()-1;
        while(start<end){
           mid = start + (end-start)/2 +1;
            if(nums[mid] > target)
                end = mid-1;
            else
                start = mid;
        }
        ret[1] = end;

        return ret;


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

    vector<int> input{5,7,7,8,8,10};
    int target = 8

    displayInt(sol.search(input,target));

    return 0;
}
