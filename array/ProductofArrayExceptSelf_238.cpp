/*

Given an integer array nums, return an array answer such that answer[i] is equal to the product of all the elements of nums except nums[i].

The product of any prefix or suffix of nums is guaranteed to fit in a 32-bit integer.

You must write an algorithm that runs in O(n) time and without using the division operation.

 

Example 1:

Input: nums = [1,2,3,4]
Output: [24,12,8,6]
Example 2:

Input: nums = [-1,1,0,-3,3]
Output: [0,0,9,0,0]
 

Constraints:

2 <= nums.length <= 105
-30 <= nums[i] <= 30
The product of any prefix or suffix of nums is guaranteed to fit in a 32-bit integer.
 

Follow up: Can you solve the problem in O(1) extra space complexity? (The output array does not count as extra space for space complexity analysis.)


WrittenBy : Himanshu Srivastava
Problem :  Product of Array Except Self
TimeComplexity : O(n)



*/



class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        
        
        vector<int> res(nums.size(),0);
        int prod = 1;
        int zeroCount = 0 ;
        
        for( int i = 0 ; i < nums.size();i++){
            
            if( nums[i] != 0){
                prod *= nums[i];
            }else{
                zeroCount++;
            }
        }
        
        if( zeroCount>1){
            return res;
        }
        
        for( int i = 0 ; i < nums.size();i++){
            
            int val = nums[i];
            
            if( zeroCount > 0 && val != 0 ){
                res[i] = 0;
            }else if ( val != 0) {
                res[i]  = prod/val ;
            }else{
                res[i] = prod;
            }
            
        }
        
        return res;
        
    }
};


