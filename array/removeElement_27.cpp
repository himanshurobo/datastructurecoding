/*

Given an array nums and a value val, remove all instances of that value in-place and return the new length.

Do not allocate extra space for another array, you must do this by modifying the input array in-place with 
O(1) extra memory.

The order of elements can be changed. It doesn't matter what you leave beyond the new length.

Example 1:

Given nums = [3,2,2,3], val = 3,

Your function should return length = 2, with the first two elements of nums being 2.

It doesn't matter what you leave beyond the returned length.


WrittenBy : Himanshu Srivastava
Problem : Remove Element similar to target
TimeComplexity : O(n)


*/


#include<iostream>
#include <vector>
#include<bits/stdc++.h>

using namespace std;


class Solution {
public:
    int removeElement(vector<int>& nums, int val) {

        int index = 0 ;
        for( int i = 0 ; i < nums.size();i++){

            if(nums[i] == val )
               continue;
            else
                nums[index++] = nums[i];

        }

        return index;
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

    vector<int> input{3,2,2,3};
    int val = 3

    int count  = sol.removeElement(input,val)
    cout<<count<<endl;
    displayInt(input);

    return 0;
}
