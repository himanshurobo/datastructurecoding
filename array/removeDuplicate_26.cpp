/*


Given a sorted array nums, remove the duplicates in-place such that each element appear only once and return
 the new length.

Do not allocate extra space for another array, you must do this by modifying the input array in-place 
with O(1) extra memory.

Example 1:

Given nums = [1,1,2],

Your function should return length = 2, with the first two elements of nums being 1 and 2 respectively.

It doesn't matter what you leave beyond the returned length.
Example 2:

Given nums = [0,0,1,1,1,2,2,3,3,4],

Your function should return length = 5, with the first five elements of nums being modified to 
0, 1, 2, 3, and 4 respectively.

It doesn't matter what values are set beyond the returned length.
Clarification:

Confused why the returned value is an integer but your answer is an array?

Note that the input array is passed in by reference, which means modification to the input array will be 
known to the caller as well.

Internally you can think of this:

// nums is passed in by reference. (i.e., without making a copy)
int len = removeDuplicates(nums);

// any modification to nums in your function would be known by the caller.
// using the length returned by your function, it prints the first len elements.
for (int i = 0; i < len; i++) {
    print(nums[i]);
}


 WrittenBy : Himanshu Srivastava
 Problem : Remove Duplicate value
 TimeComplexity : O(n)

 */

#include<iostream>
#include <vector>
#include<bits/stdc++.h>

using namespace std;



class Solution {
public:
    int removeDuplicates1(vector<int>& nums) {
        int count = 0;
        int size = nums.size();
        for( int i = 1 ; i < size; i++){

            if(nums[i] == nums[i-1])
                count++;
            else
                nums[i - count] = nums[i];
        }

        return size - count;

    }

int removeDuplicates(vector<int>& nums) {
    if (nums.empty()) return 0;

    int i = 0; // Pointer for the position of the last unique element

    for (int j = 1; j < nums.size(); ++j) {
        if (nums[j] != nums[i]) {
            ++i; // Move the pointer for unique elements
            nums[i] = nums[j]; // Update the position with a new unique element
        }
    }

    return i + 1; // Length of the array with unique elements
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

    vector<int> input{2, 2, 11, 15};

    int count  = sol.threeSumClosest(input);
    cout<<count<<endl;
    displayInt(input);

    return 0;
}
