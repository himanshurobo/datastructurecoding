
/*
Given a sorted array nums, remove the duplicates in-place such that duplicates appeared at most twice and 
return the new length.

Do not allocate extra space for another array, you must do this by modifying the input array in-place with 
O(1) extra memory.

Example 1:

Given nums = [1,1,1,2,2,3],

Your function should return length = 5, with the first five elements of nums being 1, 1, 2, 2 and 3 respectively.

It doesn't matter what you leave beyond the returned length.
Example 2:

Given nums = [0,0,1,1,1,1,2,3,3],

Your function should return length = 7, with the first seven elements of nums being modified to
 0, 0, 1, 1, 2, 3 and 3 respectively.

It doesn't matter what values are set beyond the returned length.
Clarification:

Confused why the returned value is an integer but your answer is an array?

Note that the input array is passed in by reference, which means modification to the input array will
 be known to the caller as well.

Internally you can think of this:

// nums is passed in by reference. (i.e., without making a copy)
int len = removeDuplicates(nums);

// any modification to nums in your function would be known by the caller.
// using the length returned by your function, it prints the first len elements.
for (int i = 0; i < len; i++) {
    print(nums[i]);
}


WrittenBy : Himanshu Srivastava
Problem : Remove Duplicates from Sorted Array II
TimeComplexity : O(n)


*/

#include"../header.hpp"

class Solution {
public:
    int removeDuplicates_old(vector<int>& nums) {
       int i = 0;
        for (int n : nums){
            cout<<"n-->"<<n<<" ";
            if (i < 2 || n > nums[i-2]){
                nums[i++] = n;
                cout<<i<<" "<<nums[i]<<"<"<<n<<endl;
            }
        }
                
        return i;

    }

    int removeDuplicates1(vector<int>& nums) {
        int i = 0;
        for( int j =1 ; j<nums.size();j++){
            if( nums[i] != nums[j]){
                i++;
                nums[i] = nums[j];
            }
        }

        return i+1;

    }

int removeDuplicates(vector<int>& nums) {
    if (nums.empty()) return 0;
    
    int j = 0; // Pointer for the position to place the next valid element
    int count = 0; // Count of occurrences of the current element

    for (int i = 0; i < nums.size(); ++i) {
        if (i == 0 || nums[i] != nums[i - 1]) {
            count = 1; // Reset count for a new element
        } else {
            count++;
        }
        
        // Place element if it appears at most twice
        if (count <= 2) {
            nums[j++] = nums[i];
        }
    }
    
    return j; // Length of the modified array
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

    vector<int> input{0,0,1,1,1,1,2,3,3};
    vector<vector<int>> res;
    cout<<sol.removeDuplicates(input);

    return 0;
}
