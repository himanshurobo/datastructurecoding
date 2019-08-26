/*

Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it is able to trap after raining.


The above elevation map is represented by array [0,1,0,2,1,0,1,3,2,1,2,1]. In this case, 6 units of rain water (blue section) are being trapped. Thanks Marcos for contributing this image!

Example:

Input: [0,1,0,2,1,0,1,3,2,1,2,1]
Output: 6

WrittenBy : Himanshu Srivastava
Problem : Trapping Rain Water
TimeComplexity : O(n)

*/


#include<iostream>
#include <vector>
#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {

       int l = 0, r = height.size()-1, level = 0, water = 0;
    while (l < r) {
        int lower = height[height[l] < height[r] ? l++ : r--];

        level = max(level, lower);
        water += level - lower;
         cout<<l<<" "<<r<<" "<<" "<<lower<<" "<<level<<" "<<water<<endl;
    }
    return water;

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

    vector<int> input{0,1,0,2,1,0,1,3,2,1,2,1};
    vector<vector<int>> res;
    int water = sol.trap(input);
    cout<<water<<endl;

    return 0;
}
