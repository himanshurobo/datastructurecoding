/*

In a given array nums of positive integers, find three non-overlapping subarrays with maximum sum.

Each subarray will be of size k, and we want to maximize the sum of all 3*k entries.

Return the result as a list of indices representing the starting position of each interval (0-indexed).
 If there are multiple answers, return the lexicographically smallest one.

Example:

Input: [1,2,1,2,6,7,5,1], 2
Output: [0, 3, 5]
Explanation: Subarrays [1, 2], [2, 6], [7, 5] correspond to the starting indices [0, 3, 5].
We could have also taken [2, 1], but an answer of [1, 3, 5] would be lexicographically larger.
 

Note:

nums.length will be between 1 and 20000.
nums[i] will be between 1 and 65535.
k will be between 1 and floor(nums.length / 3).
 
WrittenBy : Himanshu Srivastava
Problem : Maximum Sum of 3 Non-Overlapping Subarrays
TimeComplexity : O(n)


*/


class Solution {
public:

 vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {
        
        int n = nums.size();
        
        vector<int> sdSum(n);
        int sum =0;
        for( int i = 0 ; i < n;i++){
            
            sum +=nums[i];
            
            if( i >= k){
                sum -= nums[i-k];
            }
            
            sdSum[i] = sum;
                
        }
        
        
        vector<int> leftMax(n);
        int largestIndex = 0;
        for( int i = 0 ; i < n ;i++){
            
            if( sdSum[i] > sdSum[largestIndex]){
                largestIndex = i;                
            }
            
            leftMax[i] = largestIndex;            
        }
        
        
        vector<int> rightMax(n);
        largestIndex= n-1;
        for( int i = n-1; i>=0;i--){
            
            if(sdSum[i] >= sdSum[largestIndex]){
                largestIndex = i;
            }
            
            rightMax[i] = largestIndex;
        }
        
        
        int largestSum = -1;
        
        vector<int> res(3);
        
        for( int mid = 2*k-1; mid < n - k; mid++){
            
            int left = leftMax[mid -k] ;
            int right = rightMax[mid + k];
            
            sum = sdSum[left] + sdSum[mid] + sdSum[right];
            
            if( sum > largestSum){
                largestSum = sum;
                res[0] = left - k +1;
                res[1] = mid - k +1 ;
                res[2] = right -k +1;
            }
        }
        
        
        return res;
        
        
    }


    vector<int> maxSumOfThreeSubarrays1(vector<int>& nums, int k) {
        int n = nums.size(), maxsum = 0;
        vector<int> sum = {0}, posLeft(n, 0), posRight(n, n-k), ans(3, 0);
        for (int i:nums) sum.push_back(sum.back()+i);
       // DP for starting index of the left max sum interval
        for (int i = k, tot = sum[k]-sum[0]; i < n; i++) {
            if (sum[i+1]-sum[i+1-k] > tot) {
                posLeft[i] = i+1-k;
                tot = sum[i+1]-sum[i+1-k];
            }
            else 
                posLeft[i] = posLeft[i-1];
        }
        // DP for starting index of the right max sum interval
        // caution: the condition is ">= tot" for right interval, and "> tot" for left interval
        for (int i = n-k-1, tot = sum[n]-sum[n-k]; i >= 0; i--) {
            if (sum[i+k]-sum[i] >= tot) {
                posRight[i] = i;
                tot = sum[i+k]-sum[i];
            }
            else
                posRight[i] = posRight[i+1];
        }
        // test all possible middle interval
        for (int i = k; i <= n-2*k; i++) {
            int l = posLeft[i-1], r = posRight[i+k];
            int tot = (sum[i+k]-sum[i]) + (sum[l+k]-sum[l]) + (sum[r+k]-sum[r]);
            if (tot > maxsum) {
                maxsum = tot;
                ans = {l, i, r};
            }
        }
        return ans;
        
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

    vector<int>input{7,1,5,3,6,4}

    cout<<(sol.matrixReshape(input));

    return 0;
}