/*

Given an array of integers nums, write a method that returns the "pivot" index of this array.

We define the pivot index as the index where the sum of the numbers to the left of the index is equal
 to the sum of the numbers to the right of the index.

If no such index exists, we should return -1. If there are multiple pivot indexes, you should return 
the left-most pivot index.

Example 1:

Input: 
nums = [1, 7, 3, 6, 5, 6]
Output: 3
Explanation: 
The sum of the numbers to the left of index 3 (nums[3] = 6) is equal to the sum of numbers to the right of 
index 3.
Also, 3 is the first index where this occurs.
 

Example 2:

Input: 
nums = [1, 2, 3]
Output: -1
Explanation: 
There is no index that satisfies the conditions in the problem statement.


WrittenBy : Himanshu Srivastava
Problem : Find Pivot Index
TimeComplexity : O(n)


*/

#include"../header.hpp"

class Solution {
public:
    int pivotIndex1(vector<int>& nums) {
        int total = 0;
        for (int num : nums) total += num;
        int sum = 0;
        for (int i = 0; i < nums.size(); sum += nums[i++]){
            // cout<<sum<<" "<<(total - nums[i])<<endl;
            if (sum * 2 == total - nums[i])
                return i;
        }
        
        return -1;
    }

     int pivotIndex(vector<int>& nums) {

        int l = 0 , r = nums.size()-1;
        int leftSum = nums[l] ;
        int rightSum = nums[r];
         while(l < r){
 
             if( leftSum > rightSum){
                rightSum +=nums[--r];
             }else if ( leftSum < rightSum) {
                 leftSum += nums[++l];
             }else{
                //  cout<<l;
                 return l+1;
             }
                         cout<<leftSum<<"--"<<rightSum<<"####"<<l<<"---"<<r<<endl;
         }

         return -1;
     
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

    vector<int>input{1, 2,5, 3, 6, 5, 6,};

    cout<<(sol.pivotIndex(input));

    return 0;
}