
/*

Given a sorted array and a target value, return the index if the target is found. If not, return the index where it would be if it were inserted in order.

You may assume no duplicates in the array.

Example 1:

Input: [1,3,5,6], 5
Output: 2
Example 2:

Input: [1,3,5,6], 2
Output: 1
Example 3:

Input: [1,3,5,6], 7
Output: 4


WrittenBy : Himanshu Srivastava
Problem : Search Insert Position
TimeComplexity : O(logn)



*/


#include<iostream>
#include <vector>
#include<bits/stdc++.h>

using namespace std;




class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {

        int start = 0,end = nums.size()-1,mid;

        while(start<=end){
            mid = start + (end-start)/2;

            if(nums[mid]==target){
                break;
            }

            else if(nums[mid] < target)
                start = mid+1;
            else
                end = mid-1;
        }

        if( start>end )
            return start;
        else
            return mid;

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

    displayInt(sol.searchInsert(input,target));

    return 0;
}
