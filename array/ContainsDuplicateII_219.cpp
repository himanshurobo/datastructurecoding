



/*

Given an integer array nums and an integer k, return true if there are two distinct indices i and j in the array such that nums[i] == nums[j] and abs(i - j) <= k.

 

Example 1:

Input: nums = [1,2,3,1], k = 3
Output: true
Example 2:

Input: nums = [1,0,1,1], k = 1
Output: true
Example 3:

Input: nums = [1,2,3,1,2,3], k = 2
Output: false



WrittenBy : Himanshu Srivastava
Problem :Contains Duplicate II
TimeComplexity : O(n)

*/



#include "../header.hpp"

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        
        map<int,int> hashMap;
        
        for( int i =0 ; i < nums.size(); i++){
            
            if( hashMap.find(nums[i]) != hashMap.end() && ( i - hashMap[nums[i]] ) <= k ) {
                return true;
            }
            hashMap[nums[i]] = i;
        }
        
        return false;
        
    }
};