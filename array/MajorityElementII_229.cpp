/*

Given an integer array of size n, find all elements that appear more than ⌊ n/3 ⌋ times.

Follow-up: Could you solve the problem in linear time and in O(1) space?

 

Example 1:

Input: nums = [3,2,3]
Output: [3]
Example 2:

Input: nums = [1]
Output: [1]
Example 3:

Input: nums = [1,2]
Output: [1,2]
 

Constraints:

1 <= nums.length <= 5 * 104
-109 <= nums[i] <= 109


WrittenBy : Himanshu Srivastava
Problem :  Majority Element II ( Boyer-Moore Voting Algorithm )
TimeComplexity : O(n)

*/


class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        
        int major1 = INT_MIN;
        int major2 = INT_MIN;
        
        int count1 = 0 ; 
        int count2 = 0 ;
        
        int n = nums.size();
        
        for( int i = 0; i < n; i++ ){
            
            if( major1 == nums[i] ){
                count1++;
            }else if ( major2 == nums[i] ){
                count2++;
            }else if ( count1 == 0 ){
                major1 = nums[i];
                count1++;
            }else if( count2 == 0 ){
                major2 = nums[i];
                count2++;
            }else{
                count1--;
                count2--;
            }
        }
        
        
        count1 = 0;
        count2 = 0;
        
        for( int i = 0 ; i < n; i++){
            
            if( nums[i] == major1){
                count1++;
            }
            
            if( nums[i] == major2){
                count2++;
            }
        }
        
        
        
        vector<int> res ;
        
        if( count1 > n/3 ){
            res.push_back(major1);
        }
        
        if( count2 > n/3 ){
            res.push_back(major2);
        }
        
        return res;
        
    }
};