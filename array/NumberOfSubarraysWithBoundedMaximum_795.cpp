/*

We are given an array nums of positive integers, and two positive integers left and right (left <= right).

Return the number of (contiguous, non-empty) subarrays such that the value of the maximum array element in that subarray is at least left and at most right.

Example:
Input: 
nums = [2, 1, 4, 3]
left = 2
right = 3
Output: 3
Explanation: There are three subarrays that meet the requirements: [2], [2, 1], [3].
Note:

left, right, and nums[i] will be an integer in the range [0, 109].
The length of nums will be in the range of [1, 50000].


WrittenBy : Himanshu Srivastava
Problem : Number of Subarrays with Bounded Maximum
TimeComplexity : O(n)



*/

class Solution {
public:
    int numSubarrayBoundedMax1(vector<int>& nums, int left, int right) {
        int result=0;
        int l =-1;
        int r =-1;
        for (int i=0; i<nums.size(); i++) {
            if (nums[i]>right) l=i;
            if (nums[i]>=left) r=i;
            result+=r-l;
            // cout<<result<<" "<<l<<" "<<r<<endl;
        }
        return result;
    }

int numSubarrayBoundedMax(vector<int>& nums, int left, int right) {

        int i =0;
        int j = 0;
        int maxCount = 0;
        int m = 0 ;

        while( j < nums.size()){

            if ( nums[j]> right ){
                m = 0;
                i = j +1;
                
            }else if( nums[j]>= left && nums[j] <= right){
                m = j - i +1;
            }

            maxCount += m;
            j++;
        }

        return maxCount;
        
    }
};
