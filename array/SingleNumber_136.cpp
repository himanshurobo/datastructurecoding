/*

Given a non-empty array of integers, every element appears twice except for one. Find that single one.

Note:

Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?

Example 1:

Input: [2,2,1]
Output: 1
Example 2:

Input: [4,1,2,1,2]
Output: 4

Properties of XOR:

a ^ a = 0 (XORing a number with itself gives 0)
a ^ 0 = a (XORing a number with 0 gives the number itself)
XOR is both commutative and associative, which means the order of operations doesn’t affect the result.

*/


class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int result = 0;
        
        for( int i =0; i < nums.size() ;i++){
            result ^=nums[i];
        }
        
        return result;
    }
};
