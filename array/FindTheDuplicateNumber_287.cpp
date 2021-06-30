/*

Given an array nums containing n + 1 integers where each integer is between 1 and n (inclusive),
 prove that at least one duplicate number must exist. Assume that there is only one duplicate number, 
 find the duplicate one.

Example 1:

Input: [1,3,4,2,2]
Output: 2
Example 2:

Input: [3,1,3,4,2]
Output: 3

WrittenBy : Himanshu Srivastava
Problem : .Find the Duplicate Number
TimeComplexity : O(n)

*/
#include"../header.hpp"



class Solution {

public:
    int findDuplicate1(vector<int>& nums) {
        if (nums.size() > 1)
	{
		int slow = nums[0];
		int fast = nums[nums[0]];

		std::cout<<slow<<" : "<<fast<<endl;
		while (slow != fast)
		{
			slow = nums[slow];
			fast = nums[nums[fast]];
			std::cout<<slow<<" : "<<fast<<endl;
		}

		fast = 0;
		while (fast != slow)
		{
			fast = nums[fast];
			slow = nums[slow];
			std::cout<<slow<<" : "<<fast<<endl;
		}
		return slow;
	}
	return -1;
        
    }

	int findDuplicate(vector<int>& nums) {

		for ( int i =0 ; i < nums.size();i++){
			int index = abs(nums[i]);
			if ( nums[index] > 0 ){
				nums[index] = -nums[index];
			}else{
				return index;
			}
		}
		return -1;
	}
};




void displayInt(vector<int>input){
    std::cout<<"Displaying size "<<input.size()<<endl;
    for (std::vector<int>::size_type i = 0; i < input.size(); i++) {
        std::cout << input.at(i) << ' ';
    }
}

int main(){

    Solution sol;

    vector<int>input{1,3,4,2,3};

    std::cout<<(sol.findDuplicate(input));

    return 0;
}