/*


Given an integer array nums and an integer k, return true if nums has a continuous subarray of size at least two whose elements sum up to a multiple of k, or false otherwise.

An integer x is a multiple of k if there exists an integer n such that x = n * k. 0 is always a multiple of k.

 

Example 1:

Input: nums = [23,2,4,6,7], k = 6
Output: true
Explanation: [2, 4] is a continuous subarray of size 2 whose elements sum up to 6.
Example 2:

Input: nums = [23,2,6,4,7], k = 6
Output: true
Explanation: [23, 2, 6, 4, 7] is an continuous subarray of size 5 whose elements sum up to 42.
42 is a multiple of 6 because 42 = 7 * 6 and 7 is an integer.
Example 3:

Input: nums = [23,2,6,4,7], k = 13
Output: false
 

Constraints:

1 <= nums.length <= 105
0 <= nums[i] <= 109
0 <= sum(nums[i]) <= 231 - 1
1 <= k <= 231 - 1


WrittenBy : Himanshu Srivastava
Problem : Continuous Subarray Sum
TimeComplexity : O(n)


*/


class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
  
        //Questions to ask the interviewer - 
        
        //1. So you said k is an integer? Can the k be equal to 0? Can it be n-ve?
        // ANS - k can be positive, zero or negative - consider all cases !
        
        // Positive case - [23, 2, 4, 6, 7],  k=6; ANS = true
        //Negative Case - [23,2,4,6,7], k= -6; ANS = true (Since n=-1 and -1*-6=6)
        //Zero Case - [0,0], k=0; ANS = true 
        
        //2. 'n' can be anything right? positive, negative and zero
        
        //Explanation of algorithm to interviewer - 
        
        //A proof sketch:
        // Suppose sum_i represents the running sum starting from index 0 and ending at i
        // once we find a mod that has been seen, say modk, we have:
        
        // current one: sum_i = m*k + modk
        // previous one: sum_j = n*k + modk
        // Thus,
        // sum_i - sum_j = (m - n) *k
        
        //so if two runningSum mod k have the same values, then when they are subtracted, they are bound to be multiples of k

        //base checking - first check if the size of the array is less than 2
        
        if(nums.size()<2)
            return false;
        
        //Create a hashmap of the running_sum remainder and it's respective index
        
        unordered_map<int, int> mp;
        
        //Why to insert <0,-1> for the hashmap
        
        // <0,-1> can allow it to return true when the runningSum%k=0,
        
        //for example [1,2,3] is input and k=6
        //then the remainders are [ 1,3,0] i.e runningSum = runningSum%k
        //now 1+2+3=6 which is actually a multiple of 6 and hence 0 should be stored in the hashmap
        
        //ok - but why -1?
        //-1 is good for storing for 0 because - it will remove the case where we consider only the first element which alone
        //may be a multiple as 0-(-1) is not greater than 1
        
        // In addition, it also avoids the first element of the array is the multiple of k, since 0-(-1)=1 is not greater than 1.
        
        mp[0]=-1;
        
        int runningSum=0;
        
        for(int i=0;i<nums.size();i++)
        {
            runningSum+=nums[i];
            
            if(k!=0) 
                runningSum = runningSum%k;
            
            //check if the runningsum already exists in the hashmap
            if(mp.find(runningSum)!=mp.end())
            {
                //if it exists, then the current location minus the previous location must be greater than1
                
                if(i-mp[runningSum]>1)
                    return true;
            }
            else
            {
                //otherwise if the current runningSum doesn't exist in the hashmap, then store it as it maybe used later on
                
                mp[runningSum]=i;
            }
                    
        }
        
        return false;
    }
};