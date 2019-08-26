/*
Given an array with n objects colored red, white or blue, sort them in-place so that objects of the same color are adjacent, with the colors in the order red, white and blue.

Here, we will use the integers 0, 1, and 2 to represent the color red, white, and blue respectively.

Note: You are not suppose to use the library's sort function for this problem.

Example:

Input: [2,0,2,1,1,0]
Output: [0,0,1,1,2,2]
Follow up:

A rather straight forward solution is a two-pass algorithm using counting sort.
First, iterate the array counting number of 0's, 1's, and 2's, then overwrite array with total number of 0's, then 1's and followed by 2's.
Could you come up with a one-pass algorithm using only constant space?

WrittenBy : Himanshu Srivastava
Problem : Sort Colors
TimeComplexity : O(n)

*/


#include<iostream>
#include <vector>
#include<bits/stdc++.h>

using namespace std;


class Solution {

    void swap1( int* a, int* b){

        int temp = *a;
        *a = *b;
        *b = temp;

    }
public:
    void sortColors(vector<int>& nums) {

        int left = 0 ;
        int right = nums.size()-1;
        int mid = 0 ;
        while( mid <= right){


            switch(nums[mid]){

                case 0 : swap(nums[left],nums[mid]);
                    left++;
                    mid++;
                    break;
                case 1: mid++;
                    break;
                case 2: swap(nums[mid],nums[right]);
                    right--;
                    break;
            }

        }


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

    vector<int> input{2, 7, 11, 15};

    displayInt(sol.sortColors(input));

    return 0;
}
