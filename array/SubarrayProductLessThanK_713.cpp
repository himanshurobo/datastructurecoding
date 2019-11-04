/*

Your are given an array of positive integers nums.

Count and print the number of (contiguous) subarrays where the product of all the elements in the subarray
 is less than k.

Example 1:
Input: nums = [10, 5, 2, 6], k = 100
Output: 8
Explanation: The 8 subarrays that have product less than 100 are: [10], [5], [2], [6], [10, 5], [5, 2], [2, 6],
 [5, 2, 6].
Note that [10, 5, 2] is not included as the product of 100 is not strictly less than k.



WrittenBy : Himanshu Srivastava
Problem : Subarray Product Less Than K
TimeComplexity : O(n)



*/

#include"header.hpp"


class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        
        if (k <= 1) return 0;
        int n = nums.size(), prod = 1, ans = 0, left = 0;
        for (int i = 0; i < n; i++) {
            prod *= nums[i];
            cout<<prod<<"-->";
            while (prod >= k) prod /= nums[left++];
            ans += i - left + 1;
            cout<<ans<<" "<<i<<" "<<left<<endl;
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

    vector<int>input{10, 5, 2, 6};

    cout<<(sol.numSubarrayProductLessThanK(input,100));

    return 0;
}