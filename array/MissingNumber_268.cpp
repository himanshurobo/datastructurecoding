/*

Given an array containing n distinct numbers taken from 0, 1, 2, ..., n, find the one that is missing from the array.

Example 1:

Input: [3,0,1]
Output: 2
Example 2:

Input: [9,6,4,2,3,5,7,0,1]
Output: 8
Note:
Your algorithm should run in linear runtime complexity. Could you implement it using only constant extra space complexity?


WrittenBy : Himanshu Srivastava
Problem : . Missing Number
TimeComplexity : O(n)


*/


class Solution {
public:
    int missingNumber(vector<int>& nums) {
        
        int result = nums.size();
        for( int i = 0 ; i < nums.size(); i++){
             result ^=i;
            result^=nums[i];
        }
        
        return result;
        
       
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

    vector<int>input{7,1,5,3,6,4}

    cout<<(sol.missingNumber(input));

    return 0;
}