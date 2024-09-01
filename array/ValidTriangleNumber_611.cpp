/*
Given an integer array nums, return the number of triplets chosen from the array that can make triangles if we take them as side lengths of a triangle.

 

Example 1:

Input: nums = [2,2,3,4]
Output: 3
Explanation: Valid combinations are: 
2,3,4 (using the first 2)
2,3,4 (using the second 2)
2,2,3
Example 2:

Input: nums = [4,2,3,4]
Output: 4
 

Constraints:

1 <= nums.length <= 1000
0 <= nums[i] <= 1000


WrittenBy : Himanshu Srivastava
Problem : Valid Triangle Number
TimeComplexity : O(n)


*/


class Solution {
public:
    int triangleNumber1(vector<int>& nums) {
        
        int n = nums.size();
        int count = 0 ;
        
        sort( nums.begin(),nums.end());
        
        int i = n-1;
        
        while( i >=1 ){
            
            int start = 0 ;
            int end = i-1;
            
            while( start < end){
                
                if(nums[start] + nums[end] > nums[i]){
                    
                    count += end - start;
                    
                    end--;
                    
                }else{
                    start++;
                }
            }
            
            i--;
        }
        
        return count;
        
    }

  int triangleNumber(vector<int>& nums) {

            int n = nums.size();
    if (n < 3) return 0;

    // Sort the array
    sort(nums.begin(), nums.end());
    int count = 0;

    // Iterate through each possible third side
    for (int k = 2; k < n; ++k) {
        int i = 0, j = k - 1;
        
        // Use two pointers to find valid pairs (i, j)
        while (i < j) {
            if (nums[i] + nums[j] > nums[k]) {
                // All pairs (i, i+1, ..., j-1) with j are valid
                count += (j - i);
                --j; // Move the end pointer
            } else {
                ++i; // Move the start pointer
            }
        }
    }
    
    return count;
        
    }
};
