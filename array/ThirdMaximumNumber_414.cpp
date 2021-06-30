/*

Given integer array nums, return the third maximum number in this array. If the third maximum does not exist, return the maximum number.

 

Example 1:

Input: nums = [3,2,1]
Output: 1
Explanation: The third maximum is 1.
Example 2:

Input: nums = [1,2]
Output: 2
Explanation: The third maximum does not exist, so the maximum (2) is returned instead.
Example 3:

Input: nums = [2,2,3,1]
Output: 1
Explanation: Note that the third maximum here means the third maximum distinct number.
Both numbers with value 2 are both considered as second maximum.
 

Constraints:

1 <= nums.length <= 104
-231 <= nums[i] <= 231 - 1
 

Follow up: Can you find an O(n) solution?


WrittenBy : Himanshu Srivastava
Problem : Third Maximum Number
TimeComplexity : O(n)

*/


class Solution {
public:
    int thirdMax(vector<int>& nums) {
        
        long long int num1 = LONG_MIN;
        long long int num2 = LONG_MIN;
        long long int num3 = LONG_MIN;
        
        for( int i = 0 ; i < nums.size();i++){
            
            if( num1 == nums[i] || num2 == nums[i] || num3 == nums[i]){
                continue;
            }
            
            if( num1 < nums[i]){
                num3 = num2;
                num2 = num1;
                num1 = nums[i];
            }else if( num2 < nums[i]){
                num3 = num2;
                num2 = nums[i];
            }else if ( num3 < nums[i]){
                num3 =nums[i];
            }
            
            // cout<<num1<<" "<<num2<<" "<<num3<<endl;
        }
        
        return num3 != LONG_MIN ? num3:num1;
        
    }
};