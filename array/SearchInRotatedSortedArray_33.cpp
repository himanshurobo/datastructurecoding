/*

Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.

(i.e., [0,1,2,4,5,6,7] might become [4,5,6,7,0,1,2]).

You are given a target value to search. If found in the array return its index, otherwise return -1.

You may assume no duplicate exists in the array.

Your algorithm's runtime complexity must be in the order of O(log n).

Example 1:

Input: nums = [4,5,6,7,0,1,2], target = 0
Output: 4
Example 2:

Input: nums = [4,5,6,7,0,1,2], target = 3
Output: -1


WrittenBy : Himanshu Srivastava
Problem : next Permutation
TimeComplexity : O(logn)

*/


#include<iostream>
#include <vector>
#include<bits/stdc++.h>

using namespace std;



class Solution {
public:
    int search(vector<int>& nums, int target) {

        int start = 0 , end = nums.size()-1;

        while(start <= end ){

            int mid = start + (end-start)/2;

            if(nums[mid] == target)
                return mid;

            if(nums[mid] <= nums[end]){
                if( target > nums[mid] && target <= nums[end])
                    start = mid + 1;
                else
                    end = mid - 1;
            }

            if(nums[mid] >= nums[start]){
                if( target < nums[mid] && target >= nums[start])
                    end = mid -1 ;
                else
                    start = mid +1;

            }

        }
        return -1;

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

    vector<int> input{4,5,6,7,0,1,2};
    int target = 0

    int index  = sol.search(input,target);
    cout<<index<<endl;
    displayInt(input);

    return 0;
}
