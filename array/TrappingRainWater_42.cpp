/*

Given n non-negative integers representing an elevation map where the width of each bar is 1, compute
 how much water it is able to trap after raining.


The above elevation map is represented by array [0,1,0,2,1,0,1,3,2,1,2,1]. In this case, 6 units of rain 
water (blue section) are being trapped. Thanks Marcos for contributing this image!

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
    int trap1(vector<int>& height) {

       int l = 0, r = height.size()-1, level = 0, water = 0;
    while (l < r) {
        int lower = height[height[l] < height[r] ? l++ : r--];

        level = max(level, lower);
        water += level - lower;
         cout<<l<<" "<<r<<" "<<" "<<lower<<" "<<level<<" "<<water<<endl;
    }
    return water;

    }

int trap(vector<int>& height) {

        int n = height.size();

        if( n<= 2){
            return 0;
        }
        
        vector<int>left(n);
        int leftMax = height[0];
        left[0] = 0;
        for( int i= 1 ; i < n ; i ++){
           left[i] = leftMax;
           leftMax = max(leftMax,height[i]);
        }

        vector<int> right(n);
        int rightMax = height[n-1];
        right[n-1] = 0;
        for( int i = n-2; i>=0; i--){
            right[i] = rightMax;
            rightMax = max( rightMax,height[i]);
        }

        int water = 0;
        for( int i = 0 ; i < n ;i++){
            if( height[i] < left[i] && height[i] < right[i] ){
                water += min(left[i],right[i]) - height[i];
            }
        }

        return water;
    }

 int trap2(vector<int>& height) {

        int n = height.size();

        if( n<= 2){
            return 0;
        }
        
        int maxLeft = height[0];
        int maxRight = height[n-1];
        int water = 0 ;
        int left = 1;
        int right = n-2;

        while( left <= right ){

            if( maxLeft < maxRight ){
                if( height[left] >= maxLeft){
                    maxLeft = height[left];
                }else{
                    water += maxLeft - height[left];
                }
                left++;
            }else{
                if( height[right] > maxRight){
                    maxRight = height[right];
                }else{
                    water += maxRight - height[right];
                }
                right--;
            }
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
