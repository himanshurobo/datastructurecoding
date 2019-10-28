
/*
 WrittenBy : Himanshu Srivastava
 Problem : Container With Most Water 
 TimeComplexity : O(n)

 */


#include<iostream>
#include <vector>
#include<bits/stdc++.h> 

using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        
        int start = 0 ;
        int end = height.size() -1 ;
        int maxArea = 0 ;
        while(start<=end){
            
            if(height[start]<height[end]){
                maxArea = std::max(maxArea,height[start] * ( end - start));                
                start++;
            }else{
                maxArea = std::max(maxArea,height[end] * (end - start));
                end--;
            }
        }
        
        return maxArea;
    }
};




int main(){

    Solution sol;

    vector<int> input1{1, 3, 11, 15};

    cout<<sol.maxArea(input1)<<endl;

    return 0;
}