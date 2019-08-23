/*
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
    int removeDuplicates(vector<int>& nums) {
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
