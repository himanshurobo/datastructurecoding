/*

Given an integer array nums, you need to find one continuous subarray that if you only sort this subarray in ascending order, then the whole array will be sorted in ascending order.

Return the shortest such subarray and output its length.

 

Example 1:

Input: nums = [2,6,4,8,10,9,15]
Output: 5
Explanation: You need to sort [6, 4, 8, 10, 9] in ascending order to make the whole array sorted in ascending order.
Example 2:

Input: nums = [1,2,3,4]
Output: 0
Example 3:

Input: nums = [1]
Output: 0
 

Constraints:

1 <= nums.length <= 104
-105 <= nums[i] <= 105
 

Follow up: Can you solve it in O(n) time complexity?

WrittenBy : Himanshu Srivastava
Problem : Shortest Unsorted Continuous Subarray
TimeComplexity : O(n)

*/


class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        
        int n = nums.size();
        
        int i =0 ;
        int j =n-1;
        
        int start = 0 ;
        int end = -1;
        
        int maxSoFar = INT_MAX;
        int minSoFar = INT_MIN;
        
        
        while( j >= 0 ){
            
            if( nums[i] >= minSoFar){
                minSoFar = nums[i];
            }else{
                end = i;
            }
            
            if( nums[j] <= maxSoFar){
                maxSoFar = nums[j];
            }else{
                start = j;
            }
            
            i++;
            j--;
        }
        // cout<<i<<" "<<j<<" "<<maxSoFar<<" "<<minSoFar<<endl;
        
        return end -start +1;
        
        
        
    }
};