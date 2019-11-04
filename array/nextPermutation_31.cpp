/*
Implement next permutation, which rearranges numbers into the lexicographically next greater permutation of numbers.

If such arrangement is not possible, it must rearrange it as the lowest possible order (ie, sorted in ascending order).

The replacement must be in-place and use only constant extra memory.

Here are some examples. Inputs are in the left-hand column and its corresponding outputs are in the right-hand column.

1,2,3 → 1,3,2
3,2,1 → 1,2,3
1,1,5 → 1,5,1


WrittenBy : Himanshu Srivastava
Problem : next Permutation
TimeComplexity : O(n)



*/


#include<iostream>
#include <vector>
#include<bits/stdc++.h>

using namespace std;


class Solution {
public:
    void nextPermutation(vector<int>& nums) {

        int size = nums.size();
        if(size < 2) return ;
        int i = size-2, j = size-1;
        while(i>=0 && nums[i]>=nums[i+1]) i--;
        if(i >= 0)
        {
            while(j>=0 && nums[j]<=nums[i]) j--;
            swap(nums[i], nums[j]);
        }
        reverse(nums.begin()+i+1, nums.end());

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

    vector<int> input{3,2,2,3,2};

    sol.nextPermutation(input);
    // cout<<count<<endl;
    displayInt(input);

    return 0;
}
